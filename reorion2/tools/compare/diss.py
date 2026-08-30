"""Kde lezi referencni disassembly originalu (Orion2.exe a jeho vypisy).

Drive to bylo v `Debug/diss/` uvnitr repozitare. Ta cesta je v `.gitignore`,
takze prepnuti vetve ten adresar SMAZALO a nastroje prestaly fungovat
(vlna 131). Referencni data proto patri MIMO pracovni strom.

Poradi hledani:
  1. promenna prostredi REORION2_DISS
  2. C:/prenos/reorion2Data/diss          <- doporucene misto
  3. Debug/diss (relativne ke koreni portu) - stara cesta, pokud jeste existuje
  4. C:/prenos/mastori2/diss              - jina kopie na stroji

Pouziti:
    from diss import soubor
    open(soubor('Orion2.exe'), 'rb')
    open(soubor('Orion2.exe.lst'), 'rb')
"""
import os

MISTA = [
    os.environ.get('REORION2_DISS'),
    'C:/prenos/reorion2Data/diss',
    'Debug/diss',
    'C:/prenos/mastori2/diss',
]

def slozka():
    for m in MISTA:
        if m and os.path.isfile(os.path.join(m, 'Orion2.exe')):
            return m
    raise SystemExit(
        'Nenasel jsem referencni disassembly (Orion2.exe).\n'
        'Hledal jsem v: ' + ', '.join(m for m in MISTA if m) + '\n'
        'Nastav REORION2_DISS, nebo data zkopiruj do C:/prenos/reorion2Data/diss.')

def soubor(jmeno):
    return os.path.join(slozka(), jmeno)

if __name__ == '__main__':
    print(slozka())
