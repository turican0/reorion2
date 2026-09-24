"""Print the data labels of the original in a C-address range, with the
port's declaration of each one.

usage: python tools/compare/lst_labels.py <c_start_hex> <c_end_hex>
(C address = asm address + 0x8000)
"""
import re
import sys

LST = 'C:/prenos/reorion2Data/diss/Orion2.exe.lst'
a0 = int(sys.argv[1], 16) - 0x8000
a1 = int(sys.argv[2], 16) - 0x8000
src = open('src/game/orion_data.c', encoding='latin-1').read()
row = re.compile(r'^dseg\d+:([0-9A-F]{8})\s\s?([A-Za-z_$?@][\w$?@]*)\s+(db|dw|dd|dq|dt)\b(.*)$')
with open(LST, encoding='utf-8', errors='replace') as f:
    for line in f:
        m = row.match(line.rstrip('\n'))
        if not m:
            continue
        a = int(m.group(1), 16)
        if a < a0 or a >= a1:
            continue
        name = m.group(2)
        mm = re.match(r'([A-Za-z]+_)([0-9A-F]+)$', name)
        cname = mm.group(1) + '%X' % (int(mm.group(2), 16) + 0x8000) if mm else name
        d = re.search(r'^[^\n]*\b' + re.escape(cname) + r'\b[^\n]*;', src, re.M)
        print('%06X %-14s %-4s %-28s | %s' % (a + 0x8000, cname, m.group(3), m.group(4).split(';')[0].strip()[:28],
                                             d.group(0).strip()[:70] if d else '-- not in orion_data.c'))
