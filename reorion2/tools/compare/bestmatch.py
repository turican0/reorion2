"""Nejlepsi shoda mezi dvema SADAMI snimku (port vs dosbox).

Proc: obrazovky s animaci (panacci na COLONIES, blikajici kurzor) maji na
kazde strane jinou fazi, takze "posledni proti poslednimu" hlasi rozdil, ktery
neni chyba. Tohle projde vsechny dvojice a vrati tu nejlepsi - jeji skore je
horni odhad SKUTECNEHO rozdilu.

Pouziti: bestmatch.py <port_dir_nebo_soubor> <dosbox_dir> [--top N]
"""
import sys, os, glob
import numpy as np

def frames(path):
    if os.path.isdir(path):
        files = sorted(glob.glob(os.path.join(path, 'frame_*.raw')))
    else:
        files = [path]
    for f in files:
        d = np.fromfile(f, dtype=np.uint8)
        yield f, d[:768], d[768:]

def main(a, b, *rest):
    top = 1
    if '--top' in rest:
        top = int(rest[list(rest).index('--top') + 1])
    ref = list(frames(b))
    # POZOR: kdyz vysledek hlasi nenulovou neshodu palety, je vybrany
    # referencni snimek nejspis uprostred fadu - neni to nutne chyba portu.
    src = list(frames(a))
    results = []
    for fa, pala, fba in src:
        for fb, palb, fbb in ref:
            if fba.size != fbb.size:
                continue
            results.append((int(np.count_nonzero(fba != fbb)), fa, fb, pala, palb))
    results.sort(key=lambda t: t[0])
    for n, fa, fb, pala, palb in results[:top]:
        palmis = int(np.count_nonzero((pala >> 2) != palb))
        print(f"{os.path.basename(fa)} vs {os.path.basename(fb)}: "
              f"{n} px ({100.0*n/307200:.2f} %), paleta {palmis}/768")
    return results[0][1], results[0][2]

if __name__ == '__main__':
    main(*sys.argv[1:])
