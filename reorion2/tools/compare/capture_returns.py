"""Capture a result that the decompiler dropped.

Hex-Rays marks a register variable read after a call to a function it
believed `void` with `// ADDR: variable 'vN' is possibly undefined`. For
each given callee, every statement `CALLEE(...);` whose following lines (up
to the next call of the same callee) read such a variable becomes
`vN = CALLEE(...);`, and the comment is dropped.

usage: python tools/compare/capture_returns.py [--dry] sub_X [sub_Y ...]
Check each reported site against the asm (which register the caller reads).
"""
import glob
import re
import sys

LF, CRLF = b'\n', b'\r\n'
dry = '--dry' in sys.argv
callees = [a for a in sys.argv[1:] if a.startswith('sub_')]

FUNC = re.compile(r'^[A-Za-z_][^\n;=]*?\b(sub_[0-9A-F]+)\s*\([^;{]*\)\s*\n\{', re.M)
total = 0
for p in sorted(glob.glob('src/game/orion_part_*.c')):
    raw = open(p, 'rb').read()
    crlf = CRLF in raw
    t = raw.replace(CRLF, LF).decode('latin-1')
    starts = [m.start() for m in FUNC.finditer(t)] + [len(t)]
    out, last, n = [], 0, 0
    for k in range(len(starts) - 1):
        s, e = starts[k], starts[k + 1]
        f = t[s:e]
        undef = dict((m.group(2), m.group(0)) for m in
                     re.finditer(r"^// ([0-9A-F]+): variable '(\w+)' is possibly undefined\n", f, re.M))
        if not undef:
            continue
        changed = False
        for callee in callees:
            pat = re.compile(r'^(\s*)(%s\([^;\n]*\);)[^\n]*\n' % callee, re.M)
            pos = 0
            while True:
                m = pat.search(f, pos)
                if not m:
                    break
                nxt = pat.search(f, m.end())
                window = f[m.end():nxt.start() if nxt else len(f)]
                window = window.split('\n//')[0]
                used = [v for v in re.findall(r'\b(v\d+)\b', window) if v in undef]
                if not used:
                    pos = m.end()
                    continue
                v = used[0]
                new = '%s%s = %s\n' % (m.group(1), v, m.group(2))
                f = f[:m.start()] + new + f[m.end():]
                f = f.replace(undef.pop(v), '')
                print('%s: %s = %s' % (p.split('\\')[-1], v, m.group(2)[:90]))
                n += 1
                changed = True
                pos = m.start() + len(new)
        if changed:
            out.append(t[last:s])
            out.append(f)
            last = e
    out.append(t[last:])
    if n:
        total += n
        if not dry:
            b = ''.join(out).encode('latin-1')
            open(p, 'wb').write(b.replace(LF, CRLF) if crlf else b)
print('captured: %d' % total)
