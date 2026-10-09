"""cmp_stepframes.py A_DIR B_DIR [OUT_DIR] - wave 183.

Compares frames of the same names in two directories: my DOSBox (DOSBOX_STEPFRAMES,
GAMEREC / GAMEPLAY frames=) or the port (REORION2_CHAIN_FRAMES). Every file is the
game's 6-bit VGA DAC palette (768 B) + 640x480 indices; an older port frame with an
8-bit palette (a value over 63) is brought back with >> 2 (it was v << 2 | v >> 4).
GAMEREC frames carry 2 x int16 after the pixels: the cursor position the game has.
The cursor is drawn by the mouse interrupt, not by the game logic, so a 32x32 box
at the cursor of either frame is left out (and counted separately).
Colours are compared after the palette lookup. With OUT_DIR, side-by-side PNGs
(A | B | differing pixels in magenta) of the frames that differ.
"""
import os
import struct
import sys
import zlib

W, H = 640, 480
CUR = 32


def load(path):
    d = open(path, 'rb').read()
    pal = d[:768]
    if max(pal) > 63:
        pal = bytes(c >> 2 for c in pal)
    pix = d[768:768 + W * H]
    cur = struct.unpack_from('<hh', d, 768 + W * H) if len(d) >= 768 + W * H + 4 else None
    return pal, pix, cur


def show(pal):
    return bytes(min(255, c * 255 // 63) for c in pal)


def png(path, w, h, rgb):
    raw = b''.join(b'\0' + bytes(rgb[y * w * 3:(y + 1) * w * 3]) for y in range(h))

    def chunk(t, b):
        c = struct.pack('>I', len(b)) + t + b
        return c + struct.pack('>I', zlib.crc32(t + b) & 0xFFFFFFFF)
    open(path, 'wb').write(b'\x89PNG\r\n\x1a\n' + chunk(b'IHDR', struct.pack('>IIBBBBB', w, h, 8, 2, 0, 0, 0))
                           + chunk(b'IDAT', zlib.compress(raw, 6)) + chunk(b'IEND', b''))


def in_box(x, y, cur):
    return cur is not None and cur[0] - 4 <= x < cur[0] + CUR - 4 and cur[1] - 4 <= y < cur[1] + CUR - 4


def main():
    da, db = sys.argv[1], sys.argv[2]
    out = sys.argv[3] if len(sys.argv) > 3 else None
    if out:
        os.makedirs(out, exist_ok=True)
    names = sorted(n for n in os.listdir(db) if n.endswith('.raw'))
    same = differ = missing = 0
    for n in names:
        pa_path = os.path.join(da, n)
        if not os.path.exists(pa_path):
            missing += 1
            continue
        pa, xa, ca = load(pa_path)
        pb, xb, cb = load(os.path.join(db, n))
        bad = masked = 0
        x0, y0, x1, y1 = W, H, -1, -1
        for i in range(W * H):
            a, b = xa[i], xb[i]
            if pa[a * 3:a * 3 + 3] == pb[b * 3:b * 3 + 3]:
                continue
            y, x = divmod(i, W)
            if in_box(x, y, ca) or in_box(x, y, cb):
                masked += 1
                continue
            bad += 1
            x0, y0, x1, y1 = min(x0, x), min(y0, y), max(x1, x), max(y1, y)
        if not bad:
            same += 1
            if masked:
                print('%-14s same (cursor: %d px left out)' % (n, masked))
            continue
        differ += 1
        print('%-14s %6.2f %% differ  box %d,%d-%d,%d%s' % (n, bad * 100.0 / (W * H), x0, y0, x1, y1,
                                                          '  (cursor: %d px left out)' % masked if masked else ''))
        if out:
            sa, sb = show(pa), show(pb)
            rgb = bytearray(W * 3 * H * 3)
            for y in range(H):
                for x in range(W):
                    i = y * W + x
                    a = sa[xa[i] * 3:xa[i] * 3 + 3]
                    b = sb[xb[i] * 3:xb[i] * 3 + 3]
                    o = (y * W * 3 + x) * 3
                    rgb[o:o + 3] = a
                    rgb[o + W * 3:o + W * 3 + 3] = b
                    rgb[o + W * 6:o + W * 6 + 3] = b'\xff\x00\xff' if a != b else bytes(c // 3 for c in a)
            png(os.path.join(out, n[:-4] + '.png'), W * 3, H, rgb)
    print('frames: %d same, %d differ, %d without a pair' % (same, differ, missing))


if __name__ == '__main__':
    main()
