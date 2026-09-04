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


### Srovnani PAMETI mezi portem a dosboxem (vlna 133)

Kdyz se hypotezy zacnou stridat rychleji nez mereni, prestan hadat a **odecti
tutez pamet z obou stran**. Ve vlne 133 to nasло pricinu na prvni pokus,
kdyz tri predchozi domnenky merenim padly.

**dosbox** - `DUMPMEM` umi jen `cond=eip:` a vypali JEDNOU, takze spousteci
adresa musi byt funkce, ktera bezi jen na merene obrazovce:

```
DUMPMEM cond=eip:<funkce + 0x224000> addr=<data + 0x216000> size=<N> label=x
```

Velikost neni omezena - klidne 1728 B naraz, at je v jednom vypisu cela
struktura i jeji pomocne tabulky.

**port** - sonda na tomtez miste, vypis pres `PortDebug_ProbeLog` v hex.

**odecteni** - hledej PRVNI odlisny bajt. Ve vlne 133 vyslo "zaznamy 0..191
sedi, 192..255 ne", coz okamzite rekne, ktery blok se plni spatne; setrideny
seznam a kbelicky uz byly jen nasledek.

Pozor na ukazatele: v portu jsou 64bitove, v dosboxu 32bitove herni adresy.
Porovnavej je jako ODSTUPY od prvniho prvku, ne absolutne.

Az je blok zuzeny, doraz to hardwarovym watchpointem na jeho prvni bajt -
ten rekne zapisovatele.


### Dobra doba behu dosboxovych sond (vlna 134)

`STOP cond=cycle_ge:140000000` staci - klik na zalozku padne kolem 81M cyklu.
Puvodnich 200M znamenalo 15+ minut na jedno mereni.

**Oba `esc` (cycle_ge:40000000 i 90000000) tam musi zustat.** Emulace neni mezi
behy uplne deterministicka (`cycles=auto` v moo2_sondy.conf), takze intro
nekdy dobiha dyl; bez druheho `esc` se hra do menu nedostane a beh propadne
naprazdno - trace je prazdny a vypada to jako "sonda nic nenasla".

Kontrola v logu: musi tam byt `SENDKEY : stisk v cyklu ... (eip=002A56F2)`.
Kdyz tam neni, hra se do menu nedostala a mereni je neplatne.


### Trida poskozeni 9: `memset` pres nekolik samostatnych symbolu

`memset(&symbol, v, N)`, kde `N` je vetsi nez velikost `symbol`, znamena, ze
v originale slo o **jeden souvisly blok**, ktery IDA rozdrobila na nekolik
symbolu. V portu jsou to samostatne objekty a memset prepise **cizi pamet**.

Priklad (vlna 135):

```c
memset(&word_199EC7, -1, 9);   /* word_199EC7 je int16_t = 2 B */
```

Blok 0x199EC7..0x199ED0 = `word_199EC7/EC9/ECB/ECD` + `byte_199ECF`.

**Jak to poznat plosne:** hledej `memset`/`memcpy`, kde treti argument je vetsi
nez `sizeof` ciloveho symbolu. Velikost bloku potvrd adresou nasledujiciho
symbolu (tady `word_199ED0` = 0x199EC7 + 9).

**Proc je to zakerne:** chyba se neprojevi, dokud linker nepolozi za obet neco
dulezitehо. Vlna 135 ji odhalila az tim, ze vlna 134 zvetsila `byte_199EC2`
z jednoho bajtu na pet a linker ho presunul prave za `word_199EC7`. Kazde
sloucovani tabulek muze takovou latentni chybu probudit - proto po nem VZDY
promerit vsechny obrazovky, ne jen tu opravovanou.

### Nasazovani watchpointu: kdyz nic nezachyti, arm ho DRIV

Watchpoint, ktery nezasahne, neznamena "nikdo tam nepise" - znamena "nikdo tam
nepise PO nasazeni". Nasazuj ho co nejbliz k mistu, kde je hodnota jeste
spravna, ideálne **hned za inicializaci**, a k tomu si nech vypsat obsah:

```c
PortDebug_ProbeLog("EC2 po inicializaci: %d %d %d %d %d", ...);
PortDebug_WatchWrite(&pole[0], 1);
PortDebug_WatchEnable(1);
```

Vypis rekne, jestli je vychozi stav spravny (a hledas prepisovatele), nebo uz
inicializace sama je spatne (a hledas jinde).

### Regresni brana `gate.py`

`genCompare/compare_frames.exe` nikdy nebyla v gitu a pri prepnuti vetve zmizela.
Nahradil ji `tools/compare/gate.py`, ktery **v gitu je**:

```
python tools/compare/gate.py <ref_dir> <port_dir> 640 480
```

Snimky portu: `REORION2_BLIT_DUMP_DIR=<d> REORION2_BLIT_DUMP_COUNT=600
REORION2_DUMP_INCLUDE_PALETTE=1 REORION2_VIDEO_AUDIO=0`.
Referencni sada patri do `C:/prenos/reorion2Data/`, ne do pracovniho stromu.
Branu nikdy nepoustej, kdyz bezi dosbox.


### Animovane oblasti: porovnavej MINIMUM pres snimky, ne jeden snimek

Pevne cislo "918 rozdilnych pixelu" muze byt z vetsiny artefakt mereni.
Na LEADERS se otaceji planety, takze porovnani jednoho snimku portu s jednim
snimkem dosboxu ukazalo 690 px rozdilu tam, kde je port **pixel-presny** -
jen v jine fazi otaceni.

Postup:

1. **Rozdel rozdilove pixely do shluku** (souvisle oblasti, tolerance ~3 px)
   misto jednoho souctu. Shluk je jedna vec, kterou lze samostatne vysetrit.
2. Pro kazdy shluk vezmi **minimum pres vsechny zachycene snimky portu**.
   Shluk, ktery nekde klesne na 0, je hotovy - jde o animaci, ne o chybu.
3. Teprve zbytek je skutecny rozdil.

Kdyz shluk na 0 neklesne, jeste over **posun**: zkus dx,dy v rozsahu -4..+4.
Kdyz nejlepsi vysledek zustane na dx=0,dy=0, neni to posunuty obraz.

### Barevne rampy fontu (8 B) - kde hledat cernou barvu textu

Kdyz text ma SPRAVNE TVARY, ale spatnou barvu, chyba neni v kresleni fontu.
Barva glyfu je `byte_1B3E7C[k-1]`; tu plni `sub_120BB5(font, rampa)` z
osmibajtove rampy. Rampy jsou v datech souvisle rady osmibajtovych bloku,
ktere IDA casto vypise jako `_UNKNOWN` skalary - pak je rampa v portu nulova
a text vychazi CERNY.

Sonda, ktera to rekne hned:

```c
PortDebug_ProbeLog("120BB5 font=%d rampa=%02X %02X %02X %02X %02X %02X %02X %02X", ...);
PortDebug_Backtrace("rampa", 4);
```

Skutecne bajty pak `tools/compare/dumpdata.py <asm adresa> 8 --data`
(asm adresa = C jmeno - 0x8000). **Vzdy over posun na sousedni jiz opravene
rampe** - kdyz sedi bajt po bajtu, cte se na spravnem miste.

Zname rampy u sebe (vlna 122 + 136): 18227C, 182284, 182298, 1822A0,
1822A8, 1822B0. Kdyz najdes dalsi `_UNKNOWN` mezi opravenymi rampami,
je to skoro jiste taky rampa.


### Sondovy soubor se dosboxu predava pres DOSBOX_CTL_FILE, NE druhym -conf

```
DOSBOX_CTL_FILE="<cesta>/muj.cfg" \
  C:/prenos/dosbox-x-remc2/bin/x64/Release/dosbox-x.exe -conf moo2_sondy.conf
```

Kdyz se sondovy soubor preda jako **druhy `-conf`**, dosbox ho vezme jako
dalsi KONFIGURACI, nezname klice tise zahodi a **zadny verb se nespusti**.
Beh pak dojede az do `STOP` (nebo visi v menu), trace je prazdny a vypada to
jako "sonda nic nenasla" - stejne zradne jako vypadly `esc` z vlny 134.

**Kontrola pred cekanim na vysledek:** v behovem logu musi byt radky
`SENDKEY` / `SENDCLICK` / `DUMPMEM`. Kdyz tam nejsou, ctl soubor se vubec
nenacetl - beh zabij a spust znovu spravne, nemá smysl cekat.


### Trida poskozeni 10: dva zasobnikove sloty splacane do jedne promenne

Kdyz IDA slouci nekolik sousednich zasobnikovych slotu do jedne siroke
promenne (typicky `int64_t`), zacnou `SWORD1`, `SHIWORD` a `HIWORD` nad ni
ukazovat na **TYZ dvoubajt** (vsechna tri jsou `*((short *)&x + 1)`), i kdyz
v originale jde o RUZNA mista.

Priklad (vlna 137, `sub_77048`):

```c
int64_t a26;                 /* pokryva arg_64..arg_6B */
SWORD1(a26)   /* a26+2 = arg_66  - index  */
SHIWORD(a26)  /* a26+2           - ale asm cte arg_6A = a26+6 */
```

Port pak misto `arg_6A/2` odecital `index/2` a znacky objektu na male mape
byly o `index/2` radku vys.

**Jak to poznat:** kdyz je promenna sirsi nez 4 B a pouzivaji se nad ni
`SWORD1` i `SHIWORD`/`HIWORD` s ruznym VYZNAMEM (jednou index, jindy hodnota),
je to skoro jiste tohle. Over v `.lst`, ktere `arg_XX` asm na tom miste cte.

**Pozor - zapis byva spravne.** V teto vlne `sub_773B7(..., (_WORD *)&a26 + 3)`
plnil arg_6A korektne; poskozena byla jen CTENI. Nehledej tedy chybu
u zapisovatele, kdyz sedi.

**Oprava:** pojmenovane makro na spravny offset, platne jen v te funkci:

```c
#define PORT_A26_ARG6A (*((int16_t *)&a26 + 3))
...
#undef PORT_A26_ARG6A
```

### Pozor pri davkove nahrade: neprepis vlastni komentar

Skript, ktery nahrazuje `SHIWORD(a26)` -> `PORT_A26_ARG6A` v rozsahu funkce,
zasahne i komentar, ktery si prave vlozil a ten retezec v nem ma. Pocitadlo
nahrad pak nesedi. Bud komentar formuluj bez toho retezce, nebo nahrazuj az
pred jeho vlozenim.


### Kurzor mysi: port ho kresli do dumpu, dosbox ne

Hru si kurzor kresli sama (`port_dos.cpp`, INT 33h funkce 2 - "schovej kurzor,
hra si kresli vlastni"), takze v portu skonci v tomtez bufferu, ktery se
dumpuje. Dosboxovy `DUMPFRAME` ale cte obraz hry BEZ nej.

**Dusledek:** kazde mereni zalozky, kde kurzor lezi nad obsahem, ma navic
~226 px "rozdilu", ktery neni chyba portu. Na FLEETS to bylo 226 z 228 px -
skutecny rozdil jsou 2 px.

**Jak to poznat:** shluk ~20x17 px prave tam, kam skript naposledy presunul
mys. **Jak to dokazat:** pridej do `REORION2_CLICK` presun jinam
(`;620,300@62000:0`) a znovu zmer - kdyz se shluk presune s mysi, je to kurzor.

Pri mereni zalozek kurzor vyrad - maskou na jeho zname pozici nebo presunem
mimo zajmovou oblast.

### Cervena brana nemusi byt regrese - overuj, ze beh vubec probehl

Beh portu obcas propadne: hra nespusti intro a nabehne rovnou do menu.
Brana pak hlasi ~1/600 matched, protoze reference ma intro video.

Kontrola: vyrenderuj snimek 5 z portu. Kdyz je na nem MENU misto hvezdnych
car intra, beh je neplatny - opakuj ho, nehledej regresi. Tataz trida jako
vypadly `esc` (vlna 134) nebo ctl soubor predany druhym `-conf` (vlna 136):
**vzdy nejdriv over, ze mereni vubec probehlo, nez zacnes vysetrovat vysledek.**


### Jmena `arg_XX` od IDA nemusi byt offsety - u posunute baze jsou posunuta

Kdyz funkce v prologu posune bazi (`sub ebp, 82h`), IDA pojmenuje argumenty
podle nejakeho vlastniho pocatku, ne podle skutecneho offsetu. U `sub_24ACA`
(vlna 139) plati **jmeno = offset - 0x10**:

```
arg_82 je na offsetu 92h,  arg_86 na 96h,  arg_92 na 0A2h
```

Skutecne zasobnikove argumenty zacinaji na `[ebp_orig + 10h]` (za `push esi`,
`push edi`, ulozenym `ebp` a navratovou adresou).

**Nikdy neodvozuj prirazeni pseudoargumentu `aN` aritmetikou z jejich cisla** -
IDA michá dvou- a ctyrbajtove pseudoargumenty, takze cislovani nesedi.
Misto toho **projdi asm radek po radku** a u kazdeho pouziti `aN`
v dekompilatu se podivej, ktere `[ebp+arg_XX]` se tam ve skutecnosti cte.
U `sub_24ACA` to dalo jednoznacne prirazeni sedmi mist na pet argumentu,
zatimco aritmeticky odhad vychazel pokazde jinak.

### Prazdny thunk + prolog ukladajici registry = dve tridy poskozeni naraz

`sub_24E08` (vlna 139) byl `DECOMP_TODO`, ale sam o sobe je trivialni - jen
nastavi -1 a skoci do sdileneho tela. Problem byl, ze **i to sdilene telo**
melo poskozeny ramec (registrove argumenty jako neinicializovane lokalky).
Opravit jen thunk by nepomohlo.

Priznak, ze telo je taky rozbite: IDA pod nim vypise
`variable 'vXX' is possibly undefined` prave pro ty lokalky, ktere odpovidaji
slotum ulozenym prologem (`push eax/edx/ebx/ecx` hned za `enter`).


### Kdyz sonda na blitteru mlci, hledej text

Drobny prvek na obrazovce nemusi byt sprite. Ve vlne 140 sonda na RLE
blitteru `sub_14852C` v oblasti znacky nenasla nic navic - a **dosboxova
sonda na `sub_12A478` dala presne tytez volani jako port**. To je silny
signal: kdyz obe strany kresli pres blitter totez, a presto se obraz lisi,
jde ten rozdil JINOU cestou - typicky pres font (`sub_1212B3`,
`sub_1231B1`).

Postup pak je: najit funkci, ktera to misto pocita (tady `sub_9AC79`,
`a1 + 6` a `a2 - 1`), overit sondou, ze se do ni port dostane, a teprve pak
se divat, CO se kresli. Ve vlne 140 se kreslil prazdny retezec, protoze
`unk_179B8D/90/92` ("oc", "o", "c") byly jednobajtove `_UNKNOWN` pahyly.

### Sousedni lokalky, ze kterych se cte jako z jednoho bloku

`sub_9AC79` dela:

```c
int v28;        /* [ebp-24h] */
char v29[12];   /* [ebp-20h] */
sub_120BB5(0, (int)&v28);   /* cte OSM bajtu */
```

`sub_120BB5` cte osmibajtovou rampu, `v28` ma ctyri bajty - v originale za
nim v ramci lezi `v29`, takze rampa je `v28` + prvni ctyri znaky `v29`
("BA??"). Ze je to zamerne, potvrzuje hodnota `v28` = 0x43393A00: bajt 0x3A
je presne barva, kterou ta znacka ma.

V portu jsou to samostatne lokalky a jejich sousednost prekladac
NEGARANTUJE. Je to tataz trida jako `memset` pres nekolik symbolu (vlna 135),
jen na zasobniku misto v datech. Hledej `sub_120BB5`/`memcpy`/`memset`, kde
je delka vetsi nez `sizeof` predaneho objektu - a poznamenej si to i tam,
kde to zatim nevadi.


### `cond=changed:ADDR:W` neni spolehlivy hlidac zapisu

Ve vlne 141 watch na bajt framebufferu spravne reprodukoval dve ze tri hodnot,
ktere ma dany pixel v referencnich snimcich (`3B`, `04`), ale **treti (`0D`)
nenahlasil nikdy** - ani pri behu na plnou delku. Adresa pritom byla overene
spravna: `DUMPFRAME` cte pamet lineárne
(`fb[i] = mem_readb(w.framebuf + i)`, `src/engine/engine.cpp`).

Nejpravdepodobnejsi vysvetleni: watchi unikaji blokove zapisy (`rep movsd`).

**Nepouzivej ho tedy jako dukaz, ze se nekam nezapisuje.** Kdyz `cond=changed`
mlci, ale obsah snimku se lisi, je to signal o NASTROJI, ne o hre.

Nahradni postup: `DUMPMEM` na tutez oblast ve dvou ruznych okamzicich (dve
spousteci `eip`) a odecteni - ukaze, mezi kterymi dvema body se hodnota meni,
a odtud uz jde zuzovat dal.

### Srovnani SEZNAMU volani je silnejsi nez srovnani jednoho mista

Ve vlne 141 se ukazalo uzitecne vypsat **vsechna** volani kreslici funkce
z obou stran a porovnat mnoziny pozic:

* v portu sondou bez filtru (cap 400 radku),
* v dosboxu `DUMPREGS cond=eip:<funkce> repeat=always`.

**Dosboxovou stopu je nutne zuzit na spravne obdobi** - pokryva cely beh
vcetne obrazovek pred merenou zalozkou. Kotva: prvni vyskyt nektere pozice,
ktera patri jen te zalozce (tady `(425,435)`, cyklus 133 750 768). Bez toho
zuzeni vychazelo 46 "chybejicich" volani, po nem **nula**.

Kdyz se seznamy shoduji beze zbytku, rozdil neni v tom, CO se kresli, ale
v datech nebo uvnitr kreslici rutiny - a hledani se tim posune o patro niz.


### Korelace DUMPFRAME + DUMPREGS v jednom behu

Kdyz potrebujes vedet, KTERE volani zpusobilo zmenu na obrazovce, a
`cond=changed` neni spolehlivy (vlna 141), pust v JEDNOM behu obojí:

```
DUMPREGS  cond=eip:<kreslici funkce> label=blit repeat=always
DUMPFRAME cond=eip:0x00349814 framebuf=0x452044 width=640 height=480 maxcount=60 dir=...
```

`DUMPFRAME` zapisuje do OUTPUT radek `FRAME <label> cycle=<N> index=<i>
file=<cesta>`, `DUMPREGS` zapisuje kazde volani rovnez s cyklem. Pak staci
najit dva sousedni snimky, mezi kterymi se sledovane misto zmenilo, a vypsat
volani v jejich cyklovem okne.

### NEJDRIV OVER REFERENCI, teprve pak hledej chybu v portu

Ve vlne 142 se ukazalo, ze rozdil 228 px na FLEETS (226 "kurzor" + 2 px na
spodnim radku) **nebyl chybou portu vubec** - referencni sada
`scratchpad/dbx/fleets` byla porizena v behu, kde mys skoncila jinde a
spodni hrana mela jiny obsah. Proti CERSTVE porizene referenci je rozdil
**0 px**.

Stalo to dve vlny hledani (138 a 141) a vedlo to k zapsani chybneho zaveru
("dosbox kurzor nekresli, port ano"), ktery je ted opraveny.

**Pravidlo:** kdyz zbyva maly rozdil, ktery nejde vysvetlit, nebo kdyz
vysvetleni zacina znit jako "artefakt mereni", **porid referenci znovu**.
Je to jeden beh dosboxu (~4 minuty) proti hodinam hledani neexistujici chyby.

Referencni sady patri do `C:/prenos/reorion2Data/`, ne do scratchpadu -
scratchpad je docasny a jeho sady zastaravaji.


### "U tebe to funguje, u me ne" = hledej PROSTREDI, ne kod

Ve vlne 143 se stejny build choval jinak u me a u uzivatele. Pricinou nebyl
kod, ale **pracovni adresar**: `fopen("MOX.SET", "rb")` je relativni cesta.
Ja spoustel z `x64/Debug` (soubor tam neni -> pouziji se vychozi hodnoty),
uzivatel z korene projektu, kde lezel poskozeny `mox.set`.

Kdyz se projev lisi mezi dvema spustenimi teze binarky, projdi v tomhle
poradi:

1. **pracovni adresar** a vsechny relativni cesty (`fopen` bez cesty),
2. datove soubory vedle exe i v hernim adresari (`find -iname` napric stromem
   - klidne najdes tri kopie s ruznym obsahem),
3. promenne prostredi,
4. teprve pak kod.

A pozor na **verzovane stavove soubory**: `mox.set` byl v gitu, takze se
poskozeny stav vracel po kazdem checkoutu. Stavove soubory, ktere si hra sama
prepisuje, do repozitare nepatri.

### Sebeuzamykajici se poskozeny stav

`sub_12227` nacte `mox.set`, nastavi znacku `word_199CBE = 130` a soubor
**zapise zpet**. Kdyz byl vstup prazdny, ulozi se nuly SE znackou - a od te
chvile hra soubor povazuje za platny a vychozi hodnoty uz nikdy nepouzije.
Originál to ma stejne, takze to neopravuj; jen o tom vedet.


### Runtime adresa dat = C jmeno + 0x216000, NE asm jmeno

Ve vlne 145 jsem si tim vyrobil falesny nalez: spocital jsem
`0x191BE0 + 0x216000` (ASM jmeno `byte_191BE0`) misto
`0x199BE0 + 0x216000` (C jmeno `byte_199BE0`). Rozdil je prave tech 0x8000,
takze adresa ukazovala na uplne jinou promennou - nahodou dovnitr tabulky
`word_1906C0`, kterou hra plni `memset(-1, 6864)`. Vysledek: "v originale je
tam 0xFF, v portu 0" a hodina honeni neexistujici chyby.

**Kontrola:** kdyz z watchpointu vyleze podezrele kulata hodnota (same 0xFF),
over, jestli adresa nelezi uvnitr nejakeho velkeho pole, ktere se memsetuje.
`DUMPMEM` na sousedni bajty to ukaze hned.

### `DUMPREGS` nepodporuje `cond=cycle_ge:`

Jen `cond=eip:`, `cond=eax:` a `cond=changed:`. Pri `cycle_ge` ctl hlasi
*"DUMPREGS bez platne cond=eip:/eax:/changed:, preskakuji"* a mlci.
Vypsat okno instrukci kolem konkretniho cyklu takhle nejde - pouzij misto
toho `cond=eip:` na kandidatske funkci, nebo `changed:` na dotcene pameti.

### Kdyz sonda na blitteru mlci, zkus DISPECERA, ne jen jednu vetev

Vlna 146: znak na (305,149) nekreslil `sub_14852C` ani textove
`sub_1210FD`/`sub_1212B3`. Kreslil ho `sub_12A478` - DISPECER, ktery podle
`*(_BYTE *)(dword_1BC2A8 + 11) & 3` vybira mezi `sub_14852C`, `sub_1485B3`,
`sub_12B2D9`/`sub_12AFCC`. Sonda na dispecerovi pokryje vsechny vetve naraz
a rovnou da i backtrace.

### Sourozenci lisici se jedinym bajtem offsetu

`sub_79CF9` (bajt +3Fh) a `sub_79D50` (bajt +40h) sdileji telo od `loc_79D0F`.
IDA prvni dekompilovala spravne a z druhe udelala `JUMPOUT` - v portu NO-OP.

**Postup, kdyz najdes `JUMPOUT` thunk:** podivej se na asm TESNE PRED cilem
skoku. Sdilene telo je obvykle konec sousedni funkce, ktera uz v portu
implementovana JE - staci ji zkopirovat a zmenit ten jeden lisici se detail.


### Zahozena navratova hodnota: pozor na `for` a `++i`

Vlna 147: `sub_78800` v asm drzi vysledek v `ebx` (`mov ebx, eax` pri
nalezeni) a vraci ho (`mov eax, ebx`). Port ji mel jako `void`.

Pri doplnovani NESTACI vratit citac smycky: dekompilovany `for (i = 0;
i < N && !v2; ++i)` provede `++i` i v iteraci, kde se naslo, takze `i`
ukazuje **o jedna dal** nez asm `ebx`. Vzdy zaved samostatnou promennou
presne tam, kde asm dela `mov ebx, eax`.

### Jak najit VSECHNY volajici, kteri navratovou hodnotu potrebuji

Vypis v `.lst` vsechna `call sub_XXXX` a podivej se na NASLEDUJICI instrukci:

```
cwde / movsx ecx, ax / mov ebx, eax / mov [ebp+var_N], eax / imul eax, ...
        -> navratovou hodnotu POUZIVA
lea eax, [...] / mov eax, <neco jineho>
        -> eax se PREPISE, volajici ji nepotrebuje
```

Ve vlne 147 to z osmi volani `sub_78800` oddelilo sedm "pouziva" od jednoho
"nepotrebuje" - a rovnou reklo, do ktere promenne v portu hodnota patri
(`mov ebx, eax` -> promenna komentovana `// ebx`, `mov [ebp+var_8], eax` ->
lokalka na `[ebp-8]`).

### Zpetne apostrofy v komentarich pri generovani pres bash

`python -c "...'`mov eax, ebx`'..."` uvnitr dvojitych uvozovek v bashi:
zpetne apostrofy se vyhodnoti jako substituce prikazu a text z komentare
ZMIZI (a bash hlasi "movsx: command not found"). Patchovaci skripty piš
pres nastroj Write, nebo se zpetnym apostrofum v generovanem textu vyhni -
je to tataz trida jako zakaz heredocu kvuli zpetnym lomitkum.

