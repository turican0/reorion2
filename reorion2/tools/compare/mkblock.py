"""mkblock.py <file> <sub_XXXX> <firstvar> <size> [--fix]
Turn the stack locals covering [firstvar, firstvar+size) (by their ebp offsets) into one
byte block with lvalue macros, so memset/struct copies over them work like the original."""
import re, sys, os
os.chdir(r'C:\prenos\reorion2\reorion2')
p, func, first, size = sys.argv[1], sys.argv[2], sys.argv[3], int(sys.argv[4], 0)
fix = '--fix' in sys.argv
d = open(p, 'rb').read()
crlf = b'\r\n' in d
t = d.replace(b'\r\n', b'\n').decode('latin-1')
hdr = '//----- (%08X)' % int(func[4:], 16)
hs = t.index(hdr)
bs = t.index('\n{\n', hs) + 3
be = t.index('\n}\n', bs) + 1
body = t[bs:be]
SZ = {'char': 1, '_BYTE': 1, 'uint8_t': 1, 'int8_t': 1, '_BOOL1': 1, 'int16_t': 2, '_WORD': 2, 'uint16_t': 2,
      'int': 4, '_DWORD': 4, 'unsigned int': 4, 'int32_t': 4, 'uint32_t': 4, 'signed int': 4}
decl = []
for m in re.finditer(r'^  ((?:unsigned |signed )?\w+) (v\d+)(\[(\d+)\])?; // \[esp[^\]]*\] \[ebp([+-][0-9A-F]+)h\][^\n]*\n', body, re.M):
    ty, v, n, off = m.group(1), m.group(2), m.group(4), int(m.group(5), 16)
    decl.append((off, v, ty, int(n) if n else None, m.group(0)))
base = [x for x in decl if x[1] == first]
assert base, 'no ' + first
b0 = base[0][0]
grp = [x for x in decl if b0 <= x[0] < b0 + size]
grp.sort()
blk = 'blk%s_%s' % (func[4:], first)
out = ['  /* wave 182: %s..%s are one %d-byte record in the frame (ebp%+Xh) */\n' % (grp[0][1], grp[-1][1], size, b0),
       '  _BYTE %s[%d];\n' % (blk, size)]
for off, v, ty, n, line in grp:
    o = off - b0
    if n:
        out.append('#define %s ((%s *)(%s + %d))\n' % (v, ty, blk, o))
    else:
        out.append('#define %s (*(%s *)(%s + %d))\n' % (v, ty, blk, o))
    print('  %s %s%s @+%d' % (ty, v, '[%d]' % n if n else '', o))
nb = body
first_line = grp[0][4]
for g in grp:
    nb = nb.replace(g[4], '' if g is not grp[0] else '\x00', 1)
nb = nb.replace('\x00', ''.join(out), 1)
nb = nb.rstrip('\n') + '\n' + ''.join('#undef %s\n' % g[1] for g in grp)
# sizeof(vN) of a macro'd scalar is fine; arrays are pointers now -> flag
for g in grp:
    if g[3] and re.search(r'sizeof\(%s\)' % g[1], nb):
        print('  WARNING sizeof(%s) on array' % g[1])
if fix:
    t = t[:bs] + nb + t[be:]
    b = t.encode('latin-1')
    open(p, 'wb').write(b.replace(b'\n', b'\r\n') if crlf else b)
    print('fixed', func)
