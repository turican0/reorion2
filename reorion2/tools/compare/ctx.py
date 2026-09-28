"""ctx.py <sub_XXXX> <var@EA> [...] - asm around EA + port lines using var."""
import re, glob, os, sys
os.chdir(r'C:\prenos\reorion2\reorion2')
LST = 'C:/prenos/reorion2Data/diss/Orion2.exe.lst'
lst = [l.rstrip('\n') for l in open(LST, encoding='utf-8', errors='replace')]
idx = {}
for i, l in enumerate(lst):
    m = re.match(r'cseg01:([0-9A-F]{8})\s{3,}\S', l)
    if m and ';' not in l.split(None, 1)[1][:1]:
        idx.setdefault(int(m.group(1), 16), i)
func = sys.argv[1]
src = None
for p in sorted(glob.glob('src/game/orion_part_*.c')):
    t = open(p, encoding='latin-1').read().replace('\r\n', '\n')
    m = re.search(r'\n[^\n/]*\b%s\s*\([^\n]*\)\n(//[^\n]*\n)*\{\n.*?\n\}\n' % func, t, re.S)
    if m:
        src = (p, t[:m.start()].count('\n') + 2, m.group(0).split('\n'))
        break
for arg in sys.argv[2:]:
    v, ea = arg.split('@')
    ea = int(ea, 16)
    print('==== %s %s @ %X' % (func, v, ea))
    i = idx.get(ea)
    if i is None:
        k = min((a for a in idx if a >= ea), default=None)
        i = idx[k]
    out = []
    j = i
    while len(out) < 12 and j > 0:
        j -= 1
        s = re.sub(r'^cseg01:[0-9A-F]{8}\s+', '', lst[j]).split(';')[0].rstrip()
        if s.strip():
            out.insert(0, '  %s' % s)
    for s in out:
        print(s)
    print('> ' + re.sub(r'^cseg01:([0-9A-F]{8})\s+', r'\1 ', lst[i]))
    j = i
    n = 0
    while n < 4:
        j += 1
        s = re.sub(r'^cseg01:[0-9A-F]{8}\s+', '', lst[j]).split(';')[0].rstrip()
        if s.strip():
            print('  ' + s)
            n += 1
    if src:
        p, base, lines = src
        for k, l in enumerate(lines):
            if re.search(r'\b%s\b' % v, l) and '//' not in l[:3]:
                print('   %s:%d %s' % (os.path.basename(p), base + k - 1, l.strip()))
