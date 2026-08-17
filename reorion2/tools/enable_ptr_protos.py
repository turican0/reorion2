# -*- coding: ascii -*-
"""
Zapne SKUTECNE PROTOTYPY pro funkce s UKAZATELOVYMI parametry.

`orion_common.h` deklaruje vsechny funkce jako `extern T sub_X();` a plne
signatury drzi jen v komentari `// plna signatura: ...` (a v bloku, ktery je
cely v `#if 0`). Prazdne zavorky v C znamenaji "neznamy seznam argumentu",
takze prekladac na volani NIC nekontroluje ani nekonvertuje - a u parametru
typu UKAZATEL to na x64 znamena, ze volajici zapise do 8bajtoveho slotu jen
4 bajty a horni pulka zustane po predchozim zapisu. Presne tim padaly LEADERS
(vlna 105: `sub_A1C74(..., 0, &v30)` predalo `a9` jako 0x191B7CC800000000).

Skript proto u kazde funkce, jejiz plna signatura obsahuje `*`, nahradi
`extern T sub_X();` skutecnym prototypem. Cisla a neukazatelove typy nechava
byt - tam prazdne zavorky nevadi a hromadna zmena by jen prinesla riziko.

Pouziti:  python tools/enable_ptr_protos.py [--apply]
"""
import os, re, sys

H = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
                 "src", "game", "orion_common.h")
APPLY = "--apply" in sys.argv

data = open(H, "rb").read().decode("latin-1")
nl = "\r\n" if "\r\n" in data else "\n"
lines = data.split(nl)

sig_re = re.compile(r"^// plna signatura:\s*(.+);\s*$")
ext_re = re.compile(r"^extern\s+.*\b(sub_[0-9A-F]+|[A-Za-z_]\w*_[0-9A-F]+)\s*\(\)\s*;")

out, changed = [], 0
i = 0
while i < len(lines):
    m = sig_re.match(lines[i])
    if m and i + 1 < len(lines):
        m2 = ext_re.match(lines[i + 1])
        sig = m.group(1)
        if m2 and "*" in sig and "..." not in sig:
            out.append(lines[i])
            out.append("%s;   /* vlna 105: skutecny prototyp (ukazatelove argumenty) */" % sig)
            changed += 1
            i += 2
            continue
    out.append(lines[i])
    i += 1

print("prototypu k zapnuti: %d%s" % (changed, "" if APPLY else "  (nic nezapsano)"))
if APPLY:
    tmp = H + ".tmp"
    open(tmp, "wb").write(nl.join(out).encode("latin-1"))
    os.replace(tmp, H)
