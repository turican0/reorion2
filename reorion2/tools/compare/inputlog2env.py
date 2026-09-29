"""inputlog2env.py <input_log.txt> [--from MS] [--to MS] [--no-move] [--dbx OUT.cfg] [--shift MS]

Converts a REORION2_INPUT_LOG record (port, wave 183) into
  - REORION2_CLICK / REORION2_SENDKEY strings for a port replay (times as recorded,
    plus --shift),
  - SENDCLICK / SENDKEY lines for my DOSBox (--dbx): times relative to the SYNC
    line (first entry of sub_816F2), armed by after=0x002A56F2, delayms/holdms in
    emulated ms. Events before SYNC are skipped on the DOSBox side (the conf
    skips the intro itself).
"""
import argparse
import re

ap = argparse.ArgumentParser()
ap.add_argument('log')
ap.add_argument('--from', dest='t0', type=int, default=0)
ap.add_argument('--to', dest='t1', type=int, default=10 ** 12)
ap.add_argument('--no-move', action='store_true')
ap.add_argument('--dbx')
ap.add_argument('--shift', type=int, default=0)
a = ap.parse_args()

sync = None
clicks, keys = [], []   # (ms, x, y, hold, btn) / (ms, code)
for ln in open(a.log, encoding='utf-8', errors='replace'):
    ln = ln.strip()
    m = re.match(r'SYNC \w+@(\d+)', ln)
    if m:
        sync = int(m.group(1))
        continue
    m = re.match(r'CLICK (\d+),(\d+)@(\d+):(\d+):(\d+)', ln)
    if m:
        x, y, t, h, b = map(int, m.groups())
        clicks.append((t, x, y, h, b))
        continue
    m = re.match(r'MOVE (\d+),(\d+)@(\d+):0', ln)
    if m and not a.no_move:
        x, y, t = map(int, m.groups())
        clicks.append((t, x, y, 0, 1))
        continue
    m = re.match(r'KEY (0x[0-9A-Fa-f]+):(\d+)', ln)
    if m:
        keys.append((int(m.group(2)), int(m.group(1), 16)))

clicks = sorted(c for c in clicks if a.t0 <= c[0] <= a.t1)
keys = sorted(k for k in keys if a.t0 <= k[0] <= a.t1)

print('REORION2_CLICK=' + ';'.join('%d,%d@%d:%d:%d' % (x, y, t + a.shift, h, b)
                                   for t, x, y, h, b in clicks))
# ';' at the end forces the list mode of REORION2_SENDKEY
print('REORION2_SENDKEY=' + ''.join('0x%X:%d;' % (c, t + a.shift) for t, c in keys))

if a.dbx:
    if sync is None:
        raise SystemExit('no SYNC line in the log')
    names = {8: 'backspace', 9: 'tab', 13: 'enter', 27: 'esc', 32: 'space'}
    out = []
    for t, x, y, h, b in clicks:
        if t < sync:
            continue
        out.append('SENDCLICK after=0x002A56F2 delayms=%d x=%d y=%d holdms=%d button=%d label=t%d'
                   % (t - sync, x, y, h, 1 if b == 2 else 0, t))
    for t, c in keys:
        if t < sync:
            continue
        ch = c & 0xFF
        n = names.get(ch) or (chr(ch).lower() if chr(ch).isalnum() else None)
        if n is None:
            print('# key 0x%X at %d has no DOSBox name, skipped' % (c, t))
            continue
        out.append('SENDKEY after=0x002A56F2 delayms=%d key=%s holdms=80 label=k%d' % (t - sync, n, t))
    open(a.dbx, 'w').write('\n'.join(out) + '\n')
    print('%s: %d lines (sync %d ms)' % (a.dbx, len(out), sync))
