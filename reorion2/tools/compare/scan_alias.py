"""Najde symboly, ktere existuji DVAKRAT na tomtez miste:
jako pahyl `int unk_ADR;` v link_stubs.c a zaroven jako skutecna data
`<typ> <prefix>_ADR[...]` v orion_data.c.

IDA dava temuz mistu ruzna jmena podle toho, jak se na nej kod diva
(`unk_` = neznamy typ). V portu z toho vzniknou DVA ruzne objekty: jeden se
plni, z druheho se cte - a cte se prazdno. Vlna 130 to nasla na RACES
(`byte_1AD418` se plnil, `unk_1AD418` se kreslil).
"""
import re, collections

def symboly(path, vzor):
    out = collections.defaultdict(list)
    for n, line in enumerate(open(path, 'rb').read().decode('latin-1').split('\n'), 1):
        m = vzor.match(line.strip())
        if m:
            out[m.group('adr').upper()].append((n, line.strip()[:100]))
    return out

pahyl = re.compile(r'^(?:int|char|_UNKNOWN|int16_t|_BYTE|_WORD|_DWORD)\s+'
                   r'(?P<jm>unk_(?P<adr>[0-9A-Fa-f]{4,6}))\s*(\[[^\]]*\])?\s*;')
data = re.compile(r'^(?:extern\s+)?[A-Za-z_][A-Za-z0-9_ ]*\**\s*'
                  r'(?P<jm>(?:byte|word|dword|off|unk|asc|a)_(?P<adr>[0-9A-Fa-f]{4,6}))\s*'
                  r'(\[[^\]]*\])?\s*(=|;)')

A = symboly('src/game/link_stubs.c', pahyl)
B = symboly('src/game/orion_data.c', data)

kolize = sorted(set(A) & set(B))
print(f'pahylu v link_stubs.c: {len(A)},  symbolu v orion_data.c: {len(B)}')
print(f'KOLIZE (tataz adresa v obou souborech): {len(kolize)}\n')
for adr in kolize:
    print(f'0x{adr}:')
    for n, l in A[adr]:
        print(f'   link_stubs.c:{n}  {l}')
    for n, l in B[adr]:
        print(f'   orion_data.c:{n}  {l}')
