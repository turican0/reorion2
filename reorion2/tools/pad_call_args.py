# -*- coding: ascii -*-
"""
Doplni chybejici argumenty na volanich, ktera prekladac oznacil jako
"moc maly pocet argumentu" (C2198).

Proc to jde: jde o funkce, ktere v originale bezi na REGISTROVE konvenci a
volajici casto nastavil jen prvni registr - zbytek si funkce precetla jako
"co tam zbylo". Na x64 to reprodukovat nejde a `ServiceAudioTick_FE8BE`
(hlavni takova funkce) ma v komentari uz od drivejska zavedenou konvenci:
doplnit explicitni nuly. Do vlny 105 se to delalo rucne, protoze prazdne
zavorky `extern T f();` v hlavicce zadnou kontrolu nedelaly - ted uz ano.

Vstup: build log s chybami C2198.
Pouziti:  python tools/pad_call_args.py <build.log> [--apply]
"""
import os, re, sys

ROOT = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "src", "game")
LOG = sys.argv[1]
APPLY = "--apply" in sys.argv

def split_args(s):
    """rozdel seznam argumentu podle zavorek nejvyssi urovne"""
    out, depth, cur = [], 0, ""
    for ch in s:
        if ch in "([": depth += 1
        elif ch in ")]": depth -= 1
        if ch == "," and depth == 0:
            out.append(cur); cur = ""
        else:
            cur += ch
    out.append(cur)
    return out

sites = {}   # (soubor, radek) -> (jmeno, pocet_parametru)
for line in open(LOG, encoding="latin-1", errors="replace"):
    key = "error C2198: "
    if key not in line:
        continue
    left, right = line.split(key, 1)
    left = left.strip().rstrip(")")
    if "(" not in left:
        continue
    path, pos = left.rsplit("(", 1)
    fn = path.split("\\")[-1]
    ln = int(pos.split(",")[0])
    decl = right.split(": ", 1)[0]
    name = decl.split("(", 1)[0].split()[-1].lstrip("*")
    params = decl[decl.index("(") + 1:decl.rindex(")")]
    want = 0 if params.strip() in ("", "void") else len(split_args(params))
    sites[(fn, ln)] = (name, want)

byfile = {}
for (fn, ln), v in sites.items():
    byfile.setdefault(fn, []).append((ln, v))

total = 0
for fn, items in sorted(byfile.items()):
    p = os.path.join(ROOT, fn)
    data = open(p, "rb").read().decode("latin-1")
    nl = "\r\n" if "\r\n" in data else "\n"
    lines = data.split(nl)
    changed = 0
    for ln, (name, want) in sorted(items):
        idx = ln - 1
        if idx >= len(lines) or (name + "(") not in lines[idx]:
            print("  ! %s:%d nenalezeno volani %s" % (fn, ln, name))
            continue
        s = lines[idx]
        start = s.index(name + "(") + len(name)
        j, depth = start + 1, 1
        while j < len(s) and depth:
            if s[j] == "(": depth += 1
            elif s[j] == ")": depth -= 1
            j += 1
        if depth:
            print("  ! %s:%d volani %s pokracuje na dalsi radek" % (fn, ln, name))
            continue
        inner = s[start + 1:j - 1]
        have = 0 if inner.strip() == "" else len(split_args(inner))
        if have >= want:
            continue
        pad = ", ".join(["0"] * (want - have))
        newinner = (inner + ", " + pad) if inner.strip() else pad
        lines[idx] = s[:start + 1] + newinner + s[j - 1:]
        changed += 1
    if changed and APPLY:
        tmp = p + ".tmp"
        open(tmp, "wb").write("\n".join(lines).encode("latin-1"))
        os.replace(tmp, p)
    print("%-20s doplneno %d volani" % (fn, changed))
    total += changed
print("\ncelkem: %d%s" % (total, "" if APPLY else "  (nic nezapsano)"))
