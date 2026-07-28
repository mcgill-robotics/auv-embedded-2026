import socket

JETSON_IP = "ubuntu.local"
PORT = 9000
OUTFILE = "ad3_stream.bin"

with socket.create_connection((JETSON_IP, PORT)) as sock:
    f = sock.makefile("rb")

    header = f.readline().decode().strip()
    print("Header:", header)

    with open(OUTFILE, "wb") as out:
        while True:
            data = f.read(65536)
            if not data:
                break
            out.write(data)
