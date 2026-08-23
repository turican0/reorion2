# Porovna dva syrove snimky (768 B palety + 640x480 indexu).
# Dosbox ma paletu 6bitovou, port 8bitovou -> porovnavam v 6 bitech (>>2).
import sys
W,H = 640,480

def load(p, six):
    d = open(p,'rb').read()
    pal = list(d[:768])
    if not six: pal = [c >> 2 for c in pal]     # port 8bit -> 6bit
    return pal, d[768:768+W*H]

def main(a, b, out=None):
    pa, ia = load(a, True)    # dosbox
    pb, ib = load(b, False)   # port
    palsame = sum(1 for i in range(768) if pa[i]!=pb[i])
    print('paleta: %d/768 slozek se lisi' % palsame)
    if palsame:
        bad = [i//3 for i in range(768) if pa[i]!=pb[i]]
        print('  dotcene indexy:', sorted(set(bad))[:20], '...' if len(set(bad))>20 else '')
    # rozdil po RGB (index muze byt jiny, ale barva stejna)
    diff_idx = diff_rgb = 0
    rows = {}
    mask = bytearray(W*H)
    for y in range(H):
        for x in range(W):
            k = y*W+x
            va, vb = ia[k], ib[k]
            if va != vb:
                diff_idx += 1
                if pa[va*3:va*3+3] != pb[vb*3:vb*3+3]:
                    diff_rgb += 1
                    mask[k] = 1
                    rows[y] = rows.get(y,0)+1
    print('rozdilnych pixelu (index): %d / %d  (%.2f %%)' % (diff_idx, W*H, 100.0*diff_idx/(W*H)))
    print('rozdilnych pixelu (barva): %d / %d  (%.2f %%)' % (diff_rgb, W*H, 100.0*diff_rgb/(W*H)))
    if rows:
        ys = sorted(rows)
        print('rozsah radku: %d..%d' % (ys[0], ys[-1]))
        top = sorted(rows.items(), key=lambda t:-t[1])[:8]
        print('nejhorsi radky (y:pocet):', ', '.join('%d:%d'%t for t in top))
        xs = [k%W for k in range(W*H) if mask[k]]
        print('rozsah sloupcu: %d..%d' % (min(xs), max(xs)))
    if out:
        import zlib, struct
        raw=b''.join(b'\x00'+bytes(255 if mask[y*W+x] else 0 for x in range(W)) for y in range(H))
        def ch(t,b):
            c=t+b; return struct.pack('>I',len(b))+c+struct.pack('>I',zlib.crc32(c))
        png=(b'\x89PNG\r\n\x1a\n'+ch(b'IHDR',struct.pack('>IIBBBBB',W,H,8,0,0,0,0))
             +ch(b'IDAT',zlib.compress(raw,9))+ch(b'IEND',b''))
        open(out,'wb').write(png); print('maska ->', out)

main(*sys.argv[1:])
