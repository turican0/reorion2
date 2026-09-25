"""Register arguments that the prologue saves on the stack and Hex-Rays
turned into never-assigned locals.

    enter N, 0 / push eax / push edx ... [/ sub ebp, M]

puts EAX at [ebp-N-4], EDX at [ebp-N-8], ... ; the port declares a local at
that offset (the comment shows [ebp-(N+4k-M)]) and never assigns it
(waves 166, 174, 179, 181: sub_89183, sub_A2123, sub_1089C6, sub_D896F,
sub_D87BB). The fix is `vN = aK;` where aK is the parameter in that register
(Watcom: eax, edx, ebx, ecx).

usage: python tools/compare/phantom_args.py [--fix]
"""
import glob
import re
import sys

sys.path.insert(0, 'tools/compare')
import protos  # noqa: E402

LST ='C:/prenos/reorion2Data/diss/Orion2.exe.lst'
REG_ARG = {'eax': 1, 'edx': 2, 'ebx': 3, 'ecx': 4}

pro = {}
cur, state, enter_n, pushes = None, 0, 0, []
for line in open(LST, encoding='utf-8', errors='replace'):
    m = re.match(r'cseg01:([0-9A-F]{8})\s{3,}(\S.*)$', line.rstrip('\n'))
    if not m:
        continue
    body = m.group(2).split(';')[0].strip()
    pm = re.match(r'^(sub_[0-9A-F]+)\s+proc\b', body)
    if pm:
        cur, state, pushes = pm.group(1), 0, []
        continue
    if not cur or not body or re.match(r'^\w+\s+=\s', body):
        continue
    if state == 0:
        em = re.match(r'^enter\s+(\w+),\s*0$', body)
        if em:
            v = em.group(1)
            enter_n = int(v[:-1], 16) if v.endswith('h') else int(v)
            state = 1
        elif not body.startswith('push'):
            cur = None
        continue
    if state == 1:
        pu = re.match(r'^push\s+(eax|edx|ebx|ecx)$', body)
        if pu:
            pushes.append(pu.group(1))
            continue
        sm = re.match(r'^sub\s+ebp,\s*(\w+)$', body)
        sub = 0
        if sm:
            v = sm.group(1)
            sub = int(v[:-1], 16) if v.endswith('h') else int(v)
        if pushes:
            pro[cur] = [(r, enter_n + 4 * (i + 1) - sub) for i, r in enumerate(pushes)]
        cur = None

fix = '--fix' in sys.argv
LF, CRLF = b'\n', b'\r\n'
found = 0
for p in sorted(glob.glob('src/game/orion_part_*.c')):
    raw = open(p, 'rb').read()
    crlf = CRLF in raw
    t = raw.replace(CRLF, LF).decode('latin-1')
    changed = False
    # from the end of the file, so that an insertion never shifts a function
    # that is still to be processed
    for m in reversed(list(re.finditer(r'^[A-Za-z_][^\n;=]*?\b(sub_[0-9A-F]+)\s*\(([^;{]*)\)\s*\n\{', t, re.M))):
        name = m.group(1)
        if name not in pro:
            continue
        s = m.end()
        e = t.index('\n}\n', s)
        f = t[s:e]
        f0 = f
        params = [x.strip() for x in m.group(2).split(',') if x.strip() and x.strip() != 'void']
        pnames = [re.findall(r'(\w+)\s*$', x)[0] if re.findall(r'(\w+)\s*$', x) else '' for x in params]
        for reg, off in pro[name]:
            if off <= 0:
                continue
            dm = re.search(r'^\s+[^;\n]*?\b(v\d+)(\[\d+\])?; // \[esp[^\]]*\] \[ebp-%Xh\]' % off, f, re.M)
            if not dm:
                continue
            v = dm.group(1)
            lhs = v + ('[0]' if dm.group(2) else '')   # the slot is the first element of an array
            # the prologue stores the register there on entry, whatever the
            # function does with the slot later - only skip if already done
            # the parameter in that register, from the original prototype
            # (protos.py); Watcom order only when no prototype is known
            if protos.params(name) is not None:
                arg = protos.param_of(name, reg)
                if arg and arg not in pnames:
                    arg = None
            else:
                k = REG_ARG[reg]
                arg = pnames[k - 1] if k - 1 < len(pnames) else None
            if arg and re.search(r'^\s+%s(\[0\])? = %s;' % (v, arg), f, re.M):
                continue
            if not arg and re.search(r'\b%s\s*=[^=]' % v, f):
                continue
            found += 1
            print('%s %s: %s = %s (%s, [ebp-%Xh])%s' % (p.split('\\')[-1], name, v, arg, reg, off,
                                                       '' if arg else '  <-- no such parameter'))
            if fix and arg:
                decl_end = f.index('\n\n') + 2
                f = f[:decl_end] + '  %s = %s;   /* wave 181: %s saved by the prologue (push %s) */\n' % (lhs, arg, v, reg) + f[decl_end:]
        if f != f0:
            t = t[:s] + f + t[e:]
            changed = True
    if changed:
        b = t.encode('latin-1')
        open(p, 'wb').write(b.replace(LF, CRLF) if crlf else b)
print('found: %d' % found)
