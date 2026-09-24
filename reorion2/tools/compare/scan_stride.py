"""Find arrays that the port declares with a single element but the code
indexes with a stride (`name[K * i]`) or with a variable - interleaved tables
that IDA split into several labels (wave 179: word_183C31 / word_183C33).

usage: python tools/compare/scan_stride.py
"""
import glob
import re

src = open('src/game/orion_data.c', encoding='latin-1').read()
one = {}
for m in re.finditer(r'^[A-Za-z_][\w ]*?\b([a-z]+_[0-9A-F]{5,6})\[(1)?\](?: = \{\s*[^,}\n]*\})?;', src, re.M):
    one[m.group(1)] = True
hits = {}
for p in glob.glob('src/game/orion_part_*.c'):
    for n, line in enumerate(open(p, encoding='latin-1'), 1):
        if line.lstrip().startswith('//'):
            continue
        for m in re.finditer(r'\b([a-z]+_[0-9A-F]{5,6})\[([^\]]+)\]', line):
            name, idx = m.group(1), m.group(2).strip()
            if name in one and idx not in ('0',):
                hits.setdefault(name, []).append('%s:%d  %s' % (p.split('\\')[-1], n, line.strip()[:100]))
for name in sorted(hits):
    print('%s (%d)' % (name, len(hits[name])))
    for h in hits[name][:3]:
        print('    ' + h)
