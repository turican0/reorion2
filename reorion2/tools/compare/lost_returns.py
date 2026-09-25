"""Functions that are `void` in the port but whose result the original uses.

For every `call sub_X` in the listing the next instruction is checked: if it
reads EAX / AX / AL before writing it (mov r, eax / movsx r, ax / test al, al
/ cmp ax, ... / cwde ...), the caller uses X's return value. Functions that
the port declares `void` and that are used that way lost their result
(wave 181: sub_22F5C, sub_6478D, sub_63EDD, sub_643A0, sub_5EF4B, sub_DDFD3).

usage: python tools/compare/lost_returns.py [--sites]
"""
import glob
import re
import sys

LST = 'C:/prenos/reorion2Data/diss/Orion2.exe.lst'
READS = re.compile(r'^(mov|movsx|movzx|add|sub|cmp|test|and|or|xor|imul|lea|push|inc|dec|shl|sar|shr|neg|cwde|cdq|cwd|xchg)\b(.*)$')
ACC = re.compile(r'\b(eax|ax|al|ah)\b')


def reads_eax(ins):
    m = READS.match(ins)
    if not m:
        return None
    op, rest = m.group(1), m.group(2).strip()
    if op in ('cwde', 'cdq', 'cwd'):
        return True
    if op == 'push':
        return bool(ACC.search(rest))
    parts = [p.strip() for p in rest.split(',', 1)]
    if op in ('mov', 'movsx', 'movzx', 'lea'):
        if len(parts) == 2 and ACC.search(parts[1]):
            return True
        if ACC.search(parts[0]) and not re.search(r'\[', parts[0]):
            return False      # overwritten
        return None
    if op in ('xor', 'sub') and len(parts) == 2 and parts[0] == parts[1] and ACC.search(parts[0]):
        return False
    return bool(ACC.search(rest)) or None


calls = {}
prev = None
lines = []
for line in open(LST, encoding='utf-8', errors='replace'):
    m = re.match(r'cseg01:([0-9A-F]{8})\s{3,}(\S.*)$', line.rstrip('\n'))
    if not m:
        continue
    body = m.group(2).split(';')[0].strip()
    if not body or re.match(r'^[\w$?@]+:$', body) or re.match(r'^[\w$?@]+\s+(proc|endp)\b', body) \
            or body.startswith(('db ', 'dd ', 'dw ', 'align', 'assume')):
        continue
    lines.append((int(m.group(1), 16), body))

for i, (a, ins) in enumerate(lines):
    m = re.match(r'^call\s+(sub_[0-9A-F]+)$', ins)
    if not m or i + 1 >= len(lines):
        continue
    nxt = lines[i + 1][1]
    r = reads_eax(nxt)
    calls.setdefault(m.group(1), [0, 0, []])
    calls[m.group(1)][1] += 1
    if r:
        calls[m.group(1)][0] += 1
        calls[m.group(1)][2].append('%X: %s' % (lines[i + 1][0], nxt))

void = set()
for p in glob.glob('src/game/*.c'):
    for m in re.finditer(r'^void\s+(sub_[0-9A-F]+)\s*\(', open(p, encoding='latin-1').read(), re.M):
        void.add(m.group(1))

rows = sorted(((c[0], n, c[1]) for n, c in calls.items() if n in void and c[0]), reverse=True)
print('void in the port but result used in the original: %d functions, %d call sites'
      % (len(rows), sum(r[0] for r in rows)))
for used, name, total in rows:
    print('%-12s used at %3d of %3d call sites' % (name, used, total))
    if '--sites' in sys.argv:
        for s in calls[name][2][:5]:
            print('      ' + s)
