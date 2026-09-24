"""Compare the port's dseg (raw dump) with a DOSBox DUMPMEM of the same data
object, symbol by symbol. Pointer slots (LE fixups) are compared as targets.

usage: python tools/compare/dseg_vs_mem.py <port.bin> <dosbox.txt> <label> [--init]
    --init   only the initialized part (C 0x178000..0x18C000)
"""
import re
import sys

import le_fixups
import lst_block

C0 = 0x178000
port = bytearray(open(sys.argv[1], 'rb').read())
txt = open(sys.argv[2]).read()
m = re.search(r'MEM %s addr=([0-9A-F]+) size=(\d+) bytes=([0-9A-F]+)' % re.escape(sys.argv[3]), txt)
dbx = bytearray(bytes.fromhex(m.group(3)))
end = 0x14000 if '--init' in sys.argv else len(dbx)

fx = le_fixups.data_fixups()
slots = {}
base = None
for s, t, ta in fx:
    o = s - C0
    pv = int.from_bytes(port[o:o + 4], 'little')
    dv = int.from_bytes(dbx[o:o + 4], 'little')
    if t == 2 and base is None and pv:
        base = pv - (ta + lst_block.DELTA - C0)
    slots[o] = (t, ta, pv, dv)
bad_slots = []
for o, (t, ta, pv, dv) in slots.items():
    if t == 2:
        pt = (pv - base) if pv else None
        dt = (dv - 0x216000 - C0) if dv else None
        if pt != dt:
            bad_slots.append((o, pt, dt))
    port[o:o + 4] = dbx[o:o + 4]          # exclude from the byte comparison
print('dseg base in the port 0x%X; pointer slots differing: %d' % (base, len(bad_slots)))
for o, pt, dt in bad_slots[:20]:
    print('  slot %06X port->%s dosbox->%s' % (o + C0, hex(pt + C0) if pt is not None else None,
                                            hex(dt + C0) if dt is not None else None))

# run-time pointers into the heap differ by nature: DOSBox heap is below
# 32 MB, the port heap above 16 MB - hide dwords where both look like that
def heapish(buf, i, lo, hi):
    return lo <= int.from_bytes(buf[i:i + 4], 'little') < hi


hidden = 0
# pointers into the data object itself: compare their targets
DB0 = 0x38E000                      # DOSBox runtime address of C 0x178000
same_target = 0
for i in range(0, end - 3):
    pv = int.from_bytes(port[i:i + 4], 'little')
    dv = int.from_bytes(dbx[i:i + 4], 'little')
    if pv != dv and base <= pv < base + len(port) and DB0 <= dv < DB0 + len(dbx) and pv - base == dv - DB0:
        port[i:i + 4] = dbx[i:i + 4]
        same_target += 1
print('dseg pointers with the same target: %d' % same_target)
for i in range(0, end - 3):
    if port[i:i + 4] != dbx[i:i + 4] and heapish(dbx, i, 0x200000, 0x2000000) and \
            heapish(port, i, 0x1000000, 0x80000000) and not (0x38E000 <= int.from_bytes(dbx[i:i + 4], 'little') < 0x38E000 + len(dbx)):
        port[i:i + 4] = dbx[i:i + 4]
        hidden += 1
print('heap pointer dwords hidden: %d' % hidden)
bad_slots = [b for b in bad_slots if not (b[1] is not None and b[2] is not None and
                                          not (0 <= b[1] < len(dbx)) and not (0 <= b[2] < len(dbx)))]
print('pointer slots differing (not heap): %d' % len(bad_slots))
for o, pt, dt in bad_slots[:20]:
    print('  slot %06X port->%s dosbox->%s' % (o + C0, hex(pt + C0) if pt is not None else None,
                                            hex(dt + C0) if dt is not None else None))

labels = sorted((a + lst_block.DELTA, lst_block.cname(lab)) for a, lab, k, ops in lst_block._load() if lab)
import bisect
keys = [a for a, n in labels]
by = {}
for i in range(end):
    if port[i] != dbx[i]:
        a = i + C0
        k = bisect.bisect_right(keys, a) - 1
        nm = labels[k][1] if k >= 0 else '?'
        by.setdefault((labels[k][0] if k >= 0 else 0, nm), []).append(i)
print('differing bytes %d in %d symbols' % (sum(len(v) for v in by.values()), len(by)))
for (a, nm), v in sorted(by.items()):
    o = a - C0
    print('%06X %-22s %5d B  first +%X  dosbox %s | port %s' % (
        a, nm, len(v), v[0] + C0 - a, dbx[v[0]:v[0] + 8].hex(' '), port[v[0]:v[0] + 8].hex(' ')))
