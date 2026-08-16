# -*- coding: ascii -*-
"""
Oprava tridy "sirka ukazatele" pro HERNI STRUKTURY:

    *(_WORD **)(dword_19C598 + 4)      <- na x64 cte OSM bajtu
    -> (_WORD *)(intptr_t)*(uint32_t *)(dword_19C598 + 4)

V originale je slot ve strukture 4bajtovy (`*(_DWORD *)(dword_19C598 + 4) = v3`
- tak ho i port PLNI), ale cteni pres `**` si na x64 vezme 8 bajtu, takze horni
pulku vezme ze SOUSEDNIHO pole. Presne tim spadl PLANETS: `a4` vyslo
0xFFFFFFFFFFFFFFFF.

Ze pretypovani 32bit hodnoty na ukazatel je bezpecne, je zmereno ve vlne 95:
zasobnik i kod portu lezi pod 2 GB.

Zamerne se resi JEN tvar `*(T **)(dword_XXXXXX [+ N])` - tedy globalni ukazatel
na herni strukturu. Tvary jako `*(T **)((char *)&retaddr + 2)` jsou jina vec
(argumenty na zasobniku) a tenhle skript se jich nedotkne.

Pouziti:  python tools/ptrwidth_fix.py            (jen vypis)
          python tools/ptrwidth_fix.py --apply
"""
import os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, "src", "game")
APPLY = "--apply" in sys.argv

PAT_START = re.compile(r"\*\(((?:unsigned |signed |const )?[A-Za-z_][A-Za-z_0-9]*) \*\*\)\(")

def convert(data):
    """prepise `*(T **)(<vyraz zacinajici dword_...>)` na ctyrbajtove cteni"""
    out, i, n = [], 0, 0
    while True:
        m = PAT_START.search(data, i)
        if not m:
            out.append(data[i:])
            break
        # najdi zavorku patrici k otevirajici na konci shody
        j, depth = m.end(), 1
        while j < len(data) and depth:
            if data[j] == "(":
                depth += 1
            elif data[j] == ")":
                depth -= 1
            j += 1
        inner = data[m.end():j - 1]
        # jen vyrazy, ktere zacinaji globalem `dword_` (herni struktura)
        if re.match(r"^dword_[0-9A-F]+", inner.strip()):
            out.append(data[i:m.start()])
            out.append("(%s *)(intptr_t)*(uint32_t *)(%s)" % (m.group(1), inner))
            n += 1
        else:
            out.append(data[i:j])
        i = j
    return "".join(out), n

total = 0
for fn in sorted(os.listdir(SRC)):
    if not fn.startswith("orion_part") or not fn.endswith(".c"):
        continue
    p = os.path.join(SRC, fn)
    data = open(p, "rb").read().decode("latin-1")
    new, n = convert(data)
    if not n:
        continue
    total += n
    print("%-20s %3d mist" % (fn, n))
    if APPLY:
        open(p + ".tmp", "wb").write(new.encode("latin-1"))
        os.replace(p + ".tmp", p)
print("\ncelkem: %d%s" % (total, "" if APPLY else "  (nic nezapsano, spust s --apply)"))
