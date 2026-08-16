# -*- coding: ascii -*-
"""
Aplikuje opravu k `tools/fmtcheck.py`: kazdemu argumentu, ktery jde do `%s`
a je v portu `int`, doplni pretypovani `(char *)(intptr_t)`.

Proc to staci: zmereno ve vlne 95, ze zasobnik i kod portu lezi hluboko pod
2 GB (0x4FFBF0 / 0x753014), takze hodnota v `int`u je platny ukazatel - jen se
do varargs slotu musi dostat v plne sirce.

Pouziti:  python tools/fmtfix.py            (jen vypis)
          python tools/fmtfix.py --apply    (zapise zmeny)
"""
import os, re, subprocess, sys, collections

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SRC = os.path.join(ROOT, "src", "game")
APPLY = "--apply" in sys.argv

out = subprocess.run([sys.executable, os.path.join(ROOT, "tools", "fmtcheck.py")],
                     capture_output=True, text=True).stdout
sites = collections.defaultdict(list)   # (soubor) -> [(radek, arg)]
for line in out.split("\n"):
    m = re.match(r"^(orion_part_\d+\.c):(\d+)\s+format #\d+\s+arg \d+ \(`([^`]+)`", line)
    if m:
        sites[m.group(1)].append((int(m.group(2)), m.group(3)))

total = 0
for fn, items in sorted(sites.items()):
    p = os.path.join(SRC, fn)
    data = open(p, "rb").read().decode("latin-1")
    # DULEZITE: delit stejne jako fmtcheck.py (na "\n"), jinak nesedi cisla
    # radku u souboru s CRLF. Konce radku zustanou soucasti retezcu.
    lines = data.split("\n")
    byline = collections.defaultdict(list)
    for ln, arg in items:
        byline[ln].append(arg)
    for ln, args in sorted(byline.items()):
        i = ln - 1
        orig = lines[i]
        new = orig
        for arg in sorted(set(args), key=len, reverse=True):
            # nahrad JEN samostatny argument (mezi carkou/zavorkou a carkou/zavorkou)
            pat = re.compile(r"(?<=[(,] )" + re.escape(arg) + r"(?=[,)])")
            new2 = pat.sub("(char *)(intptr_t)" + arg, new)
            if new2 == new:
                print("  !! %s:%d nesel nahradit argument `%s`" % (fn, ln, arg))
            new = new2
        if new != orig:
            lines[i] = new
            total += 1
            print("%s:%d" % (fn, ln))
            print("   - %s" % orig.strip())
            print("   + %s" % new.strip())
    if APPLY:
        open(p + ".tmp", "wb").write("\n".join(lines).encode("latin-1"))
        os.replace(p + ".tmp", p)
print("\nupravenych radku: %d%s" % (total, "" if APPLY else "  (nic nezapsano, spust s --apply)"))
