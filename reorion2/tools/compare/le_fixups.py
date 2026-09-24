"""Relocations (fixups) of the original Orion2.exe (LE, DOS4GW).

The fixup table is the ground truth for pointers stored in the data segment:
IDA also prints `dd offset X` for plain numbers that merely look like an
address (wave 179: off_183DC9), the fixup table never does.

    data_fixups() -> [(slot_c, target_obj, target_ida)]
        slot_c      C address of the 32-bit slot (IDA address + 0x8000)
        target_obj  1 = code, 2 = data
        target_ida  IDA address of the target (code: = sub_ name, data: C - 0x8000)

As a script: prints the count and the first entries, or with an address the
fixups inside [c_start, c_end).
    python tools/compare/le_fixups.py [c_start_hex c_end_hex]
"""
import struct
import sys

EXE = 'C:/prenos/reorion2Data/diss/Orion2.exe'
DELTA = 0x8000


def _le():
    d = open(EXE, 'rb').read()
    le = struct.unpack_from('<I', d, 0x3C)[0]
    if d[le:le + 2] != b'LE':
        le = d.find(b'LE\x00\x00')
    return d, le


def objects():
    d, le = _le()
    tab, n = struct.unpack_from('<II', d, le + 0x40)
    out = []
    for k in range(n):
        vs, base, fl, pti, npg, _ = struct.unpack_from('<6I', d, le + tab + 24 * k)
        out.append((vs, base, fl, pti, npg))
    return out


def fixups():
    """All internal fixups: (src_obj, src_ida, target_obj, target_ida)."""
    d, le = _le()
    objs = objects()
    fpt = le + struct.unpack_from('<I', d, le + 0x68)[0]
    frt = le + struct.unpack_from('<I', d, le + 0x6C)[0]
    out = []
    for oi, (vs, base, fl, pti, npg) in enumerate(objs, 1):
        for pg in range(npg):
            page = pti - 1 + pg
            a, b = struct.unpack_from('<II', d, fpt + 4 * page)
            p = frt + a
            end = frt + b
            while p < end:
                src, flg = d[p], d[p + 1]
                p += 2
                if src & 0x20:
                    cnt = d[p]
                    p += 1
                    offs = None
                else:
                    offs = [struct.unpack_from('<h', d, p)[0]]
                    p += 2
                if flg & 3 != 0:
                    raise SystemExit('non-internal fixup at page %d' % page)
                if flg & 0x40:
                    tobj = struct.unpack_from('<H', d, p)[0]
                    p += 2
                else:
                    tobj = d[p]
                    p += 1
                if (src & 0x0F) == 2:      # 16-bit selector: no offset
                    toff = 0
                elif flg & 0x10:
                    toff = struct.unpack_from('<I', d, p)[0]
                    p += 4
                else:
                    toff = struct.unpack_from('<H', d, p)[0]
                    p += 2
                if offs is None:
                    offs = [struct.unpack_from('<h', d, p + 2 * k)[0] for k in range(cnt)]
                    p += 2 * cnt
                for o in offs:
                    if o < 0:
                        continue       # the part of a fixup that crosses from the previous page
                    out.append((oi, base + pg * 0x1000 + o, tobj, objs[tobj - 1][1] + toff, src & 0x0F))
    return out


def data_fixups():
    return [(s + DELTA, t, ta) for so, s, t, ta, kind in fixups() if so == 2 and kind == 7]


if __name__ == '__main__':
    fx = data_fixups()
    kinds = {}
    for so, s, t, ta, kind in fixups():
        if so == 2:
            kinds[kind] = kinds.get(kind, 0) + 1
    print('data fixups by source type:', kinds)
    if len(sys.argv) == 3:
        a0, a1 = int(sys.argv[1], 16), int(sys.argv[2], 16)
        for s, t, ta in fx:
            if a0 <= s < a1:
                print('%06X -> %s %06X' % (s, 'code' if t == 1 else 'data', ta if t == 1 else ta + DELTA))
    else:
        print(len(fx), '32-bit offset fixups in the data object')
        for s, t, ta in fx[:10]:
            print('%06X -> %s %06X' % (s, 'code' if t == 1 else 'data', ta if t == 1 else ta + DELTA))
