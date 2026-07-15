#!/usr/bin/env python3
"""
rename_symbol.py - hromadne a bezpecne prejmenovani symbolu (funkce/globalni
promenne) napric vsemi .c/.h soubory dekompilovaneho projektu Orion.

Pouziti:
    python3 tools/rename_symbol.py old_name new_name [dalsi_pary...]
    python3 tools/rename_symbol.py --map renames.txt

Kazdy radek v renames.txt: "old_name new_name" (oddelene mezerou).

Skript pouziva hranice slova (\b), takze sub_107E6 se neprepise uvnitr
sub_107E60 apod. Provede se nad vsemi *.c a *.h v src/game/.
"""
import re
import sys
import glob
import os

GAME_DIR = os.path.join(os.path.dirname(__file__), "..", "src", "game")


def rename_one(old: str, new: str) -> int:
    pattern = re.compile(r"\b" + re.escape(old) + r"\b")
    total_hits = 0
    for path in glob.glob(os.path.join(GAME_DIR, "*.c")) + glob.glob(os.path.join(GAME_DIR, "*.h")):
        with open(path, "r", encoding="utf-8", errors="surrogateescape") as f:
            content = f.read()
        new_content, n = pattern.subn(new, content)
        if n:
            with open(path, "w", encoding="utf-8", errors="surrogateescape") as f:
                f.write(new_content)
            total_hits += n
    print(f"  {old} -> {new}: {total_hits} vyskytu")
    return total_hits


def main(argv):
    pairs = []
    if len(argv) >= 1 and argv[0] == "--map":
        with open(argv[1], encoding="utf-8") as f:
            for line in f:
                line = line.strip()
                if not line or line.startswith("#"):
                    continue
                old, new = line.split()
                pairs.append((old, new))
    else:
        if len(argv) % 2 != 0:
            print("Chyba: argumenty musi byt dvojice old new")
            sys.exit(1)
        for i in range(0, len(argv), 2):
            pairs.append((argv[i], argv[i + 1]))

    for old, new in pairs:
        rename_one(old, new)


if __name__ == "__main__":
    main(sys.argv[1:])
