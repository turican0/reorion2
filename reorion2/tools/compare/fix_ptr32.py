"""Wave 180: 8-byte pointer accesses into 4-byte data slots.

`*(char **)((char *)&off_17EEE0 + 47 * i)` reads 8 bytes on x64 - the name
pointer of record i plus 4 bytes of the next field. In the original every
pointer in the data object is 32 bits. Reads become
`((char *)(intptr_t)*(int *)(ADDR))`, writes
`*(uint32_t *)(ADDR) = (uint32_t)(uintptr_t)(RHS)`, for every address that
names a symbol of dseg (orion_dseg.h).

usage: python tools/compare/fix_ptr32.py [--dry]
"""
import glob
import re
import sys

LF, CRLF = b'\n', b'\r\n'
names = set(re.findall(r'^#define (\w+) ', open('src/game/orion_dseg.h', encoding='latin-1').read(), re.M))
CAST = re.compile(r'\*\(((?:const )?(?:_UNKNOWN|char|_BYTE|_WORD|_DWORD|void|int16_t|uint8_t|uint16_t|int|unsigned int|__int16)) \*\*\)\s*')


def group(t, i):
    """End of the operand that starts at t[i]: a parenthesised group or &name."""
    if t[i] == '(':
        d = 0
        for k in range(i, len(t)):
            if t[k] == '(':
                d += 1
            elif t[k] == ')':
                d -= 1
                if d == 0:
                    return k + 1
    m = re.match(r'&?\w+', t[i:])
    return i + m.end() if m else None


def rhs_end(t, i):
    d = 0
    for k in range(i, len(t)):
        c = t[k]
        if c in '([{':
            d += 1
        elif c in ')]}':
            if d == 0:
                return k
            d -= 1
        elif c in ';,' and d == 0:
            return k
    return None


total = 0
for p in sorted(glob.glob('src/game/orion_part_*.c')):
    raw = open(p, 'rb').read()
    crlf = CRLF in raw
    t = raw.replace(CRLF, LF).decode('latin-1')
    out, pos, n = [], 0, 0
    for m in CAST.finditer(t):
        if m.start() < pos:
            continue
        a0 = m.end()
        a1 = group(t, a0)
        if a1 is None:
            continue
        addr = t[a0:a1]
        # only the data object itself (&name); `ptr + k` with a pointer taken
        # from dseg reads heap memory that the port fills
        ids = set(re.findall(r'&\s*([A-Za-z_]\w*)\b', addr))
        if not ids & names:
            continue
        typ = m.group(1)
        k = a1
        while k < len(t) and t[k] in ' \t':
            k += 1
        out.append(t[pos:m.start()])
        if t[k] == '=' and t[k + 1] != '=':
            r0 = k + 1
            r1 = rhs_end(t, r0)
            rhs = t[r0:r1].strip()
            out.append('*(uint32_t *)%s = (uint32_t)(uintptr_t)(%s)' % (addr, rhs))
            pos = r1
        else:
            out.append('((%s *)(intptr_t)*(int *)%s)' % (typ, addr))
            pos = a1
        n += 1
        print('%s:%d  %s' % (p.split('\\')[-1], t.count('\n', 0, m.start()) + 1, t[m.start():min(a1 + 40, len(t))].split('\n')[0][:110]))
    out.append(t[pos:])
    if n:
        total += n
        if '--dry' not in sys.argv:
            b = ''.join(out).encode('latin-1')
            open(p, 'wb').write(b.replace(LF, CRLF) if crlf else b)
print('rewritten: %d' % total)
