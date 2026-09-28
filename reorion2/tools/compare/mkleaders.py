"""mkleaders.py <in> <out> - give player 0 two hired leaders (status 1 at Trilar, like the AI's Ruola)."""
import sys
d = bytearray(open(sys.argv[1], 'rb').read())
BASE = 105115
for idx in (1, 2):          # Kimbuzzi (ship officer), Cyr (colony leader)
    o = BASE + 59 * idx
    d[o + 53:o + 55] = (29).to_bytes(2, 'little')   # location: star 29 = Trilar
    d[o + 57] = 1                                   # status: hired, in the pool
    d[o + 58] = 0                                   # owner: player 0
open(sys.argv[2], 'wb').write(d)
print('ok')
