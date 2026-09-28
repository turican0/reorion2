"""rngcmp.py <dbx_rng.txt> <port_rng.txt> - compare the RNG call sequences of a turn."""
import bisect
import re
import sys

LST = 'C:/prenos/reorion2Data/diss/Orion2.exe.lst'
starts = []
names = []
for line in open(LST, encoding='utf-8', errors='replace'):
    m = re.match(r'cseg01:([0-9A-F]{8})\s+(sub_[0-9A-F]+|\w+)\s+proc\b', line)
    if m:
        starts.append(int(m.group(1), 16))
        names.append(m.group(2))


def func(ida):
    i = bisect.bisect_right(starts, ida) - 1
    return '%s+0x%x' % (names[i], ida - starts[i]) if i >= 0 else hex(ida)


turn = None
dbx = []
for line in open(sys.argv[1]):
    m = re.match(r'REGS (\w+) cycle=(\d+) eip=(\w+) eax=(\w+).* ret=(\w+)', line)
    if not m:
        continue
    if m.group(1) == 'TURN' and turn is None:
        turn = int(m.group(2))
    if m.group(1) == 'rng' and turn is not None:
        ret = int(m.group(5), 16) - 0x224000
        dbx.append((int(m.group(4), 16), func(ret)))
port = []
for line in open(sys.argv[2]):
    p = line.split()
    if len(p) >= 4:
        port.append((int(p[1]), p[3]))
print('dbx %d calls, port %d calls' % (len(dbx), len(port)))
shown = 0
for i in range(max(len(dbx), len(port))):
    a = dbx[i] if i < len(dbx) else None
    b = port[i] if i < len(port) else None
    fa = a[1].split('+')[0] if a else None
    fb = b[1].split('+')[0] if b else None
    if a is None or b is None or a[0] != b[0] or fa != fb:
        print('%4d dbx %-8s %-24s | port %-8s %s' % (i, a and a[0], a and a[1], b and b[0], b and b[1]))
        shown += 1
        if shown > 25:
            break
if not shown:
    print('identical sequences')
