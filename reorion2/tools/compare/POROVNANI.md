# Soupis porovnavani port vs dosbox (vlna 125+)

Metoda: **zespoda nahoru.** Sonda na nejnizsi kreslici funkci v dosboxu
(`DUMPREGS ... repeat=always`), z `ret=` se urci SKUTECNY volajici, ten se
prelozi na jmeno funkce a porovna s portem. Teprve pak o patro vys.
U promennych `cond=changed:0xADDR[:1|2|4]` - watchpoint, ktery hlasi i EIP
zapisujici instrukce.

Prevody: `kod runtime = IDA + 0x224000`, `data runtime = C jmeno + 0x216000`
(C jmeno = asm jmeno + 0x8000). Mapovani ret -> jmeno: skript nize.

## !!! PAST, KTERA STALA CELOU JEDNU VLNU !!!

`enginestep()` (kde bezi VSECHNY ctl sondy) je volany **jen z
`src/cpu/core_normal.cpp`**. Dynamicka jadra (`core_dyn_x86`, `core_dynrec`)
ho nevolaji vubec. `moo2.conf` ma `core=auto`, dosbox po chvili prepne na
dynamicke jadro a **sondy tise prestanou strilet**.

=> Pro sondovani VZDY `tools/compare/moo2_sondy.conf` (`core=normal`).
=> "Sonda nic nenasla" neni dukaz, dokud v tomtez behu nestrili KONTROLNI
   sonda na misto, ktere se urcite provede.

Falesny zaver, ktery z toho vznikl: "PLANETS kresli original jinym kodem".
Ve skutecnosti obe strany jedou pres `sub_9BF70`.

## Retez kresleni PLANETS (overeno na OBOU stranach)

    sub_1049B (case 32)
      -> sub_9D252  -> sub_9D0C6 -> sub_9BF70   <- kresli radky
           sub_9BF70 -> sub_1210FD (4x sloupec) -> sub_1212EB/sub_122309
             -> sub_121814 / sub_12260F -> sub_121DEB (blit glyfu)

Pocty v dosboxu po kliku: glyf 3698x, z toho `sub_12260F` 2322x,
`sub_121814` 1376x. Port ma tytez dva volajici.

## Prověřené / opravene

| co | vysledek |
|---|---|
| `sub_C5934`/`sub_C5426` | **NENI PLANETS** - je to seznam planet v pop-upu kolonie |
| `word_1822B8` | **OPRAVENO** - bylo `[1]`, ma byt `[33]` (spolu s `word_1822BA`) |
| `sub_79C6B` | **OPRAVENO** - vraci `dl` (poradi planety), IDA mela `void` |
| `sub_1205E6` | v poradku, cte spravny zaznam FONTS.LBX |
| `sub_12AE00` | zdroj palety 192..255 - v portu se nespusti (chybi portrety) |
| `sub_C4562` (COLONIES) | bezi v obou (kontrolni bod pro sondy) |

## Otevrene - PLANETS (5608 px)

1. **Poradi radku prohozene** (port: Trilar I, Trilar IV; dosbox opacne)
   -> trideni seznamu.
2. **Chybi druhy radek ve sloupci CLIMATE** ("2 Food" / "0 Food").
3. **Spatne `prod/worker`** (port 8/0, dosbox 5/3) a **`max pop`**
   (port 45/45, dosbox 12/1) - vypada na spatny index do tabulky.
4. Pod jmenem planety navic glyf "()".

## Otevrene - ostatni

* **COLONIES** 3873 px: stredni panel (panacci) + pravy panel (Reserve/Income).
* **RACES** 5597 px: chybi zelene "NO CONTACT" a "SPY/AGENT".
* **LEADERS** 6650 px: chybi portrety -> proto i paleta 192..255.
* **INFO** 13299 px: dvojita tlacitka vlevo, posun prvniho sloupce.
* **sub_37308**: 29 oprav "skladani retezce" tam rozbije PLANETS (vraceno).

## Pomocny skript: ret= -> jmeno funkce

```python
import re
lst=open('Debug/diss/Orion2.exe.lst','rb').read().decode('latin-1').split('\n')
procs=sorted((int(m.group(1),16), m.group(2)) for l in lst
             for m in [re.match(r'^cseg01:([0-9A-F]{8})\s+(sub_[0-9A-F]+)\s+proc near', l)] if m)
def owner(rt):
    ida=rt-0x224000
    prev=None
    for a,n in procs:
        if a<=ida: prev=(a,n)
        else: break
    return f'{prev[1]} + 0x{ida-prev[0]:X}'
```

## Opraveno ve vlne 126 (vsechno pres retez sub_9BF70)

| symbol / funkce | co bylo spatne |
|---|---|
| `byte_DD4B5` | `[1]` misto `[5] {1,2,3,5,8}` - prod/worker podle nerostu |
| `byte_DD4EB` | `[1]` misto `[10] {25,25,25,25,25,25,40,60,80,100}` - klima -> obyvatelnost |
| `byte_DD4E1` | `[3]` misto `[5]` |
| `byte_DD4E6` | `[1]` misto `[5]` |
| `byte_DD4F5` | `[3]` misto `[8]` |
| `sub_9A2BA` | zahozena navratova hodnota `sub_E0B4F` (max. populace) |
| `byte_1B071B..1E` | JEDEN editacni buffer 257 B rozsekany na ctyri symboly |

Novy nastroj: **`tools/compare/dumpdata.py <adresa> <pocet>`** vypise bajty
primo z `Debug/diss/Orion2.exe` (mapovani `soubor = cseg01 + 0x85654`).
Rychlejsi a spolehlivejsi nez opisovat z `.lst`, kde IDA slucuje `db/dw/dd`
a `align` vubec nevypisuje.

## Kontrolni seznam pro "zkracenou tabulku"

1. `grep -n "^char <jmeno>\[" src/game/orion_data.c` - ma rozmer?
2. `grep -rn "<jmeno>\[" src/game/orion_part_*.c` - indexuje se? cim?
3. `python tools/compare/dumpdata.py <adresa> <n>` - kolik prvku ma obraz?
4. hranici urcuje dalsi symbol v `orion_data.c` (musi byt mezera >= n)

## Vlna 127-128

### Posuny do `Orion2.exe` - POZOR, jsou DVA

| usek | posun | kotva |
|---|---|---|
| kod (a tabulky v nem, napr. `0xDD4B5`) | `+0x85654` | `0xDD4B5` = `01 02 03 05 08` |
| data (`dseg` symboly, napr. `0x17AC26`) | `+0x7E654` | `0x17AC26` = `E4 E5 E5 00x5` |

Mezi useky je 0x7000 nealokovaneho mista. `dumpdata.py` proto vypisuje obe
varianty a spravnou pozna clovek podle kontextu (nebo si ji overi sondou
`DUMPREGS cond=changed:<C jmeno + 0x216000>:2 repeat=always`).

Tohle byla prima pricina toho, ze `word_182310` vypadal jako nula, i kdyz
je v obraze `01 00`.

### Opraveno ve vlne 127-128

| symbol / funkce | co bylo spatne |
|---|---|
| `sub_122259` v `sub_9BF70` | zahozena navratova hodnota (vyska fontu) -> druhy radek CLIMATE na spatne y |
| `sub_7A47A` | deklarovana `void`, ale konci `mov al, cl` -> volajici tiskl "()" |
| `off_18230E` | nesmyslny ukazatel ze dvou `dw` -> rozdeleno na `word_18230E=0`, `word_182310=1` |
| `sub_14852C` | RLE smycka bez pokroku pri `rc==0` -> zamrznuti (pridana brzda) |

### Nova pravidla

- **Zaseknuty proces se meri hlidacem, ne hadanim.** `REORION2_WATCHDOG=8`
  (prah kratsi nez zbyvajici cas behu!) pozastavi hlavni vlakno a vypise
  zasobnik. Prah 70 s pri behu do 95 s se nikdy nestihne projevit.
- **Kdyz smycka konci jen ubyvanim jedne promenne, over, ze v KAZDE vetvi
  ubyva.** Dekompilator umi vetev, kde je krok nulovy, poskladat tak, ze to
  neni videt.


## Vlna 129

### Ktera funkce kresli text? Zalezi na obrazovce

| rodina | co obsluhuje |
|---|---|
| `sub_1212B3` / `sub_1212EB` / `sub_122309` / `sub_121814` | mapa, dialogy, jednotlive popisky |
| `sub_103D53` -> `sub_106171` -> `sub_121DEB` | **seznamove obrazovky** (COLONIES, PLANETS, INFO) - obalovani, sloupce, zarovnani |

`sub_103D53(x, y, sirka, retezec, ...)`. V retezci jsou ridici kody:
`\x1A` + '0'/'1' prepina zarovnani sloupce, `\r` konci radek.

Sonda na spatne rodine vypada jako "obrazovka se vubec nekresli" - a to je
falesne. Kontrola: kdyz sonda za cely beh zachyti jen par retezcu z mapy,
je spatne SONDA, ne hra.

### Sonda nesmi menit to, co meri

`PortDebug_CrashLog` dela `fopen`+`fclose` na kazdy radek. Jako sonda uvnitr
kreslici funkce (desetitisice volani) zpomali beh tak, ze kliky zadavane
v milisekundach dopadnou do jineho stavu hry. Pouzivej **`PortDebug_ProbeLog`**
(`REORION2_PROBE_LOG=1`, bufferovany `probe_text.log` s casovou znackou).

Casova znacka je nutna: obrazovka se cela vykresli JEDNOU pri vstupu, pak uz
se prekresluji jen animovane casti. Konec logu proto vypada jako jina
obrazovka, i kdyz hra nikam neodesla.

### Tri vzorce chyb, ktere se v teto vlne opakovaly

| vzorec | jak se pozna | priklady |
|---|---|---|
| zahozena navratova hodnota | IDA hlasi `variable 'vX' is possibly undefined`, v asm je za `call` hned `test al,al` nebo `mov ?, eax` | `sub_106AF3` (3 volajici), `sub_BBC6F`, `sub_BBC8B` |
| prazdny thunk | v portu `void f() { JUMPOUT(0x...); }`; v asm `push <priznak> / jmp <spolecne telo>` | `sub_B55C7`, `sub_B53C8`, `sub_BBC6F` |
| argument ulozeny prologem | `[ebp+var_N]` se v cele funkci jen CTE; v prologu je `push eax` hned za `enter` | `sub_B55CF` (`v58` = `a1`) |

Postup u thunku: najdi sourozence se stejnym telem a jinym priznakem - ten uz
byva v portu spravne prelozeny a staci ho okopirovat.

### Retez kresleni COLONIES (overeny obema stranami)

```
sub_1049B -> sub_C4562 -> sub_C3D34 -> sub_C26F4  -> sub_103BC4 -> sub_103D53   (pravy panel)
                                    -> sub_C3B3C  -> sub_B55C7  -> sub_B55CF    (stredni panel, panacci)
                                                  -> sub_B53C8  -> sub_B53CC
                                                  -> sub_1031AA                 (levy panel)
                                    -> sub_90C4F                                (nahled soustavy)
```


### Sonda: casova brana a flush (vlna 129)

`PortDebug_ProbeLog` (port_dos.cpp, `REORION2_PROBE_LOG=1`) ma dva doplnky,
bez kterych se sonda chova zradne:

- **`REORION2_PROBE_ARMED` / `REORION2_PROBE_AFTER_MS`** - `PortDebug_ProbeArmed()`
  vrati true az po zadane milisekunde behu. Kreslici funkce se volaji
  desetitisickrat uz behem intra, takze sonda s poctovym limitem (`n < 40`) se
  vycerpa driv, nez hra dojde na merenou obrazovku. Prah se dava stejne jako
  cas kliku v `REORION2_CLICK`.
- **flush po kazdem radku** - beh sondy koncime `taskkill /F`, takze bez nej
  se posledni (a casto jediny zajimavy) kus logu ztrati v bufferu. Proti
  `PortDebug_CrashLog` je to porad jen jeden zapis misto fopen+write+fclose.

### Nedodelana rodina sub_24ACA (vlna 129)

Dosazovani cisel a jmen do retezcu z LBX. **V portu nema `sub_24ACA` ani
jednoho volajiciho** - vsechny thunky nad ni jsou bud `DECOMP_TODO` pahyly
(`sub_24D4C`, `sub_24E08`, `sub_24E54`), nebo `JUMPOUT` NO-OPy (`sub_24D6A`,
`sub_24D83`, `sub_24DF0`, `sub_24E27`, `sub_24E3E`, `sub_24E73`). Samotna
`sub_24ACA` je prelozena spatne (`v53` je neinicializovany ukazatel na format,
argumenty slite do `a29`/`a33`/`a34` jako int64).

Projev: v retezci chybi cislo - napr. "Net Income:  BC" misto
"Net Income: 8 BC" na INFO. Kdykoliv v porovnani chybi jen CISLO a text kolem
nej sedi, je podezreni na tuhle rodinu.

Prevod argumentu thunku (Watcom: eax, edx, ebx, ecx, pak zasobnik; posledni
`push` je prvni zasobnikovy argument):

```
sub_24E08(eax=buffer, dx=hodnota, bx=velikost)
    -> sub_24ACA(buffer, -1, -1, -1, hodnota, -1, -1, -1, velikost, ecx_orig)
sub_24D4C(eax=buffer, dx=v1, bx=v2, cx=velikost)
    -> sub_24ACA(buffer, v1, -1, -1, v2, -1, -1, -1, velikost)
```


### Kontrolni seznam pro "zkracenou tabulku" (doplneno vlnou 130)

Vzorec uz poctvrte. Priznak: kod indexuje `pole[2*i]`, ale pole je v portu
jednoprvkove a hned za nim je druhy symbol s "zbytkem".

```
word_A[]   = { prvni_x };
word_B[13] = { y0, x1, y1, x2, y2, ... };
```

Oprava: slouc do `word_A[N]` s hodnotami z obrazu a z `word_B` udelej makro
`(word_A + 1)`. N urci **dalsi symbol** v `orion_data.c`.

Nalezene dosud: `byte_1B071B` (v126), `byte_183C27` (v129), `word_183FF1`,
`word_18400D`, `word_184037`, `word_184053`, `word_18406F` (v130).

**Pozor na tabulky schovane v `align`**: `byte_100A36` mela v `.lst` jen
`db 0`, pak `align 4`, `dd 0F6F60F0Ah` a `db 2 dup(0Fh)` - dohromady 8 bajtu.
`dumpdata.py` je ukaze vsechny; `.lst` ne.

### Tyz symbol dvakrat (vlna 130)

IDA dava temuz miste ruzna jmena podle toho, jak se na nej kod diva
(`unk_` = neznamy typ). Kdyz pak `link_stubs.c` vyrobi `int unk_ADR;`
a `orion_data.c` ma na te adrese skutecna data, vzniknou **dva objekty**:
jeden se plni, z druheho se cte.

Sken: `scratchpad/scan_alias.py` (adresy z obou souboru, prunik). Vlna 130
nasla 13 kolizi; vsechny se pouzivaly jen jako `&unk_X`, takze staci
`#define unk_X (*realny_symbol)` v `orion_common.h` a pahyl smazat.

Priznak v obraze: text/hodnota se pocita spravne, ale kresli se prazdno.

### Prazdne thunky - jak je poznat a opravit

`void f() { JUMPOUT(0x...); }` v portu = **NO-OP**. V asm je to
`push <priznak> / jmp <spolecne telo>`.

Postup: najdi sourozence, ktery skace do TEHOZ tela s jinym priznakem - ten
uz byva v portu prelozeny spravne a staci ho okopirovat. Poradi zasobnikovych
argumentu: **posledni `push` je prvni zasobnikovy argument**.

Nalezene dosud: `sub_B55C7`, `sub_B53C8`, `sub_BBC6F` (v129),
`sub_102FA8`, `sub_10275F`, `sub_102776` (v130).


### Hardwarovy watchpoint (vlna 130)

Kdyz se v portu prepisuje pamet, nehadej podle sousedu - nech to rict procesoru:

```c
extern void PortDebug_WatchWrite(void *addr, int len);   /* len = 1, 2 nebo 4 */
PortDebug_WatchWrite(&dword_1BB880, 4);
```

Nastavi debug registr (DR0-DR3) na zapis; `DebugVectoredHandler` v reorion2.cpp
odchyti `EXCEPTION_SINGLE_STEP`, vypise instrukci i cely zasobnik a bezi dal.
Ctyri watchpointy naraz, per-vlakno (volat z hlavniho vlakna).

Vlna 130 tim nasla prepis palety a AIL handlu na prvni pokus - `byte_1BD154[i] = 1`
v `sub_139D7E` s nesmyslnym `i`.

### Prekryvajici se pohledy na jednu tabulku (vlna 130)

Nejzakernejsi varianta "zkracene tabulky": IDA vyrobi NEKOLIK symbolu, ktere
ukazuji do TEHOZ bloku s ruznym posunem, a vsechny krome jednoho jsou
jednoprvkove. `scan_velikosti.py` je nenajde (kazdy ma "spravnou" vzdalenost
k sousedovi), pozna je az **indexace v kodu**:

```
dword_1BD352[3*i]   word_1BD356[6*i]   word_1BD358[6*i]   byte_1BD35A[12*i]
```

Ruzne nasobky u sousednich adres = jeden zaznam, tady 12 bajtu:
`3*i` dwordu = 12*i B, `6*i` slov = 12*i B, `12*i` bajtu = 12*i B.
Krok v bajtech vyjde u vsech stejny -> je to jedna tabulka a symboly jsou
jen pohledy na jeji pole.

Oprava: jeden `char blok_ADR[velikost]` a z ostatnich udelat makra s pretypovanim.
Velikost = vzdalenost k prvnimu symbolu, ktery uz do bloku nepatri.


### Argument ulozeny prologem (uz potreti - vlna 131)

Watcom u vetsich funkci ulozi prvni registrovy argument hned za `enter` pres
`push eax`, tedy POD ramec. IDA z toho udela lokalku, kterou uz nikdo
neinicializuje, a sama to prizna hlaskou `variable 'vX' is possibly undefined`.

Poznaci se to takhle:
1. IDA hlasi "possibly undefined" pro promennou, ktera vypada jako index/handle.
2. V asm je hned za `enter <N>, 0` instrukce `push eax`.
3. Slot `[ebp-(N+4)]` (u IDA `[ebp+fpd+var_(N+4)]`) se v cele funkci **jen cte**.

Nalezene: `sub_10BFBD` (v122), `sub_B55CF` (v130, `v58`), `sub_A31DA` (v131,
`v50` i `v51` - tyz slot dvakrat).

Rychla kontrola vsech kandidatu:
```bash
grep -rn "possibly undefined" src/game/*.c | wc -l
```

### Tabulka schovana v nepojmenovanych `db`/`dd` (vlna 131)

`word_EB4C5` a `word_138405` mely v `.lst` pojmenovany jen PRVNI prvek a zbytek
zustal jako `db 0C0h, 2, 74h` / `dd 0F603B501h ...` bez jmena. `scan_velikosti.py`
je nenajde (dalsi POJMENOVANY symbol je daleko), pozna je az indexace v kodu
(`tabulka[2*i]`, `tabulka[uhel]`) a vypis z obrazu pres `dumpdata.py`.

Sinusova tabulka `word_138405` (sin(deg)*65536, 0..89) je zvlast zradna: port
z ni mel jen nulu, takze VSECHNY uhly krome nuly davaly 0. Projevilo se to az
o tri urovne vys - planety v pohledu na soustavu se nakupily do stredu - a
zaroven to tise kazilo stinovani na COLONIES.


### Kde lezi referencni disassembly (vlna 131)

**Ne v `Debug/diss/`.** Ta cesta je v `.gitignore`, takze prepnuti vetve ten
adresar smaze a nastroje prestanou fungovat - presne to se stalo ve vlne 131.

Referencni data (`Orion2.exe`, `.lst`, `.asm`, `.c`, `.map`, ...) patri
**mimo pracovni strom**, doporucene do `C:/prenos/reorion2Data/diss/`.

Nastroje si cestu najdou samy pres `tools/compare/diss.py`:

```
1. promenna prostredi REORION2_DISS
2. C:/prenos/reorion2Data/diss
3. Debug/diss (stara cesta, pokud jeste existuje)
4. C:/prenos/mastori2/diss
```

```python
from diss import soubor
open(soubor('Orion2.exe.lst'), 'rb')
```

Kdyz nic nenajde, skonci s hlaskou, kde hledal - ne s `FileNotFoundError`
uprostred mereni.

### tools/compare/owner.py

`ret=` z dosboxoveho trace -> `sub_XXXXX+0xNN`. Zakladni krok metody
"zespoda nahoru": sonda `DUMPREGS cond=eip:<funkce> repeat=always` rekne,
KDO tu funkci vola, a to i s x/y (eax/edx) a tretim argumentem (ebx).

```bash
python tools/compare/owner.py <trace.txt> [cyklus_od] [cyklus_do]
```

Skript uz nepiste porad dokola do scratchpadu - je soucasti repozitare.


### Tyz symbol definovany dvakrat (vlna 132)

`link_stubs.c` a `orion_data.c` obcas definuji **tentyz nazev**:

```c
/* link_stubs.c */   int word_1931BC;
/* orion_data.c */   int16_t word_1931BC[];
```

V C jsou to obe "tentative definitions". MSVC je emituje jako COMMON a linker
je **slouci - vezme tu vetsi**. Vysledek: z dvoubajtoveho pole je ctyrbajtovy
objekt, `memset(&word_1931BC, 0, 180)` do nej psal daleko za nej a tise nicil
sousedni globaly.

Sken (prunik nazvu mezi obema soubory) najde **181 takovych dvojic**. Vetsina
je nejspis neskodna, ale kazdy `memset`/`qmemcpy`/`strcpy` pres takovy symbol
je latentni prepis pameti. Priznak: hlidace portu hlasi prepsany global,
nebo se data "sama od sebe" meni.

```python
# prunik definic mezi link_stubs.c a orion_data.c
vz = re.compile(r'^(?:[A-Za-z_][A-Za-z0-9_ ]*?)\s*\**\s*'
                r'(?P<jm>[A-Za-z_][A-Za-z0-9_]*_[0-9A-Fa-f]{4,6})\s*(\[[^\]]*\])?\s*(=|;)')
```

Opravene dosud: 13 s prefixem `unk_` (vlna 130), `word_1931BC/BE/C0/C2` (vlna 132).

### Kde hledat velikost bloku: primo v kodu

Nejlepsi dukaz velikosti tabulky neni sousedni symbol, ale **`memset` v hernim
kodu**. `memset(&word_1931BC, 0, 180)` rekne rovnou 180 bajtu - a sedelo to
i s `0x193270 - 0x1931BC`.

```bash
grep -rn "memset(&\|qmemcpy(&" src/game/*.c | grep -v "sizeof"
```

