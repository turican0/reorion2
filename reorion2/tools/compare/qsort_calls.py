"""qsort calls of the port against the asm (wave 182).

Watcom `qsort_(eax = base, edx = count, ebx = size, ecx = comparator)`.
For every function the comparators of its `call qsort_` (the last
`mov ecx, offset X` before each call) are listed next to the port's calls;
a port call without a comparator crashes (sub_9BBED).

usage: python tools/compare/qsort_calls.py
"""
import glob
import re

LST = 'C:/prenos/reorion2Data/diss/Orion2.exe.lst'
funcs, cur, body = {}, None, []
for line in open(LST, encoding='utf-8', errors='replace'):
    m = re.match(r'cseg01:([0-9A-F]{8})\s{3,}(\S.*)$', line.rstrip('\n'))
    if not m:
        continue
    ins = m.group(2).split(';')[0].strip()
    pm = re.match(r'^(sub_[0-9A-F]+)\s+proc\b', ins)
    if pm:
        cur, body = pm.group(1), []
        continue
    if cur and re.match(r'^%s\s+endp\b' % cur, ins):
        funcs[cur] = body
        cur = None
        continue
    if cur and ins:
        body.append(ins)

for p in sorted(glob.glob('src/game/orion_part_*.c')):
    t = open(p, encoding='latin-1').read()
    for m in re.finditer(r'^[A-Za-z_][^\n;]*\b(sub_[0-9A-F]+)\s*\([^;{]*\)\s*\n\{', t, re.M):
        e = t.index('\n}\n', m.end())
        f = t[m.end():e]
        pcalls = re.findall(r'\bqsort\(([^;]*)\);', f)
        if not pcalls:
            continue
        acmp = []
        b = funcs.get(m.group(1), [])
        for k, ins in enumerate(b):
            if re.match(r'^call\s+qsort_$', ins):
                c = None
                for j in range(k - 1, max(-1, k - 12), -1):
                    cm = re.match(r'^mov\s+ecx,\s*offset\s+(\w+)$', b[j])
                    if cm:
                        c = cm.group(1)
                        break
                acmp.append(c)
        pc = []
        for a in pcalls:
            parts = [x.strip() for x in a.split(',')]
            pc.append(parts[3] if len(parts) >= 4 else None)
        ok = [x for x in pc if x] == [x for x in acmp if x] and len(pc) == len(acmp)
        print('%s %s %s: port %s | asm %s' % ('ok' if ok else '!!', p.split('\\')[-1], m.group(1), pc, acmp))
