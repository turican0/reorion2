"""edx:eax pairs used as pointers (wave 182).

Hex-Rays keeps edx:eax in one `int64_t vN; // rax` / `uint64_t vN; // rax`
variable and writes HIDWORD(vN) = ... for edx. When eax is a pointer the
code then does `*(_WORD *)(vN + 124)` - on x64 the whole 64-bit value,
with edx in the upper half, is the address (TECHSEL sub_10DC12, the save
dialog sub_7E154). The address must be the low half: `(uint32_t)vN`.

usage: python tools/compare/pair_pointers.py [--fix]
"""
import glob
import re
import sys

LF, CRLF = b'\n', b'\r\n'
fix = '--fix' in sys.argv
FUNC = re.compile(r'^[A-Za-z_][^\n;]*\b(sub_[0-9A-F]+)\s*\([^;{]*\)\s*\n\{', re.M)
total = 0
for p in sorted(glob.glob('src/game/orion_part_*.c')):
    raw = open(p, 'rb').read()
    crlf = CRLF in raw
    t = raw.replace(CRLF, LF).decode('latin-1')
    edits = []
    for m in FUNC.finditer(t):
        e = t.index('\n}\n', m.end())
        f = t[m.end():e]
        pairs = re.findall(r'^  u?int64_t (v\d+); // (?:rax|edx:eax|kr\w+)', f, re.M)
        for v in pairs:
            # pointer uses: *(T *)(vN + ...) / *(T *)(vN - ...) / *(T *)vN
            for u in re.finditer(r'(\*\(\w+(?: \w+)? \*\)\()(%s)( [+-] )' % v, f):
                edits.append((m.end() + u.start(2), m.end() + u.end(2), '(uint32_t)%s' % v))
                total += 1
                print('%s %s %s: %s' % (p.split('\\')[-1], m.group(1), v,
                                        f[u.start():u.start() + 50].split('\n')[0]))
    if fix and edits:
        for a, b, r in sorted(edits, reverse=True):
            t = t[:a] + r + t[b:]
        bb = t.encode('latin-1')
        open(p, 'wb').write(bb.replace(LF, CRLF) if crlf else bb)
print('sites: %d' % total)
