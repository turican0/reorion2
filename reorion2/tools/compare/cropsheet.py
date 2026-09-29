"""cropsheet.py <out.png> <cols> <x0> <y0> <x1> <y1> <scale> file.raw[:6|:8] ... - crops of many frames."""
import struct, sys, zlib
W, H = 640, 480
out, cols, x0, y0, x1, y1, sc = sys.argv[1], int(sys.argv[2]), *map(int, sys.argv[3:8])
imgs = []
for a in sys.argv[8:]:
    p, m = (a[:-2], a[-1]) if a[-2:] in (':6', ':8') else (a, '6')
    d = open(p, 'rb').read()
    pal = d[:768]
    pal = bytes(min(255, c * 255 // 63) for c in pal) if m == '6' else bytes(pal)
    imgs.append((pal, d[768:768 + W * H]))
w, h = (x1 - x0) * sc, (y1 - y0) * sc
rows = (len(imgs) + cols - 1) // cols
TW, TH = cols * (w + 3), rows * (h + 3)
buf = bytearray(b'\xff\x00\xff' * (TW * TH))
for n, (pal, idx) in enumerate(imgs):
    ox, oy = (n % cols) * (w + 3), (n // cols) * (h + 3)
    for y in range(h):
        sy = y0 + y // sc
        for x in range(w):
            c = idx[sy * W + x0 + x // sc]
            o = ((oy + y) * TW + ox + x) * 3
            buf[o:o + 3] = pal[3 * c:3 * c + 3]
raw = b''.join(b'\x00' + bytes(buf[y * TW * 3:(y + 1) * TW * 3]) for y in range(TH))
def chunk(t, dd):
    return struct.pack('>I', len(dd)) + t + dd + struct.pack('>I', zlib.crc32(t + dd) & 0xffffffff)
open(out, 'wb').write(b'\x89PNG\r\n\x1a\n' + chunk(b'IHDR', struct.pack('>IIBBBBB', TW, TH, 8, 2, 0, 0, 0))
                      + chunk(b'IDAT', zlib.compress(raw)) + chunk(b'IEND', b''))
print(out, len(imgs))
