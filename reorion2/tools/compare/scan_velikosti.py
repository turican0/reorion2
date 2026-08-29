"""Najde v `orion_data.c` symboly, ktere jsou MENSI nez misto, ktere v obraze
hry zabiraji.

IDA vypisuje globaly podle toho, jak se na ne kod diva; kdyz nekam sahne jen
jednim bajtem, vyrobi jednobajtovou promennou, i kdyz je to ve skutecnosti
ctyrkilobajtovy blok. Hra pak dela `memset(&X, 0, 4172)` a v portu, kde je
kazdy symbol samostatny objekt, to **prepise sousedni globaly**.

Uz dvakrat opraveno rucne (`unk_1AF620` ve vlne 12, `byte_1B071B` ve vlne 126);
tenhle skript hleda zbytek. Velikost v obraze = vzdalenost k DALSIMU symbolu.

Pouziti:
    python tools/compare/scan_velikosti.py            # jen podezrele (rozdil >= 4 B)
    python tools/compare/scan_velikosti.py --vse      # vsechno
    python tools/compare/scan_velikosti.py --min 64   # jen velke rozdily

POZOR: ne kazdy rozdil je chyba - mezi symboly byva zarovnani (align) a IDA
nektera mista nepojmenuje vubec. Ber to jako seznam kandidatu, ktery se overi
`dumpdata.py` a tim, jak se symbol pouziva (memset/strcpy/index).
"""
import re, sys

P = 'src/game/orion_data.c'

VELIKOSTI = {
    'char': 1, 'uint8_t': 1, '_BYTE': 1, 'int8_t': 1, 'unsigned char': 1,
    'int16_t': 2, '_WORD': 2, 'uint16_t': 2, 'short': 2,
    'int': 4, '_DWORD': 4, 'uint32_t': 4, 'unsigned int': 4, 'long': 4,
    'float': 4, '_UNKNOWN': 1,
}

DEKL = re.compile(
    r'^(?P<typ>[A-Za-z_][A-Za-z0-9_ ]*?)\s*(?P<hvezda>\*+)?\s*'
    r'(?P<jm>[A-Za-z_][A-Za-z0-9_]*_(?P<adr>[0-9A-Fa-f]{4,6}))\s*'
    r'(\[\s*(?P<n>[0-9]*)\s*\])?\s*(=|;)')

def main(argv):
    vse = '--vse' in argv
    minimum = 4
    if '--min' in argv:
        minimum = int(argv[argv.index('--min') + 1])

    symboly = []
    for cislo, radek in enumerate(open(P, 'rb').read().decode('latin-1').split('\n'), 1):
        s = radek.strip()
        if s.startswith('//') or s.startswith('/*'):
            continue
        m = DEKL.match(s)
        if not m:
            continue
        try:
            adr = int(m.group('adr'), 16)
        except ValueError:
            continue
        typ = m.group('typ').strip()
        if m.group('hvezda'):
            prvek = 4          # ukazatele jsou v obraze 32bitove
        else:
            prvek = VELIKOSTI.get(typ)
            if prvek is None:
                continue
        n = m.group('n')
        pocet = int(n) if n else 1
        symboly.append((adr, m.group('jm'), cislo, prvek * pocet, s[:70]))

    symboly.sort()
    print(f'{len(symboly)} symbolu s adresou v {P}\n')
    nalezeno = 0
    for i in range(len(symboly) - 1):
        adr, jm, cislo, velikost, txt = symboly[i]
        mezera = symboly[i + 1][0] - adr
        if mezera <= 0:
            continue
        rozdil = mezera - velikost
        if vse or rozdil >= max(minimum, 1):
            if rozdil < minimum and not vse:
                continue
            nalezeno += 1
            print(f'0x{adr:06X} {jm:<20} radek {cislo:>6}  '
                  f'deklarovano {velikost:>6} B, v obraze {mezera:>6} B  '
                  f'(chybi {rozdil} B)')
            print(f'          {txt}')
    print(f'\nkandidatu: {nalezeno}')

main(sys.argv[1:])
