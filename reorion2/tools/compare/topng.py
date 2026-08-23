# raw snimek -> PNG.  Format: 768 B palety (RGB) + width*height indexu.
# port ma paletu 8bitovou, dosbox 6bitovou (prepinac --6bit).
import sys, zlib, struct

def topng(src, dst, w=640, h=480, six=False):
    d = open(src,'rb').read()
    assert len(d) >= 768 + w*h, f'{src}: {len(d)} B, ceka se {768+w*h}'
    pal = d[:768]
    if six:
        pal = bytes(min(255, c*255//63) for c in pal)
    idx = d[768:768+w*h]
    raw = b''.join(b'\x00' + idx[y*w:(y+1)*w] for y in range(h))
    def chunk(t, b):
        c = t + b
        return struct.pack('>I', len(b)) + c + struct.pack('>I', zlib.crc32(c))
    png = (b'\x89PNG\r\n\x1a\n'
           + chunk(b'IHDR', struct.pack('>IIBBBBB', w, h, 8, 3, 0, 0, 0))
           + chunk(b'PLTE', pal)
           + chunk(b'IDAT', zlib.compress(raw, 9))
           + chunk(b'IEND', b''))
    open(dst,'wb').write(png)

if __name__ == '__main__':
    a = [x for x in sys.argv[1:] if not x.startswith('--')]
    topng(a[0], a[1], six='--6bit' in sys.argv)
    print('ok', a[1])
