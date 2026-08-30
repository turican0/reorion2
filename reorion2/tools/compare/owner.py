"""Prelozi `ret=` z dosboxoveho trace na jmeno funkce (+ offset).

Sonda `DUMPREGS cond=eip:<adresa> repeat=always` vypise u kazdeho volani i
navratovou adresu. Tenhle skript z ni udela `sub_XXXXX+0xNN`, takze je hned
videt, KDO merenou funkci vola - to je zakladni krok metody "zespoda nahoru".

Pouziti:
    owner.py <trace.txt> [cyklus_od] [cyklus_do]

Vypise pocty podle volajicich a pak jednotliva volani setridena podle y
(edx), s x (eax) a treti registrovym argumentem (ebx). Registry odpovidaji
Watcom konvenci: eax, edx, ebx, ecx, pak zasobnik.

Referencni disassembly se hleda pres diss.py (viz tam).
"""
import collections
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from diss import soubor

DELTA_KOD = 0x224000          # runtime = IDA + 0x224000


def _procedury():
    vzor = re.compile(r'^cseg01:([0-9A-F]{8})\s+(sub_[0-9A-F]+)\s+proc near')
    with open(soubor('Orion2.exe.lst'), 'rb') as f:
        text = f.read().decode('latin-1')
    out = []
    for radek in text.split('\n'):
        m = vzor.match(radek)
        if m:
            out.append((int(m.group(1), 16), m.group(2)))
    out.sort()
    return out


def _hledej(procs, runtime):
    ida = runtime - DELTA_KOD
    prev = None
    for adr, jmeno in procs:
        if adr <= ida:
            prev = (adr, jmeno)
        else:
            break
    if not prev:
        return f'?{runtime:08X}'
    return f'{prev[1]}+0x{ida - prev[0]:X}'


def main(cesta, od='0', do=None):
    od = int(od)
    do = int(do) if do else 1 << 62
    procs = _procedury()

    radky = []
    for radek in open(cesta):
        pole = dict(kv.split('=', 1) for kv in radek.split() if '=' in kv)
        if 'cycle' not in pole:
            continue
        c = int(pole['cycle'])
        if not (od <= c <= do):
            continue
        def znam(jmeno):
            v = int(pole[jmeno], 16)
            return v - 0x10000 if v > 0x8000 else v
        radky.append((c, znam('eax'), znam('edx'),
                      int(pole['ebx'], 16), int(pole['ret'], 16)))

    print(f'{len(radky)} volani v rozsahu {od}..{do}\n')
    print('volajici (ret= -> funkce):')
    for jmeno, n in collections.Counter(_hledej(procs, r[4]) for r in radky).most_common():
        print(f'  {n:5d}  {jmeno}')

    print('\nvolani setridena podle y (edx), x = eax, ebx = treti argument:')
    for c, x, y, bx, ret in sorted(radky, key=lambda r: (r[2], r[1])):
        print(f'  x={x:5d} y={y:5d} ebx=0x{bx:08X}  <- {_hledej(procs, ret)}  (cycle {c})')


if __name__ == '__main__':
    main(*sys.argv[1:])
