"""Port functions whose body is only a JUMPOUT into another function's tail
(wave 182: sub_BCB07, sub_BBB8A, sub_C5D55, ... - they did nothing at all).

For each one prints the tail it jumps to (the code at the target up to the
return) so the function can be rewritten as `return sub_Y(args);`.

usage: python tools/compare/empty_jumpouts.py [--tails]
"""
import glob
import re
import sys

LST = 'C:/prenos/reorion2Data/diss/Orion2.exe.lst'
show = '--tails' in sys.argv

code = []
for line in open(LST, encoding='utf-8', errors='replace'):
    m = re.match(r'cseg01:([0-9A-F]{8})\s{3,}(\S.*)$', line.rstrip('\n'))
    if m:
        ins = m.group(2).split(';')[0].strip()
        if ins:
            code.append((int(m.group(1), 16), ins))
index = {}
for k, (a, ins) in enumerate(code):
    index.setdefault(a, k)

n = 0
for p in sorted(glob.glob('src/game/orion_part_*.c')):
    t = open(p, encoding='latin-1').read()
    for m in re.finditer(r'^[^\n;]*\b(sub_[0-9A-F]+)\s*\([^;{]*\)\s*\n\{\n((?:  [^\n]*\n)*?)  JUMPOUT\(0x([0-9A-F]+)\);\n\}\n', t, re.M):
        pre = [x.strip() for x in m.group(2).splitlines() if x.strip() and not x.strip().startswith(('//', '/*'))]
        if len(pre) > 2:
            continue
        n += 1
        tgt = int(m.group(3), 16)
        tail = []
        k = index.get(tgt)
        while k is not None and k < len(code) and len(tail) < 8:
            ins = code[k][1]
            if not re.match(r'^[\w$?@]+:$', ins):
                tail.append(ins)
            if ins.startswith(('retn', 'jmp')):
                break
            k += 1
        calls = [x for x in tail if x.startswith('call')]
        print('%s %s -> %X: %s' % (p.split('\\')[-1], m.group(1), tgt, ' | '.join(calls) or tail[:1]))
        if show:
            for x in tail:
                print('      ' + x)
print('empty JUMPOUT functions: %d' % n)
