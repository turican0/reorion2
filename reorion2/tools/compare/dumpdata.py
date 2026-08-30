"""Vypise bajty z ORIGINALNIHO obrazu hry podle adresy v cseg01.

Proc: pulka nalezenych chyb je "tabulka v `orion_data.c` ma jeden prvek,
v obraze jich ma N". Opisovat je z `Orion2.exe.lst` je pomale a chybove -
IDA slucuje `db`/`dw`/`dd` do jednoho radku a `align` nevypisuje vubec.

POZOR: soubor ma DVA ruzne posuny (mezi useky je 0x7000 nealokovaneho mista),
takze nastroj vypise OBE varianty a spravnou pozna clovek podle kontextu:

  kod  (napr. 0xDD4B5, tabulky ulozene v kodovem useku): +0x85654
  data (napr. 0x17AC26, dseg symboly)                  : +0x7E654

Kotvy, na kterych jsou posuny overene:
  0xDD4B5  = 01 02 03 05 08   (byte_DD4B5) nasledovane 32 19 (word_DD4BA)
  0x17AC26 = E4 E5 E5 00...   (unk_17AC26) nasledovane F5 FD FC 00... (unk_17AC2E)

Kdyz si nejsi jisty, over hodnotu jeste sondou v dosboxu:
  DUMPREGS cond=changed:<C jmeno + 0x216000>:2 label=x repeat=always

Pouziti:
  dumpdata.py 0xDD4EB 10          # obe varianty
  dumpdata.py 0x17A310 4 --data   # jen datova
  dumpdata.py 0xDD4EB 10 --kod --c   # jen kodova, jako C inicializator
"""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from diss import soubor

DELTA_KOD  = 0x85654
DELTA_DATA = 0x7E654
EXE = soubor('Orion2.exe')   # vlna 131: uz ne Debug/diss - viz diss.py

def show(d, addr, count, delta, label, as_c):
    off = addr + delta
    b = d[off:off + count]
    if as_c:
        print(f'{label}: {{ ' + ', '.join(str(x) for x in b) + ' }')
        return
    print(f'{label}  cseg01:{addr:08X} (soubor 0x{off:X}):')
    for i in range(0, len(b), 16):
        row = b[i:i+16]
        print(f'  +{i:03X}  ' + ' '.join(f'{x:02X}' for x in row)
              + '   ' + ' '.join(f'{x:3d}' for x in row))

def main(addr, count, *opts):
    addr = int(addr, 0); count = int(count, 0)
    d = open(EXE, 'rb').read()
    as_c = '--c' in opts
    if '--data' in opts:
        show(d, addr, count, DELTA_DATA, 'DATA', as_c)
    elif '--kod' in opts:
        show(d, addr, count, DELTA_KOD, 'KOD ', as_c)
    else:
        show(d, addr, count, DELTA_KOD, 'KOD ', as_c)
        show(d, addr, count, DELTA_DATA, 'DATA', as_c)

if __name__ == '__main__':
    main(*sys.argv[1:])
