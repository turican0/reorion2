"""Vypise bajty z ORIGINALNIHO obrazu hry podle adresy v cseg01.

Proc: pulka nalezenych chyb je "tabulka v `orion_data.c` ma jeden prvek,
v obraze jich ma N". Opisovat je z `Orion2.exe.lst` je pomale a chybove
(IDA slucuje `db`/`dw`/`dd` a `align` vubec nevypisuje).

Mapovani souboru: `file = cseg01 + 0x85654` (nalezeno pres unikatni vzorek
`byte_DD4B5 = 01 02 03 05 08` nasledovany `word_DD4BA = 1932h`).

Pouziti:
  dumpdata.py 0xDD4EB 10          # 10 bajtu od adresy
  dumpdata.py 0xDD4EB 10 --c      # rovnou jako C inicializator
"""
import sys

DELTA = 0x85654
EXE = 'Debug/diss/Orion2.exe'

def main(addr, count, *opts):
    addr = int(addr, 0); count = int(count, 0)
    d = open(EXE, 'rb').read()
    off = addr + DELTA
    b = d[off:off + count]
    if '--c' in opts:
        print('{ ' + ', '.join(str(x) for x in b) + ' }')
    else:
        print(f'cseg01:{addr:08X} (soubor 0x{off:X}):')
        for i in range(0, len(b), 16):
            row = b[i:i+16]
            print(f'  +{i:03X}  ' + ' '.join(f'{x:02X}' for x in row)
                  + '   ' + ' '.join(f'{x:3d}' for x in row))

if __name__ == '__main__':
    main(*sys.argv[1:])
