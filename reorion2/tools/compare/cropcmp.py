"""Crop the same region of a DOSBox frame and a port frame, scale it up and
stack the two (DOSBox on top) into one RGB PNG - for looking at small
differences in text and icons.

usage: python tools/compare/cropcmp.py <dosbox.raw> <port.raw> x0 y0 x1 y1 scale <out.png>
(DOSBox raw has a 6-bit palette, the port raw an 8-bit one.)
"""
import struct
import sys
import zlib

W, H = 640, 480


def rgb_rows(path, six, x0, y0, x1, y1, k):
    d = open(path, 'rb').read()
    pal = d[:768]
    if six:
        pal = bytes(min(255, c * 255 // 63) for c in pal)
    idx = d[768:768 + W * H]
    rows = []
    for y in range(y0, y1):
        line = bytearray()
        for x in range(x0, x1):
            i = idx[y * W + x]
            line += pal[3 * i:3 * i + 3] * k
        for _ in range(k):
            rows.append(bytes(line))
    return rows


def main():
    a = sys.argv[1:]
    x0, y0, x1, y1, k = (int(v) for v in a[2:7])
    rows = rgb_rows(a[0], True, x0, y0, x1, y1, k)
    rows.append(b'\xff\x00\xff' * ((x1 - x0) * k))
    rows += rgb_rows(a[1], False, x0, y0, x1, y1, k)
    w, h = (x1 - x0) * k, len(rows)
    raw = b''.join(b'\x00' + r for r in rows)

    def chunk(t, b):
        c = t + b
        return struct.pack('>I', len(b)) + c + struct.pack('>I', zlib.crc32(c))
    png = (b'\x89PNG\r\n\x1a\n' + chunk(b'IHDR', struct.pack('>IIBBBBB', w, h, 8, 2, 0, 0, 0))
           + chunk(b'IDAT', zlib.compress(raw, 9)) + chunk(b'IEND', b''))
    open(a[7], 'wb').write(png)
    print('ok', a[7])


if __name__ == '__main__':
    main()
