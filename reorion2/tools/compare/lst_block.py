"""Read a contiguous data region of the original from the IDA listing.

    region(c_start, c_end) -> (bytes, labels, fixups)

bytes   bytearray of the region (`?` and alignment gaps are 0)
labels  [(offset, c_name, directive)] - every named object in the region
fixups  [(offset, c_target, addend)] - `dd offset X+N` slots; in the port
        these must be filled at run time with the 32-bit address of X

All addresses are C names (asm address + 0x8000); code labels (sub_,
loc_) keep their IDA address.

As a script it prints the region:
    python tools/compare/lst_block.py <c_start_hex> <c_end_hex>
"""
import re
import sys

LST = 'C:/prenos/reorion2Data/diss/Orion2.exe.lst'
DELTA = 0x8000
WIDTH = {'db': 1, 'dw': 2, 'dd': 4, 'dq': 8, 'dt': 10}
ROW = re.compile(r'^dseg\d+:([0-9A-F]{8})\s+(?:([A-Za-z_$?@][\w$?@]*)\s+)?(db|dw|dd|dq|dt|align)\b(.*)$')

_lines = None


def _load():
    """Parsed data rows: (asm address, label or None, directive, operands)."""
    global _lines
    if _lines is None:
        _lines = []
        with open(LST, encoding='utf-8', errors='replace') as f:
            for line in f:
                if line.startswith('dseg'):
                    m = ROW.match(line.rstrip('\n'))
                    if m:
                        _lines.append((int(m.group(1), 16), m.group(2), m.group(3), m.group(4)))
    return _lines


def next_label(c_addr):
    """C address of the first label after c_addr (the object's end)."""
    a = c_addr - DELTA
    for addr, lab, kind, ops in _load():
        if addr > a and lab:
            return addr + DELTA
    return None


def cname(asm):
    """asm data name -> C name (address + 0x8000); code names unchanged."""
    m = re.match(r'^(unk|byte|word|dword|qword|off|stru|asc|flt|dbl|a[A-Za-z0-9_]*?)_([0-9A-F]{5,6})$', asm)
    if m and not asm.startswith(('sub_', 'loc_', 'nullsub_')):
        return '%s_%X' % (m.group(1), int(m.group(2), 16) + DELTA)
    return asm


def _items(text):
    text = text.split(';')[0].strip()
    out, cur, q, depth = [], '', False, 0
    for ch in text:
        if ch == "'":
            q = not q
        if not q and ch == '(':
            depth += 1
        if not q and ch == ')':
            depth -= 1
        if ch == ',' and not q and depth == 0:
            out.append(cur.strip())
            cur = ''
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def _num(tok):
    tok = tok.strip()
    if tok == '?':
        return 0
    if tok[-1] in 'hH':
        return int(tok[:-1], 16)
    return int(tok, 10)


def _emit(kind, ops, out, fix):
    """Append the bytes of one directive to out; pointer slots go to fix."""
    w = WIDTH[kind]
    for it in _items(ops):
        m = re.match(r'^(\w+)\s+dup\((.*)\)$', it)
        if m:
            for _ in range(_num(m.group(1))):
                _emit(kind, m.group(2), out, fix)
            continue
        if it.startswith("'"):
            out.extend(ord(ch) for ch in it[1:-1])
            continue
        m = re.match(r'^offset\s+([\w$?@]+)\s*(?:\+\s*(\w+))?$', it)
        if m:
            fix.append((len(out), cname(m.group(1)), _num(m.group(2)) if m.group(2) else 0))
            out.extend([0] * w)
            continue
        v = _num(it)
        out.extend((v >> (8 * k)) & 0xFF for k in range(w))


def region(c0, c1):
    a0, a1 = c0 - DELTA, c1 - DELTA
    data = bytearray(a1 - a0)
    labels, fixups = [], []
    for a, lab, kind, ops in _load():
        if a < a0 or a >= a1:
            continue
        if lab:
            labels.append((a - a0, cname(lab), kind))
        if kind == 'align':
            continue
        out, fix = [], []
        _emit(kind, ops, out, fix)
        if a - a0 + len(out) > len(data):
            raise SystemExit('object at %06X crosses the region end' % (a + DELTA))
        data[a - a0:a - a0 + len(out)] = bytes(out)
        fixups.extend((a - a0 + o, t, n) for o, t, n in fix)
    return data, labels, fixups


if __name__ == '__main__':
    c0, c1 = int(sys.argv[1], 16), int(sys.argv[2], 16)
    d, l, f = region(c0, c1)
    print('size 0x%X' % len(d))
    for o, n, k in l:
        print('  +0x%03X %s %s' % (o, k, n))
    for o, t, n in f:
        print('  fix +0x%03X -> %s+0x%X' % (o, t, n))
    print(' '.join('%02X' % b for b in d))
