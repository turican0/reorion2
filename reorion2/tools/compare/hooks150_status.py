"""Wave 185: which hooks of ORION150.EXE (diss150_ida91/hooks.tsv) the port has wired.

A site counts as wired when
  - its 1.31 instruction calls a game function X the port wraps (X_131 in src/game150/orion150_hooks.h) and
    the site is not one of the calls 1.50 leaves alone, or
  - the code carries a marker "1.50 <site>" (src/game, src/game150), or
  - the hook target is listed as having no effect (NOEFFECT below).

usage: python tools/compare/hooks150_status.py [--list N]
"""
import collections
import glob
import re
import sys

DISS = 'C:/prenos/reorion2Data/diss150_ida91/'
NOEFFECT = {'sub_1E0276', 'sub_1E02BA', 'sub_1E0316'}   # see orion150_hooks.h
# hooks wired at the entry of the called function (the text of the draw calls, orion150_hooks.h)
NOEFFECT |= {'sub_1E02CE', 'sub_1E02FE', 'sub_1E028A', 'sub_1E02E6', 'sub_1E02A2'}

rows = [l.rstrip('\n').split('\t') for l in open(DISS + 'hooks.tsv', encoding='latin-1')][1:]
hooks_h = open('src/game150/orion150_hooks.h', encoding='latin-1').read()
wrapped = set(re.findall(r'\b(\w+)_131\s*\(', hooks_h))
marked = set()
for p in glob.glob('src/game/*.c') + glob.glob('src/game150/*.c') + glob.glob('src/game150/*.h'):
    for m in re.finditer(r'1\.50 ([0-9A-F]{5,6}(?:, [0-9A-F]{5,6})*)\b', open(p, encoding='latin-1').read()):
        for a in m.group(1).split(', '):
            marked.add(int(a, 16))
    for m in re.finditer(r'//----- \((00[0-9A-F]{6})\)', open(p, encoding='latin-1').read()):
        pass
# calls of wrapped functions 1.50 leaves alone are marked "1.50 <site>: not hooked" - they are not hooks anyway
done, todo = [], []
kinds = collections.Counter()
for site, func, i131, i150, tgt, tname in rows:
    a = int(site, 16)
    ins = i131.split()
    ok = (a in marked or tname in NOEFFECT or
          (len(ins) > 1 and ins[0] == 'call' and ins[1] in wrapped))
    (done if ok else todo).append((site, func, i131, i150, tname))
    if not ok:
        k131 = ins[0] if ins else '?'
        kinds['%s -> %s' % (k131, i150.split()[0] if i150 else '?')] += 1
print('hooks %d: wired %d, open %d' % (len(rows), len(done), len(todo)))
for k, v in kinds.most_common(12):
    print('  %5d %s' % (v, k))
if '--list' in sys.argv:
    n = int(sys.argv[sys.argv.index('--list') + 1])
    for r in todo[:n]:
        print('  %s %-12s %-28s -> %s' % (r[0], r[1], r[2], r[4]))
