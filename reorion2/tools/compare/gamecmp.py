"""gamecmp.py DOSDIR PORTDIR FRAMES... - game arrays at frames: DOS <frame>.raw.mem (DOSBOX_GR_MEM, 16 MB) vs
port <frame>.raw.game (REORION2_GAMEPLAY_GAME: players, stars, planets, colonies, ships, leaders)."""
import os, struct, sys
ARR = [('players', 0x197F98, 3753, 8), ('stars', 0x19306C, 113, 72), ('planets', 0x1930D4, 17, 360),
       ('colonies', 0x192B18, 361, 250), ('ships', 0x197F9C, 129, 500), ('leaders', None, 59, 67)]
DSEG = 0x21E000   # 1.50: C address + 0x21E000 = linear
for fr in sys.argv[3:]:
    pm, gm = os.path.join(sys.argv[1], fr + '.raw.mem'), os.path.join(sys.argv[2], fr + '.raw.game')
    if not (os.path.exists(pm) and os.path.exists(gm)):
        print(fr, 'missing', os.path.exists(pm), os.path.exists(gm))
        continue
    m = open(pm, 'rb').read()
    g = open(gm, 'rb').read()
    out, o = [], 0
    for name, ptr, rs, n in ARR:
        addr = struct.unpack_from('<I', m, (ptr if ptr else 0x1930DC) + DSEG)[0]
        a = m[addr:addr + rs * n]
        b = g[o:o + rs * n]
        o += rs * n
        d = [i for i in range(rs * n) if a[i] != b[i]]
        if d:
            recs = sorted(set(i // rs for i in d))
            out.append('%s: %d B in recs %s first %s' % (name, len(d), recs[:10],
                       ['%d+%d %02X/%02X' % (i // rs, i % rs, a[i], b[i]) for i in d[:8]]))
    print(fr, 'same' if not out else '\n   ' + '\n   '.join(out))
