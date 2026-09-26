"""Wave 182: 8-byte pointer reads of 4-byte pointer FIELDS in game structures
(`*(_WORD **)(v1 + 115)`, `*(char **)((char *)dword_19C4CC + k)`).

fix_ptr32.py (wave 180) handled the data object only. This one takes the
remaining `*(T **)(ADDR)` in the game parts 01-19, except
  - addresses built from a parameter's or a local's address (`&a25 + 2`,
    `&retaddr`): those functions read the caller's frame and need a rewrite,
  - the sound driver parts 20-23, where the port may own the structures.
Reads become `((T *)(uintptr_t)*(uint32_t *)(ADDR))`; writes are reported.

usage: python tools/compare/fix_ptr32_fields.py [--dry]
"""
import glob
import re
import sys

sys.path.insert(0, 'tools/compare')
from fix_ptr32 import CAST, group  # noqa: E402

LF, CRLF = b'\n', b'\r\n'
total = 0
for p in sorted(glob.glob('src/game/orion_part_*.c')):
    num = int(re.search(r'orion_part_(\d+)', p).group(1))
    if num >= 20:
        continue
    raw = open(p, 'rb').read()
    crlf = CRLF in raw
    t = raw.replace(CRLF, LF).decode('latin-1')
    out, pos, n = [], 0, 0
    for m in CAST.finditer(t):
        if m.start() < pos:
            continue
        line0 = t.rfind('\n', 0, m.start()) + 1
        if t[line0:m.start()].lstrip().startswith(('//', '/*', '*')):
            continue
        a0 = m.end()
        a1 = group(t, a0)
        if a1 is None:
            continue
        addr = t[a0:a1]
        if re.search(r'&\s*(a\d+|v\d+|retaddr|_\w+|vars\d*)\b', addr) or 'dseg' in addr:
            continue
        k = a1
        while k < len(t) and t[k] in ' \t':
            k += 1
        if t[k] == '=' and t[k + 1] != '=':
            print('?? write %s:%d %s' % (p.split('\\')[-1], t.count('\n', 0, m.start()) + 1, t[m.start():a1]))
            continue
        out.append(t[pos:m.start()])
        out.append('((%s *)(uintptr_t)*(uint32_t *)%s)' % (m.group(1), addr))
        pos = a1
        n += 1
        print('%s:%d  %s' % (p.split('\\')[-1], t.count('\n', 0, m.start()) + 1, t[m.start():a1][:100]))
    out.append(t[pos:])
    if n:
        total += n
        if '--dry' not in sys.argv:
            b = ''.join(out).encode('latin-1')
            open(p, 'wb').write(b.replace(LF, CRLF) if crlf else b)
print('rewritten: %d' % total)
