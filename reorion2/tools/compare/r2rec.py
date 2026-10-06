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
GAP_MAX = 150   # ms, dbx: longest kept gap between steps once a game is loaded


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

    nvars = {0x40: 1, 0x41: 0, 0x42: 2 + len(REGIONS) + 1 + 2, 0x43: 2, 0x44: 1, 0x45: 2}
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
            n = len(REGIONS)
            out.append(dict(kind='press', G=g, ms=pl[0], x=x, y=y, b=b,
                            crc=pl[2:2 + n], rng=pl[2 + n], waitfn=pl[3 + n], caller=pl[4 + n]))
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


LST = 'C:/prenos/reorion2Data/diss/Orion2.exe.lst'
CODE_DELTA = 0x224000   # IDA code address -> DOSBox runtime


def proc_ranges():
    """IDA function start -> end (from the proc/endp lines of the listing)"""
    starts, rng = {}, {}
    rx = re.compile(r'^cseg01:([0-9A-F]{8})\s+(\S+)\s+(proc|endp)\b')
    for ln in open(LST, encoding='latin1'):
        m = rx.match(ln)
        if not m:
            continue
        a, name, kind = int(m.group(1), 16), m.group(2), m.group(3)
        if kind == 'proc':
            starts[name] = a
        elif name in starts:
            rng[starts[name]] = a + 1
    return rng


def cmd_dbx(rec, out):
    """Step chain (SENDCLICK seq=1): each press waits for the previous release,
    the recorded gap and the recorded structure state (from the first press
    after the game was loaded - before that the structures are not set up)."""
    cl = clicks(rec)
    sync = next((c['ms'] for c in cl if c['kind'] == 'sync'), None)
    if sync is None:
        raise SystemExit('no SYNC (the main menu was never reached)')
    names = {8: 'backspace', 9: 'tab', 13: 'enter', 27: 'esc', 32: 'space'}
    # the intro is skipped by the port (REORION2_SKIPINTRO) - ESC twice here
    lines = ['SENDKEY cond=cycle_ge:40000000 key=esc', 'SENDKEY cond=cycle_ge:90000000 key=esc']
    n = 0
    presses = [c for c in cl if c['kind'] == 'press' and c['ms'] >= sync]
    base = presses[0]['crc'] if presses else None
    loaded = False
    keys_in_chain = 0
    last_rel = sync
    ranges = proc_ranges()
    for i, c in enumerate(cl):
        if c['ms'] < sync:
            continue
        if c['kind'] == 'press':
            rel = next((r['ms'] for r in cl[i + 1:] if r['kind'] == 'release'), c['ms'] + 100)
            n += 1
            loaded = loaded or c['crc'][4] != base[4]      # players changed = a game is loaded
            state = (' state=' + ','.join('%08X' % v for v in c['crc'])) if loaded else ''
            first = ' after=0x002A56F2' if n == 1 and not keys_in_chain else ''
            # the recorded gap is the player's thinking time - readiness comes from
            # the state gate + settle, so only a short gap is kept (menu clicks
            # before the load have no state and keep the full gap)
            gap = max(c['ms'] - last_rel, 0)
            if loaded:
                gap = min(gap, GAP_MAX)
            # input loop of the step: waiting function entry + caller range
            loop = ''
            if c['waitfn']:
                loop = ' waitfn=0x%X' % (c['waitfn'] + CODE_DELTA)
                if c['caller'] in ranges:
                    loop += ' callerlo=0x%X callerhi=0x%X' % (c['caller'] + CODE_DELTA,
                                                              ranges[c['caller']] + CODE_DELTA)
            lines.append('SENDCLICK seq=1%s gapms=%d x=%d y=%d holdms=%d button=%d settlems=250 timeoutms=5000%s%s label=p%d'
                         % (first, gap, c['x'], c['y'], max(rel - c['ms'], 1),
                            1 if c['b'] & 2 else 0, loop, state, n))
            last_rel = rel
        elif c['kind'] == 'key':
            ch = c['code'] & 0xFF
            nm = names.get(ch) or (chr(ch).lower() if 32 < ch < 127 and chr(ch).isalnum() else None)
            if nm:
                # a chain step - in order with the clicks (a timed key could land
                # on another screen than in the port)
                # no input loop is recorded for a key - keep up to 1 s of the gap so
                # the screen of the previous click has settled
                gap = min(max(c['ms'] - last_rel, 0), 1000)
                first = ' after=0x002A56F2' if n == 0 and not keys_in_chain else ''
                lines.append('SENDCLICK seq=1%s gapms=%d key=%s holdms=80 settlems=250 timeoutms=5000 label=k%d'
                             % (first, gap, nm, c['G']))
                keys_in_chain += 1
                last_rel = c['ms'] + 80
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
