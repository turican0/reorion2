"""leaders.py <save> - list the leader table (67 x 59 B at 105115)."""
import struct
import sys
d = open(sys.argv[1], 'rb').read()
BASE = 105115
for i in range(67):
    r = d[BASE + 59 * i:BASE + 59 * (i + 1)]
    name = r[:15].split(b'\0')[0].decode('latin-1')
    t35 = r[35]
    w36 = struct.unpack('<h', r[36:38])[0]
    skills = struct.unpack('<I', r[38:42])[0]
    w53 = struct.unpack('<h', r[53:55])[0]
    st57 = r[57]
    own = struct.unpack('b', r[58:59])[0]
    print('%2d %-15s type=%d lvl=%d skills=%08X loc=%d status=%d owner=%d' % (i, name, t35, w36, skills, w53, st57, own))
