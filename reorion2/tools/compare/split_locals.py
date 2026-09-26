"""Local tables that Hex-Rays split into several scalar locals (wave 182).

`*((uint8_t *)&v9 + v4 + 2)` with v9 an `int` and v10 an `int64_t` next to
it was one 12-byte table in the original (sub_B67E4); on x64 the compiler
does not keep v9 and v10 adjacent, so the index reads garbage. Reported:
every `(T *)&vN + <non-constant>` or `&vN + <non-constant>` where vN is a
scalar local (declared without [..]).

usage: python tools/compare/split_locals.py
"""
import glob
import re

FUNC = re.compile(r'^[A-Za-z_][^\n;=]*?\b(sub_[0-9A-F]+)\s*\([^;{]*\)\s*\n\{', re.M)
n = 0
for p in sorted(glob.glob('src/game/orion_part_*.c')):
    t = open(p, encoding='latin-1').read()
    for m in FUNC.finditer(t):
        e = t.index('\n}\n', m.end())
        f = t[m.end():e]
        decl = dict((d.group(2), d.group(1)) for d in re.finditer(
            r'^  ([A-Za-z_][\w ]*?\**)\s*(v\d+);', f, re.M))
        hits = set()
        for u in re.finditer(r'\((?:uint8_t|_BYTE|char|int16_t|_WORD|uint16_t|int|_DWORD) \*\)&(v\d+) \+ ([^)\];,]+)', f):
            v, idx = u.group(1), u.group(2).strip()
            if v in decl and not re.match(r'^\d+$', idx):
                hits.add(v)
        for v in sorted(hits):
            n += 1
            print('%s %s %s (%s)' % (p.split('\\')[-1], m.group(1), v, decl[v]))
print('sites: %d' % n)
