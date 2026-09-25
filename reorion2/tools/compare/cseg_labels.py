"""Data labels of the code object (cseg01) that the port references.

IDA names in the code object keep their address (byte_B4D5B is at
0xB4D5B, no +0x8000). Hex-Rays declares many of them as one scalar
(`char byte_B4D5B = 6;`) although the original copies a whole table from
there (wave 182: sub_B6227 copies 0x62 bytes, the port got one byte and
COLROADS.LBX was asked for entry 25449).

For every label: its span (up to the next label of any kind, code or
data), the port declaration and the 32-bit fixups inside the span.

    labels() -> {name: (ida, span, [fixup ida targets])}

usage: python tools/compare/cseg_labels.py
"""
import glob
import re
import sys

sys.path.insert(0, 'tools/compare')
import le_fixups  # noqa: E402

LST = 'C:/prenos/reorion2Data/diss/Orion2.exe.lst'
NAME = re.compile(r'\b((?:byte|word|dword|unk|off|stru|qword|asc|flt|dbl)_([0-9A-F]{4,6}))\b')
ROW = re.compile(r'^cseg01:([0-9A-F]{8})\s+([A-Za-z_$?@][\w$?@]*)(?:\s+|:)')


def used_names():
    names = set()
    for p in glob.glob('src/game/*.c') + glob.glob('src/game/*.h'):
        if p.endswith(('orion_dseg.h', 'orion_dseg.c')):
            continue
        for m in NAME.finditer(open(p, encoding='latin-1').read()):
            if int(m.group(2), 16) < 0x170000:
                names.add(m.group(1))
    return names


def all_labels():
    """Sorted [(ida, name)] of every label in cseg01 (code and data)."""
    out = []
    with open(LST, encoding='utf-8', errors='replace') as f:
        for line in f:
            if not line.startswith('cseg01:'):
                continue
            m = ROW.match(line)
            if m and m.group(2) not in ('proc', 'endp', 'db', 'dw', 'dd', 'align', 'assume'):
                out.append((int(m.group(1), 16), m.group(2)))
    return sorted(set(out))


def labels():
    want = used_names()
    lab = all_labels()
    fx = [(s, t, ta) for so, s, t, ta, kind in le_fixups.fixups() if so == 1 and kind == 7]
    out = {}
    for k, (a, n) in enumerate(lab):
        if n not in want:
            continue
        end = next((b for b, _ in lab[k + 1:] if b > a), a + 1)
        out[n] = (a, end - a, [(s - a, t, ta) for s, t, ta in fx if a <= s < end])
    return out


if __name__ == '__main__':
    want = used_names()
    got = labels()
    decl = {}
    for p in ['src/game/orion_data.c', 'src/game/link_stubs.c']:
        for line in open(p, encoding='latin-1'):
            m = NAME.search(line)
            if m and m.group(1) in want and re.match(r'^[A-Za-z_]', line) and '(' not in line.split('=')[0]:
                decl.setdefault(m.group(1), line.strip()[:90])
    for n in sorted(want, key=lambda x: int(x.split('_')[1], 16)):
        if n not in got:
            print('%-14s NOT IN LISTING' % n)
            continue
        a, span, fx = got[n]
        print('%-14s span 0x%-4X fix %-2d | %s' % (n, span, len(fx), decl.get(n, '-')))
