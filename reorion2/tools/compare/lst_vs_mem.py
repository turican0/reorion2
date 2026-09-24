"""Compare a DOSBox DUMPMEM of a data region with the bytes lst_block.py
rebuilds from the listing. Pointer slots are compared as runtime addresses
(data: C name + 0x216000, code: IDA address + 0x224000).

usage: python tools/compare/lst_vs_mem.py <dump.txt> <label> <c_start_hex>
"""
import re
import sys

import lst_block

dump, label, c0 = sys.argv[1], sys.argv[2], int(sys.argv[3], 16)
text = open(dump).read()
m = re.search(r'MEM %s addr=([0-9A-F]+) size=(\d+) bytes=([0-9A-F]+)' % re.escape(label), text)
mem = bytes.fromhex(m.group(3))
data, labels, fixups = lst_block.region(c0, c0 + len(mem))
fixed = {}
for off, tgt, add in fixups:
    mm = re.search(r'_([0-9A-F]+)$', tgt)
    if not mm:
        print('  fix +0x%03X -> %s (no address in the name)' % (off, tgt))
        continue
    a = int(mm.group(1), 16) + add
    a += 0x224000 if tgt.startswith(('sub_', 'nullsub_', 'loc_')) else 0x216000
    data[off:off + 4] = a.to_bytes(4, 'little')
    fixed[off] = tgt
names = sorted(labels)
diff = 0
for i in range(len(mem)):
    if mem[i] != data[i]:
        lab = [l for l in names if l[0] <= i][-1] if any(l[0] <= i for l in names) else (0, '?', '')
        print('+0x%03X (%s+0x%X) listing %02X memory %02X%s' % (
            i, lab[1], i - lab[0], data[i], mem[i],
            '  [slot %s]' % fixed[i - i % 1] if i in fixed else ''))
        diff += 1
print('%d of %d bytes differ' % (diff, len(mem)))
