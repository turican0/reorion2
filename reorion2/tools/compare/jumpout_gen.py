"""Rewrite port functions that are only `JUMPOUT(tail)` (wave 182).

Such a function sets a few registers and jumps into the tail of another
function, which calls one function and returns (sub_BBB8A: `movsx edx, ax /
mov eax, offset aColony2Lbx / add edx, 13h / jmp loc_BBBB2` ->
`call sub_127C27 / pop / retn`). The port body did nothing.

A small symbolic evaluator runs the asm from the function start through the
jump and the tail up to `retn`: registers hold C expressions; calls use
the callee's register parameters (protos.py, else Watcom order and the port
parameter count). Parameters of the rewritten function are the registers
read before they are written, in Watcom order. Everything it does not
understand is reported, not generated.

usage: python tools/compare/jumpout_gen.py [--fix] [sub_X ...]
"""
import glob
import re
import sys

sys.path.insert(0, 'tools/compare')
import lst_block  # noqa: E402
import protos  # noqa: E402

LST = 'C:/prenos/reorion2Data/diss/Orion2.exe.lst'
WAT = ['eax', 'edx', 'ebx', 'ecx']
R16 = {'ax': 'eax', 'dx': 'edx', 'bx': 'ebx', 'cx': 'ecx', 'si': 'esi', 'di': 'edi'}
R8 = {'al': 'eax', 'dl': 'edx', 'bl': 'ebx', 'cl': 'ecx'}
ALL = ['eax', 'edx', 'ebx', 'ecx', 'esi', 'edi']
fix = '--fix' in sys.argv
only = [a for a in sys.argv[1:] if a.startswith('sub_')]
LF, CRLF = b'\n', b'\r\n'

code, index = [], {}
for line in open(LST, encoding='utf-8', errors='replace'):
    m = re.match(r'cseg01:([0-9A-F]{8})\s{3,}(\S.*)$', line.rstrip('\n'))
    if not m:
        continue
    ins = m.group(2).split(';')[0].strip()
    if not ins:
        continue
    a = int(m.group(1), 16)
    pm = re.match(r'^(sub_[0-9A-F]+)\s+proc\b', ins)
    if pm:
        index['@' + pm.group(1)] = len(code)
        continue
    if re.match(r'^\w+\s+(endp|=)\b', ins):
        continue
    lm = re.match(r'^([\w$?@]+):$', ins)
    if lm:
        index.setdefault(a, len(code))
        continue
    index.setdefault(a, len(code))
    code.append((a, ins))

# port signatures: name -> number of parameters
nparams = {}
isvoid = set()
for p in glob.glob('src/game/orion_part_*.c'):
    for m in re.finditer(r'^([A-Za-z_][^\n;=(]*?)\b(sub_[0-9A-F]+)\s*\(([^;{]*)\)\s*\n\{', open(p, encoding='latin-1').read(), re.M):
        ps = [x for x in m.group(3).split(',') if x.strip() and x.strip() != 'void']
        nparams[m.group(2)] = len(ps)
        if re.match(r'^\s*(static\s+)?void\s*$', m.group(1)):
            isvoid.add(m.group(2))


DSEG_MACROS = set(re.findall(r'^#define (\w+) \(\*\(', open('src/game/orion_dseg.h', encoding='latin-1').read(), re.M))
CSEG_MACROS = set(re.findall(r'^#define (\w+) \(\*\(', open('src/game/orion_cseg.h', encoding='latin-1').read(), re.M))


def data_addr(nm):
    """C expression of a data label's address."""
    if nm in DSEG_MACROS or nm in CSEG_MACROS:
        return '(int)(intptr_t)&%s' % nm
    mm = re.search(r'_([0-9A-F]{5,6})$', nm)
    if mm and 0x178000 <= int(mm.group(1), 16) < 0x178000 + 0x5DCD0:
        return '(int)(intptr_t)(dseg + 0x%05X) /* %s */' % (int(mm.group(1), 16) - 0x178000, nm)
    return '(int)(intptr_t)&%s' % nm


class Fail(Exception):
    pass


def num(s):
    s = s.strip()
    if re.match(r'^-?[0-9A-F]+h$', s):
        v = int(s[:-1], 16)
    elif re.match(r'^-?\d+$', s):
        v = int(s)
    else:
        raise Fail('operand ' + s)
    if v >= 0x80000000:
        v -= 0x100000000
    return v


class Machine(object):
    def __init__(self):
        self.r = {}
        self.params = set()
        self.lines = []
        self.nv = 0

    def get(self, reg):
        if reg in R16:
            return '(int16_t)(%s)' % self.get(R16[reg])
        if reg in R8:
            return '(int8_t)(%s)' % self.get(R8[reg])
        if reg not in self.r:
            if reg in WAT:
                self.params.add(reg)
                return 'P_' + reg
            raise Fail('read of ' + reg)
        return self.r[reg]

    def val(self, op):
        op = op.strip()
        if op in ALL or op in R16 or op in R8:
            return self.get(op)
        m = re.match(r'^offset\s+([\w$?@]+)(?:\+([0-9A-F]+h|\d+))?$', op)
        if m:
            base = data_addr(lst_block.cname(m.group(1)))
            return base if not m.group(2) else '(%s + %d)' % (base, num(m.group(2)))
        m = re.match(r'^(?:(dword|word|byte) ptr )?([a-z]+_[0-9A-F]+)$', op)
        if m and not op.startswith(('sub_', 'loc_')):
            nm = lst_block.cname(m.group(2))
            kind = m.group(1) or {'dword': 'dword', 'word': 'word', 'byte': 'byte'}.get(nm.split('_')[0], 'dword')
            return {'dword': '(int)(intptr_t)%s', 'word': '(int16_t)%s', 'byte': '(uint8_t)%s'}[kind] % nm
        if '[' in op:
            kind, a = self.addr(op)
            return {'dword': '*(int *)(intptr_t)(%s)', 'word': '*(int16_t *)(intptr_t)(%s)',
                    'byte': '*(uint8_t *)(intptr_t)(%s)'}[kind] % a
        return str(num(op))

    def addr(self, op):
        """(size, C address expression) of a memory operand."""
        km = re.match(r'^(dword|word|byte) ptr (.*)$', op)
        kind = km.group(1) if km else 'dword'
        op = km.group(2) if km else op
        m = re.match(r'^(?:([a-z]+_[0-9A-F]+))?\[(.*)\]$', op)
        if not m:
            raise Fail('memory ' + op)
        parts = []
        if m.group(1):
            nm = lst_block.cname(m.group(1))
            parts.append(data_addr(nm))
            if not km:
                kind = {'dword': 'dword', 'word': 'word', 'byte': 'byte'}.get(m.group(1).split('_')[0], 'dword')
        for sign, term in re.findall(r'([+-]?)([^+-]+)', m.group(2)):
            term = term.strip()
            sm = re.match(r'^(\w+)\*(\d)$', term)
            if sm:
                parts.append('%s%s * %s' % ('- ' if sign == '-' else '', self.get(sm.group(1)), sm.group(2)))
            elif term in ALL:
                parts.append(('- ' if sign == '-' else '') + self.get(term))
            elif term.startswith(('var_', 'arg_')) or term in ('ebp', 'esp'):
                raise Fail('stack operand ' + op)
            else:
                parts.append(str(-num(term) if sign == '-' else num(term)))
        return kind, ' + '.join(parts)

    def store(self, dst, value):
        """Write to memory: a statement in the generated body."""
        if '[' in dst:
            kind, a = self.addr(dst)
            lhs = {'dword': '*(int *)(intptr_t)(%s)', 'word': '*(int16_t *)(intptr_t)(%s)',
                   'byte': '*(uint8_t *)(intptr_t)(%s)'}[kind] % a
        else:
            km = re.match(r'^(?:(dword|word|byte) ptr )?([a-z]+_[0-9A-F]+)$', dst)
            if not km:
                raise Fail('store ' + dst)
            lhs = lst_block.cname(km.group(2))
        self.lines.append((None, '%s = %s' % (lhs, value), None))

    def set(self, reg, expr):
        if reg in R16:
            raise Fail('16-bit write ' + reg)
        if len(expr) > 40 and not re.match(r'^\w+$', expr):
            self.nv += 1
            v = 't%d' % self.nv
            self.lines.append((v, expr, None))
            expr = v
        self.r[reg] = expr


def run(func):
    k = index.get('@' + func)
    if k is None:
        raise Fail('no proc')
    m = Machine()
    steps = 0
    last_call = None
    while True:
        steps += 1
        if steps > 60 or k >= len(code):
            raise Fail('too long')
        a, ins = code[k]
        k += 1
        mm = re.match(r'^(\w+)\s*(.*)$', ins)
        op, rest = mm.group(1), mm.group(2)
        ops = [x.strip() for x in rest.split(',')] if rest else []
        if op in ('push', 'pop', 'nop'):
            continue
        if op == 'retn':
            return m, last_call
        if op == 'jmp':
            t = re.match(r'^(?:short )?(loc_|locret_|sub_)([0-9A-F]+)$', rest)
            if not t:
                raise Fail('jmp ' + rest)
            k = index.get(int(t.group(2), 16))
            if k is None:
                raise Fail('jmp target')
            continue
        if op == 'call':
            cm = re.match(r'^(sub_[0-9A-F]+)$', rest)
            if not cm:
                raise Fail('call ' + rest)
            callee = cm.group(1)
            ps = protos.params(callee)
            if ps is not None and all(r for _, r in ps):
                regs = [r for _, r in ps]
            elif callee in nparams and nparams[callee] <= 4:
                regs = WAT[:nparams[callee]]
            else:
                raise Fail('callee ' + callee)
            if callee in nparams and len(regs) > nparams[callee]:
                regs = regs[:nparams[callee]]
            args = [m.get(r) for r in regs]
            if callee in isvoid:
                m.lines.append((None, '%s(%s)' % (callee, ', '.join(args)), callee))
                m.r.pop('eax', None)
                m.r['eax'] = '0 /* eax after void %s */' % callee
                continue
            m.nv += 1
            v = 'r%d' % m.nv
            m.lines.append((v, '%s(%s)' % (callee, ', '.join(args)), callee))
            m.r['eax'] = v
            last_call = v
            continue
        if op == 'cwde':
            m.set('eax', '(int16_t)(%s)' % m.get('eax'))
            continue
        if op == 'cdq':
            m.r['edx'] = 'CDQ(%s)' % m.get('eax')
            continue
        if op == 'imul' and len(ops) == 3:
            if ops[0] not in ALL:
                raise Fail(ins)
            m.set(ops[0], '(%s * %d)' % (m.val(ops[1]), num(ops[2])))
            continue
        if len(ops) != 2 and op not in ('inc', 'dec', 'neg'):
            raise Fail(ins)
        dst = ops[0]
        if op == 'mov' and dst not in ALL and dst not in R16 and dst not in R8:
            m.store(dst, m.val(ops[1]))
            continue
        if op == 'mov' and (dst in R16 or dst in R8):
            full = R16.get(dst) or R8[dst]
            if dst in R16:
                m.set(full, '((%s & ~0xFFFF) | (uint16_t)(%s))' % (m.get(full), m.val(ops[1])))
            else:
                m.set(full, '((%s & ~0xFF) | (uint8_t)(%s))' % (m.get(full), m.val(ops[1])))
            continue
        if dst not in ALL:
            raise Fail('dst ' + ins)
        if op == 'mov':
            m.set(dst, m.val(ops[1]))
        elif op in ('movsx', 'movzx'):
            src = ops[1]
            wide = src in R16 or 'word ptr' in src or (src.startswith('word_') and '[' in src)
            v = m.get(R16[src]) if src in R16 else m.get(R8[src]) if src in R8 else m.val(src)
            if op == 'movsx':
                m.set(dst, '(%s)(%s)' % ('int16_t' if wide else 'int8_t', v))
            else:
                m.set(dst, '(%s)(%s)' % ('uint16_t' if wide else 'uint8_t', v))
        elif op == 'xor' and ops[0] == ops[1]:
            m.set(dst, '0')
        elif op in ('add', 'sub', 'imul', 'and', 'or', 'shl', 'sar', 'shr'):
            sym = {'add': '+', 'sub': '-', 'imul': '*', 'and': '&', 'or': '|', 'shl': '<<', 'sar': '>>', 'shr': '>>'}[op]
            srcv = ops[1]
            if op == 'sub' and srcv == 'edx' and m.r.get('edx', '').startswith('CDQ('):
                m.set(dst, m.get(dst))     # cdq / sub eax, edx / sar eax, 1 = signed / 2
                m.r['_half'] = dst
                continue
            if op == 'sar' and m.r.get('_half') == dst and num(srcv) == 1:
                m.set(dst, '(%s) / 2' % m.get(dst))
                del m.r['_half']
                continue
            m.set(dst, '(%s %s %s)' % (m.get(dst), sym, m.val(srcv)))
        elif op in ('inc', 'dec'):
            m.set(dst, '(%s %s 1)' % (m.get(dst), '+' if op == 'inc' else '-'))
        elif op == 'lea':
            lm = re.match(r'^\[(\w+)(?:\+(\w+)(?:\*(\d))?)?(?:([+-])([0-9A-F]+h|\d+))?\]$', ops[1])
            if not lm:
                raise Fail(ins)
            e = m.get(lm.group(1))
            if lm.group(2):
                e = '%s + %s%s' % (e, m.get(lm.group(2)), ' * %s' % lm.group(3) if lm.group(3) else '')
            if lm.group(4):
                e = '%s %s %d' % (e, lm.group(4), num(lm.group(5)))
            m.set(dst, '(%s)' % e)
        else:
            raise Fail(ins)


class _Regen(object):
    """A function this tool generated before - regenerated in place."""

    def __init__(self, m):
        self.m = m

    def group(self, k):
        return {1: self.m.group('n2'), 3: self.m.group('t2')}[k]

    def start(self):
        return self.m.start()

    def end(self):
        return self.m.end()


def main():
    out = {}
    for p in sorted(glob.glob('src/game/orion_part_*.c')):
        t = open(p, encoding='latin-1').read()
        pat = (r'^[^\n;]*\b(sub_[0-9A-F]+)\s*\([^;{]*\)\s*\n\{\n((?:  [^\n]*\n)*?)  JUMPOUT\(0x([0-9A-F]+)\);\n\}\n'
               r'|^/\* wave 182: generated by tools/compare/jumpout_gen\.py - the original\n'
               r'   jumps into the tail at 0x(?P<t2>[0-9A-F]+) \*/\nint (?P<n2>sub_[0-9A-F]+)\([^\n]*\)\n\{\n.*?\n\}\n')
        for fm in re.finditer(pat, t, re.M | re.S):
            if fm.group('n2'):
                fm = _Regen(fm)
            name = fm.group(1)
            if only and name not in only:
                continue
            try:
                m, res = run(name)
            except Fail as e:
                print('-- %s: %s' % (name, e))
                continue
            regs = [r for r in WAT if r in m.params]
            if regs:
                regs = WAT[:WAT.index(regs[-1]) + 1]
            names = dict((r, 'a%d' % (i + 1)) for i, r in enumerate(regs))
            body = [(v, call) for v, call, callee in m.lines]
            text = []
            sig = 'int %s(%s)' % (name, ', '.join('int %s' % names[r] for r in regs) or 'void')
            text.append('/* wave 182: generated by tools/compare/jumpout_gen.py - the original')
            text.append('   jumps into the tail at 0x%s */' % fm.group(3))
            text.append(sig)
            text.append('{')
            used = [v for v, _ in body if v]
            for v in used:
                text.append('  int %s;' % v)
            if used:
                text.append('')
            for v, call in body:
                text.append('  %s = %s;' % (v, call) if v else '  %s;' % call)
            ret = m.r.get('eax', '0')
            text.append('  return %s;' % ret)
            text.append('}')
            src = '\n'.join(text) + '\n'
            for r, n in names.items():
                src = src.replace('P_' + r, n)
            if 'P_' in src:
                print('-- %s: undeclared register' % name)
                continue
            print('%s: %s' % (name, ' ; '.join(c for _, c in body)))
            out.setdefault(p, []).append((fm.start(), fm.end(), src, name, sig))
    if fix:
        hdr = open('src/game/orion_common.h', encoding='latin-1').read()
        for p, items in out.items():
            raw = open(p, 'rb').read()
            crlf = CRLF in raw
            t = raw.replace(CRLF, LF).decode('latin-1')
            for s, e, src, name, sig in sorted(items, reverse=True):
                t = t[:s] + src + t[e:]
                hdr = re.sub(r'^(extern )?[^\n;(]*\b%s\s*\([^;\n]*\);' % name, lambda mm: (mm.group(1) or '') + sig + ';', hdr, flags=re.M)
            b = t.encode('latin-1')
            open(p, 'wb').write(b.replace(LF, CRLF) if crlf else b)
        open('src/game/orion_common.h', 'w', encoding='latin-1', newline='').write(hdr)
    print('generated %d' % sum(len(v) for v in out.values()))


if __name__ == '__main__':
    main()
