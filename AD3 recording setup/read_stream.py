import socket
import os
import numpy as np


JETSON_IP = "localhost"#"ubuntu.local"
PORT = 9000
OUTFILE = "ad3_stream_stereo_f32le.bin"
READ_SIZE = 65536

EXPECTED_BIAS_V = 1.6
TOLERANCE_V = 0.5
STARTUP_FRAMES = 200   # number of stereo frames to inspect


def parse_header(header_line: str) -> dict:
    """
    Example:
    STREAM sample_format=float32le sample_rate=500000.0 channels=2 channel_order=1,2 layout=interleaved probe_scale=10.0
    """
    parts = header_line.strip().split()
    if not parts or parts[0] != "STREAM":
        raise RuntimeError(f"Unexpected header: {header_line!r}")

    info = {}
    for token in parts[1:]:
        if "=" in token:
            k, v = token.split("=", 1)
            info[k] = v
    return info


def in_range(v: float, target: float, tol: float) -> bool:
    return (target - tol) <= v <= (target + tol)


if os.path.exists(OUTFILE):
    raise RuntimeError(
        "Attention: a target bin file with the same name already exists. "
        "Aborting recording to avoid overwriting"
    )

with socket.create_connection((JETSON_IP, PORT)) as sock:
    f = sock.makefile("rb")

    header = f.readline().decode(errors="replace").strip()
    print("Header:", header)

    info = parse_header(header)

    sample_format = info.get("sample_format")
    sample_rate = float(info.get("sample_rate", "0"))
    channels = int(info.get("channels", "1"))
    layout = info.get("layout", "unknown")
    channel_order = info.get("channel_order", "")
    probe_scale = float(info.get("probe_scale", "1.0"))

    if sample_format != "float32le":
        raise RuntimeError(f"Unsupported sample format: {sample_format}")

    if channels != 2:
        raise RuntimeError(f"Expected 2 channels, got {channels}")

    if layout != "interleaved":
        raise RuntimeError(f"Expected interleaved layout, got {layout}")

    print(f"Sample rate   : {sample_rate} Hz")
    print(f"Channels      : {channels}")
    print(f"Channel order : {channel_order}")
    print(f"Layout        : {layout}")
    print(f"Probe scale   : {probe_scale}")

    # ---- Startup bias check on first N stereo frames ----
    startup_bytes_needed = STARTUP_FRAMES * channels * 4  # float32 = 4 bytes
    startup_buf = bytearray()

    while len(startup_buf) < startup_bytes_needed:
        chunk = f.read(startup_bytes_needed - len(startup_buf))
        if not chunk:
            raise RuntimeError("Stream ended before enough startup samples were received")
        startup_buf.extend(chunk)

    startup_arr = np.frombuffer(startup_buf, dtype="<f4").reshape(-1, 2)
    ch1_mean = float(startup_arr[:, 0].mean())
    ch2_mean = float(startup_arr[:, 1].mean())

    print(f"Startup check over {STARTUP_FRAMES} frames:")
    print(f"  CH1 mean = {ch1_mean:.4f} V")
    print(f"  CH2 mean = {ch2_mean:.4f} V")
    print(f"  Expected = {EXPECTED_BIAS_V:.4f} ± {TOLERANCE_V:.4f} V")

    if not in_range(ch1_mean, EXPECTED_BIAS_V, TOLERANCE_V):
        raise RuntimeError(
            f"Startup voltage check failed on CH1: mean={ch1_mean:.4f} V, "
            f"expected {EXPECTED_BIAS_V:.4f} ± {TOLERANCE_V:.4f} V"
        )

    if not in_range(ch2_mean, EXPECTED_BIAS_V, TOLERANCE_V):
        raise RuntimeError(
            f"Startup voltage check failed on CH2: mean={ch2_mean:.4f} V, "
            f"expected {EXPECTED_BIAS_V:.4f} ± {TOLERANCE_V:.4f} V"
        )

    print("Startup voltage check passed.")

    total_bytes = 0

    with open(OUTFILE, "wb") as out:
        # Keep the validated startup samples in the recorded file
        out.write(startup_buf)
        total_bytes += len(startup_buf)

        while True:
            data = f.read(READ_SIZE)
            if not data:
                break
            out.write(data)
            total_bytes += len(data)

    bytes_per_frame = 4 * channels
    total_frames = total_bytes // bytes_per_frame
    total_seconds = total_frames / sample_rate if sample_rate > 0 else 0.0

    print("\nRecording complete")
    print(f"Saved file    : {OUTFILE}")
    print(f"Bytes written : {total_bytes}")
    print(f"Frames        : {total_frames}")
    print(f"Duration      : {total_seconds:.3f} s")