"""Check the lines inserted by phantom_args.py and int16_params.py against
the register of each parameter in the original prototypes (protos.py).

  vN = aK;   /* ... saved by the prologue (push REG) */   aK must be in REG
  aK = (int16_t)aK;   /* ... low word (movsx) */           checked by int16_params

With --fix, a wrong phantom line is re-pointed to the parameter that really
is in REG, or removed when no parameter is in REG; wrong int16 lines are
removed (int16_params.py re-adds the right ones).

usage: python tools/compare/verify_regmap.py [--fix]
"""
import glob
import re
import sys

import protos

WATCALL = ['eax', 'edx', 'ebx', 'ecx']
fix = '--fix' in sys.argv
LF, CRLF = b'\n', b'\r\n'
bad = 0
FUNC = re.compile(r'^[A-Za-z_][^\n;=(]*?\b(sub_[0-9A-F]+)\s*\(', re.M)
for p in sorted(glob.glob('src/game/orion_part_*.c')):
    raw = open(p, 'rb').read()
    crlf = CRLF in raw
    t = raw.replace(CRLF, LF).decode('latin-1')
    heads = [(m.start(), m.group(1)) for m in FUNC.finditer(t)]
    out = []
    pos = 0
    changed = False
    for m in re.finditer(r'^  (\w+)(\[0\])? = (a\d+);   /\* wave 181: \w+ saved by the prologue \(push (\w+)\) \*/\n', t, re.M):
        func = [n for s, n in heads if s < m.start()][-1]
        reg = m.group(4)
        want = protos.param_of(func, reg)
        if protos.params(func) is None or want == m.group(3):
            continue
        bad += 1
        print('%s %s: %s = %s, but %s is %s' % (p.split('\\')[-1], func, m.group(1), m.group(3), reg,
                                                  want or 'not a parameter'))
        out.append(t[pos:m.start()])
        if want:
            out.append(m.group(0).replace(' = %s;' % m.group(3), ' = %s;' % want, 1))
        pos = m.end()
        changed = True
    out.append(t[pos:])
    t2 = ''.join(out)
    out, pos = [], 0
    heads = [(m.start(), m.group(1)) for m in FUNC.finditer(t2)]
    for m in re.finditer(r'^  (a(\d+)) = \(int16_t\)a\d+;   /\* wave 181: the original reads only the low word \(movsx\) \*/\n', t2, re.M):
        func = [n for s, n in heads if s < m.start()][-1]
        k = int(m.group(2))
        real = protos.reg_of(func, m.group(1))
        if protos.params(func) is None or real in WATCALL:
            continue      # int16_params.py checked the movsx of that register
        bad += 1
        print('%s %s: %s assumed in %s, really %s' % (p.split('\\')[-1], func, m.group(1), assumed, real))
        out.append(t2[pos:m.start()])
        pos = m.end()
        changed = True
    out.append(t2[pos:])
    t2 = ''.join(out)
    if changed and fix:
        b = t2.encode('latin-1')
        open(p, 'wb').write(b.replace(LF, CRLF) if crlf else b)
print('wrong: %d' % bad)
