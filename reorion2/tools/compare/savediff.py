"""savediff.py <a.GAM> <b.GAM> - differing byte ranges mapped to save sections."""
import sys
a = open(sys.argv[1], 'rb').read()
b = open(sys.argv[2], 'rb').read()
SECT = [(0, 'version'), (4, 'name'), (41, 'stardate'), (45, 'mode'), (46, 'settings553'), (599, 'seed?4'),
        (603, 'nplanets'), (605, 'planets 250x361'), (90855, 'n17'), (90857, 'colonies? 360x17'),
        (96977, 'nstars'), (96979, 'stars 72x113'), (105115, 'leaders 67x59'), (109068, 'nplayers'),
        (109070, 'players 8x3753'), (139094, 'nships'), (139096, 'ships x129')]


def sect(o):
    name, base = '?', 0
    for s, n in SECT:
        if o >= s:
            name, base = n, s
    return '%s+%d' % (name, o - base)


diffs = [i for i in range(min(len(a), len(b))) if a[i] != b[i]]
runs = []
for i in diffs:
    if runs and i - runs[-1][1] <= 4:
        runs[-1][1] = i
    else:
        runs.append([i, i])
print(len(diffs), 'bytes in', len(runs), 'runs')
for s, e in runs[:60]:
    print('%6d..%6d %-28s a=%s b=%s' % (s, e, sect(s), a[s:e + 1].hex(), b[s:e + 1].hex()))
