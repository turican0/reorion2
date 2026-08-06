# Vlna 58: dekompilator zahodil 4. argument qsort (porovnavaci funkci) -
# Watcom ji predava v ECX. Kazde takove volani je pad v CRT (__debugbreak /
# "invalid parameter"). Skript pro kazde 3argumentove volani v portu dohleda
# v asm dumpu odpovidajici `mov ecx, offset sub_XXXX` pred `call qsort_`.
import re, os, sys

ASM = r"C:\prenos\reorion2\reorion2\Debug\diss\Orion2.exe.asm"
SRC = r"C:\prenos\reorion2\reorion2\src\game"

lines = open(ASM, "r", errors="replace").read().splitlines()

# mapa: IDA adresa funkce -> seznam komparatoru v poradi volani qsort
proc_cmp = {}
cur = None
pending = None
for ln in lines:
    m = re.match(r"^(sub_([0-9A-F]+))\s+proc near", ln)
    if m:
        cur = int(m.group(2), 16)
        proc_cmp.setdefault(cur, [])
        pending = None
        continue
    if cur is None:
        continue
    m = re.match(r"^\s+mov\s+ecx,\s+offset\s+(\S+)", ln)
    if m:
        pending = m.group(1)
    if re.match(r"^\s+call\s+qsort_", ln):
        proc_cmp[cur].append(pending)
        pending = None

QS3 = re.compile(r"qsort\(([^;]*?)\)\s*;")

def three_args(argtext):
    depth = 0
    n = 1
    for ch in argtext:
        if ch in "([":
            depth += 1
        elif ch in ")]":
            depth -= 1
        elif ch == "," and depth == 0:
            n += 1
    return n == 3

rows = []
for fn in sorted(os.listdir(SRC)):
    if not fn.endswith(".c"):
        continue
    func = None
    for no, ln in enumerate(open(os.path.join(SRC, fn), "r", errors="replace"), 1):
        m = re.match(r"^//----- \(([0-9A-F]+)\)", ln)
        if m:
            func = int(m.group(1), 16)
            idx = 0
        for mm in QS3.finditer(ln):
            if ln.lstrip().startswith("//"):
                continue
            if not three_args(mm.group(1)):
                idx = idx + 1 if func else 0
                continue
            cmps = proc_cmp.get(func, [])
            got = cmps[idx] if idx < len(cmps) else None
            rows.append((fn, no, "sub_%X" % func if func else "?", got, len(cmps)))
            idx += 1

print("Volani qsort bez porovnavaci funkce: %d" % len(rows))
print("%-18s %-7s %-12s %s" % ("soubor", "radek", "funkce", "komparator z asm"))
ok = 0
for fn, no, f, got, ncalls in rows:
    print("%-18s %-7d %-12s %s" % (fn, no, f, got or "!! NENALEZEN (qsort volani v asm: %d)" % ncalls))
    if got:
        ok += 1
print("\ndohledano: %d / %d" % (ok, len(rows)))
