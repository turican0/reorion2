"""Vzorec "skladani retezce pres sousedni lokalku" - hledani a oprava.

Original: EDI ukazuje na bajt TESNE PRED bufferem, `inc edi` ho posune na jeho
zacatek. IDA to prelozila jako `vX = &vBASE;` (pripadne `+N`), kde `vBASE` je
jina lokalka - v originale s bufferem sousedi, na x64 uz ne.

Spravny cil jde dopocitat: u kazde lokalky mame v komentari posun od ebp,
takze cil je ta lokalka, ktera lezi presne na `offset(vBASE) + N + 1`.

Pouziti: fix_strappend.py <soubor.c> ... [--apply]
"""
import re, sys

DECL = re.compile(r'^\s*[A-Za-z_][\w \*]*?\b(\w+)\s*(\[[^\]]*\])?\s*;\s*//\s*\[esp[^\]]*\]\s*\[ebp([+-])([0-9A-Fa-f]+)h\]')
ASSIGN = re.compile(r'^(\s*)(\w+) = (?:\((?:char|_BYTE|uint8_t) \*\))?&(\w+)(?:\s*\+\s*(\d+))?;\s*$')
FUNC = re.compile(r'^[A-Za-z_].*\b(sub_[0-9A-F]+|GameMain_\w+)\s*\(')

def scan(path, apply=False):
    raw = open(path, 'rb').read()
    nl = '\r\n' if b'\r\n' in raw else '\n'
    lines = raw.decode('latin-1').split(nl)
    starts = [i for i, l in enumerate(lines) if FUNC.match(l)] + [len(lines)]
    ok = amb = 0
    for fi in range(len(starts) - 1):
        a, b = starts[fi], starts[fi + 1]
        offs, isarr = {}, {}
        for i in range(a, min(a + 250, b)):
            m = DECL.match(lines[i])
            if m:
                offs[m.group(1)] = (-1 if m.group(3) == '-' else 1) * int(m.group(4), 16)
                isarr[m.group(1)] = m.group(2) is not None
        for i in range(a, b - 3):
            m = ASSIGN.match(lines[i])
            if not m: continue
            var = m.group(2)
            if not (lines[i+1].strip() == 'do' and lines[i+2].strip() == '++%s;' % var
                    and lines[i+3].strip().startswith('while ( *%s );' % var)):
                continue
            base, plus = m.group(3), int(m.group(4) or 0)
            if base not in offs: continue
            want = offs[base] + plus + 1
            cand = [n for n, o in offs.items() if o == want]
            if len(cand) != 1 or not isarr.get(cand[0]):
                print(f'{path}:{i+1}  {var} = &{base}+{plus} -> ebp{want:+#x}: {cand or "nic"}'
                      f'{"" if cand else ""} NEJEDNOZNACNE/NENI POLE'); amb += 1; continue
            tgt = cand[0]
            print(f'{path}:{i+1}  {var} = &{base}+{plus}  ->  {tgt} - 1')
            if apply:
                lines[i] = (f'{m.group(1)}{var} = (char *){tgt} - 1;'
                            f'   /* vlna 124: cil je sousedni buffer {tgt}, ne &{base} */')
            ok += 1
    if apply:
        open(path, 'wb').write(nl.join(lines).encode('latin-1'))
    return ok, amb

if __name__ == '__main__':
    files = [x for x in sys.argv[1:] if not x.startswith('--')]
    ap = '--apply' in sys.argv
    to = ta = 0
    for f in files:
        o, a = scan(f, ap); to += o; ta += a
    print(f'=== jednoznacnych {to}, nejasnych {ta} ===')
