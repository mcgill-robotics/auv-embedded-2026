import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import spectrogram


BIN_FILE = "ad3_stream_stereo_f32le.bin"
FS = 500_000.0   # sample rate in Hz


# ---------- Load interleaved stereo float32le ----------
raw = np.fromfile(BIN_FILE, dtype="<f4")

if raw.size % 2 != 0:
    raise RuntimeError("File does not contain an even number of float32 values")

stereo = raw.reshape(-1, 2)
ch1 = stereo[:, 0]
ch2 = stereo[:, 1]

print(f"Loaded {stereo.shape[0]} frames")
print(f"CH1 samples: {ch1.shape[0]}")
print(f"CH2 samples: {ch2.shape[0]}")


# ---------- Spectrogram parameters ----------
nperseg = 4096
noverlap = 3072
window = "hann"


# ---------- Compute spectrograms ----------
f1, t1, Sxx1 = spectrogram(
    ch1,
    fs=FS,
    window=window,
    nperseg=nperseg,
    noverlap=noverlap,
    detrend=False,
    scaling="density",
    mode="psd",
)

f2, t2, Sxx2 = spectrogram(
    ch2,
    fs=FS,
    window=window,
    nperseg=nperseg,
    noverlap=noverlap,
    detrend=False,
    scaling="density",
    mode="psd",
)

# Convert to dB, avoid log(0)
Sxx1_dB = 10 * np.log10(Sxx1 + 1e-20)
Sxx2_dB = 10 * np.log10(Sxx2 + 1e-20)


# ---------- Plot ----------
fig, axes = plt.subplots(2, 1, figsize=(12, 8), sharex=True)

im1 = axes[0].pcolormesh(t1, f1, Sxx1_dB, shading="auto")
axes[0].set_title("CH1 Spectrogram")
axes[0].set_ylabel("Frequency [Hz]")
fig.colorbar(im1, ax=axes[0], label="PSD [dB]")

im2 = axes[1].pcolormesh(t2, f2, Sxx2_dB, shading="auto")
axes[1].set_title("CH2 Spectrogram")
axes[1].set_ylabel("Frequency [Hz]")
axes[1].set_xlabel("Time [s]")
fig.colorbar(im2, ax=axes[1], label="PSD [dB]")

plt.tight_layout()
plt.show()