"""Fill in the arguments of calls that the compiler reports as too short
(C2198) after a callee got its register parameters (wave 182).

For the k-th call of the callee in the port function the tool takes the
k-th `call callee` in the asm of the same function and traces every
parameter register back (inside the block) to a constant, an offset, a
global or a stack variable; stack variables map to port locals through the
`// [esp+..] [ebp-XXh]` comments of the declarations. Calls it cannot
resolve are listed.

usage: python tools/compare/fix_callers.py <build log> [--fix]
"""
import re
import sys

sys.path.insert(0, 'tools/compare')
import lst_block  # noqa: E402
import protos  # noqa: E402

LST = 'C:/prenos/reorion2Data/diss/Orion2.exe.lst'
WAT = ['eax', 'edx', 'ebx', 'ecx']
R16 = {'ax': 'eax', 'dx': 'edx', 'bx': 'ebx', 'cx': 'ecx', 'si': 'esi', 'di': 'edi'}
fix = '--fix' in sys.argv
LF, CRLF = b'\n', b'\r\n'

funcs, cur, body, shift = {}, None, [], {}
for line in open(LST, encoding='utf-8', errors='replace'):
    m = re.match(r'cseg01:([0-9A-F]{8})\s{3,}(\S.*)$', line.rstrip('\n'))
    if not m:
        continue
    ins = m.group(2).split(';')[0].strip()
    pm = re.match(r'^(sub_[0-9A-F]+)\s+proc\b', ins)
    if pm:
        cur, body = pm.group(1), []
        continue
    if cur is None or not ins:
        continue
    if re.match(r'^%s\s+endp\b' % cur, ins):
        funcs[cur] = body
        cur = None
        continue
    sm = re.match(r'^sub\s+ebp,\s*([0-9A-F]+h|\d+)$', ins)
    if sm:
        v = sm.group(1)
        shift[cur] = int(v[:-1], 16) if v.endswith('h') else int(v)
    if re.match(r'^\w+\s+=\s', ins):
        continue
    body.append(ins)


def num(s):
    return int(s[:-1], 16) if s.endswith('h') else int(s)


def trace(fbody, k, reg, locals_, fname, depth=0):
    """C expression of reg at fbody[k] or None."""
    if depth > 4:
        return None
    for j in range(k - 1, max(-1, k - (80 if reg in ("esi", "edi") else 30)), -1):
        ins = fbody[j]
        if reg in ('esi', 'edi'):
            if re.match(r'^jmp', ins):
                return None       # esi/edi survive calls, labels and conditional jumps
        elif re.match(r'^[\w$?@]+:$', ins) or re.match(r'^j', ins):
            return None
        m = re.match(r'^(\w+)\s+(.*)$', ins)
        if not m:
            if ins == 'cwde' and reg == 'eax':
                v = trace(fbody, j, 'eax', locals_, fname, depth + 1)
                return '(int16_t)(%s)' % v if v else None
            if ins == 'cdq' and reg == 'edx':
                return None
            continue
        op, rest = m.group(1), m.group(2)
        if op == 'call':
            if reg == 'eax':
                return None
            continue
        ops = [x.strip() for x in rest.split(',', 1)]
        dst = ops[0]
        full = R16.get(dst, dst)
        if full != reg or op in ('cmp', 'test', 'push'):
            continue
        if len(ops) != 2:
            return None
        src = ops[1]
        if op == 'xor' and src == dst:
            return '0'
        if op not in ('mov', 'movsx', 'movzx'):
            return None
        cast = ''
        if op == 'movsx':
            cast = '(int8_t)' if 'byte' in src or src in ('al', 'bl', 'cl', 'dl') else '(int16_t)'
        if op == 'movzx':
            cast = '(uint8_t)' if 'byte' in src or src in ('al', 'bl', 'cl', 'dl') else '(uint16_t)'
        src2 = re.sub(r'^(dword|word|byte) ptr ', '', src)
        if re.match(r'^[0-9A-F]+h$|^\d+$', src2):
            v = num(src2)
            return str(v - 0x100000000 if v >= 0x80000000 else v)
        mm = re.match(r'^offset\s+([\w$?@]+)$', src2)
        if mm:
            return '(int)(intptr_t)&%s' % lst_block.cname(mm.group(1))
        if src2 in WAT + ['esi', 'edi'] or src2 in R16:
            v = trace(fbody, j, R16.get(src2, src2), locals_, fname, depth + 1)
            return '%s(%s)' % (cast, v) if v and cast else v
        mm = re.match(r'^\[ebp\+(?:([0-9A-F]+h)\+)?(var|arg)_([0-9A-F]+)\]$', src2)
        if mm:
            sh = num(mm.group(1)) if mm.group(1) else 0
            off = (sh - int(mm.group(3), 16)) if mm.group(2) == 'var' else None
            if off is None:
                return None
            name = locals_.get(off)
            if not name:
                return None
            return '%s%s' % (cast, name) if cast else name
        mm = re.match(r'^([a-z]+_[0-9A-F]+)$', src2)
        if mm and not src2.startswith(('sub_', 'loc_')):
            nm = lst_block.cname(src2)
            if 'word' in src and nm.startswith('dword'):
                return '%s(int16_t)%s' % (cast, nm)
            return '%s%s' % (cast, nm) if cast else nm
        return None
    return None


def main():
    log = open(sys.argv[1], encoding='utf-8', errors='replace').read()
    callees = sorted(set(re.findall(r'error C2198: int (sub_[0-9A-F]+)\(', log)))
    byfile = {}
    import glob
    for p in sorted(glob.glob('src/game/orion_part_*.c')):
        t = open(p, encoding='latin-1').read()
        for c in callees:
            for cm in re.finditer(r'\b%s\(\s*\)' % c, t):
                if re.match(r'^[A-Za-z_]', t[t.rfind('\n', 0, cm.start()) + 1:]):
                    continue          # the definition
                byfile.setdefault(p.split('\\')[-1].split('/')[-1], []).append((t.count('\n', 0, cm.start()) + 1, c))
    errs = [x for v in byfile.values() for x in v]
    fixed = 0
    for f, items in byfile.items():
        p = 'src/game/' + f
        raw = open(p, 'rb').read()
        crlf = CRLF in raw
        t = raw.replace(CRLF, LF).decode('latin-1')
        lines = t.split('\n')
        heads = [(t.count('\n', 0, m.start()) + 1, m.group(1), m.end())
                 for m in re.finditer(r'^[A-Za-z_][^\n;=(]*?\b(sub_[0-9A-F]+)\s*\([^;{]*\)\s*\n\{', t, re.M)]
        edits = []
        for line, callee in items:
            h = [x for x in heads if x[0] <= line][-1]
            fname, fstart = h[1], h[2]
            fend = t.index('\n}\n', fstart)
            ftext = t[fstart:fend]
            locals_ = {}
            for dm in re.finditer(r'^  [^\n;]*?\b(v\d+|[a-z]\w*)(?:\[\d+\])?; // .*\[ebp([+-])([0-9A-F]+)h\]', ftext, re.M):
                off = int(dm.group(3), 16) * (1 if dm.group(2) == '+' else -1)
                locals_.setdefault(off, dm.group(1))
            # parameters the prologue saves (`enter N,0` / `mov ebp, esp` + push reg)
            fbp = funcs.get(fname, [])
            base = None
            for ins in fbp[:12]:
                em = re.match(r'^enter\s+([0-9A-F]+h|\d+),\s*0$', ins)
                if em:
                    base = num(em.group(1))
                    continue
                if ins.replace(' ', '') == 'movebp,esp':
                    base = 0
                    continue
                pm2 = re.match(r'^push\s+(eax|edx|ebx|ecx)$', ins)
                if pm2 and base is not None:
                    base += 4
                    r = pm2.group(1)
                    pname = protos.param_of(fname, r) if protos.params(fname) is not None else None
                    if not pname and r in WAT:
                        pname = 'a%d' % (WAT.index(r) + 1)
                    if pname and re.search(r'\b%s\b' % pname, ftext):
                        locals_.setdefault(-base, pname)
                elif base is not None and not ins.startswith('push'):
                    break
            calls_port = [cm.start() for cm in re.finditer(r'\b%s\(' % callee, ftext)]
            pos_line = sum(len(x) + 1 for x in lines[:line - 1])
            k = [i for i, s in enumerate(calls_port) if fstart + s >= pos_line][0] if calls_port else None
            fb = funcs.get(fname, [])
            calls_asm = [i for i, ins in enumerate(fb) if re.match(r'^call\s+%s$' % callee, ins)]
            where = '%s:%d %s -> %s' % (f, line, fname, callee)
            if k is None or len(calls_asm) != len(calls_port):
                print('?? %s: %d port calls, %d asm calls' % (where, len(calls_port), len(calls_asm)))
                continue
            gm = re.search(r'^int %s\(([^)]*)\)' % callee, open('src/game/orion_common.h', encoding='latin-1').read(), re.M)
            n = len([x for x in gm.group(1).split(',') if x.strip() and x.strip() != 'void']) if gm else 0
            args = [trace(fb, calls_asm[k], r, locals_, fname) for r in WAT[:n]]
            if any(a is None for a in args):
                print('?? %s: %s' % (where, args))
                continue
            s = fstart + calls_port[k]
            e = t.index(')', s)
            inner = t[s + len(callee) + 1:e]
            if inner.strip():
                print('?? %s: call already has arguments (%s)' % (where, inner))
                continue
            print('%s: (%s)' % (where, ', '.join(args)))
            edits.append((s + len(callee) + 1, e, ', '.join(args)))
            fixed += 1
        if fix and edits:
            for a, b, r in sorted(edits, reverse=True):
                t = t[:a] + r + t[b:]
            b = t.encode('latin-1')
            open(p, 'wb').write(b.replace(LF, CRLF) if crlf else b)
    print('resolved %d of %d' % (fixed, len(errs)))


if __name__ == '__main__':
    main()
