# Regresni brana videa: porovna referencni snimky z dosboxu se snimky z portu.
#
# Nahrazuje binarku genCompare/compare_frames.exe, ktera nikdy nebyla v gitu
# a pri prepnuti vetve se ztratila (stejne jako Debug/diss - vlna 132).
# Proto je tenhle skript ULOZENY V GITU. Referencni snimky patri do
# C:/prenos/reorion2Data/, ne do gitignorovanych adresaru v pracovnim strome.
#
# Snimky portu:
#   REORION2_BLIT_DUMP_DIR=<d> REORION2_BLIT_DUMP_COUNT=600
#   REORION2_DUMP_INCLUDE_PALETTE=1 REORION2_VIDEO_AUDIO=0
#
# Format snimku: 768 B palety + 640*480 bajtu indexu.
# Dosbox ma paletu 6bitovou, port 8bitovou -> porovnava se v 6 bitech (>>2),
# stejne jako v diffshot.py. Snimek "sedi", kdyz se shoduji VSECHNY pixely
# po prevodu pres vlastni paletu (jiny index se stejnou barvou je v poradku).
#
# Pouziti:
#   python tools/compare/gate.py <ref_dir> <port_dir> [640 480]
# Navratovy kod 0 = vsechny snimky sedi.
import os
import sys

W, H = 640, 480


def nacti(cesta, sest_bitu):
    d = open(cesta, 'rb').read()
    pal = list(d[:768])
    if not sest_bitu:
        pal = [c >> 2 for c in pal]      # port 8bit -> 6bit
    return pal, d[768:768 + W * H]


def rgb_mapa(pal):
    return [tuple(pal[3 * i:3 * i + 3]) for i in range(256)]


def porovnej(a, b):
    """Vrati pocet odlisnych pixelu (po prevodu pres vlastni paletu)."""
    pa, ia = nacti(a, True)
    pb, ib = nacti(b, False)
    if len(ia) != W * H or len(ib) != W * H:
        return -1
    ra, rb = rgb_mapa(pa), rgb_mapa(pb)
    # rychla cesta: shodna paleta i shodne indexy
    if pa == pb and ia == ib:
        return 0
    lisi = 0
    for k in range(W * H):
        va, vb = ia[k], ib[k]
        if va != vb and ra[va] != rb[vb]:
            lisi += 1
    return lisi


def main(ref_dir, port_dir):
    ref = sorted(f for f in os.listdir(ref_dir) if f.endswith('.raw'))
    if not ref:
        print('CHYBA: v %s nejsou zadne .raw snimky' % ref_dir)
        return 2
    sedi = rozchazi = chybi = 0
    prvni = []
    for f in ref:
        p = os.path.join(port_dir, f)
        if not os.path.exists(p):
            chybi += 1
            continue
        n = porovnej(os.path.join(ref_dir, f), p)
        if n == 0:
            sedi += 1
        else:
            rozchazi += 1
            if len(prvni) < 10:
                prvni.append((f, n))
    celkem = sedi + rozchazi
    print('%d/%d matched, %d diverged%s' %
          (sedi, celkem, rozchazi,
           (', %d chybi v portu' % chybi) if chybi else ''))
    for f, n in prvni:
        print('  %s: %d px' % (f, n))
    return 0 if rozchazi == 0 and chybi == 0 else 1


if __name__ == '__main__':
    if len(sys.argv) < 3:
        print(__doc__ or 'pouziti: gate.py <ref_dir> <port_dir> [W H]')
        sys.exit(2)
    if len(sys.argv) >= 5:
        W, H = int(sys.argv[3]), int(sys.argv[4])
    sys.exit(main(sys.argv[1], sys.argv[2]))
