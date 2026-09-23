"""List every one-byte `_UNKNOWN unk_X;` in orion_data.c together with its
size in the original (distance to the next declared symbol) and how the
port uses it. A block copy or a multi-byte write into a one-byte object
overwrites whatever the linker placed next (wave 179: unk_1BC390, a 0x400
byte palette backup, overwrote the LBX cache handle dword_1BC288).

usage: python tools/compare/unknown_sizes.py [--min N]
"""
import glob
import re
import sys

MIN = int(sys.argv[sys.argv.index('--min') + 1]) if '--min' in sys.argv else 2
src = open('src/game/orion_data.c', encoding='latin-1').read()
decl = re.compile(r'^[A-Za-z_][\w \*]*?\b(?:unk|byte|word|dword|qword|off|stru|asc|a[A-Z]\w*?)_([0-9A-F]{5,6})\b', re.M)
syms = []
for m in re.finditer(r'^[^/\n#][^\n;(]*?\b([A-Za-z]+_([0-9A-F]{5,6}))\b[^\n;(]*;', src, re.M):
    syms.append((int(m.group(2), 16), m.group(1), m.group(0)))
syms.sort()
code = {}
for p in glob.glob('src/game/*.c'):
    if p.endswith('orion_data.c'):
        continue
    code[p] = open(p, encoding='latin-1').read()
for i, (a, name, line) in enumerate(syms):
    if not re.match(r'_UNKNOWN\s+unk_[0-9A-F]+\s*;', line):
        continue
    nxt = syms[i + 1][0] if i + 1 < len(syms) else a + 1
    size = nxt - a
    if size < MIN:
        continue
    uses = []
    for p, t in code.items():
        for u in re.finditer(r'[^\n]*\b' + name + r'\b[^\n]*', t):
            uses.append(u.group(0).strip()[:110])
    print('%s size=0x%X uses=%d' % (name, size, len(uses)))
    for u in uses[:6]:
        print('    ' + u)
