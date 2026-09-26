"""Capture dropped results everywhere (wave 182), without a list of callees.

`// ADDR: variable 'vN' is possibly undefined` names the address where the
variable is read. When the instruction right before ADDR in the listing is
`call sub_X` (the read is the first thing after the call - cwde, movsx
r, ax, push eax, ...), vN is the result of sub_X. The dropped statement
`sub_X(...);` nearest before the first use of vN becomes `vN = sub_X(...);`.

Only calls whose port declaration returns a value are changed; the others
are listed (the callee needs a return value first).

usage: python tools/compare/capture_auto.py [--fix]
"""
import glob
import re
import sys

LST = 'C:/prenos/reorion2Data/diss/Orion2.exe.lst'
fix = '--fix' in sys.argv
LF, CRLF = b'\n', b'\r\n'

# previous instruction of every code address
prev = {}
here = {}
last = None
for line in open(LST, encoding='utf-8', errors='replace'):
    m = re.match(r'cseg01:([0-9A-F]{8})\s{3,}(\S.*)$', line.rstrip('\n'))
    if not m:
        continue
    ins = m.group(2).split(';')[0].strip()
    if not ins or re.match(r'^[\w$?@]+:$', ins) or re.match(r'^\w+\s+(=|proc|endp)\b', ins):
        continue
    a = int(m.group(1), 16)
    if last is not None and a != last[0]:
        prev[a] = last[1]
    here.setdefault(a, ins)
    last = (a, ins)

# functions of the port that return a value
returns = {}
for p in glob.glob('src/game/orion_part_*.c'):
    for m in re.finditer(r'^([A-Za-z_][^\n;=(]*?)\b(sub_[0-9A-F]+)\s*\([^;{]*\)\s*\n\{', open(p, encoding='latin-1').read(), re.M):
        returns[m.group(2)] = not re.match(r'^\s*(static\s+)?void\s*$', m.group(1))

FUNC = re.compile(r'^[A-Za-z_][^\n;=]*?\b(sub_[0-9A-F]+)\s*\([^;{]*\)\s*\n\{', re.M)
done = need = 0
for p in sorted(glob.glob('src/game/orion_part_*.c')):
    raw = open(p, 'rb').read()
    crlf = CRLF in raw
    t = raw.replace(CRLF, LF).decode('latin-1')
    starts = [m.start() for m in FUNC.finditer(t)] + [len(t)]
    edits = []
    for k in range(len(starts) - 1):
        s, e = starts[k], starts[k + 1]
        f = t[s:e]
        fname = FUNC.match(f).group(1)
        for um in re.finditer(r"^// ([0-9A-F]+): variable '(\w+)' is possibly undefined\n", f, re.M):
            addr, var = int(um.group(1), 16), um.group(2)
            pi = prev.get(addr, '')
            cm = re.match(r'^call\s+(sub_[0-9A-F]+)$', pi)
            if not cm or here.get(addr, '').startswith('call'):
                continue      # a call reading eax is only Hex-Rays' guess of an argument
            callee = cm.group(1)
            body_end = f.index('\n}\n')
            use = re.search(r'\b%s\b' % var, f[f.index('{'):body_end])
            # first use after the declarations
            uses = [x.start() + f.index('{') for x in re.finditer(r'\b%s\b(?! *;? *//)' % var, f[f.index('{'):body_end])]
            uses = [u for u in uses if not re.match(r'^\s*\w[\w\s\*]*\b%s\b\s*;' % var, f[f.rfind('\n', 0, u) + 1:])]
            if not uses:
                continue
            u = uses[0]
            line = f[f.rfind('\n', 0, u) + 1:f.find('\n', u)]
            where = '%s %s %s <- %s' % (p.split('\\')[-1], fname, var, callee)
            if re.match(r'^\s*(?:[A-Z]+\d*\()?%s\)?\s*=[^=]' % var, line):
                print('?? %s: first use assigns it (%s)' % (where, line.strip()[:60]))
                continue
            calls = list(re.finditer(r'^(\s*)(%s\([^;\n]*\);)' % callee, f[:u], re.M))
            # the dropped call must be one of the 3 lines before the use
            if calls and f.count('\n', calls[-1].start(), u) > 3:
                calls = []
            if not calls:
                print('?? %s: no dropped call right before the use' % where)
                continue
            if not returns.get(callee, True):
                need += 1
                print('void %s: the callee returns nothing in the port' % where)
                continue
            c = calls[-1]
            done += 1
            print('%s' % where)
            edits.append((s + c.start(2), s + c.start(2), '%s = ' % var))
            edits.append((s + um.start(), s + um.end(), ''))
    if fix and edits:
        for a, b, r in sorted(edits, reverse=True):
            t = t[:a] + r + t[b:]
        b = t.encode('latin-1')
        open(p, 'wb').write(b.replace(LF, CRLF) if crlf else b)
print('captured %d, callee without a result %d' % (done, need))
