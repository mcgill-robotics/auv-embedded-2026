import ctypes
import platform
import threading
import time
import socket
import queue
import signal
import sys
import numpy as np


# ---------- Load libdwf ----------
if platform.system() == "Windows":
    dwf = ctypes.cdll.dwf
elif platform.system() == "Darwin":
    dwf = ctypes.cdll.LoadLibrary("/Library/Frameworks/dwf.framework/dwf")
else:
    dwf = ctypes.cdll.LoadLibrary("libdwf.so")


# ---------- DWF constants ----------
hdwfNone = ctypes.c_int(0)

acqmodeRecord = 3
trigsrcNone = 0
filterDecimate = 0


def check_ok(ok):
    if ok:
        return
    err_msg = ctypes.create_string_buffer(512)
    dwf.FDwfGetLastErrorMsg(err_msg)
    raise RuntimeError(err_msg.value.decode(errors="replace"))


def open_first_device():
    hdwf = ctypes.c_int()
    check_ok(dwf.FDwfDeviceOpen(ctypes.c_int(-1), ctypes.byref(hdwf)))
    if hdwf.value == hdwfNone.value:
        raise RuntimeError("No Digilent device opened.")
    return hdwf


def close_device(hdwf):
    dwf.FDwfDeviceClose(hdwf)


class TcpStreamer:
    def __init__(
        self,
        host="0.0.0.0",
        port=9000,
        sample_rate=500_000.0,
        input_range=5.0,
        chunk_hint=8192,
        probe_scale=1.0,
        queue_chunks=64,
        enable_vplus=True,
        vplus_volts=5.0,
        power_limit_w=15.0,
    ):
        self.host = host
        self.port = int(port)

        self.channels = (0, 1)   # API channel 0 = UI Channel 1, API channel 1 = UI Channel 2
        self.sample_rate = float(sample_rate)
        self.input_range = float(input_range)
        self.chunk_hint = int(chunk_hint)
        self.probe_scale = float(probe_scale)

        self.enable_vplus = bool(enable_vplus)
        self.vplus_volts = float(vplus_volts)
        self.power_limit_w = float(power_limit_w)

        self.hdwf = None
        self.local_chunk = None

        self.server_sock = None
        self.client_sock = None
        self.client_addr = None
        self.client_lock = threading.Lock()

        self.tx_queue = queue.Queue(maxsize=queue_chunks)

        self.stop_event = threading.Event()
        self.accept_thread = None
        self.acquire_thread = None
        self.send_thread = None

        self.samples_sent = 0
        self.samples_lost_dwf = 0
        self.samples_corrupt_dwf = 0
        self.chunks_dropped_net = 0
        self.last_error = None

    # ---------- Power supplies ----------
    def configure_supplies(self):
        """
        Configure AD3 supplies:
          - V+ = +5.0 V
          - V+ enabled
          - hardware power limit = 15 W
          - AnalogIO master enable on
        """
        # Reset AnalogIO to a known state
        check_ok(dwf.FDwfAnalogIOReset(self.hdwf))

        # AD3 forum guidance: hardware power limit is channel 3, node 0
        check_ok(dwf.FDwfAnalogIOChannelNodeSet(
            self.hdwf,
            ctypes.c_int(3),
            ctypes.c_int(0),
            ctypes.c_double(self.power_limit_w),
        ))

        if self.enable_vplus:
            # V+ channel = 0
            # node 1 = voltage
            check_ok(dwf.FDwfAnalogIOChannelNodeSet(
                self.hdwf,
                ctypes.c_int(0),
                ctypes.c_int(1),
                ctypes.c_double(self.vplus_volts),
            ))

            # node 0 = enable
            check_ok(dwf.FDwfAnalogIOChannelNodeSet(
                self.hdwf,
                ctypes.c_int(0),
                ctypes.c_int(0),
                ctypes.c_double(1.0),
            ))

        # Master enable
        check_ok(dwf.FDwfAnalogIOEnableSet(
            self.hdwf,
            ctypes.c_int(1),
        ))

        # Apply AnalogIO settings
        check_ok(dwf.FDwfAnalogIOConfigure(self.hdwf))

        # Optional status readback
        try:
            check_ok(dwf.FDwfAnalogIOStatus(self.hdwf))

            vplus_read = ctypes.c_double()
            check_ok(dwf.FDwfAnalogIOChannelNodeStatus(
                self.hdwf,
                ctypes.c_int(0),
                ctypes.c_int(1),
                ctypes.byref(vplus_read),
            ))
            print(f"[SUPPLY] V+ configured, readback={vplus_read.value:.3f} V")
        except Exception as e:
            print(f"[SUPPLY] Configured, but readback failed: {e}")

        print(f"[SUPPLY] Hardware power limit set to {self.power_limit_w:.1f} W")

    # ---------- Device ----------
    def arm_device(self):
        if self.hdwf is not None:
            return

        self.hdwf = open_first_device()

        # Configure supplies first
        self.configure_supplies()

        dwf.FDwfDeviceAutoConfigureSet(self.hdwf, ctypes.c_int(0))
        dwf.FDwfAnalogInReset(self.hdwf)

        for ch in self.channels:
            check_ok(dwf.FDwfAnalogInChannelEnableSet(
                self.hdwf, ctypes.c_int(ch), ctypes.c_int(1)
            ))
            check_ok(dwf.FDwfAnalogInChannelRangeSet(
                self.hdwf, ctypes.c_int(ch), ctypes.c_double(self.input_range)
            ))
            check_ok(dwf.FDwfAnalogInChannelFilterSet(
                self.hdwf, ctypes.c_int(ch), ctypes.c_int(filterDecimate)
            ))

        check_ok(dwf.FDwfAnalogInAcquisitionModeSet(
            self.hdwf, ctypes.c_int(acqmodeRecord)
        ))
        check_ok(dwf.FDwfAnalogInFrequencySet(
            self.hdwf, ctypes.c_double(self.sample_rate)
        ))
        check_ok(dwf.FDwfAnalogInRecordLengthSet(
            self.hdwf, ctypes.c_double(0.0)
        ))
        check_ok(dwf.FDwfAnalogInTriggerSourceSet(
            self.hdwf, ctypes.c_int(trigsrcNone)
        ))

        buf_min = ctypes.c_int()
        buf_max = ctypes.c_int()
        check_ok(dwf.FDwfAnalogInBufferSizeInfo(
            self.hdwf, ctypes.byref(buf_min), ctypes.byref(buf_max)
        ))

        self.local_chunk = min(self.chunk_hint, max(1024, buf_max.value))
        time.sleep(0.2)

    # ---------- TCP ----------
    def start_server(self):
        self.server_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.server_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        self.server_sock.bind((self.host, self.port))
        self.server_sock.listen(1)
        self.server_sock.settimeout(1.0)
        print(f"[TCP] Listening on {self.host}:{self.port}")

    def _replace_client(self, conn, addr):
        with self.client_lock:
            old = self.client_sock
            self.client_sock = conn
            self.client_addr = addr

        if old is not None:
            try:
                old.close()
            except Exception:
                pass

    def _drop_client(self):
        with self.client_lock:
            sock = self.client_sock
            self.client_sock = None
            self.client_addr = None

        if sock is not None:
            try:
                sock.close()
            except Exception:
                pass

    def accept_loop(self):
        while not self.stop_event.is_set():
            try:
                conn, addr = self.server_sock.accept()
                conn.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
                conn.setsockopt(socket.SOL_SOCKET, socket.SO_SNDBUF, 1 << 20)
                self._replace_client(conn, addr)
                print(f"[TCP] Client connected: {addr}")
            except socket.timeout:
                continue
            except OSError:
                break
            except Exception as e:
                self.last_error = str(e)
                print(f"[TCP] Accept error: {e}")
                time.sleep(0.2)

    # ---------- Acquisition ----------
    def acquire_loop(self):
        c_samples_ch1 = (ctypes.c_double * self.local_chunk)()
        c_samples_ch2 = (ctypes.c_double * self.local_chunk)()

        try:
            check_ok(dwf.FDwfAnalogInConfigure(
                self.hdwf, ctypes.c_int(1), ctypes.c_int(1)
            ))
            print("[DWF] Acquisition started")
        except Exception as e:
            self.last_error = str(e)
            print(f"[DWF] Start error: {e}")
            self.stop_event.set()
            return

        while not self.stop_event.is_set():
            try:
                sts = ctypes.c_byte()
                check_ok(dwf.FDwfAnalogInStatus(
                    self.hdwf, ctypes.c_int(1), ctypes.byref(sts)
                ))

                available = ctypes.c_int()
                lost = ctypes.c_int()
                corrupt = ctypes.c_int()
                check_ok(dwf.FDwfAnalogInStatusRecord(
                    self.hdwf,
                    ctypes.byref(available),
                    ctypes.byref(lost),
                    ctypes.byref(corrupt),
                ))

                if lost.value:
                    self.samples_lost_dwf += lost.value
                if corrupt.value:
                    self.samples_corrupt_dwf += corrupt.value

                n = available.value
                while n > 0 and not self.stop_event.is_set():
                    take = min(n, self.local_chunk)

                    check_ok(dwf.FDwfAnalogInStatusData(
                        self.hdwf,
                        ctypes.c_int(0),
                        ctypes.byref(c_samples_ch1),
                        ctypes.c_int(take),
                    ))
                    check_ok(dwf.FDwfAnalogInStatusData(
                        self.hdwf,
                        ctypes.c_int(1),
                        ctypes.byref(c_samples_ch2),
                        ctypes.c_int(take),
                    ))

                    arr1 = np.ctypeslib.as_array(c_samples_ch1)[:take].astype(np.float32, copy=True)
                    arr2 = np.ctypeslib.as_array(c_samples_ch2)[:take].astype(np.float32, copy=True)

                    arr1 *= self.probe_scale
                    arr2 *= self.probe_scale

                    # Interleave into stereo float32: [ch1_0, ch2_0, ch1_1, ch2_1, ...]
                    interleaved = np.empty(take * 2, dtype=np.float32)
                    interleaved[0::2] = arr1
                    interleaved[1::2] = arr2

                    payload = interleaved.tobytes(order="C")

                    try:
                        self.tx_queue.put_nowait(payload)
                    except queue.Full:
                        self.chunks_dropped_net += 1

                    n -= take

                if available.value == 0:
                    time.sleep(0.001)

            except Exception as e:
                self.last_error = str(e)
                print(f"[DWF] Acquire error: {e}")
                self.stop_event.set()
                break

        try:
            check_ok(dwf.FDwfAnalogInConfigure(
                self.hdwf, ctypes.c_int(0), ctypes.c_int(0)
            ))
        except Exception:
            pass

        print("[DWF] Acquisition stopped")

    # ---------- Sender ----------
    def send_loop(self):
        header = (
            f"STREAM sample_format=float32le "
            f"sample_rate={self.sample_rate} "
            f"channels=2 "
            f"channel_order=1,2 "
            f"layout=interleaved "
            f"probe_scale={self.probe_scale}\n"
        ).encode()

        header_sent_for_current_client = False
        last_client_id = None

        while not self.stop_event.is_set():
            with self.client_lock:
                sock = self.client_sock
                client_id = id(sock) if sock is not None else None

            if client_id != last_client_id:
                header_sent_for_current_client = False
                last_client_id = client_id

            if sock is None:
                time.sleep(0.05)
                continue

            if not header_sent_for_current_client:
                try:
                    sock.sendall(header)
                    header_sent_for_current_client = True
                    print("[TCP] Stream header sent")
                except Exception as e:
                    print(f"[TCP] Header send failed: {e}")
                    self._drop_client()
                    continue

            try:
                payload = self.tx_queue.get(timeout=0.1)
            except queue.Empty:
                continue

            try:
                sock.sendall(payload)
                self.samples_sent += len(payload) // (4 * 2)
            except Exception as e:
                print(f"[TCP] Send failed: {e}")
                self._drop_client()

    # ---------- Lifecycle ----------
    def start(self):
        self.arm_device()
        self.start_server()

        self.accept_thread = threading.Thread(target=self.accept_loop, daemon=True)
        self.acquire_thread = threading.Thread(target=self.acquire_loop, daemon=True)
        self.send_thread = threading.Thread(target=self.send_loop, daemon=True)

        self.accept_thread.start()
        self.acquire_thread.start()
        self.send_thread.start()

    def stop(self):
        self.stop_event.set()

        self._drop_client()

        if self.server_sock is not None:
            try:
                self.server_sock.close()
            except Exception:
                pass
            self.server_sock = None

        if self.accept_thread is not None:
            self.accept_thread.join(timeout=2.0)
        if self.acquire_thread is not None:
            self.acquire_thread.join(timeout=2.0)
        if self.send_thread is not None:
            self.send_thread.join(timeout=2.0)

        if self.hdwf is not None:
            try:
                # turn off master enable on exit
                dwf.FDwfAnalogIOEnableSet(self.hdwf, ctypes.c_int(0))
                dwf.FDwfAnalogIOConfigure(self.hdwf)
            except Exception:
                pass

            try:
                close_device(self.hdwf)
            except Exception:
                pass
            self.hdwf = None

    def stats(self):
        return {
            "client": self.client_addr,
            "samples_sent": self.samples_sent,
            "seconds_streamed": self.samples_sent / self.sample_rate if self.sample_rate > 0 else 0.0,
            "dwf_lost_samples": self.samples_lost_dwf,
            "dwf_corrupt_samples": self.samples_corrupt_dwf,
            "net_chunks_dropped": self.chunks_dropped_net,
            "last_error": self.last_error,
        }


def main():
    streamer = TcpStreamer(
        host="0.0.0.0",
        port=9000,
        channel=0,          # Channel 1
        sample_rate=500_000.0,
        input_range=5.0,
        chunk_hint=8192,
        probe_scale=10.0,
        queue_chunks=64,
        enable_vplus=True,
        vplus_volts=5.0,
        power_limit_w=15.0,
    )

    def handle_sigint(sig, frame):
        print("\nStopping...")
        streamer.stop()
        print(streamer.stats())
        sys.exit(0)

    signal.signal(signal.SIGINT, handle_sigint)

    streamer.start()
    print("Streaming continuously.")
    print("V+ set to +5 V, hardware power limit set to 15 W.")
    print("Connect a TCP client to the Jetson on port 9000.")
    print("Press Ctrl+C to stop.")

    while True:
        time.sleep(2.0)
        print(streamer.stats())


if __name__ == "__main__":
    main()