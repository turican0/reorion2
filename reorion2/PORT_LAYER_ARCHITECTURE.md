# Port Layer Architecture — základní infostruktura

> Účel dokumentu: základ pro AI (nebo člověka), který bude postupně
> generovat/rozšiřovat `port_*.cpp` vrstvu při dekompilaci DOS4GW/Watcom
> executables (Orion2, Magic Carpet 2 apod.) v rámci `exetool` / REMC2
> ekosystému. Vychází z analýzy zdrojové struktury **DOSBox-X**
> (`src/hardware`, `src/ints`, `src/gui`, `src/dos`, `src/misc`) a z
> konvencí použitých v **REMC2** (čisté oddělení dat od reprezentace,
> jedno „centrum pravdy" pro stav, žádná logika rozeseta v UI/vstupní
> vrstvě).

---

## 1. Filozofie vrstvy

Dekompilovaný kód hry (`Orion2.exe` apod.) volá DOS/BIOS interrupty a
porty (`INT 10h`, `INT 21h`, `INT 33h`, `IN/OUT` na I/O portech PIC/PIT/
Sound Blasteru...). Tyto volání **nepřepisujeme přímo na SDL volání
uvnitř herní logiky**. Místo toho:

1. Herní kód (přeložený 1:1 z disassembly) zůstává volat funkce, které
   vypadají jako tenké wrappery nad původním BIOS/DOS rozhraním
   (např. `Int33_SetMousePosition_4A210(x, y)`).
2. Tyto wrappery žijí v `port_*.cpp` souborech a překládají volání na
   moderní backend (SDL3).
3. Cílem je, aby diff mezi disassemblovaným EXE a naším C++ portem byl
   co nejmenší — stejná granularita volání, stejné názvy interrupt
   handlerů, jen s čitelnými jmény a adresou v sufixu.

To zrcadlí přístup DOSBox-X: `src/ints/mouse.cpp`, `src/ints/int10.cpp`,
`src/hardware/sblaster.cpp` atd. **emulují BIOS/DOS rozhraní**, hra nad
nimi běží beze změny. My děláme totéž, ale směrem "ven" — dekompilovaná
hra běží jako nativní C++ a port vrstva simuluje přesně to rozhraní, se
kterým hra počítala.

---

## 2. Konvence pojmenování

- **Funkce**: `PascalCase`, s adresou z originálního binárního souboru
  jako sufix, oddělenou podtržítkem:
  `DrawFrame_75E70`, `Int10_SetVideoMode_1A3F0`, `MixerSubmit_88120`.
  - Adresa = původní offset/RVA funkce v analyzovaném `.exe` (tak jak ho
    vrací `exetool` po auto-kalibraci offsetů). Pomáhá to při zpětném
    dohledávání v IDA a při psaní ekvivalenčních testů.
  - Pokud funkce nemá jasný protějšek v originále (je to čistě naše nová
    port-vrstva, např. `Sdl_InitAudioDevice()`), adresa se **nepřidává**.
- **Proměnné**: `snake_case`, adresa (pokud jde o known DOS memory
  location / globální proměnnou z originálu) jako sufix:
  `mouse_x_4F2A0`, `vga_mode_reg_3D4`, `pit_counter0_reload_61A2`.
  - Lokální pomocné proměnné bez vazby na originál nemají adresu.
- **Struktury**: vždy se snažíme vytknout `struct`/`class` tam, kde
  originál používal packed C struktury na fixní adrese (BIOS Data Area,
  DOS PSP, VGA registry, MCB atd.). Název struktury bez adresy
  (`struct BiosDataArea`), pojmenování polí odpovídá konvenci proměnných.
- **Soubory**: `port_<subsystem>.cpp/.h`, vše malými písmeny,
  podtržítko jako oddělovač (`port_vga.cpp`, `port_sound.cpp`,
  `port_mouse.cpp`, `port_pit.cpp`, `port_pic.cpp`, `port_keyboard.cpp`,
  `port_dos.cpp`, `port_net.cpp`, `port_term.cpp`).

Příklad:
```cpp
// port_mouse.cpp
struct MouseState {
    int32_t x_4F2A0;
    int32_t y_4F2A4;
    uint16_t buttons_4F2A8;
};

static MouseState g_mouse;

void Int33_SetMousePosition_4A210(int32_t x, int32_t y) {
    g_mouse.x_4F2A0 = x;
    g_mouse.y_4F2A4 = y;
    Sdl_WarpMouse(x, y); // volání do SDL3 backendu, bez adresy (naše)
}
```

---

## 3. Adresářová struktura

```
src/
  game/              # 1:1 port herní logiky z disassembly (žádný SDL, žádný DOS/BIOS)
  port/
    port_term.cpp    # terminálová emulace + brzká inicializace grafiky
    port_term.h
    port_vga.cpp     # INT 10h, VGA registry, framebuffer, palety, mode set
    port_vga.h
    port_sound.cpp   # Sound Blaster / Adlib / PC speaker emulace -> SDL3 audio
    port_sound.h
    port_mouse.cpp   # INT 33h mouse driver emulace
    port_mouse.h
    port_keyboard.cpp# INT 16h/09h keyboard, scancode mapování
    port_keyboard.h
    port_pit.cpp     # 8253/8254 PIT časovač (IRQ0), tick generátor
    port_pit.h
    port_pic.cpp     # 8259 PIC — IRQ řadič, priority, EOI
    port_pic.h
    port_dos.cpp     # INT 21h subset skutečně používaný hrou (souborový I/O, paměť)
    port_dos.h
    port_memory.cpp  # nahrada za DOS segment:offset alokaci - malloc/free s evidenci leaku
    port_memory.h
    port_file.cpp    # case-insensitive FILE I/O (FAT byl case-insensitive, ext4/APFS nejsou)
    port_file.h
    port_net.cpp     # (už existuje z MC2 portu) NetBIOS -> TCP
    port_net.h
    port_common.h    # sdílené typy: Bitu/Bit16u ekvivalenty, port I/O rozhraní
  backend/
    sdl_video.cpp    # čisté SDL3 volání, bez znalosti DOS/BIOS sémantiky
    sdl_audio.cpp
    sdl_input.cpp
```

Pravidlo: `port_*.cpp` **zná DOS/BIOS sémantiku, nezná SDL3 API přímo**
(volá `backend/sdl_*`). `backend/*` zná SDL3, nezná nic o DOS. Tím se
port vrstva dá teoreticky přepojit na jiný backend (např. čistý
terminál/headless test) beze změny herní logiky.

---

## 4. Terminálová emulace a brzká inicializace

Requirement: grafiku potřebujeme inicializovat **hned na startu**
(ne až při prvním `INT 10h` volání hry), protože chceme vidět chybové
hlášky/log okamžitě, podobně jako DOSBox-X otevírá SDL okno + textovou
konzoli současně (`src/gui/sdlmain.cpp`).

`port_term.cpp` odpovědnosti:
- Otevře SDL3 okno (i když je ještě ve "text mode" 80x25) hned v
  `main()`, ještě před tím, než dekompilovaná hra začne volat interrupty.
- Emuluje jednoduchou textovou obrazovku (BIOS text mode, `INT 10h`
  funkce `0Eh`/`13h` teletype output) vykreslovanou do SDL textury.
- Zároveň **zrcadlí veškerý textový výstup na `stdout`** (přes
  `fputs`/`printf`), pokud je terminál/log dostupný — užitečné při
  ladění bez GUI (headless testy, CI, `exetool` diagnostika).
- Poskytuje přepínání mezi textovým a grafickým (VGA 13h/mode X apod.)
  režimem — `port_vga.cpp` mu jen oznámí změnu video módu.

```cpp
// port_term.h
void Term_Init();                 // volat jako úplně první věc v main()
void Term_WriteChar(char c, uint8_t attr);
void Term_SetMode(int vga_mode);  // volá port_vga.cpp při INT10 mode setu
void Term_Shutdown();
```

---

## 5. Subsystémy — detailní rozpad

### 5.1 `port_vga.cpp` (inspirace: `src/hardware/vga.cpp`, `src/ints/int10*.cpp`)

Zodpovědnost:
- Emulace VGA registrů (CRTC, sequencer, graphics controller, attribute
  controller) v rozsahu, který hra skutečně čte/zapisuje.
- Framebuffer jako lineární pole (odpovídající segmentu `0xA000`/`0xB800`
  v originále) — čtení/zápis přes stejné adresy, jaké používala hra
  (`Vga_WriteByte_A0000(offset, value)`).
- Implementace používaných funkcí `INT 10h` (set mode, set palette,
  get/set pixel, DAC registr).
- Palety (256 barev VGA DAC) → převod na SDL3 `SDL_Palette`/texturu.
- Page flipping / vsync, pokud hra na něj spoléhá (mnoho Bullfrog titulů
  ano — DOSBox-X toto řeší v `vga.cpp` přes `VGA_VerticalTimer`).

DOSBox-X orientační body k nastudování:
`src/hardware/vga.cpp` (hlavní stavový stroj), `src/ints/int10_modes.cpp`
(tabulky video módů), `src/ints/int10_put_pixel.cpp`,
`src/ints/int10_pal.cpp` (paleta).

### 5.2 `port_sound.cpp` (inspirace: `src/hardware/sblaster.cpp`,
`adlib.cpp`, `pcspeaker.cpp`, `mixer.cpp`)

Zodpovědnost:
- Emulace I/O portů Sound Blasteru (DSP příkazy, IRQ/DMA konfigurace) —
  jen v rozsahu, který hra reálně používá (zjistí se z callgraphu přes
  `exetool`, kolik DSP příkazů je vůbec volaných).
- OPL2/OPL3 (Adlib) emulace hudby — lze znovupoužít existující OPL
  jádro (např. `dbopl`/`nuked-opl`) jako blackbox, DOSBox-X to dělá
  stejně (`dbopl.cpp`, `nukedopl.cpp` jsou samostatná jádra volaná
  z `sblaster.cpp`/`adlib.cpp`).
- Mixer: sjednocení všech zdrojů (DSP PCM, OPL, PC speaker) do jednoho
  SDL3 audio streamu — ekvivalent `src/hardware/mixer.cpp`.
- PC speaker piezo emulace jen pokud ji hra používá jako fallback.

Doporučené pořadí implementace: nejdřív DSP PCM přehrávání (nejčastěji
používané pro digitalizované efekty), pak OPL hudba.

### 5.3 `port_mouse.cpp` (inspirace: `src/ints/mouse.cpp`)

Zodpovědnost:
- `INT 33h` subset: init driveru, get/set position, get/set button
  stav, mickey counters, callback mechanismus (pokud hra registruje
  event-driven mouse handler přes `INT 33h AX=0Ch`).
- Souřadnicový systém 1:1 s originálem (často 0–319/0–199 pro mode 13h,
  škáluje se až v `backend/sdl_input.cpp`).
- Sensitivity/mickey-to-pixel poměr — DOSBox-X řeší přes
  `mickey_threshold`, `adjust_x`/`adjust_y` v `mouse.cpp` (viz. hlavička
  souboru — dobrý referenční bod pro edge-case chování, které hry
  očekávají).

### 5.4 `port_keyboard.cpp` (inspirace: `src/hardware/keyboard.cpp`,
`src/ints/bios_keyboard.cpp`)

Zodpovědnost:
- Scancode fronta (BIOS keyboard buffer, `INT 16h` funkce 0/1/10h/11h).
- Překlad SDL3 scancode → PC XT/AT scancode sada, kterou hra očekává.
- Shift/Ctrl/Alt stavové bity (BIOS Data Area `0x417`).

### 5.5 `port_pit.cpp` + `port_pic.cpp` (inspirace: `src/hardware/timer.cpp`,
`src/hardware/pic.cpp`)

Toto je základ, na kterém stojí prakticky vše ostatní (timing hry, IRQ0
tick, případně IRQ1 klávesnice). Tomáš už tuto vrstvu částečně řešil u
MC2 portu (`std::thread`-based 8253/8254 PIT) — **tento kód by se měl
sjednotit a přesunout právě sem**, aby ho sdílely všechny porty místo
duplikace per-projekt.

Zodpovědnost `port_pit.cpp`:
- 3 kanály PIT, reload hodnoty, mode 2/3 (rate generator/square wave),
  generování IRQ0 tiku v reálném čase (mapování DOS cyklů na wall-clock
  přes `std::chrono`).
- Čtení/zápis do portů `0x40–0x43`.

Zodpovědnost `port_pic.cpp`:
- 2× 8259 (master/slave), IRQ maskování, prioritní řetězení, EOI
  (`0x20`/`0xA0`), přerušení mapovaná na jednotné rozhraní, které
  `port_pit.cpp`/`port_keyboard.cpp`/`port_sound.cpp` volají
  (`Pic_ActivateIRQ(0)` apod.) — DOSBox-X toto dělá přes centrální
  event queue v `pic.cpp` (`PIC_QUEUESIZE`, `PIC_AddEvent`).

> Doporučení: `port_pic.cpp` by měl být implementován **před** ostatními
> port_* soubory, protože IRQ signalizace (timer, klávesnice, myš,
> zvuková karta) na něm závisí. Pořadí buildu: `pic → pit → keyboard →
> mouse → vga → sound → dos → net`.

### 5.6 `port_dos.cpp` (inspirace: `src/dos/dos.cpp`, `dos_files.cpp`,
`dos_memory.cpp`)

Zodpovědnost:
- Jen subset `INT 21h`, který hra reálně volá (typicky file I/O:
  open/read/write/seek/close, alokace paměti přes MCB, get/set DTA).
- Emulace DOS memory control blocks jen natolik, aby seděly adresy,
  které hra očekává (často relevantní pro EXE s vlastním overlay
  loaderem — Watcom/DOS4GW extendery mají svou logiku, tu raději řešit
  zvlášť, viz sekce 7).

### 5.7 `port_net.cpp` (už existuje z MC2 projektu)

Zodpovědnost: NetBIOS emulace nahrazená TCP soketem (hotovo pro MC2,
zde jen sjednotit rozhraní se zbytkem port vrstvy — použít stejné
`port_common.h` typy).

### 5.8 `port_common.h`

Sdílené typy a pomocné makra napříč porty, inspirace
`include/dosbox.h`/`include/inout.h`:
```cpp
using Bit8u  = uint8_t;
using Bit16u = uint16_t;
using Bit32u = uint32_t;

// Jednotné I/O port rozhraní pro emulaci IN/OUT instrukcí
void IoWriteByte(uint16_t port, uint8_t val);
uint8_t IoReadByte(uint16_t port);
```

---

## 6. Vztah port vrstvy k `exetool`

`exetool` (auto-kalibrace offsetů, detekce entry pointu, call-graph
tracing) slouží k identifikaci:
1. Které funkce v originále odpovídají BIOS/DOS/IO voláním (typicky
   volané přes `INT xx` softwarové přerušení nebo přímo `IN`/`OUT`
   instrukce na známé porty — PIC 0x20/0xA0, PIT 0x40-0x43, SB 0x220+,
   VGA 0x3C0-0x3DA).
2. Adresy těchto volajících míst → použijí se jako sufix při
   pojmenovávání odpovídající `Port_*`/`Int*_*` funkce.
3. Call-graph umožní zjistit, které konkrétní subfunkce DOS/BIOS API
   hra vůbec využívá — **neimplementujeme celé DOSBox-X**, jen ten
   průnik, který hra skutečně potřebuje (minimalizace rozsahu portu).

Doporučený postup pro každou nově dekompilovanou funkci:
1. `exetool` identifikuje adresu a (pokud možno) druh volání (INT
   vector, I/O port rozsah).
2. Podle rozsahu/vektoru se zařadí do příslušného `port_*.cpp` (tabulka
   v sekci 8).
3. Napíše se čitelný C++ ekvivalent se jménem `Xxx_Yyy_ADDR`.
4. Vytvoří se equivalenční test proti chování DOSBox-X (spustit stejnou
   sekvenci vstupů v DOSBox-X i v našem portu, porovnat výstupní stav —
   podobně jako se dnes dělá u MC2 vs IDA decompiler output).

---

## 7. Co NENÍ součástí port vrstvy

- DOS4GW/Watcom extender loader (relokace, LE header parsing, segment
  setup) — to patří do samostatné vrstvy (`loader/` nebo přímo do
  `exetool`), protože to není BIOS/DOS runtime služba, ale jednorázová
  inicializace procesu. Nezaměňovat s `port_dos.cpp`, který řeší běhové
  `INT 21h` volání.
- CPU emulace / instrukční dekódování — irelevantní, protože cílem je
  hru **portovat do nativního C++**, ne emulovat x86.

---

## 8. Rychlá orientační tabulka (interrupt/port → soubor)

| Zdroj v originále                       | Cílový soubor        |
|------------------------------------------|-----------------------|
| `INT 10h` (video)                        | `port_vga.cpp`        |
| VGA I/O porty `0x3C0–0x3DA`, `0xA000` seg | `port_vga.cpp`        |
| `INT 21h` (DOS services)                 | `port_dos.cpp`        |
| `INT 33h` (mouse)                        | `port_mouse.cpp`      |
| `INT 16h`/`09h` (keyboard)                | `port_keyboard.cpp`   |
| I/O porty `0x40–0x43` (PIT)               | `port_pit.cpp`        |
| I/O porty `0x20`, `0xA0` (PIC)            | `port_pic.cpp`        |
| I/O porty `0x220+` (Sound Blaster), `0x388` (Adlib) | `port_sound.cpp` |
| NetBIOS volání                            | `port_net.cpp`        |
| Textový výstup / BIOS text mode / logging | `port_term.cpp`       |
| `malloc`/`calloc`/`realloc`/`free`, Watcom `nmalloc`/`nfree` | `port_memory.cpp` |
| `fopen`/`fclose`/`fread`/`fwrite`/`fflush`/`access` (souborovy I/O) | `port_file.cpp` |

**Poznámka k realné implementaci (reorion2, vlna 06):** v konkrétním
Orion2 portu je terminálová emulace zatím součástí `port_dos.cpp` (ne
samostatného `port_term.cpp` jak plánuje sekce 3) - obě jsou malé a úzce
svázané (terminál se inicializuje jako první krok DOS/BIOS vrstvy), takže
rozdělení přijde až bude jasné, že si to zaslouží vlastní soubor (viz
zásada v sekci 2 - nová struktura se tvoří postupně, ne dopředu).
`port_memory.cpp`/`port_file.cpp` řeší runtime služby, které nejsou vázané
na konkrétní `INT`/I/O port (na rozdíl od zbytku tabulky), ale na
celoprojektové C funkce (`malloc`, `fopen`...) - proto jsou navíc oproti
původnímu rozpisu v sekci 5.

**Poznatky z praxe (doplňováno postupně, viz PROGRESS.md pro detaily):**
- **Skryté registrové parametry:** Hex-Rays občas neukáže parametr, který
  volající předává jen tím, že ho nechá ležet ve stejném registru, ve
  kterém ho sám dostal (žádná instrukce `MOV` = žádný viditelný parametr
  v pseudokódu). Po překompilování moderním kompilátorem to vede k
  Access Violation (viz `strstr` v `MarkCheatPatternFlag_F4FD5`) nebo
  k tichému čtení nedefinované paměti (`argc`/`argv` v
  `ParseCommandLine_107E6`). Řešení: dohledat, odkud by hodnota reálně
  přišla (typicky parametr volající funkce, nebo nedávno vypočtená
  proměnná), a předat ji explicitně.
- **Konstanty maskované jako adresy:** IDA občas automaticky převede
  obyčejnou 32bit celočíselnou konstantu na `offset symbol+delta`, když
  hodnota náhodou padne do adresního rozsahu programu (viz `loc_63FFB+5`
  = ve skutečnosti jen číslo 0x64000). Poznat lze podle toho, že "adresa"
  nedává smysl jako skutečný jump/data target (padá doprostřed jiné
  instrukce) a číselně dobře sedí jako parametr (např. velikost alokace).
- **`JUMPOUT` je no-op:** v `hexrays_compat.h` je `JUMPOUT(adr)` jen
  zaznamenaná adresa bez efektu - každý výskyt je nutné ručně nahradit
  (`return`/`break`/`continue`) podle toho, kam cílová adresa vzhledem k
  tělu funkce skutečně směřuje. V jednom souboru (`orion_part_01.c`) jich
  je přes 40, napříč projektem pravděpodobně stovky.
- **Chybějící argumenty u knihovních funkcí:** stejný "skrytý registr"
  problém postihuje i běžné CRT funkce (`fprintf`, `sprintf`, `fopen`,
  `fseek`, `calloc`...) - před hromadným přesměrováním na port vrstvu je
  nutné auditovat počet argumentů na VŠECH voláních (ne jen na vzorku),
  jinak makra jako `#define fopen(p,m) PortFile_Open(p,m)` odhalí desítky
  chybějících parametrů najednou (užitečné, ale je potřeba to očekávat).
- **Pointery uložené jako `int`:** dekompilovaný kód všude ukládá
  ukazatele (souborové handly, návratové hodnoty alokátorů) do 32bit
  `int`/`_DWORD` proměnných. Cokoliv v port vrstvě, co by na 64bit
  sestavení vracelo skutečný 8bajtový ukazatel, se při takovém uložení
  ořízne - proto `port_file.cpp` vrací malý celočíselný handle (index do
  interní tabulky) místo `FILE*`.

---

## 9. Další kroky (roadmap pro navazující AI session)

1. Založit `port_common.h` + `port_pic.cpp` + `port_pit.cpp` (fundament,
   sjednotit s existujícím `std::thread`-PIT kódem z MC2).
2. `port_term.cpp` — brzká SDL3 inicializace + stdout mirroring.
3. `port_vga.cpp` — nejdřív jen mode set + framebuffer write, paletu
   později.
4. `port_keyboard.cpp`, `port_mouse.cpp`.
5. `port_sound.cpp` — DSP PCM první, OPL hudba později.
6. `port_dos.cpp` — jen funkce reálně použité (dle `exetool` call-graphu
   pro konkrétní cílovou hru, např. Orion2.exe).
7. Průběžně: equivalenční testy vůči DOSBox-X pro každý nově portovaný
   subsystém, než se prohlásí za hotový.

