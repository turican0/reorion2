"""For every one-byte `_UNKNOWN unk_X;` in orion_data.c that the port uses,
read the original object from the IDA listing: its exact size (up to the
next label) and its initial bytes.

The port declares these as a single zero byte; in the original many are
multi-byte buffers or initialized tables (wave 179: unk_1BC390 is a 0x400
byte palette backup - the copy into it overwrote the LBX cache handle).

C name = asm name + 0x8000.

usage: python tools/compare/unknown_lst.py [--all]
"""
import glob
import re
import sys

LST = 'C:/prenos/reorion2Data/diss/Orion2.exe.lst'
src = open('src/game/orion_data.c', encoding='latin-1').read()
names = re.findall(r'^_UNKNOWN\s+(unk_[0-9A-F]+)\s*;', src, re.M)

used = {}
if '--all' not in sys.argv:
    for p in glob.glob('src/game/*.c'):
        if p.endswith('orion_data.c'):
            continue
        for line in open(p, encoding='latin-1'):
            for n in re.findall(r'\bunk_[0-9A-F]{5,6}\b', line):
                used[n] = used.get(n, 0) + 1
    names = [n for n in names if n in used]

want = {'unk_%X' % (int(n[4:], 16) - 0x8000): n for n in names}

row = re.compile(r'^dseg\d+:([0-9A-F]{8})\s(.*)$')
label = re.compile(r'^\s?([A-Za-z_$?@][\w$?@]*)\s+(db|dw|dd|dq|dt)\b(.*)$')
anon = re.compile(r'^\s+(db|dw|dd|dq|dt)\b(.*)$')
width = {'db': 1, 'dw': 2, 'dd': 4, 'dq': 8, 'dt': 10}


def items(text):
    """Split the operand of a data directive at top-level commas."""
    text = text.split(';')[0].strip()
    out, cur, q, depth = [], '', False, 0
    for ch in text:
        if ch == "'" :
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


def value(tok):
    tok = tok.strip()
    if tok == '?':
        return None
    if tok.endswith('h') or tok.endswith('H'):
        return int(tok[:-1], 16)
    return int(tok, 0) if not tok.startswith('0') or tok == '0' else int(tok, 10)


def emit(kind, ops, out):
    w = width[kind]
    for it in items(ops):
        m = re.match(r'^(\w+)\s+dup\((.*)\)$', it)
        if m:
            cnt = value(m.group(1))
            inner = m.group(2).strip()
            for _ in range(cnt):
                emit(kind, inner, out)
            continue
        if it.startswith("'"):
            for ch in it[1:-1]:
                out.append(ord(ch))
            continue
        try:
            v = value(it)
        except ValueError:
            # offset / symbol: record as unknown pointer bytes
            out.extend([('ptr', it)] + [None] * (w - 1))
            continue
        if v is None:
            out.extend([None] * w)
        else:
            out.extend([(v >> (8 * k)) & 0xFF for k in range(w)])


cur = None
res = {}
with open(LST, encoding='utf-8', errors='replace') as f:
    for line in f:
        m = row.match(line.rstrip('\n'))
        if not m:
            continue
        body = m.group(2)
        lm = label.match(body)
        if lm:
            if cur is not None:
                res[cur[0]] = cur[1]
                cur = None
            if lm.group(1) in want:
                cur = (lm.group(1), [])
                emit(lm.group(2), lm.group(3), cur[1])
            continue
        if cur is None:
            continue
        am = anon.match(body)
        if am:
            emit(am.group(1), am.group(2), cur[1])
        elif re.match(r'^\s+align\b', body) or re.match(r'^\s*[A-Za-z_]\w*\s*(label|=)', body):
            res[cur[0]] = cur[1]
            cur = None
if cur is not None:
    res[cur[0]] = cur[1]

for asm, cname in sorted(want.items(), key=lambda kv: kv[1]):
    data = res.get(asm)
    if data is None:
        print('%s MISSING in listing' % cname)
        continue
    init = [b for b in data if b is not None]
    ptr = [b for b in data if isinstance(b, tuple)]
    kind = 'bss' if not init else ('ptr' if ptr else 'init')
    nz = sum(1 for b in data if isinstance(b, int) and b)
    print('%s size=%d %s nonzero=%d uses=%d' % (cname, len(data), kind, nz, used.get(cname, 0)))
