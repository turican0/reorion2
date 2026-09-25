"""Replace `JUMPOUT(tail)` by `return X;` where the shared tail only moves a
value into EAX and returns (wave 181: sub_DC323 / sub_DC416 -> loc_DC31D
`mov eax, edx`; sub_6478D -> loc_63E00 `mov eax, ebx`).

X is found from the Hex-Rays declaration comments:
    mov eax, edx        -> the only local declared `// edx`
    mov eax, [ebp+var_C] -> the local declared `[ebp-Ch]`
    mov al, bh          -> the only local declared `// bh`
    xor eax, eax        -> 0
A void function becomes int (char for `mov al, ...`), the prototypes in
orion_common.h follow. Ambiguous cases are only reported.

usage: python tools/compare/jumpout_values.py [--fix]
"""
import glob
import re
import sys

sys.path.insert(0, 'tools/compare')
import jumpout_tails as J  # noqa: E402  (builds the code map on import)

EPI = J.EPI
fix = '--fix' in sys.argv
LF, CRLF = b'\n', b'\r\n'
done, skipped = 0, []
retypes = {}

for p in sorted(glob.glob('src/game/orion_part_*.c')):
    raw = open(p, 'rb').read()
    crlf = CRLF in raw
    t = raw.replace(CRLF, LF).decode('latin-1')
    changed = False
    funcs = list(re.finditer(r'^([A-Za-z_][^\n;=(]*?)\b(sub_[0-9A-F]+)\s*\(([^;{]*)\)\s*\n\{', t, re.M))
    for m in reversed(funcs):
        s = m.end()
        e = t.index('\n}\n', s)
        f = t[s:e]
        if 'JUMPOUT(' not in f:
            continue
        rettype, name = m.group(1).strip(), m.group(2)
        decls = f[:f.index('\n\n')] if '\n\n' in f else ''
        newret = None
        f2 = f
        for jm in reversed(list(re.finditer(r'JUMPOUT\(0x([0-9A-F]+)\);', f))):
            tail = J.tail(int(jm.group(1), 16))
            if J.classify(tail) != 'value':
                continue
            first = tail[0]
            val, kind = None, 'int'
            mm = re.match(r'^mov\s+eax, (ebx|ecx|edx|esi|edi)$', first)
            if mm:
                r32 = mm.group(1)
                names = {r32, r32[1:]} | ({r32[1] + 'l'} if r32 in ('ebx', 'ecx', 'edx') else set())
                vs = [v for v, reg in re.findall(r'\b(v\d+|result|i|j|k); // (\w+)\s*$', decls, re.M) if reg in names]
                val = vs[0] if len(vs) == 1 else None
            mm = re.match(r'^mov\s+al, (\d+)$', first)
            if mm:
                val, kind = mm.group(1), 'char'
            if re.match(r'^xor\s+al, al$', first):
                val, kind = '0', 'char'
            mm = re.match(r'^mov\s+eax, offset (\w+)$', first)
            if mm:
                n = mm.group(1)
                m2 = re.match(r'^([a-z]+)_([0-9A-F]+)$', n)
                cn = '%s_%X' % (m2.group(1), int(m2.group(2), 16) + 0x8000) if m2 else n
                val = '(int)(intptr_t)&%s' % cn
            mm = re.match(r'^mov\s+eax, \[ebp\+var_([0-9A-F]+)\]$', first)
            if mm:
                vs = re.findall(r'\b(v\d+)(?:\[\d+\])?; // \[esp[^\]]*\] \[ebp-%sh\]' % mm.group(1), decls)
                val = vs[0] if len(vs) == 1 else None
            mm = re.match(r'^mov\s+al, (bl|bh|cl|ch|dl|dh)$', first)
            if mm:
                vs = re.findall(r'\b(v\d+); // %s\b' % mm.group(1), decls)
                val = vs[0] if len(vs) == 1 else None
                kind = 'char'
            if re.match(r'^xor\s+eax, eax$', first):
                val = '0'
            if val is None or len(tail) > 1 and not all(EPI.match(x) for x in tail[1:]):
                skipped.append('%s %s -> %s: %s' % (p.split('\\')[-1], name, jm.group(1), ' / '.join(tail[:2])))
                continue
            f2 = f2[:jm.start()] + 'return %s;   /* wave 181: tail loc_%s `%s` */' % (val, jm.group(1), first) + f2[jm.end():]
            newret = newret or kind
            done += 1
            print('%s %s: JUMPOUT(0x%s) -> return %s' % (p.split('\\')[-1], name, jm.group(1), val))
        if f2 != f and fix:
            head = t[m.start():m.end()]
            if rettype == 'void' and newret:
                head = head.replace('void ' + name, newret + ' ' + name, 1)
                retypes[name] = newret
            t = t[:m.start()] + head + f2 + t[e:]
            changed = True
    if changed:
        b = t.encode('latin-1')
        open(p, 'wb').write(b.replace(LF, CRLF) if crlf else b)

if fix and retypes:
    p = 'src/game/orion_common.h'
    raw = open(p, 'rb').read()
    crlf = CRLF in raw
    t = raw.replace(CRLF, LF).decode('latin-1')
    for name, typ in retypes.items():
        t = re.sub(r'\b(extern )?void %s\(' % name, lambda mm: (mm.group(1) or '') + typ + ' ' + name + '(', t)
    b = t.encode('latin-1')
    open(p, 'wb').write(b.replace(LF, CRLF) if crlf else b)
print('replaced: %d, retyped: %d, skipped: %d' % (done, len(retypes), len(skipped)))
for s in skipped:
    print('  skipped ' + s)
