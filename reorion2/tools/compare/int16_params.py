"""Register parameters that the original uses only as 16-bit values.

If the first instruction of a function that reads a parameter register is
`movsx r, dx` (or `cwde` / `movsx r, ax` for EAX), the caller's high word
does not matter - and Hex-Rays callers often pass garbage there
(`HIWORD(v6) = HIWORD(dword_197F9C); LOWORD(v6) = index;`). The port treats
the `int` parameter as a full value (wave 181: sub_FF799 computed
113 * a2 with the high word of a pointer in a2). The fix is
`aK = (int16_t)aK;` at the top of the body.

usage: python tools/compare/int16_params.py [--fix]
"""
import glob
import re
import sys

sys.path.insert(0, 'tools/compare')
import protos  # noqa: E402

LST ='C:/prenos/reorion2Data/diss/Orion2.exe.lst'
REGS = [('eax', 'ax', 'al', 1), ('edx', 'dx', 'dl', 2), ('ebx', 'bx', 'bl', 3), ('ecx', 'cx', 'cl', 4)]

funcs = {}
cur, body = None, []
for line in open(LST, encoding='utf-8', errors='replace'):
    m = re.match(r'cseg01:([0-9A-F]{8})\s{3,}(\S.*)$', line.rstrip('\n'))
    if not m:
        continue
    ins = m.group(2).split(';')[0].strip()
    pm = re.match(r'^(sub_[0-9A-F]+)\s+proc\b', ins)
    if pm:
        cur, body = pm.group(1), []
        continue
    if cur is None:
        continue
    if re.match(r'^(sub_[0-9A-F]+)\s+endp\b', ins):
        funcs[cur] = body
        cur = None
        continue
    if not ins or re.match(r'^[\w$?@]+:$', ins) or re.match(r'^\w+\s+=\s', ins):
        continue
    body.append(ins)


def first_use(body, full, word, byte, idx):
    """'int16' if the first read of the register sign-extends its word."""
    for ins in body[:40]:
        if ins.startswith(('push ', 'enter', 'sub     ebp', 'sub ebp')):
            if re.match(r'^push\s+%s$' % full, ins):
                continue      # saved for a phantom local - the slot keeps the full value
            continue
        if ins.startswith(('jmp', 'call', 'retn', 'j')):
            return None
        if idx == 1 and ins == 'cwde':
            return 'int16'
        m = re.match(r'^(\w+)\s+(.*)$', ins)
        if not m:
            continue
        op, rest = m.group(1), m.group(2)
        parts = [x.strip() for x in rest.split(',', 1)]
        src = parts[1] if len(parts) == 2 else parts[0]
        dst = parts[0]
        if op == 'movsx' and src in (word,):
            return 'int16'
        # wave 182: `cmp bx, 1` / `test dx, dx` as the first read (sub_B4E64),
        # when no later instruction reads the full register before it is
        # written again
        if op in ('cmp', 'test') and dst == word:
            k = body.index(ins)
            for later in body[k + 1:]:
                mm = re.match(r'^(\w+)\s+(.*)$', later)
                if not mm:
                    if idx == 1 and later == 'cwde':
                        return 'int16'
                    continue
                lop = mm.group(1)
                lparts = [x.strip() for x in mm.group(2).split(',', 1)]
                ldst = lparts[0]
                lsrc = lparts[1] if len(lparts) == 2 else ''
                if lop in ('mov', 'movsx', 'movzx', 'lea') and ldst == full and not re.search(r'\b%s\b' % full, lsrc):
                    return 'int16'
                if lop == 'xor' and ldst == full and lsrc == full:
                    return 'int16'
                if lop == 'call' and idx == 1:
                    return 'int16'      # eax is the result register
                if re.search(r'\b%s\b' % full, mm.group(2)) or (idx == 1 and later in ('cdq',)):
                    return None         # the full register is read later
            return 'int16'
        if re.search(r'\b(%s|%s|%s|%s)\b' % (full, word, byte, full[1:] + 'h' if full != 'eax' else 'ah'), src) \
                or (op not in ('mov', 'movsx', 'movzx', 'lea') and re.search(r'\b(%s|%s|%s)\b' % (full, word, byte), dst)):
            return None       # read in another way first
        if re.match(r'^(%s|%s|%s)$' % (full, word, byte), dst) and op in ('mov', 'movsx', 'movzx', 'lea', 'xor'):
            return None       # overwritten before any read
    return None


fix = '--fix' in sys.argv
LF, CRLF = b'\n', b'\r\n'
found = 0
for p in sorted(glob.glob('src/game/orion_part_*.c')):
    raw = open(p, 'rb').read()
    crlf = CRLF in raw
    t = raw.replace(CRLF, LF).decode('latin-1')
    changed = False
    for m in reversed(list(re.finditer(r'^[A-Za-z_][^\n;=]*?\b(sub_[0-9A-F]+)\s*\(([^;{]*)\)\s*\n\{', t, re.M))):
        name = m.group(1)
        if name not in funcs:
            continue
        params = [x.strip() for x in m.group(2).split(',') if x.strip() and x.strip() != 'void']
        s = m.end()
        e = t.index('\n}\n', s)
        f = t[s:e]
        add = []
        decls = {}
        for d in params:
            pm = re.match(r'^(unsigned int|int|_DWORD|unsigned __int32|uint32_t|int32_t)\s+(a\d+)$', d)
            if pm:
                decls[pm.group(2)] = True
        for full, word, byte, idx in REGS:
            # the parameter in this register, from the original prototype
            if protos.params(name) is not None:
                a = protos.param_of(name, full)
            else:
                a = 'a%d' % idx if idx <= len(params) else None
            if not a or a not in decls:
                continue
            if first_use(funcs[name], full, word, byte, idx) != 'int16':
                continue
            if re.search(r'\b%s = \(int16_t\)%s;' % (a, a), f):
                continue
            add.append(a)
            found += 1
            print('%s %s: %s is 16-bit (%s)' % (p.split('\\')[-1], name, a, word))
        if fix and add:
            # after the declarations and after `vN = aK;` lines of phantom_args.py
            pos = f.index('\n\n') + 2 if '\n\n' in f else 1
            while True:
                mm = re.match(r'  [\w\[\]]+ = a\d+;   /\* wave 181: \w+ saved by the prologue[^\n]*\n', f[pos:])
                if not mm:
                    break
                pos += mm.end()
            ins = ''.join('  %s = (int16_t)%s;   /* wave 181: the original reads only the low word (movsx) */\n'
                          % (a, a) for a in add)
            f = f[:pos] + ins + f[pos:]
            t = t[:s] + f + t[e:]
            changed = True
    if changed:
        b = t.encode('latin-1')
        open(p, 'wb').write(b.replace(LF, CRLF) if crlf else b)
print('found: %d' % found)
