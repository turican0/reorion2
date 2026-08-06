# Vlna 58: klasifikace vsech JUMPOUT(adr) v portu proti asm dumpu.
# JUMPOUT je v decomp_compat.h NO-OP. Kdyz cil skoku je jen epilog funkce
# (posloupnost leave/pop/retn), da se JUMPOUT bezpecne nahradit `return`.
import re, os, sys, collections

ASM = r"C:\prenos\reorion2\reorion2\Debug\diss\Orion2.exe.asm"
SRC = r"C:\prenos\reorion2\reorion2\src\game"

# 1) nacti asm a zaindexuj navesti loc_XXXXX / locret_XXXXX
lines = open(ASM, "r", errors="replace").read().splitlines()
label_at = {}
for i, ln in enumerate(lines):
    m = re.match(r"^(loc(?:ret)?_([0-9A-F]+)):", ln)
    if m:
        label_at.setdefault(int(m.group(2), 16), i)

EPI = re.compile(r"^\s+(pop|leave|popa|retn|retf|ret)\b")
OTHER = re.compile(r"^\s+[a-z]")

def classify(addr):
    i = label_at.get(addr)
    if i is None:
        return "cil nenalezen"
    j = i + 1
    steps = 0
    while j < len(lines) and steps < 12:
        ln = lines[j]
        if not ln.strip() or ln.lstrip().startswith(";") or re.match(r"^\S+\s+endp", ln):
            j += 1
            continue
        # Vlna 58 (oprava): navesti UVNITR epilogu neni konec analyzy -
        # `locret_X: leave` / `loc_Y: pop edi ... retn` je bezny tvar
        # sdileneho epilogu. Pokracujeme dal, dokud nenarazime na skutecnou
        # instrukci, ktera epilog neni.
        if re.match(r"^loc(ret)?_[0-9A-F]+:", ln):
            j += 1
            continue
        if re.match(r"^(sub_|\S+\s+proc)", ln):
            return "pokracuje jinam"
        if EPI.match(ln):
            if re.match(r"^\s+(retn|retf|ret)\b", ln):
                return "EPILOG"
            j += 1
            steps += 1
            continue
        if OTHER.match(ln):
            return "skutecny skok"
        j += 1
    return "nejasne"

counts = collections.Counter()
rows = []
for fn in sorted(os.listdir(SRC)):
    if not fn.endswith(".c"):
        continue
    for n, ln in enumerate(open(os.path.join(SRC, fn), "r", errors="replace"), 1):
        for m in re.finditer(r"JUMPOUT\(0x([0-9A-Fa-f]+)\)", ln):
            a = int(m.group(1), 16)
            k = classify(a)
            counts[k] += 1
            rows.append((fn, n, "0x%X" % a, k))

print("SOUHRN:")
for k, v in counts.most_common():
    print("  %-18s %d" % (k, v))
with open(sys.argv[1], "w") as f:
    for r in rows:
        f.write("%s:%d\t%s\t%s\n" % r)
print("detail zapsan do", sys.argv[1])
