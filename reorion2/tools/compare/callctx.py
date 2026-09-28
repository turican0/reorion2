"""callctx.py <sub_F> <sub_G> [n] - asm lines before every call of sub_G inside sub_F."""
import re, sys
LST = 'C:/prenos/reorion2Data/diss/Orion2.exe.lst'
F, G = sys.argv[1], sys.argv[2]
n = int(sys.argv[3]) if len(sys.argv) > 3 else 12
body, cur = [], None
for line in open(LST, encoding='utf-8', errors='replace'):
    m = re.match(r'cseg01:([0-9A-F]{8})\s{3,}(\S.*)$', line.rstrip('\n'))
    if not m:
        continue
    s = m.group(2).split(';')[0].rstrip()
    if re.match(r'^%s\s+proc\b' % F, s):
        cur = True
        continue
    if cur and re.match(r'^%s\s+endp\b' % F, s):
        break
    if cur and s.strip():
        body.append('%s %s' % (m.group(1)[3:], s))
k = 0
for i, s in enumerate(body):
    if re.search(r'call\s+%s\b' % G, s):
        k += 1
        print('--- call #%d' % k)
        for x in body[max(0, i - n):i + 1]:
            print('  ' + x)
