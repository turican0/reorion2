# Orion2.exe - rozdeleny a kompilovatelny Hex-Rays dump

## Co tu je

- `out/orion_common.h` - spolecna hlavicka: kompatibilni typy/makra (viz
  `hexrays_compat.h`), deklarace VSECH funkci (odvozene primo z definic,
  ne z puvodni - casto nespolehlive - Hex-Rays hlavicky) a extern
  deklarace vsech globalnich dat.
- `out/orion_data.c` - vsechna globalni data (puvodni "Data declarations"
  blok).
- `out/orion_part_01.c` .. `orion_part_26.c` - funkce rozdelene PO 200 do
  souboru, v puvodnim adresnim poradi. Tohle je jen HRUBE prvni rozdeleni
  podle adresy (viz `out/MANIFEST.txt` pro rozsahy) - az bude jasne, co
  ktera cast dela (grafika/zvuk/UI/...), da se snadno prejmenovat a
  presunout funkce mezi soubory (jsou uplne nezavisle, potrebuji jen
  `#include "orion_common.h"`).
- `out/hexrays_compat.h` - kompatibilni vrstva nahrazujici Hex-Rays
  pseudo-typy/makra (`_BYTE`, `_DWORD`, `LOBYTE`, `MEMORY[]`, `JUMPOUT`,
  `__usercall` apod.) standardnimi C konstrukcemi.
- `out/MANIFEST.txt` - adresni rozsah a pocet funkci v kazdem souboru.

## Jak zkompilovat / zkontrolovat

```
cd out
for f in orion_common.h orion_data.c orion_part_*.c; do
  gcc -fsyntax-only -std=gnu11 -fno-builtin -w -I. "$f"
done
```

Momentalne projde bez jedine chyby (0/280 447 radku, 5098 funkci).

**Proc `-fno-builtin`:** nekolik volani (`calloc`, `exit`, ...) ma v
puvodnim Hex-Rays vystupu jiny pocet argumentu, nez rika skutecny
prototyp z `<stdlib.h>` (dekompilator si nekdy neni jisty, kolik registru
bylo na danem miste volani skutecne pouzito). `-fno-builtin` vypina GCC
vestavenou znalost techto funkci a necha projit implicitni deklaraci.

## Regenerace od nuly

Cely pipeline je reprodukovatelny ze zdrojoveho `Orion2_exe.c`:

```
python3 split.py      # rozdeli + opravi puvodni dump -> out/
cp hexrays_compat.h out/
python3 autofix.py    # dopatchuje zbylych par mist, kde ma Hex-Rays
                       # vnitrne nekonzistentni signatury/pouziti
```

`split.py` dela (v poradi):
1. Rozdeli original na 3 bloky: deklarace / data / funkce.
2. Odstrani `@<reg>` registrove anotace a `__spoils<...>` (nejsou platny C).
3. Prevede `unsigned/signed __intN` na stdint typy (kombinace s typedefem
   neni v C platna).
4. Prevede kazdy `__asm { ... }` blok na komentar + `DECOMP_TODO()` marker.
5. Kazdou z 35 funkci, kde Hex-Rays dekompilace uplne selhala (`#error`
   v originale), nahradi prazdnym stub telem se stejnou signaturou.
6. Odvodi deklaraci KAZDE funkce primo z jeji definice (misto z puvodni
   Hex-Rays hlavicky, ktera byla u ~700 funkci s registrovymi parametry
   jen v komentari a casto neodpovidala tela). Deklarace jsou zamerne
   K&R stylem (bez seznamu parametru) - Hex-Rays na ruznych mistech
   volani tehoz `__usercall`/`__userpurge` casto uvadi jiny pocet
   argumentu (artefakt analyzy registru), presny prototyp by to odmital.
7. Parametry predavane hodnotou s "uzkym" typem (`int16_t`, `char`, ...)
   promuje na `int`/`unsigned int` - jinak by K&R deklarace nebyla s
   definici kompatibilni (pravidlo o default argument promotion).
8. Dohleda "osirele" adresy (pouzite, ale nikde nedefinovane - typicky
   uvnitr staticky linkovane knihovny) a doplni jim genericke extern
   deklarace.

`autofix.py` pak iterativne kompiluje a automaticky opravuje zbytek:
- volani s jeste porad nesouhlasicim poctem argumentu (cast pres
  genericky ukazatel na funkci),
- symboly pouzite soucasne jako pole i jako skalar (Hex-Rays nekonzistence
  u prekryvajicich se dat) - prida `[0]`,
- symbol s typem "ukazatel na funkci" pouzity jako bajtove pole - cast,
  - neslucitelne typy ukazatelu pri odecitani.

## DECOMP_TODO - co je potreba jeste rucne dohledat v IDA

Hledej `grep -rn DECOMP_TODO out/` - oznacuje:
- 35 funkci, kde Hex-Rays dekompilace uplne selhala (prazdne stuby),
- vsechny puvodni `__asm { ... }` bloky (FPU inicializace, port I/O),
- `arg8_ED48B` (sub_ED48B) - dekompilator neurcil typ 8. argumentu,
- par funkci, kde Hex-Rays odvodil `void` navratovy typ, ale volajici ho
  pouzivaji jako hodnotu (`sub_FE8BE`, `sub_97A2D`, `sub_C8DB8`,
  `sub_F53D7`, `sub_158B50`, `sub_B6352`) - navratovy typ je nastaven na
  `int`, skutecnou hodnotu/semantiku je potreba overit.

Vsechny tyto zmeny jsou funkcni/typove zjednoduseni pro to, aby soubor
sel prelozit - NEJDE o overenou behovou korektnost. Pred realnym
sestavenim/spustenim je potreba projit DECOMP_TODO mista.
