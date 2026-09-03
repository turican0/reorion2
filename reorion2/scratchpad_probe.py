import io

P = 'src/game/orion_part_07.c'
lines = open(P, 'rb').read().split(b'\n')
EOL = b'\r' if lines[0].endswith(b'\r') else b''

def w(s):
    return s.encode('ascii') + EOL

# Probe 1: entry of sub_83669 (system-view opener)
i = [k for k,l in enumerate(lines) if l.rstrip(b'\r') == b'void sub_83669( int a1)']
assert len(i) == 1, i
z = i[0]
while lines[z].strip() != b'{':
    z += 1
blok = [
 '  /*SONDA-SYS*/ if ( PortDebug_ProbeArmed() ) {',
 '  /*SONDA-SYS*/   static int n = 0;',
 '  /*SONDA-SYS*/   if ( n < 20 ) { ++n;',
 '  /*SONDA-SYS*/     PortDebug_ProbeLog("sub_83669 VOLANA a1(star)=%d vlastnik=%d", a1,',
 '  /*SONDA-SYS*/       (int)*(int8_t *)(dword_19306C + 113 * a1 + 20));',
 '  /*SONDA-SYS*/     PortDebug_Backtrace("sys", 6); } }',
]
lines[z+1:z+1] = [w(s) for s in blok]
print('probe SYS (sub_83669 entry) nasazena')

# Probe 2: click resolution in sub_86188
target = b'      v20 = sub_857F8(0, (int16_t *)&v78, &v73);'
i2 = [k for k,l in enumerate(lines) if l.rstrip(b'\r') == target]
assert len(i2) == 1, i2
z2 = i2[0]
blok2 = [
 '      /*SONDA-CLK*/ if ( PortDebug_ProbeArmed() ) {',
 '      /*SONDA-CLK*/   static int n2 = 0;',
 '      /*SONDA-CLK*/   if ( n2 < 25 ) { ++n2;',
 '      /*SONDA-CLK*/     PortDebug_ProbeLog("KLIK pred857F8: 199EC7=%d 199ECB=%d 199EC9=%d 199ECD=%d 199ECF=%d word19999C=%d",',
 '      /*SONDA-CLK*/       (int)word_199EC7, (int)word_199ECB, (int)word_199EC9, (int)word_199ECD,',
 '      /*SONDA-CLK*/       (int)(uint8_t)byte_199ECF, (int)word_19999C); } }',
]
lines[z2:z2] = [w(s) for s in blok2]
print('probe CLK (pred sub_857F8) nasazena')

# Probe 3: right after v20/v21/v22 set, before the big if, dump v20 v21 v73 v78 v22 word_199976
target3 = b'      v22 = 0;'
i3 = [k for k,l in enumerate(lines) if l.rstrip(b'\r') == target3]
assert len(i3) == 1, i3
z3 = i3[0]
blok3 = [
 '      /*SONDA-CLK2*/ ',
]
# insert AFTER the assignment sequence; but v21/v22/word_19C18A get set below.
print('probe3 skip - handled below')

open(P, 'wb').write(b'\n'.join(lines))
print('orion_part_07.c ulozen')
