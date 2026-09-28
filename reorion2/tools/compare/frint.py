"""frint.py <log.txt> - DOSBox present intervals (kcycles) per frame."""
import re, sys
c = [int(re.search(r'cycle=(\d+)', l).group(1)) for l in open(sys.argv[1]) if 'FRAME' in l]
out = []
for i in range(1, len(c)):
    out.append('%d@%dM:%dk' % (i, c[i] // 1000000, (c[i] - c[i - 1]) // 1000))
for i in range(0, len(out), 8):
    print('  '.join(out[i:i + 8]))
