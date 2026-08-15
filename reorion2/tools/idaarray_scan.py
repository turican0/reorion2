# -*- coding: ascii -*-
"""
Hleda POLE S NEURCENOU VELIKOSTI z IDA dumpu, ktera jsou v portu rozsekana
na samostatne skalary (`; int dword_18ABE0[]` v asm, ale v portu
`int dword_192BE0[];` + `int dword_192BE4;` + ...).

V originale lezi prvky za sebou, takze `dword_18ABE0[i]` cte sousedni symbol;
v portu je kazdy z nich jiny objekt a indexovane cteni jde mimo.
Presne tahle chyba shodila obrazovku kolonie (vlna 91).

Pouziti:  python tools/idaarray_scan.py
"""
import os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ASM = os.path.join(ROOT, "Debug", "diss", "Orion2.exe.asm")
SRC = os.path.join(ROOT, "src", "game")

DELTA = 0x8000  # asm jmeno + 0x8000 = C jmeno

hdr = re.compile(r"^; (int|__int16|char|_UNKNOWN) (\w+)\[\]\s*$")
sym = re.compile(r"^(\w+)\s+(dd|dw|db)\s")
anysym = re.compile(r"^(\w+)\s+(dd|dw|db|proc|=)")

def scan_asm():
    """vrati [(base_asm, [member_asm...], size_bytes)] pro anotovana pole"""
    out = []
    cur = None
    with open(ASM, "r", encoding="latin-1") as f:
        for line in f:
            m = hdr.match(line)
            if m:
                if cur:
                    out.append(cur)
                cur = {"type": m.group(1), "members": [], "base": None}
                continue
            if cur is None:
                continue
            m = sym.match(line)
            if m:
                if cur["base"] is None:
                    cur["base"] = m.group(1)
                cur["members"].append((m.group(1), m.group(2)))
                continue
            if line.startswith("; ") or line.strip() == "" or line.startswith(" "):
                continue
            # jiny symbol/label bez anotace -> konec bloku
            if anysym.match(line):
                out.append(cur)
                cur = None
    if cur:
        out.append(cur)
    return [b for b in out if b["base"]]

def cname(asm_name):
    m = re.match(r"^(dword|word|byte|unk|off|asc|a)_([0-9A-F]+)$", asm_name)
    if not m:
        return None
    return "%s_%X" % (m.group(1), int(m.group(2), 16) + DELTA)

def load_sources():
    txt = {}
    for fn in os.listdir(SRC):
        if fn.endswith((".c", ".h")):
            with open(os.path.join(SRC, fn), "r", encoding="latin-1") as f:
                txt[fn] = f.read()
    return txt

def main():
    src = load_sources()
    header = src.get("orion_common.h", "")
    data = src.get("orion_data.c", "")
    stubs = src.get("link_stubs.c", "")
    code = {k: v for k, v in src.items() if k.startswith("orion_part")}

    print("%-16s %5s %5s  %s" % ("C jmeno", "prvku", "index", "stav"))
    bad = 0
    for blk in scan_asm():
        if len(blk["members"]) < 2:
            continue
        base = cname(blk["base"])
        if not base:
            continue
        # je base v portu indexovana necim jinym nez [0]?
        idx = 0
        for fn, t in code.items():
            for m in re.finditer(re.escape(base) + r"\[([^\]]*)\]", t):
                if m.group(1).strip() not in ("0",):
                    idx += 1
        if idx == 0:
            continue
        # jsou clenove samostatne symboly?
        split = []
        for name, _w in blk["members"][1:]:
            cn = cname(name)
            if cn and re.search(r"^\s*(extern\s+)?\w[\w \*]*\b" + re.escape(cn) + r"\b\s*(\[[^\]]*\])?\s*;",
                                header, re.M):
                split.append(cn)
        dup = bool(re.search(r"^\s*\w[\w \*]*\b" + re.escape(base) + r"\s*;", stubs, re.M))
        if split or dup:
            bad += 1
            print("%-16s %5d %5d  ROZSEKANE: %d clenu%s" %
                  (base, len(blk["members"]), idx, len(split),
                   " + DUPLICITNI SKALAR v link_stubs.c" if dup else ""))
    print("\ncelkem podezrelych bloku: %d" % bad)

main()
