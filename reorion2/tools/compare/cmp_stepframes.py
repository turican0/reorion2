"""cmp_stepframes.py DBX_DIR PORT_DIR [OUT_DIR] - wave 183.

Compares the step frames of my DOSBox (DOSBOX_STEPFRAMES, 6-bit palette) with the
port's (REORION2_CHAIN_FRAMES, 8-bit palette): <label>_a.raw before each press,
<label>_b.raw 300 ms after its release. Colours are compared after the palette
lookup (RGB), so the same picture with a reordered palette counts as equal.
Prints one line per frame pair with the share of differing pixels and their
bounding box; with OUT_DIR writes side-by-side PNGs (DOSBox | port | diff) of the
frames that differ.
"""
import os
import struct
import sys
import zlib

W, H = 640, 480


def load(path, six_bit):
    d = open(path, 'rb').read()
    pal = d[:768]
    if six_bit:
        pal = bytes(min(255, c * 255 // 63) for c in pal)
    pix = d[768:768 + W * H]
    return pal, pix


def rgb_rows(pal, pix):
    return [pal[c * 3:c * 3 + 3] for c in pix]


def png(path, w, h, rgb):
    raw = b''.join(b'\0' + bytes(rgb[y * w * 3:(y + 1) * w * 3]) for y in range(h))

    def chunk(t, b):
        c = struct.pack('>I', len(b)) + t + b
        return c + struct.pack('>I', zlib.crc32(t + b) & 0xFFFFFFFF)
    open(path, 'wb').write(b'\x89PNG\r\n\x1a\n' + chunk(b'IHDR', struct.pack('>IIBBBBB', w, h, 8, 2, 0, 0, 0))
                           + chunk(b'IDAT', zlib.compress(raw, 6)) + chunk(b'IEND', b''))


def main():
    dbx, port = sys.argv[1], sys.argv[2]
    out = sys.argv[3] if len(sys.argv) > 3 else None
    if out:
        os.makedirs(out, exist_ok=True)
    names = sorted(n for n in os.listdir(port) if n.endswith('.raw'))
    same = differ = missing = 0
    for n in names:
        dp = os.path.join(dbx, n)
        if not os.path.exists(dp):
            missing += 1
            continue
        pa, xa = load(dp, True)
        pb, xb = load(os.path.join(port, n), False)
        bad = 0
        x0, y0, x1, y1 = W, H, -1, -1
        for i in range(W * H):
            ca, cb = xa[i], xb[i]
            if pa[ca * 3:ca * 3 + 3] != pb[cb * 3:cb * 3 + 3]:
                bad += 1
                y, x = divmod(i, W)
                x0, y0, x1, y1 = min(x0, x), min(y0, y), max(x1, x), max(y1, y)
        if not bad:
            same += 1
            continue
        differ += 1
        print('%-14s %6.2f %% differ  box %d,%d-%d,%d' % (n, bad * 100.0 / (W * H), x0, y0, x1, y1))
        if out:
            rgb = bytearray(W * 3 * H * 3)
            for y in range(H):
                for x in range(W):
                    i = y * W + x
                    a = pa[xa[i] * 3:xa[i] * 3 + 3]
                    b = pb[xb[i] * 3:xb[i] * 3 + 3]
                    o = (y * W * 3 + x) * 3
                    rgb[o:o + 3] = a
                    rgb[o + W * 3:o + W * 3 + 3] = b
                    rgb[o + W * 6:o + W * 6 + 3] = b'\xff\x00\xff' if a != b else bytes(c // 3 for c in a)
            png(os.path.join(out, n[:-4] + '.png'), W * 3, H, rgb)
    print('frames: %d same, %d differ, %d without a DOSBox pair' % (same, differ, missing))


if __name__ == '__main__':
    main()
