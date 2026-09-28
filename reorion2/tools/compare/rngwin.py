"""rngwin.py <dbx_rng.txt> <port_rng.txt> <from> <to> - side-by-side window of RNG calls (asm offsets for dbx)."""
import bisect, re, sys
LST = 'C:/prenos/reorion2Data/diss/Orion2.exe.lst'
starts, names = [], []
for line in open(LST, encoding='utf-8', errors='replace'):
    m = re.match(r'cseg01:([0-9A-F]{8})\s+(sub_[0-9A-F]+|\w+)\s+proc\b', line)
    if m:
        starts.append(int(m.group(1), 16)); names.append(m.group(2))
def func(ida):
    i = bisect.bisect_right(starts, ida) - 1
    return '%s+0x%x (%X)' % (names[i], ida - starts[i], ida)
dbx = []
for line in open(sys.argv[1]):
    m = re.match(r'REGS rng .*eax=([0-9A-F]+) .*ret=([0-9A-F]+)', line)
    if m:
        dbx.append((int(m.group(1), 16), func(int(m.group(2), 16) - 0x224000)))
port = []
for line in open(sys.argv[2]):
    p = line.split()
    if len(p) >= 4:
        port.append((int(p[1]), p[3]))
for i in range(int(sys.argv[3]), int(sys.argv[4])):
    a = dbx[i] if i < len(dbx) else ('', '')
    b = port[i] if i < len(port) else ('', '')
    print('%4d  %-6s %-34s | %-6s %s' % (i, a[0], a[1], b[0], b[1]))
