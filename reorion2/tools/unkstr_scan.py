# Vlna 58: hleda `_UNKNOWN unk_X` v portu, ktere jsou v originale RETEZCE.
import re, os
ASM = r"C:\prenos\reorion2\reorion2\Debug\diss\Orion2.exe.asm"
SRC = r"C:\prenos\reorion2\reorion2\src\game"
lines = open(ASM, "r", errors="replace").read().splitlines()
at = {}
for i, ln in enumerate(lines):
    m = re.match(r"^(unk|byte|word|dword|asc|a)_?([0-9A-F]{5,6})\s", ln)
    if m:
        at.setdefault(int(m.group(2), 16), i)

def bytes_after(i, limit=24):
    out = []
    m = re.search(r"db\s+([0-9A-Fa-f]+)h?\s*;", lines[i]) or re.search(r"db\s+([0-9A-Fa-f]+)h", lines[i])
    if m:
        out.append(int(m.group(1), 16))
    j = i + 1
    while j < len(lines) and len(out) < limit:
        m = re.match(r"^\s+db\s+([0-9A-Fa-f]+)h?\s*(?:;|$)", lines[j])
        if not m:
            m2 = re.match(r"^\s+db\s+0+h?\s*(;|$)", lines[j])
            if m2:
                out.append(0); j += 1; continue
            break
        out.append(int(m.group(1), 16)); j += 1
    return out

# vsechny _UNKNOWN unk_ v portu, ktere se nekde pouzivaji
decls = []
for fn in ("orion_data.c",):
    for ln in open(os.path.join(SRC, fn), "r", errors="replace"):
        m = re.match(r"^_UNKNOWN (unk_([0-9A-F]+));", ln.strip())
        if m:
            decls.append((m.group(1), int(m.group(2), 16)))

used = set()
for fn in os.listdir(SRC):
    if fn.endswith(".c") and fn != "orion_data.c":
        t = open(os.path.join(SRC, fn), "r", errors="replace").read()
        for name, _ in decls:
            if re.search(r"\b" + name + r"\b", t):
                used.add(name)

print("_UNKNOWN symbolu celkem: %d, z toho pouzitych v kodu: %d" % (len(decls), len(used)))
hits = []
for name, addr in decls:
    if name not in used:
        continue
    i = at.get(addr - 0x8000)
    if i is None:
        continue
    b = bytes_after(i)
    if len(b) >= 2 and 0 in b:
        s = b[:b.index(0)]
        if s and all(32 <= c < 127 for c in s):
            hits.append((name, "".join(chr(c) for c in s)))
print("\nPODEZRELE (bajty tvori tisknutelny retezec):")
for n, s in hits:
    print("  %-14s = %r" % (n, s))
