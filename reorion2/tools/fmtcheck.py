# -*- coding: ascii -*-
"""
Hleda chybu z vlny 93: `%s` ve formatu, kteremu port posila `int`.

Na x64 se `int` do varargs slotu ulozi jen dolni polovinou a horni zustane po
predchozim zapisu, takze `%s` dostane "skoro platny" ukazatel (typicky
0x00007FF*_xxxxxxxx) a hra spadne uvnitr vsprintf.

Formatovaci retezce se berou PRIMO Z HERNICH DAT (ESTRINGS.LBX, zaznam 0,
retezce oddelene nulou, prvni 4 bajty zaznamu jsou hlavicka) - stejne, jako je
za behu cte `sub_CDF5C(n) = dword_1A6578[n]`.

Pouziti:  python tools/fmtcheck.py [cesta_k_ESTRINGS.LBX]
"""
import os, re, struct, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, "src", "game")
LBX = sys.argv[1] if len(sys.argv) > 1 else r"C:\prenos\mastori2\ESTRINGS.LBX"

def load_formats(path):
    d = open(path, "rb").read()
    cnt = struct.unpack_from("<H", d, 0)[0]
    offs = [struct.unpack_from("<I", d, 8 + 4 * i)[0] for i in range(cnt + 1)]
    body = d[offs[0] + 4:offs[1]]
    out, i = [], 0
    while i < len(body):
        j = body.find(b"\x00", i)
        if j < 0:
            break
        out.append(body[i:j].decode("latin-1"))
        i = j + 1
    return out

def specifiers(fmt):
    """vrati seznam typu konverzi v poradi ('s', 'd', ...)"""
    return [m.group(1) for m in re.finditer(r"%[-+ #0]*[0-9*]*(?:\.[0-9*]+)?(?:hh|h|ll|l|L)?([diouxXeEfgGaAcspn%])", fmt)
            if m.group(1) != "%"]

def split_args(s):
    """rozdeli seznam argumentu na nejvyssi urovni zavorek"""
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch in "([": depth += 1
        elif ch in ")]": depth -= 1
        if ch == "," and depth == 0:
            out.append(cur.strip()); cur = ""
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out

PTRISH = re.compile(r'^\s*(\(\s*(char|const char|_BYTE|uint8_t|void)\s*\*\s*\)|&|"|\(char \*\)\(intptr_t\))')

def main():
    fmts = load_formats(LBX)
    print("nacteno %d formatovacich retezcu z %s" % (len(fmts), os.path.basename(LBX)))
    hits = 0
    for fn in sorted(os.listdir(SRC)):
        if not fn.startswith("orion_part") or not fn.endswith(".c"):
            continue
        text = open(os.path.join(SRC, fn), encoding="latin-1").read()
        lines = text.split("\n")
        # typy lokalek v cele funkci staci hledat zpetne v souboru
        for i, line in enumerate(lines):
            m = re.search(r"sprintf\(\s*([^,]+),\s*([A-Za-z_][A-Za-z_0-9]*)\s*,(.*)\);", line)
            if not m:
                continue
            fmtvar, arglist = m.group(2), m.group(3)
            # najdi prirazeni `fmtvar = (char *)sub_CDF5C(N);` vyse ve funkci
            idx = None
            for k in range(i - 1, max(0, i - 60), -1):
                mm = re.search(re.escape(fmtvar) + r"\s*=\s*\(char \*\)sub_CDF5C\((\d+)\)", lines[k])
                if mm:
                    idx = int(mm.group(1)); break
                if lines[k].startswith("//----- ("):
                    break
            if idx is None or idx >= len(fmts):
                continue
            spec = specifiers(fmts[idx])
            args = split_args(arglist)
            for pos, (sp, arg) in enumerate(zip(spec, args)):
                if sp != "s" or PTRISH.match(arg):
                    continue
                # je to lokalka typu int?
                decl = None
                for k in range(i, max(0, i - 400), -1):
                    dm = re.search(r"^\s*(int|int16_t|unsigned int|__int16)\s+" + re.escape(arg) + r"\s*;", lines[k])
                    if dm:
                        decl = dm.group(1); break
                    if lines[k].startswith("//----- ("):
                        break
                if decl:
                    hits += 1
                    print("%s:%d  format #%d  arg %d (`%s`, typ %s) jde do %%s" %
                          (fn, i + 1, idx, pos + 1, arg, decl))
                    print("      \"%s\"" % fmts[idx][:70])
    print("\npodezrelych mist: %d" % hits)

main()
