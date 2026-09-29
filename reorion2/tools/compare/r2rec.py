"""r2rec.py - tool for the port's game records (.r2rec, wave 183, src/port/port_rec.cpp).

  r2rec.py info    REC                 chunks, start files, saves, clicks
  r2rec.py extract REC DIR             start files + every save (save_NN_<name>)
  r2rec.py dbx     REC OUT.cfg         SENDCLICK/SENDKEY lines for my DOSBox
                                       (after=0x002A56F2 + delayms from SYNC)
  r2rec.py state   REC DBX_STDERR      compares the structure CRCs at every
                                       press: record (port) vs DOSBox STATE lines

A replay in the port itself: REORION2_REPLAY=REC (+ REORION2_REPLAY_EXTRACT=1
in an empty dir, REORION2_REPLAY_FAST=1); results in reorion2_replay.log.
"""
import os
import re
import struct
import sys

REGIONS = ['colonies', 'planets', 'stars', 'leaders', 'players', 'ships',
           'events', '1AA414', '19ABA4', 'counts']
NSRC = 16


def chunks(path):
    d = open(path, 'rb').read()
    if d[:6] != b'R2REC\x01':
        raise SystemExit('%s: not a record' % path)
    p = 8
    while p + 8 <= len(d):
        tag = d[p:p + 4].decode('latin1')
        n = struct.unpack_from('<I', d, p + 4)[0]
        p += 8
        if p + n > len(d):
            print('# truncated chunk %s' % tag)
            break
        yield tag, d[p:p + n]
        p += n


def records(path):
    """yields (type, G, [payload ints])"""
    ev = b''.join(c for t, c in chunks(path) if t == 'EVTS')
    pos = 0
    g = 0

    def var():
        nonlocal pos
        v = sh = 0
        while True:
            c = ev[pos]
            pos += 1
            v |= (c & 0x7F) << sh
            sh += 7
            if not c & 0x80:
                return v

    nvars = {0x40: 1, 0x41: 0, 0x42: 2 + len(REGIONS) + 1, 0x43: 2, 0x44: 1, 0x45: 2}
    while pos < len(ev):
        t = ev[pos]
        pos += 1
        g += var()
        k = 1 if t < NSRC else nvars.get(t, 0)
        yield t, g, [var() for _ in range(k)]


def mouse(m):
    """recorded value = what INT 33h gives the game: X in 0..1279 (the game
    sets range 2*(640-1)), Y in 0..479 -> game pixels 640x480"""
    return (m & 0xFFF) * 640 // 1280, (m >> 12) & 0xFFF, m >> 24


def clicks(path):
    """list of dicts: press/release/key/sync with ms (real time of the recording)"""
    out = []
    for t, g, pl in records(path):
        if t == 0x42:
            x, y, b = mouse(pl[1])
            out.append(dict(kind='press', G=g, ms=pl[0], x=x, y=y, b=b,
                            crc=pl[2:2 + len(REGIONS)], rng=pl[-1]))
        elif t == 0x43:
            out.append(dict(kind='release', G=g, ms=pl[0]))
        elif t == 0x44:
            out.append(dict(kind='sync', G=g, ms=pl[0]))
        elif t == 0x45:
            out.append(dict(kind='key', G=g, ms=pl[0], code=pl[1]))
    return out


def cmd_info(rec):
    for tag, c in chunks(rec):
        if tag == 'META':
            print('META'), print('  ' + c.decode('latin1').strip().replace('\n', '\n  '))
        elif tag == 'FILE':
            nl = struct.unpack_from('<H', c)[0]
            print('FILE %s %d B' % (c[2:2 + nl].decode('latin1'), len(c) - 2 - nl))
        elif tag == 'SAVE':
            g, nl = struct.unpack_from('<QH', c)
            print('SAVE %s %d B at G=%d' % (c[10:10 + nl].decode('latin1'), len(c) - 10 - nl, g))
    cl = clicks(rec)
    print('%d presses, %d keys, last G=%d' % (sum(1 for c in cl if c['kind'] == 'press'),
          sum(1 for c in cl if c['kind'] == 'key'), max((g for _, g, _ in records(rec)), default=0)))


def cmd_extract(rec, out):
    os.makedirs(out, exist_ok=True)
    k = 0
    for tag, c in chunks(rec):
        if tag == 'FILE':
            nl = struct.unpack_from('<H', c)[0]
            name = c[2:2 + nl].decode('latin1')
            open(os.path.join(out, name), 'wb').write(c[2 + nl:])
            print('start', name)
        elif tag == 'SAVE':
            g, nl = struct.unpack_from('<QH', c)
            k += 1
            name = 'save_%02d_%s' % (k, c[10:10 + nl].decode('latin1'))
            open(os.path.join(out, name), 'wb').write(c[10 + nl:])
            print(name, 'G=%d' % g)


def cmd_dbx(rec, out):
    """Step chain (SENDCLICK seq=1): each press waits for the previous release,
    the recorded gap and the recorded structure state (from the first press
    after the game was loaded - before that the structures are not set up)."""
    cl = clicks(rec)
    sync = next((c['ms'] for c in cl if c['kind'] == 'sync'), None)
    if sync is None:
        raise SystemExit('no SYNC (the main menu was never reached)')
    names = {8: 'backspace', 9: 'tab', 13: 'enter', 27: 'esc', 32: 'space'}
    lines = []
    n = 0
    presses = [c for c in cl if c['kind'] == 'press' and c['ms'] >= sync]
    base = presses[0]['crc'] if presses else None
    loaded = False
    last_rel = sync
    for i, c in enumerate(cl):
        if c['ms'] < sync:
            continue
        if c['kind'] == 'press':
            rel = next((r['ms'] for r in cl[i + 1:] if r['kind'] == 'release'), c['ms'] + 100)
            n += 1
            loaded = loaded or c['crc'][4] != base[4]      # players changed = a game is loaded
            state = (' state=' + ','.join('%08X' % v for v in c['crc'])) if loaded else ''
            first = ' after=0x002A56F2' if n == 1 else ''
            lines.append('SENDCLICK seq=1%s gapms=%d x=%d y=%d holdms=%d button=%d%s label=p%d'
                         % (first, max(c['ms'] - last_rel, 0), c['x'], c['y'], max(rel - c['ms'], 1),
                            1 if c['b'] & 2 else 0, state, n))
            last_rel = rel
        elif c['kind'] == 'key':
            ch = c['code'] & 0xFF
            nm = names.get(ch) or (chr(ch).lower() if 32 < ch < 127 and chr(ch).isalnum() else None)
            if nm:
                lines.append('SENDKEY after=0x002A56F2 delayms=%d key=%s holdms=80 label=k%d'
                             % (c['ms'] - sync, nm, c['G']))
            else:
                lines.append('# key 0x%X at G=%d has no DOSBox name' % (c['code'], c['G']))
    open(out, 'w').write('\n'.join(lines) + '\n')
    print('%s: %d lines' % (out, len(lines)))


def cmd_state(rec, dbx):
    port = [c for c in clicks(rec) if c['kind'] == 'press']
    sync = next((c['ms'] for c in clicks(rec) if c['kind'] == 'sync'), 0)
    port = [c for c in port if c['ms'] >= sync]
    dos = {}
    for ln in open(dbx, encoding='latin1'):
        m = re.match(r'\[ctl\] STATE p(\d+) (.*) rng=([0-9A-F]+)', ln)
        if m:
            dos[int(m.group(1))] = ([int(v, 16) for v in m.group(2).split()], int(m.group(3), 16))
    first = None
    for i, c in enumerate(port, 1):
        if i not in dos:
            print('p%d (%d,%d): no DOSBox STATE' % (i, c['x'], c['y']))
            continue
        crc, rng = dos[i]
        bad = [REGIONS[k] for k in range(len(REGIONS)) if crc[k] != c['crc'][k]]
        tag = 'OK' if not bad else 'DIFF ' + ' '.join(bad)
        print('p%-3d G=%-7d (%3d,%3d) %s%s' % (i, c['G'], c['x'], c['y'], tag,
                                              '' if rng == c['rng'] else '  rng %08X/%08X' % (c['rng'], rng)))
        if bad and first is None:
            first = i
    print('first difference at p%s' % first if first else 'all presses match')


if __name__ == '__main__':
    a = sys.argv[1:]
    if not a:
        raise SystemExit(__doc__)
    {'info': cmd_info, 'extract': cmd_extract, 'dbx': cmd_dbx, 'state': cmd_state}[a[0]](*a[1:])
