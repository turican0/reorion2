#!/usr/bin/env python3
"""
Autofix pro pripady, kdy Hex-Rays vygeneroval pro tutez funkci/ukazatel na
funkci volani s jinym poctem argumentu, nez rika prototyp VIDITELNY v tom
istem souboru (typicky primo za definici, kde uz plati presny typ misto
volneho K&R). Reseni: na danem konkretnim radku prevedeme volani na cast
pres genericky ukazatel na funkci, cimz obejdeme kontrolu poctu parametru
- presne totez, co ostatnim volani v jinych souborech dovoluje projit K&R
deklarace v common.h.
"""
import re, subprocess, sys, os

OUT = "out"
os.chdir(OUT)

ERR_RE = re.compile(r'^([^:]+):(\d+):\d+: error: too (?:few|many) arguments to function .([^\'’]+).')

def get_rettype(name):
    # zkus najit v orion_common.h bud "// plna signatura: RETTYPE ... NAME(" nebo primo extern radek
    with open("orion_common.h") as f:
        text = f.read()
    m = re.search(r'// plna signatura: (.*?)\b' + re.escape(name) + r'\s*\(', text)
    if m:
        return m.group(1).strip()
    m = re.search(r'extern (.*?)\(\s*\*+\s*' + re.escape(name) + r'\s*\)', text)
    if m:
        return m.group(1).strip()
    m = re.search(r'extern (.*?)\b' + re.escape(name) + r'\s*\(', text)
    if m:
        return m.group(1).strip()
    return 'int'

def compile_all():
    errs = []
    files = sorted([f for f in os.listdir('.') if f.endswith('.c')] + ['orion_common.h'])
    for f in files:
        r = subprocess.run(['gcc', '-fsyntax-only', '-std=gnu11', '-fno-builtin', '-w', '-I.', f],
                            capture_output=True, text=True)
        for line in r.stderr.splitlines():
            m = ERR_RE.match(line)
            if m:
                errs.append((m.group(1), int(m.group(2)), m.group(3)))
    return errs

patched = set()
for round_ in range(4):
    errs = compile_all()
    arity_errs = errs
    if not arity_errs:
        print(f"Round {round_}: no more arity errors")
        break
    print(f"Round {round_}: {len(arity_errs)} arity errors")
    by_file = {}
    for fname, lineno, symname in arity_errs:
        by_file.setdefault(fname, []).append((lineno, symname))
    for fname, items in by_file.items():
        with open(fname) as f:
            lines = f.readlines()
        for lineno, symname in items:
            idx = lineno - 1
            if idx >= len(lines):
                continue
            line = lines[idx]
            key = (fname, lineno, symname)
            pat = re.compile(r'(?<![\w.])' + re.escape(symname) + r'\s*\(')
            if not pat.search(line):
                continue
            rettype = get_rettype(symname)
            cast = f"(({rettype}(*)())(void*){symname})("
            # nahrad jen prvni vyskyt na radku
            new_line, n = pat.subn(lambda m: cast, line, count=1)
            if n:
                lines[idx] = new_line
                patched.add(key)
        with open(fname, 'w') as f:
            f.writelines(lines)

print(f"Celkem zapatchovanych mist: {len(patched)}")
for k in sorted(patched):
    print("  ", k)

# ---------- faze 2: symboly pouzite jako pole (indexovane) i jako skalar
# (bez indexu) - Hex-Rays nekonzistence pri prekryvajicich se datech.
# Oprava: na danem konkretnim radku pridej [0]. ----------
INCOMPLETE_RE = re.compile(r"^([^:]+):(\d+):\d+: error: .([A-Za-z_]\w*). has an incomplete type")
ARRASSIGN_RE = re.compile(r"^([^:]+):(\d+):\d+: error: assignment to expression with array type")

def compile_all2():
    errs = []
    files = sorted([f for f in os.listdir('.') if f.endswith('.c')] + ['orion_common.h'])
    for f in files:
        r = subprocess.run(['gcc', '-fsyntax-only', '-std=gnu11', '-fno-builtin', '-w', '-I.', f],
                            capture_output=True, text=True)
        for line in r.stderr.splitlines():
            m = INCOMPLETE_RE.match(line)
            if m:
                errs.append((m.group(1), int(m.group(2)), m.group(3)))
                continue
            m = ARRASSIGN_RE.match(line)
            if m:
                errs.append((m.group(1), int(m.group(2)), None))
    return errs

patched2 = set()
for round_ in range(4):
    errs = compile_all2()
    if not errs:
        print(f"Round {round_} (faze 2): no more errors")
        break
    print(f"Round {round_} (faze 2): {len(errs)} errors")
    by_file = {}
    for fname, lineno, symname in errs:
        by_file.setdefault(fname, []).append((lineno, symname))
    for fname, items in by_file.items():
        with open(fname) as f:
            lines = f.readlines()
        for lineno, symname in items:
            idx = lineno - 1
            if idx >= len(lines):
                continue
            line = lines[idx]
            if symname is None:
                m = re.match(r'^(\s*)([A-Za-z_]\w*)\s*=', line)
                if not m:
                    continue
                symname = m.group(2)
            pat = re.compile(r'(?<![\w\[])' + re.escape(symname) + r'(?!\s*\[)\b')
            new_line, n = pat.subn(symname + '[0]', line, count=1)
            if n:
                lines[idx] = new_line
                patched2.add((fname, lineno, symname))
        with open(fname, 'w') as f:
            f.writelines(lines)

print(f"Faze 2 - celkem zapatchovanych mist: {len(patched2)}")
for k in sorted(patched2):
    print("  ", k)

# ---------- faze 3: subscript na hodnotu s typem "ukazatel na funkci"
# (symbol pouzivany jinde i jako byte pole) ----------
SUBSCR_FUNC_RE = re.compile(r"^([^:]+):(\d+):(\d+): error: subscripted value is pointer to function")

def compile_all3():
    errs = []
    files = sorted([f for f in os.listdir('.') if f.endswith('.c')] + ['orion_common.h'])
    for f in files:
        r = subprocess.run(['gcc', '-fsyntax-only', '-std=gnu11', '-fno-builtin', '-w', '-I.', f],
                            capture_output=True, text=True)
        for line in r.stderr.splitlines():
            m = SUBSCR_FUNC_RE.match(line)
            if m:
                errs.append((m.group(1), int(m.group(2))))
    return errs

patched3 = set()
for round_ in range(3):
    errs = compile_all3()
    if not errs:
        print(f"Round {round_} (faze 3): no more errors")
        break
    by_file = {}
    for fname, lineno in errs:
        by_file.setdefault(fname, []).append(lineno)
    for fname, linenos in by_file.items():
        with open(fname) as f:
            lines = f.readlines()
        for lineno in linenos:
            idx = lineno - 1
            if idx >= len(lines):
                continue
            line = lines[idx]
            m = re.search(r'([A-Za-z_]\w*)\s*\[', line)
            if not m:
                continue
            sym = m.group(1)
            pat = re.compile(r'(?<![\w.])' + re.escape(sym) + r'(?=\s*\[)')
            new_line, n = pat.subn(f'((unsigned char*){sym})', line, count=1)
            if n:
                lines[idx] = new_line
                patched3.add((fname, lineno, sym))
        with open(fname, 'w') as f:
            f.writelines(lines)

print(f"Faze 3 - celkem zapatchovanych mist: {len(patched3)}")
for k in sorted(patched3):
    print("  ", k)

# ---------- faze 4: odecet dvou ukazatelu nekompatibilniho typu
# (napr. char* a _BYTE*) - cast praveho operandu na typ leveho ----------
BINSUB_RE = re.compile(
    r"^([^:]+):(\d+):(\d+): error: invalid operands to binary -"
    r" \(have .([^'’]+). and .([^'’]+)."
)

def compile_all4():
    errs = []
    files = sorted([f for f in os.listdir('.') if f.endswith('.c')] + ['orion_common.h'])
    for f in files:
        r = subprocess.run(['gcc', '-fsyntax-only', '-std=gnu11', '-fno-builtin', '-w', '-I.', f],
                            capture_output=True, text=True)
        for line in r.stderr.splitlines():
            m = BINSUB_RE.match(line)
            if m:
                errs.append((m.group(1), int(m.group(2)), int(m.group(3)), m.group(4)))
    return errs

patched4 = set()
for round_ in range(3):
    errs = compile_all4()
    if not errs:
        print(f"Round {round_} (faze 4): no more errors")
        break
    by_file = {}
    for fname, lineno, col, lhs_type in errs:
        by_file.setdefault(fname, []).append((lineno, col, lhs_type))
    for fname, items in by_file.items():
        with open(fname) as f:
            lines = f.readlines()
        for lineno, col, lhs_type in items:
            idx = lineno - 1
            if idx >= len(lines):
                continue
            line = lines[idx]
            # najdi '-' co nejblize sloupci col (1-indexovano)
            best = None
            for i, ch in enumerate(line):
                if ch == '-' and (i == 0 or line[i-1] != '-') and (i+1 >= len(line) or line[i+1] != '-'):
                    if best is None or abs(i - (col-1)) < abs(best - (col-1)):
                        best = i
            if best is None:
                continue
            # RHS operand: od 'best+1' do konce vyrazu (dalsi ; , ) na stejne urovni)
            rhs_start = best + 1
            depth = 0
            rhs_end = len(line)
            for i in range(rhs_start, len(line)):
                c = line[i]
                if c in '([': depth += 1
                elif c in ')]':
                    if depth == 0:
                        rhs_end = i; break
                    depth -= 1
                elif c in ';,' and depth == 0:
                    rhs_end = i; break
            rhs = line[rhs_start:rhs_end]
            new_rhs = f' ({lhs_type})({rhs.strip()})'
            new_line = line[:rhs_start] + new_rhs + line[rhs_end:]
            lines[idx] = new_line
            patched4.add((fname, lineno))
        with open(fname, 'w') as f:
            f.writelines(lines)

print(f"Faze 4 - celkem zapatchovanych mist: {len(patched4)}")
for k in sorted(patched4):
    print("  ", k)
