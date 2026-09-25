"""One-shot generator (wave 182): data labels of the code object as macros
into csegdata, a packed copy of the code-object bytes around them.

Hex-Rays declared the tables that live between functions as scalars or
one-element arrays (`char byte_B4D5B = 6;` for a 0x62-byte table,
`int16_t word_3B841[] = { 8 };` for one row of a table the loop walks
with a stride). The macros put every such label at its original place
inside a copy of the original bytes, so strides, negative indices and
loops that run into the next label read what the original reads.

Ranges: every converted label with 0x400 bytes before and after, merged
when they overlap, packed one after another into csegdata[].

Not converted: off_ labels (code addresses) and function pointers.

usage: python tools/compare/gen_cseg.py <report.txt>
"""
import re
import struct
import sys

sys.path.insert(0, 'tools/compare')
import cseg_labels  # noqa: E402
import dseg_decls as D  # noqa: E402
import le_fixups  # noqa: E402
from gen_dseg import ESIZE, eval_dim, init_bytes, load, save  # noqa: E402

ESIZE = dict(ESIZE, wchar_t=2)
MARGIN = 0x400


def code_image():
    d, le = le_fixups._le()
    vs, base, fl, pti, npg = le_fixups.objects()[0]
    psz = struct.unpack_from('<I', d, le + 0x28)[0]
    mz = next(p for p in range(le, -1, -1)
              if d[p:p + 2] == b'MZ' and struct.unpack_from('<I', d, p + 0x3C)[0] == le - p)
    datapages = mz + struct.unpack_from('<I', d, le + 0x80)[0]
    img = bytearray(npg * psz)
    for k in range(npg):
        off = datapages + (pti - 1 + k) * psz
        img[k * psz:(k + 1) * psz] = d[off:off + psz]
    return base, vs, img


def main(report_path):
    rep = open(report_path, 'w', encoding='utf-8')
    base, vs, img = code_image()
    labs = cseg_labels.labels()
    fx = [(s, t, ta) for so, s, t, ta, kind in le_fixups.fixups() if so == 1 and kind == 7]
    data, dcrlf = load('src/game/orion_data.c')
    conv = []
    for d in D.decls(data):
        if d.name not in labs or d.name.startswith('off_') or d.ptr:
            continue
        d.type = ' '.join(w for w in d.type.split() if w not in ('static', 'const', 'volatile'))
        if d.type not in ESIZE:
            rep.write('?? type %s of %s\n' % (d.type, d.name))
            continue
        conv.append(d)

    # sizes
    items = []
    for d in conv:
        a, span, _ = labs[d.name]
        es = ESIZE[d.type]
        dims = list(d.dims)
        if dims:
            unit = es
            for extra in dims[1:]:
                unit *= eval_dim(extra)
            n = eval_dim(dims[0]) if dims[0].strip() else 0
            n = max(n, 1, span // unit)
            dims[0] = str(n)
            size = n * unit
        else:
            size = es
        items.append((a, d, dims, max(size, span)))
    items.sort(key=lambda x: x[0])

    # ranges
    rngs = []
    for a, d, dims, size in items:
        r0 = max(base, a - MARGIN)
        r1 = min(base + len(img), a + size + MARGIN)   # the last page is zero-filled
        if rngs and r0 <= rngs[-1][1]:
            rngs[-1][1] = max(rngs[-1][1], r1)
        else:
            rngs.append([r0, r1])
    packed = bytearray()
    where = []
    for r0, r1 in rngs:
        where.append((r0, r1, len(packed)))
        packed += img[r0 - base:r1 - base]
    rep.write('converted %d labels, %d ranges, %d bytes\n' % (len(items), len(rngs), len(packed)))

    def pos(a):
        for r0, r1, p in where:
            if r0 <= a < r1:
                return p + a - r0
        raise SystemExit('%X outside the ranges' % a)

    macros = []
    for a, d, dims, size in items:
        off = pos(a)
        if dims:
            macros.append('#define %s (*(%s (*)%s)(csegdata + 0x%05X))   /* 0x%X */'
                          % (d.name, d.type, ''.join('[%s]' % x for x in dims), off, a))
        else:
            macros.append('#define %s (*(%s *)(csegdata + 0x%05X))   /* 0x%X */' % (d.name, d.type, off, a))
        for s, t, ta in fx:
            if a <= s < a + size:
                rep.write('!! fixup inside %s at +0x%X -> obj %d %X\n' % (d.name, s - a, t, ta))
        m = re.search(r'=(.*)$', D.strip_comments(d.text), re.S)
        if m:
            ib = init_bytes(d, m.group(1).rstrip().rstrip(';'))
            if ib is None:
                rep.write('?? initializer not evaluated: %s\n' % d.text.strip()[:100])
            elif bytes(img[a - base:a - base + len(ib)]) != ib:
                rep.write('diff %s: exe %s | port %s\n' % (d.name, img[a - base:a - base + len(ib)][:24].hex(' '),
                                                         ib[:24].hex(' ')))

    # remove the declarations from orion_data.c
    for a, d, dims, size in sorted(items, key=lambda x: -x[1].start):
        s, e = d.start, d.end
        nl = data.find('\n', e)
        if nl >= 0 and (data[e:nl].strip().startswith('//') or not data[e:nl].strip()):
            e = nl + 1
        data = data[:s] + data[e:]
    save('src/game/orion_data.c', data, dcrlf)

    names = set(d.name for a, d, dims, size in items)
    t, cr = load('src/game/orion_common.h')
    removed = [0]

    def drop(mm):
        nm = re.search(r'\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*;', mm.group(0))
        if nm and nm.group(1) in names:
            removed[0] += 1
            return ''
        return mm.group(0)
    t = re.sub(r'^extern\b[^;\n]*;[^\n]*\n', drop, t, flags=re.M)
    t = t.replace('#include "orion_dseg.h"   /* wave 180 */',
                  '#include "orion_dseg.h"   /* wave 180 */\n#include "orion_cseg.h"   /* wave 182 */')
    save('src/game/orion_common.h', t, cr)
    rep.write('orion_common.h: %d extern declarations removed\n' % removed[0])

    rows = [' ' + ','.join('%d' % x for x in packed[i:i + 32]) for i in range(0, len(packed), 32)]
    c = ['/* wave 182: bytes of the code object of Orion2.exe around the data labels',
         '   the port uses (tables between functions). Generated by',
         '   tools/compare/gen_cseg.py from the EXE pages; the labels are macros',
         '   into csegdata (orion_cseg.h).',
         '   ranges (IDA address -> offset):']
    c += ['     0x%06X..0x%06X -> 0x%05X' % (r0, r1, p) for r0, r1, p in where]
    c += ['*/', '#include "orion_common.h"', '',
          'uint8_t csegdata[0x%X] = {' % len(packed), ',\n'.join(rows), '};', '']
    open('src/game/orion_cseg.c', 'w', newline='\r\n' if dcrlf else '\n').write('\n'.join(c))
    h = ['/* wave 182: data labels of the code object as macros into csegdata -',
         '   generated by tools/compare/gen_cseg.py. */',
         '#ifndef ORION_CSEG_H', '#define ORION_CSEG_H', '',
         'extern uint8_t csegdata[0x%X];' % len(packed), ''] + macros + ['', '#endif', '']
    open('src/game/orion_cseg.h', 'w', newline='\r\n' if cr else '\n').write('\n'.join(h))
    rep.close()


if __name__ == '__main__':
    main(sys.argv[1])
