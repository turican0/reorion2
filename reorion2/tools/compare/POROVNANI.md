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

