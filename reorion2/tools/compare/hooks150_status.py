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
    for line in open(p, encoding='latin-1'):
        i = line.find('1.50 ')
        if i < 0:
            continue
        # every address after "1.50 " on the line: "1.50 029080, 029085: sub_1E3F6B; 0290A7: ..."
        for a in re.findall(r'\b([0-2][0-9A-F]{5}|[1-9A-F][0-9A-F]{4})\b', line[i + 5:]):
            if not re.fullmatch(r'\d{5}', a) or a.startswith(('1', '2', '3', '4', '5', '6', '7', '8', '9')):
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

# changed ranges of the 1.31 functions (funcdiff.tsv): done when a marker or a wired hook lies in the range
# (or up to 8 bytes before it - the nop padding after a hook call), or when 1.50 has only nops there
sys.path.insert(0, 'tools/compare')
from inlsite import LST131, LST150, load, index_of   # noqa: E402
l131, l150 = load(LST131), load(LST150)
# calls 1.50 redirects to a function of its own that the port handles inside the called function
COVERED_CALLS = {
    ('sub_126487', 'sub_16957E'),   # sub_126487 (orion_part_19.c) -> Hook150_Exit
}
COVERED_RANGES = {
    '10018-1001B',   # main_ -> the loader of the block: Start150 (reorion2.cpp)
    # dead 1.31 code reused by 1.50 as caves, each ported at its jump site:
    'F4F6F-F4FF6',   # F4F74 (sub_E98F2), F4F8D (sub_5C510), F4FAA (sub_5BD97), F4FD5 (MarkCheatPatternFlag_F4FD5)
}
# 1.31 functions 1.50 overwrote as a whole (caves, ported at the jump site)
COVERED_FUNCS = {
    'sub_F4AC8',     # F4ACA..F4D09: the 1.40 switches from sub_107E6 (109A9), orion_part_01.c
}


def call_at(lst, a):
    i = index_of(lst, a)
    while i > 0 and (lst[i][0] > a or not re.match(r'^\s+[a-z]', lst[i][1])):
        i -= 1
    m = re.match(r'^\s+call\s+(\w+)', lst[i][1])
    return m.group(1) if m else None


def only_nops(a, b):
    i = index_of(l150, a)
    seen = False
    while i < len(l150) and l150[i][0] <= b:
        t = l150[i][1].strip()
        if t and not re.match(r'^(nop|align\b|db\s+90h|xchg\s+(\w+),\s*\2$)', t) and not re.match(r'^(loc_|sub_)\w+:?$|\w+\s+endp$', t):
            return False
        seen = seen or bool(t)
        i += 1
    return seen


wired = {int(r[0], 16) for r in done}
rdone, rtodo = 0, []
for l in open(DISS + 'funcdiff.tsv', encoding='latin-1'):
    r = l.rstrip('\n').split('\t')
    if len(r) < 6 or not r[5] or r[5] == 'edit_ranges':
        continue
    for x in r[5].split():
        a, b = (int(v, 16) for v in x.split('-'))
        if (any(a - 8 <= m <= b for m in marked) or any(a - 8 <= w <= b for w in wired)
                or only_nops(a, b) or x in COVERED_RANGES or r[0] in COVERED_FUNCS
                or (call_at(l131, a), call_at(l150, a)) in COVERED_CALLS):
            rdone += 1
        else:
            rtodo.append((r[0], x))
print('changed ranges %d: wired %d, open %d (in %d functions)' %
      (rdone + len(rtodo), rdone, len(rtodo), len({f for f, _ in rtodo})))
if '--ranges' in sys.argv:
    n = int(sys.argv[sys.argv.index('--ranges') + 1])
    for f, x in rtodo[:n]:
        print('  %-12s %s' % (f, x))
