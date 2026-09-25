"""Classify every JUMPOUT(target) left in the port by what the original does
at the target (up to the first retn / jmp):

    epilogue   only pop / leave / lea esp / retn - `return` is right
    value      `mov eax, X` / `xor eax, eax` / `mov al, 1` ... then the
               epilogue - the function RETURNS X (wave 181: sub_6478D)
    code       anything else - real shared code the port skips

Also imported by jumpout_values.py (tail(), classify(), EPI).

usage: python tools/compare/jumpout_tails.py [--all]
"""
import bisect
import glob
import re
import sys

LST = 'C:/prenos/reorion2Data/diss/Orion2.exe.lst'
code = {}
order = []
for line in open(LST, encoding='utf-8', errors='replace'):
    m = re.match(r'cseg01:([0-9A-F]{8})\s{3,}(\S.*)$', line.rstrip('\n'))
    if not m:
        continue
    body = m.group(2)
    if body.startswith(';') or re.match(r'^[\w$?@]+:', body) or re.match(r'^[\w$?@]+\s+(proc|endp)\b', body):
        continue
    ins = body.split(';')[0].strip()
    if not ins or ins.startswith(('db ', 'dd ', 'dw ', 'align')):
        continue
    a = int(m.group(1), 16)
    if a not in code:
        code[a] = ins
        order.append(a)
order.sort()

EPI = re.compile(r'^(pop\s+\w+|leave|lea\s+esp, \[ebp\+\w+\]|retn(\s+\w+)?|mov\s+esp, ebp)$')
VAL = re.compile(r'^(mov\s+(eax|ax|al), .+|xor\s+(eax|al|ax), (eax|al|ax)|movsx\s+eax, .+|movzx\s+eax, .+|cwde)$')


def tail(a, n=12):
    i = bisect.bisect_left(order, a)
    out = []
    while i < len(order) and len(out) < n:
        ins = code[order[i]]
        out.append(ins)
        if ins.startswith(('retn', 'jmp')):
            break
        i += 1
    return out


def classify(t):
    if not t:
        return 'unknown'
    if all(EPI.match(x) for x in t):
        return 'epilogue'
    k = 0
    while k < len(t) and VAL.match(t[k]):
        k += 1
    if k and all(EPI.match(x) for x in t[k:]):
        return 'value'
    return 'code'


def main():
    rows = []
    for p in sorted(glob.glob('src/game/orion_part_*.c')):
        func = '?'
        for n, line in enumerate(open(p, encoding='latin-1'), 1):
            m = re.match(r'^[A-Za-z_][^\n;=]*?\b(sub_[0-9A-F]+)\s*\(', line)
            if m:
                func = m.group(1)
            for j in re.finditer(r'JUMPOUT\(0x([0-9A-F]+)\)', line):
                if line.lstrip().startswith('//'):
                    continue
                a = int(j.group(1), 16)
                t = tail(a)
                rows.append((classify(t), p.replace('\\', '/').split('/')[-1], n, func, a, ' / '.join(t)))
    counts = {}
    for r in rows:
        counts[r[0]] = counts.get(r[0], 0) + 1
    print(counts)
    for r in rows:
        if '--all' in sys.argv or r[0] != 'epilogue':
            print('%-8s %s:%d %s -> %X: %s' % (r[0], r[1], r[2], r[3], r[4], r[5][:120]))


if __name__ == '__main__':
    main()
