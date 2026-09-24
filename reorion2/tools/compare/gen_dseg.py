"""Wave 180: the whole data object of Orion2.exe as ONE byte array.

IDA split tables into one-element arrays and unrelated labels; the port gave
every label its own variable, so stride-indexed tables (`byte_17F80F[28 * i]`)
and loops over adjacent tables read unrelated memory. Here every data symbol
of orion_data.c whose type has the original size becomes a macro into `dseg`,
laid out exactly like the original.

    dseg          uint8_t[0x5DCD0], C addresses 0x178000..0x1D5CD0
    contents      the EXE pages of the data object; port initializers that
                  differ are only reported (all 24 were decompiler damage:
                  string terminators written over the next object, "s" for
                  "%s"); deliberate port changes are in KEEP_NAMES
    pointers      the 1062 fixups of the LE relocation table are filled at
                  start-up by InitDataSegment() with 32-bit port addresses
    kept apart    pointer-typed variables (8 bytes in the port), intptr_t,
                  int64_t, double, float and port structs - their dseg bytes
                  are only a shadow

Outputs: src/game/orion_dseg.c, src/game/orion_dseg.h, edits orion_data.c,
orion_common.h, orion_blocks.h, link_stubs.c; report to argv[1].

usage: python tools/compare/gen_dseg.py <report.txt>
"""
import glob
import re
import struct
import sys

import dseg_decls as D
import le_fixups
import lst_block

LF, CRLF = b'\n', b'\r\n'
C0, SIZE = D.DSEG_C0, 0x5DCD0
KEEP_TYPES = ('intptr_t', 'int64_t', 'double', 'float', 'struct DosDta', 'struct DosFarPointer',
              'TypeSaveSlotInfo_199699')
# deliberate port changes that are longer than the original object (wave 26:
# the port reads "wDIG_fake.INI" / "rMDI_fake.INI")
KEEP_NAMES = ('aWdigIni', 'aRmdiIni')
# pointer variables that hold port pointers (heap, pools, the port's own name
# arrays) - 8 bytes in the port, used as pointers everywhere. Every other
# pointer-typed label is a 32-bit field of a table and becomes a uint32_t slot.
REAL_POINTERS = (
    'dword_1ACEFC', 'dword_1ACF00', 'dword_1ACF04', 'dword_1ACF08', 'dword_1ACF0C', 'dword_1ACF10',
    'dword_1ACF14', 'dword_1A08B0', 'dword_19A00C', 'dword_19916C', 'dword_197F98', 'dword_197F9C',
    'dword_193178', 'dword_1930D4', 'dword_19306C', 'dword_193068', 'dword_192EE8', 'dword_192EF4',
    'dword_192B18', 'dword_192B24', 'dword_190298', 'byte_1BB359', 'byte_1BB35A', 'byte_1BB35B',
    'off_184480', 'off_184484', 'off_184496', 'off_18B018', 'off_18B04A', 'off_1897C4', 'off_1845D4',
    'off_183BCB', 'off_183B77', 'off_183B0E', 'off_183899', 'off_183871', 'off_183558', 'off_183554',
    'off_182314', 'off_1822FA', 'off_182278', 'off_1820B4', 'off_181FE4', 'off_18175C',
    'off_17F803', 'off_17F807', 'off_17D5E4', 'off_17D5E0', 'off_17CF22',
    'shipSizeNameA_18003A', 'shipSizeNameB_18003E', 'techName_17EB2A')
ESIZE = {'char': 1, '_BYTE': 1, 'uint8_t': 1, '_UNKNOWN': 1, 'unsigned char': 1, 'int8_t': 1,
         'int16_t': 2, '_WORD': 2, 'uint16_t': 2, '__int16': 2,
         'int': 4, '_DWORD': 4, 'uint32_t': 4, 'int32_t': 4, 'unsigned int': 4}


def load(p):
    d = open(p, 'rb').read()
    return d.replace(CRLF, LF).decode('latin-1'), CRLF in d


def save(p, t, crlf):
    b = t.encode('latin-1')
    open(p, 'wb').write(b.replace(LF, CRLF) if crlf else b)


# ------------------------------------------------------------ EXE image
def exe_image():
    d, le = le_fixups._le()
    objs = le_fixups.objects()
    vs, base, fl, pti, npg = objs[1]
    psz = struct.unpack_from('<I', d, le + 0x28)[0]
    lastsz = struct.unpack_from('<I', d, le + 0x2C)[0]
    # bound DOS4GW executable: the data pages offset is relative to the MZ
    # header of the embedded module (0x26654), not to the start of the file
    base = next(p for p in range(le, -1, -1)
                if d[p:p + 2] == b'MZ' and struct.unpack_from('<I', d, p + 0x3C)[0] == le - p)
    datapages = base + struct.unpack_from('<I', d, le + 0x80)[0]
    npages_total = struct.unpack_from('<I', d, le + 0x14)[0]
    img = bytearray(SIZE)
    for k in range(npg):
        page = pti + k                     # 1-based
        n = lastsz if page == npages_total else psz
        off = datapages + (page - 1) * psz
        img[k * psz:k * psz + n] = d[off:off + n]
    return img, npg * psz


# ------------------------------------------------------------ initializer evaluation
def c_string(s):
    out = bytearray()
    i = 0
    while i < len(s):
        c = s[i]
        if c != '\\':
            out.append(ord(c))
            i += 1
            continue
        n = s[i + 1]
        if n == 'x':
            m = re.match(r'[0-9A-Fa-f]{1,2}', s[i + 2:])
            out.append(int(m.group(0), 16))
            i += 2 + len(m.group(0))
        elif n in '01234567':
            m = re.match(r'[0-7]{1,3}', s[i + 1:])
            out.append(int(m.group(0), 8) & 0xFF)
            i += 1 + len(m.group(0))
        else:
            out.append({'n': 10, 't': 9, 'r': 13, 'a': 7, 'b': 8, 'f': 12, 'v': 11, '0': 0,
                        '\\': 92, "'": 39, '"': 34, '?': 63}[n])
            i += 2
    return bytes(out)


def split_items(s):
    out, cur, depth, q = [], '', 0, None
    for ch in s:
        if q:
            cur += ch
            if ch == q and not cur.endswith('\\' + q) or (ch == q and cur.endswith('\\\\' + q)):
                q = None
            continue
        if ch in '"\'':
            q = ch
        elif ch == '{':
            depth += 1
        elif ch == '}':
            depth -= 1
        if ch == ',' and depth == 0:
            out.append(cur.strip())
            cur = ''
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def scalar(tok):
    tok = tok.strip()
    while tok.startswith('(') and re.match(r'^\((?:unsigned |signed )?(?:char|int|int16_t|uint8_t|uint16_t|_BYTE|_WORD|_DWORD|uint32_t|int8_t|int32_t)\)', tok):
        tok = tok[tok.index(')') + 1:].strip()
    if tok.startswith("'"):
        b = c_string(tok[1:-1])
        if len(b) != 1:
            raise ValueError(tok)
        return b[0] - 256 if b[0] > 127 else b[0]
    neg = tok.startswith('-')
    if neg:
        tok = tok[1:].strip()
    tok = re.sub(r'[uUlL]+$', '', tok)
    if re.match(r'^0[xX][0-9A-Fa-f]+$', tok):
        v = int(tok, 16)
    elif re.match(r'^0[0-7]+$', tok):
        v = int(tok, 8)
    elif re.match(r'^\d+$', tok):
        v = int(tok)
    else:
        raise ValueError(tok)
    return -v if neg else v


def flat(init):
    """Flatten a brace initializer into a list of scalar tokens."""
    init = init.strip()
    if init.startswith('{'):
        body = init[1:init.rindex('}')]
        out = []
        for it in split_items(body):
            out.extend(flat(it))
        return out
    return [init]


def init_bytes(decl, init):
    """Bytes of the port initializer (explicit part only) or None."""
    es = ESIZE.get(decl.type)
    if es is None:
        return None
    init = D.strip_comments(init).strip()
    if init.startswith('"') or (init.startswith('{') and init[1:].strip().startswith('"')):
        strs = re.findall(r'"((?:[^"\\]|\\.)*)"', init)
        b = c_string(''.join(strs)) + b'\x00'
        if decl.dims and decl.dims[0].strip():
            n = eval_dim(decl.dims[0])
            b = b[:n]
        return b
    try:
        vals = [scalar(v) for v in flat(init)]
    except (ValueError, KeyError):
        return None
    out = bytearray()
    for v in vals:
        out += (v & ((1 << (8 * es)) - 1)).to_bytes(es, 'little')
    return bytes(out)


def eval_dim(s):
    s = s.strip()
    return int(eval(re.sub(r'(0x[0-9A-Fa-f]+|\d+)[uU]?', r'\1', s), {}, {}))


# ------------------------------------------------------------ main
def main(report_path):
    rep = open(report_path, 'w', encoding='utf-8')
    img, init_len = exe_image()
    data, dcrlf = load('src/game/orion_data.c')
    ds = D.decls(data)
    conv, kept = [], []
    for d in ds:
        a = D.address(d.name)
        if a is None or not (C0 <= a < C0 + SIZE):
            continue
        d.type = ' '.join(w for w in d.type.split() if w not in ('static', 'const', 'volatile'))
        # IDA's strings "1".."5" are called a1..a5 - the same names as the
        # decompiler's parameters; as macros they would replace them
        if (d.ptr and d.name in REAL_POINTERS) or d.type in KEEP_TYPES or d.name in KEEP_NAMES \
                or re.match(r'^a\d+$', d.name):
            kept.append((a, d))
            continue
        if d.ptr:
            d.type, d.ptr = 'uint32_t', False     # a 32-bit pointer field of a table
        conv.append((a, d))
    rep.write('converted %d, kept apart %d\n' % (len(conv), len(kept)))
    for a, d in kept:
        rep.write('  kept %06X %r\n' % (a, d))

    # sizes: declared dims, empty first dim -> distance to the next listing label
    macros = []
    diffs = 0
    port_img = bytearray(img)
    for a, d in sorted(conv, key=lambda x: x[0]):
        off = a - C0
        es = ESIZE.get(d.type)
        dims = list(d.dims)
        if dims and not dims[0].strip():
            nxt = lst_block.next_label(a) or (a + 1)
            unit = es or 1
            for extra in dims[1:]:
                unit *= eval_dim(extra)
            n = max(1, (nxt - a) // unit)
            # an initializer may be longer than the gap
            m = re.search(r'=(.*)$', D.strip_comments(d.text), re.S)
            if m and es:
                ib = init_bytes(d, m.group(1).rstrip().rstrip(';'))
                if ib is not None:
                    n = max(n, -(-len(ib) // unit))
            dims[0] = str(n)
        if dims:
            total = (es or 1) * 1
            for x in dims:
                total *= eval_dim(x)
            macros.append('#define %s (*(%s (*)%s)(dseg + 0x%05X))' % (d.name, d.type, ''.join('[%s]' % x.strip() for x in dims), off))
        else:
            total = es or 0
            macros.append('#define %s (*(%s *)(dseg + 0x%05X))' % (d.name, d.type, off))
        if es and off + total > SIZE:
            rep.write('!! %s exceeds the data object\n' % d.name)
        # port initializer overlay
        m = re.search(r'=(.*)$', D.strip_comments(d.text), re.S)
        if m:
            ib = init_bytes(d, m.group(1).rstrip().rstrip(';'))
            if ib is None:
                rep.write('?? initializer not evaluated: %06X %s\n' % (a, d.text.strip()[:120].replace('\n', ' ')))
            else:
                exe = bytes(img[off:off + len(ib)])
                if exe != ib:
                    diffs += 1
                    rep.write('diff %06X %s: exe %s | port %s\n' % (a, d.name, exe[:24].hex(' '), ib[:24].hex(' ')))
    rep.write('port values that differ from the EXE (the EXE is used): %d\n' % diffs)

    # remove converted declarations from orion_data.c
    for a, d in sorted(conv, key=lambda x: -x[1].start):
        s, e = d.start, d.end
        # swallow the rest of the line (trailing // comment) and the newline
        nl = data.find('\n', e)
        if nl >= 0 and data[e:nl].strip().startswith('//') or (nl >= 0 and not data[e:nl].strip()):
            e = nl + 1
        data = data[:s] + data[e:]
    # the old InitDataBlocks (wave 179) is part of the fixup table now
    m = re.search(r'// wave 179: pointer slots inside the data blocks\..*?\nvoid InitDataBlocks\(void\)\n\{.*?\n\}\n', data, re.S)
    if m:
        data = data[:m.start()] + data[m.end():]
    save('src/game/orion_data.c', data, dcrlf)

    # fixups
    names_by_addr = {}
    for line in open(lst_block.LST, encoding='utf-8', errors='replace'):
        mm = re.match(r'cseg01:([0-9A-F]{8})\s+(sub_[0-9A-F]+|nullsub_\d+)\s+proc', line)
        if mm:
            names_by_addr[int(mm.group(1), 16)] = mm.group(2)
    funcs = set()
    for p in glob.glob('src/game/*.c'):
        funcs.update(re.findall(r'^[A-Za-z_][^\n;=]*?\b(sub_[0-9A-F]+|nullsub_\d+)\s*\(', open(p, encoding='latin-1').read(), re.M))
    dfix, cfix, lost = [], [], []
    for slot, tobj, ta in le_fixups.data_fixups():
        so = slot - C0
        if tobj == 2:
            dfix.append((so, ta + lst_block.DELTA - C0))
        else:
            n = names_by_addr.get(ta)
            if n in funcs:
                cfix.append((so, n))
            else:
                lost.append((so, ta))
    rep.write('fixups: data %d, code %d, code targets without a port function %d\n' % (len(dfix), len(cfix), len(lost)))

    # orion_dseg.c
    last = max(i for i in range(SIZE) if port_img[i]) + 1
    rows = []
    for i in range(0, last, 32):
        rows.append('  ' + ','.join('%d' % x for x in port_img[i:min(i + 32, last)]))
    c = ['/* wave 180: the data object of Orion2.exe (C addresses 0x178000..0x1D5CD0).',
         '   Generated by tools/compare/gen_dseg.py from the EXE pages; port values',
         '   given explicitly in the old declarations were kept. The data symbols are',
         '   macros into dseg (orion_dseg.h). */',
         '#include "orion_common.h"',
         '',
         'uint8_t dseg[0x%X] = {' % SIZE,
         ',\n'.join(rows),
         '};',
         '',
         '/* LE relocations inside the data object: slot offset, target offset. */',
         'static const uint32_t dsegDataFixups[][2] = {']
    c.append(',\n'.join('  { 0x%05X, 0x%05X }' % f for f in dfix))
    c += ['};', '',
          '/* LE relocations to code: slot offset, port function. The original also',
          '   points at %d labels inside functions (jump tables); those stay 0. */' % len(lost),
          'static const struct { uint32_t slot; void *target; } dsegCodeFixups[] = {']
    c.append(',\n'.join('  { 0x%05X, (void *)%s }' % f for f in cfix))
    c += ['};', '',
          '/* The original stores 32-bit addresses in these slots; the port image lies',
          '   below 4 GB, so the 32-bit address of the port object is what the code',
          '   reads back. */',
          'void InitDataSegment(void)',
          '{',
          '  uint32_t i;',
          '',
          '  for ( i = 0; i < sizeof(dsegDataFixups) / sizeof(dsegDataFixups[0]); ++i )',
          '    *(uint32_t *)(dseg + dsegDataFixups[i][0]) = (uint32_t)(uintptr_t)(dseg + dsegDataFixups[i][1]);',
          '  for ( i = 0; i < sizeof(dsegCodeFixups) / sizeof(dsegCodeFixups[0]); ++i )',
          '    *(uint32_t *)(dseg + dsegCodeFixups[i].slot) = (uint32_t)(uintptr_t)dsegCodeFixups[i].target;',
          '}', '']
    open('src/game/orion_dseg.c', 'w', newline='\r\n' if dcrlf else '\n').write('\n'.join(c))

    # orion_dseg.h
    h = ['/* wave 180: data symbols as macros into dseg - generated by',
         '   tools/compare/gen_dseg.py. The layout is the original one, so tables that',
         '   IDA split into several labels are contiguous again. */',
         '#ifndef ORION_DSEG_H', '#define ORION_DSEG_H', '',
         'extern uint8_t dseg[0x%X];' % SIZE,
         'void InitDataSegment(void);', ''] + macros + ['', '#endif', '']
    hdr, hcrlf = load('src/game/orion_common.h')
    open('src/game/orion_dseg.h', 'w', newline='\r\n' if hcrlf else '\n').write('\n'.join(h))

    # remove extern declarations of converted names from the headers
    names = set(d.name for a, d in conv)
    for p in ('src/game/orion_common.h', 'src/game/orion_blocks.h'):
        t, cr = load(p)
        removed = 0

        def drop(mm):
            nonlocal removed
            nm = re.search(r'\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*;', mm.group(0))
            if nm and nm.group(1) in names:
                removed += 1
                return ''
            return mm.group(0)
        t = re.sub(r'^extern\b[^;\n]*;[^\n]*\n', drop, t, flags=re.M)
        if p.endswith('orion_common.h'):
            t = t.replace('#include "orion_blocks.h"   /* wave 179 */',
                          '#include "orion_dseg.h"   /* wave 180 */\n#include "orion_blocks.h"   /* wave 179 */')
        else:
            t = t.replace('void InitDataBlocks(void);\n', '')
        save(p, t, cr)
        rep.write('%s: %d extern declarations removed\n' % (p, removed))

    # link_stubs.c: stub variables inside the data object
    t, cr = load('src/game/link_stubs.c')
    for mm in list(re.finditer(r'^int (unk_[0-9A-F]{6});\n', t, re.M)):
        a = int(mm.group(1)[4:], 16)
        if C0 <= a < C0 + SIZE:
            rep.write('link_stubs.c: %s lies in the data object\n' % mm.group(1))
    rep.close()


if __name__ == '__main__':
    main(sys.argv[1])
