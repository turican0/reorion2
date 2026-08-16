#include "port_dos.h"
#include "port_mouse.h"
#include "port_vga.h"

#include <SDL3/SDL.h>
#include <cstring>

#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <vector> /* REORION2_CLICK - skriptovana mys, vlna 62 */

namespace Port::Dos {

namespace {
bool g_terminalReady = false;
int g_cursorRow = 0;
int g_cursorCol = 0;

// Emulovana tabulka interrupt vektoru (nahrada za realnou IVT/IDT, kterou
// v DOS4GW cetl/zapisoval INT 21h AH=35h/25h). V portu je to JEN uloziste:
// hra si pres ni uklada a obnovuje svuj INT 9 (klavesnice) handler
// (InstallKeyboardIsr_12C420 / RestoreKeyboardIsr_12C493 v orion_part_20.c),
// ale samotne preruseni uz nikdy nenastane - klavesove udalosti dodava SDL3.
// Diky tomu parova sekvence "uloz puvodni -> instaluj svuj -> obnov puvodni"
// funguje presne jako v originale, jen bez vedlejsich ucinku na system.
constexpr unsigned int kInterruptVectorCount = 256;
DosFarPointer g_interruptVectors[kInterruptVectorCount] = {};
} // namespace

bool GetDiskFree(DosDiskFree& out)
{
    std::error_code ec;
    const std::filesystem::space_info info =
        std::filesystem::space(std::filesystem::current_path(ec), ec);
    if (ec)
        return false;

    // Zakodovani realneho volneho mista do 16bitovych DOS poli: pevne
    // 512 B/sektor a 64 sektoru/cluster (32 KiB cluster - nejvetsi bezna
    // FAT16 hodnota). Pocty clusteru se zastropuji na 0xFFFF, takze
    // maximalni hlasene volne misto je 0xFFFF * 32 KiB = ~2 GiB a soucin
    // avail*spc*bps = 0x7FFF8000 se bezpecne vejde do "int" nasobeni,
    // ktere provadi GetFreeDiskSpace_111763 (orion_part_18.c). Hra misto
    // pouziva jen na test "vejde se sem jeste ulozena pozice?", takze
    // strop ~2 GiB je v praxi totez jako "mista je dost".
    static constexpr uint64_t kBytesPerSector = 512;
    static constexpr uint64_t kSectorsPerCluster = 64;
    static constexpr uint64_t kBytesPerCluster = kBytesPerSector * kSectorsPerCluster;

    const auto toClusterCount = [](uint64_t bytes) -> uint16_t {
        const uint64_t clusters = bytes / kBytesPerCluster;
        return clusters > 0xFFFF ? uint16_t(0xFFFF) : uint16_t(clusters);
    };

    out.total_clusters = toClusterCount(info.capacity);
    out.avail_clusters = toClusterCount(info.available);
    out.sectors_per_cluster = uint16_t(kSectorsPerCluster);
    out.bytes_per_sector = uint16_t(kBytesPerSector);
    return true;
}

DosFarPointer GetInterruptVector(unsigned int vectorNumber)
{
    if (vectorNumber >= kInterruptVectorCount)
        return DosFarPointer{0, 0};
    return g_interruptVectors[vectorNumber];
}

void SetInterruptVector(unsigned int vectorNumber, DosFarPointer value)
{
    if (vectorNumber >= kInterruptVectorCount)
        return;
    g_interruptVectors[vectorNumber] = value;
}

void InitTerminalEmulation()
{
    // Graficke okno (SDL3) musi existovat driv, nez do textoveho bufferu
    // neco zapiseme - Port::Vga::Init() se vola hned po nas z reorion2.cpp.
    // Zde jen pripravime stav textoveho rezimu na cisty zacatek (80x25,
    // stejne jako standardni DOS textovy rezim 03h).
    g_cursorRow = 0;
    g_cursorCol = 0;
    g_terminalReady = true;
}

void TerminalWrite(const char* text)
{
    if (!text)
        return;

    // Vzdy zrcadlit na stdout - uzitecne pri behu bez okna (napr. na serveru
    // pri ladeni) i jako obecny pozadavek ze zadani.
    std::fputs(text, stdout);

    // DECOMP_TODO: az bude port_vga.cpp umet vykreslit znakovou mrizku,
    // sem pribude zapis do skutecneho textoveho bufferu (Port::Vga::...)
    // vcetne posunu kurzoru, rolovani obrazovky atd. Zatim jen stdout, aby
    // aspon selo sledovat, co GameMain_10057 pri startu dela.
    (void)g_cursorRow;
    (void)g_cursorCol;
}

void TerminalSetCursor(int row, int col)
{
    g_cursorRow = row;
    g_cursorCol = col;
}

bool IsTerminalReady()
{
    return g_terminalReady;
}

} // namespace Port::Dos

// ---------------------------------------------------------------------
// C-linkage mosty pro dekompilovany herni kod (viz port_dos.h) - tenke
// obalky nad Port::Dos:: API vyse, stejny princip jako PortFile_* /
// PortMemory_*. Navratove konvence drzi puvodni DOS/Watcom tvar.
extern "C" {

int dos_getdiskfree(unsigned int drive, struct DosDiskFree* out)
{
    // Hra vola vyhradne drive=0 (aktualni disk). Konkretni pismeno disku
    // (1=A:, 2=B:, ...) v portu nema smysl - hra bezi tam, kde lezi jeji
    // data, takze se volne misto meri vzdy v aktualnim adresari.
    (void)drive;
    if (!out)
        return 1;
    return Port::Dos::GetDiskFree(*out) ? 0 : 1;
}

unsigned int dos_getvect(unsigned int vectorNumber)
{
    // Vraci jen offset - segmentova cast (puvodne DX) se v dekompilovanem
    // volajicim kodu bere z registroveho artefaktu, viz port_dos.h.
    return Port::Dos::GetInterruptVector(vectorNumber).offset;
}

int dos_setvect(unsigned int vectorNumber, unsigned int vectorNumberDup,
                unsigned int handlerOffset, unsigned int handlerSegment)
{
    (void)vectorNumberDup; // duplikat cisla vektoru v dalsim registru
    Port::Dos::SetInterruptVector(
        vectorNumber, DosFarPointer{handlerOffset, uint16_t(handlerSegment)});
    return 0;
}

// ---------------------------------------------------------------------
// int386 - Watcom wrapper nad softwarovymi interrupty (vlna 13). Drive
// no-op stub v link_stubs.c, ktery NEZAPISOVAL do vystupnich registru
// (neinicializovana pamet -> nahodne chovani, napr. falesne "Mouse
// driver required" v MouseInit sub_123491). Emulace:
//   - INT 33h (mys) se preklada na Port::Mouse (SDL3),
//   - ostatni interrupty (10h video, 21h DOS, 31h DPMI...) zatim vraci
//     vstupni registry beze zmeny (deterministicke; konkretni sluzby se
//     napoji az na ne herni kod skutecne narazi - DECOMP_TODO).
// Layout Watcom "union REGS" (386): eax,ebx,ecx,edx,esi,edi,cflag -
// 7x uint32 na ofsetech 0/4/8/12/16/20/24 - presne tak k nim
// dekompilovany kod pristupuje (dword_1BB8E0 = eax, +4 = ebx, ...).
struct WatcomRegs {
    uint32_t eax, ebx, ecx, edx, esi, edi, cflag;
};

// Rozsahy, ktere si hra nastavuje pres INT 33h funkce 7/8 (viz case 0x03).
// Rozmery obrazoveho rezimu portu (viz kModeWidth/kModeHeight v port_vga.cpp,
// kde jsou v anonymnim namespace, tedy mimo hlavicku).
static constexpr int kPortModeWidth  = 640;
static constexpr int kPortModeHeight = 480;
// Citlivost myï¿½i - DOS ovladac ma vychozi 50/50/50; hra si ji stejne hned
// prenastavuje funkci 26 (viz sub_12xxxx v orion_part_19.c).
static int g_mouseSensX = 50;
static int g_mouseSensY = 50;
static int g_mouseSensD = 50;
static int g_mouseMaxX = 0;
static int g_mouseMaxY = 0;

// ---------------------------------------------------------------------
// OBSLUZNA RUTINA MYSHI (vlna 26 pokr. 41) - klicova vec, ktera v portu
// chybela. Zmereno: hra si obsluhu NEregistruje funkci 0x0C pres int386,
// ale pres int386x (Watcom varianta se segmentovymi registry) - a ta byla
// v link_stubs.c prazdny stub vracejici 0. Volani jsou dve:
//   sub_1237F3  -> fn 0x0C, maska 1  (jen pohyb)          - pri inicializaci
//   sub_12386C  -> fn 0x14, maska 43 (pohyb + tlacitka)   - v menu
//   sub_123926  -> fn 0x14, maska 1
// V DOSu ovladac tuhle rutinu (sub_1236D1) volal pri kazdem pohybu/kliknuti
// a TEPRVE ONA aktualizuje herni pozici kurzoru (dword_1BBA38/1BBA34),
// stav tlacitek (word_1B921A) a KRESLI kurzor (dword_1B9208/920C/9210).
// Bez ni kurzor zustaval na 0,0 a kliknuti nemela zadny ucinek - presne
// tri projevy, ktere jsme meli otevrene.
using MouseCallback = void (*)(int eax, int ebx, int ecx, int edx, int esi, int edi);
static uint32_t g_mouseHandler = 0; // adresa herni rutiny (LAA:NO -> vejde se do 32 bitu)
static uint16_t g_mouseMask    = 0; // maska udalosti, na ktere se ma volat
static int g_lastVx = -1, g_lastVy = -1, g_lastButtons = 0;

// Prepocet pozice ze SDL do virtualniho rozsahu, ktery si hra nastavila
// funkcemi 7/8 - spolecny pro dotaz fn 3 i pro callback, aby obe cesty
// hlasily TOTEZ (drive byl vypocet jen uvnitr case 0x03).
static void ComputeVirtualMouse(int& vx, int& vy, int& buttons)
{
    Port::Mouse::Poll();
    const Port::Mouse::State& s = Port::Mouse::GetState();
    buttons = (s.leftButton ? 1 : 0) | (s.rightButton ? 2 : 0);

    // SKRIPTOVANA MYS (vlna 62) - REORION2_CLICK="x,y@ms;x,y@ms;..."
    // Souradnice se zadavaji v HERNICH pixelech (640x480), cas v ms od startu.
    // V zadanem case se kurzor presune na (x,y) a na `hold` ms se stiskne leve
    // tlacitko; mimo to je tlacitko pustene a kurzor zustava na posledni
    // pozici. Delka stisku jde zmenit pres REORION2_CLICK_HOLD (vychozi 150).
    //
    // PROC TAKHLE: synteticky klik pres SetCursorPos/mouse_event se do hry
    // NEDOSTANE (vlna 53) - SDL oknu bez fokusu vstup nedava. Tady se vstup
    // vklada rovnou do stejneho mista, ze ktereho ho cte INT 33h, takze ho
    // hra nerozezna od skutecneho kliknuti.
    // POZOR: tlacitko se NESMI drzet trvale - `sub_124105` ("cekej, dokud
    // neni zadne tlacitko stisknute") by se zatocila donekonecna (viz
    // poznamka u REORION2_FAKE_CLICK nize).
    {
        // vlna 73: za casem smi byt jeste ":hold" (ms) - hold 0 znamena
        // POUZE presun kurzoru bez stisku, coz je potreba na testovani
        // najeti mysi (hover) oddelene od kliknuti.
        struct ClickEv { int x, y; unsigned ms; unsigned hold; };
        static std::vector<ClickEv> s_evs;
        static int s_have = -1;
        static unsigned s_hold = 150;
        if (s_have < 0) {
            s_have = 0;
            if (const char* env = SDL_getenv("REORION2_CLICK")) {
                if (const char* h = SDL_getenv("REORION2_CLICK_HOLD"))
                    s_hold = (unsigned)std::atoi(h);
                const char* p = env;
                while (*p) {
                    int x = 0, y = 0; unsigned ms = 0, hold = 0; int used = 0, used2 = 0;
                    if (std::sscanf(p, "%d,%d@%u%n", &x, &y, &ms, &used) == 3) {
                        p += used;
                        if (std::sscanf(p, ":%u%n", &hold, &used2) == 1)
                            p += used2;
                        else
                            hold = s_hold;
                        s_evs.push_back(ClickEv{x, y, ms, hold});
                    } else {
                        ++p; continue;
                    }
                    while (*p == ';' || *p == ' ') ++p;
                }
                s_have = s_evs.empty() ? 0 : 1;
                if (s_have)
                    SDL_Log("Port: REORION2_CLICK - %d kliknuti, hold %u ms",
                            (int)s_evs.size(), s_hold);
            }
        }
        if (s_have) {
            const unsigned now = (unsigned)SDL_GetTicks();
            const ClickEv* cur = nullptr;
            bool down = false;
            for (const ClickEv& ev : s_evs) {
                if (now >= ev.ms) {
                    cur = &ev;
                    down = (ev.hold != 0 && now < ev.ms + ev.hold);
                }
            }
            if (cur) {
                const int maxX = (g_mouseMaxX > 0 ? g_mouseMaxX : 1279);
                const int maxY = (g_mouseMaxY > 0 ? g_mouseMaxY : 479);
                vx = cur->x * (maxX + 1) / 640;
                vy = cur->y * (maxY + 1) / 480;
                if (vx > maxX) vx = maxX;
                if (vy > maxY) vy = maxY;
                buttons = down ? 1 : 0;
                return;
            }
        }
    }

    // TEST: vstrikovani falesne pozice a tlacitka, aby sla cesta mysi overit
    // i bez cloveka u klavesnice (REORION2_FAKE_MOUSE / REORION2_FAKE_CLICK).
    static int s_fake = -1;
    if (s_fake < 0) s_fake = SDL_getenv("REORION2_FAKE_MOUSE") ? 1 : 0;
    if (s_fake) {
        static int t = 0;
        ++t;
        const int cx = (g_mouseMaxX > 0 ? g_mouseMaxX : 1278) / 2;
        const int cy = (g_mouseMaxY > 0 ? g_mouseMaxY : 479) / 2;
        // PLYNULY pohyb po ctverci (1 krok na volani) - drivejsi verze
        // kurzor TELEPORTOVALA mezi ctyrmi rohy, coz se nedalo pouzit na
        // mereni plynulosti.
        const int r = 120;
        const int per = 240;              // kroku na jednu stranu ctverce
        const int phase = (t / per) % 4;
        const int k = (t % per) * (2 * r) / per - r;
        if (phase == 0)      { vx = cx + k; vy = cy - r; }
        else if (phase == 1) { vx = cx + r; vy = cy + k; }
        else if (phase == 2) { vx = cx - k; vy = cy + r; }
        else                 { vx = cx - r; vy = cy - k; }
        // POZOR: tlacitko se musi STRIDAVE MACKAT A POUSTET, ne drzet.
        // `sub_124105` ("cekej, dokud neni zadne tlacitko stisknute") je
        // smycka, ktera se pri trvale stisknutem tlacitku zatoci donekonecna
        // - zmereno: hra se s trvalym stiskem zasekla uz v inicializaci myshi
        // (posledni vypis "RunGame.before_MouseInit"). Mackame proto jen v
        // jedne ze ctyr fazi obchuzky.
        buttons = (SDL_getenv("REORION2_FAKE_CLICK") && phase == 1) ? 1 : 0;
        return;
    }

    // POZOR (vlna 26 pokr. 39): prepocet musi vychazet z rozmeru OKNA, ne
    // rezimu. Okno se vytvari ve dvojnasobku (1280x960) a SDL_GetMouseState
    // vraci souradnice vuci oknu. Cilovy rozsah X je 0..2*(sirka-1) = 0..1278
    // (dobovy zvyk DOS ovladace; hra si ho pak deli dvema - viz sub_1236D1).
    vx = s.x;
    vy = s.y;
    const int winW = Port::Vga::GetWindowWidth();
    const int winH = Port::Vga::GetWindowHeight();
    if (g_mouseMaxX > 0 && winW > 0)
        vx = s.x * (g_mouseMaxX + 1) / winW;
    if (g_mouseMaxY > 0 && winH > 0)
        vy = s.y * (g_mouseMaxY + 1) / winH;
    if (g_mouseMaxX > 0 && vx > g_mouseMaxX) vx = g_mouseMaxX;
    if (g_mouseMaxY > 0 && vy > g_mouseMaxY) vy = g_mouseMaxY;
    if (vx < 0) vx = 0;
    if (vy < 0) vy = 0;
}

extern "C" int PortDos_Int386(int intNum, const void* inRegs, void* outRegs)
{
    WatcomRegs regs{};
    std::memcpy(&regs, inRegs, sizeof(regs));
    regs.cflag = 0;

    if (intNum == 0x33) {
        const uint16_t fn = (uint16_t)regs.eax;
        // PORT (vlna 26 pokr. 30): zaznam VSECH volani INT 33h. Uzivatel
        // zmeril, ze `case 0x03` (cti pozici) se v menu vubec nevola, takze
        // hra pozici ziskava jinak - podezreni na funkci 0x0C (registrace
        // obsluzne rutiny myshi), kterou port ignoruje, takze se nikdy
        // nezavola. Zapina REORION2_MOUSE_TRACE=1.
        {
            static int s_on = -1;
            if (s_on < 0)
                s_on = SDL_getenv("REORION2_MOUSE_TRACE") ? 1 : 0;
            if (s_on) {
                static int s_seen[64] = {0};
                static int s_n = 0;
                bool isNew = true;
                for (int i = 0; i < s_n; ++i)
                    if (s_seen[i] == (int)fn) { isNew = false; break; }
                if (isNew && s_n < 64) {
                    s_seen[s_n++] = (int)fn;
                    SDL_Log("INT33: NOVA funkce 0x%02X (AX=%u)  BX=%u CX=%u DX=%u",
                            fn, fn, (unsigned)(uint16_t)regs.ebx,
                            (unsigned)(uint16_t)regs.ecx, (unsigned)(uint16_t)regs.edx);
                }
            }
        }
        switch (fn) {
        case 0x00: // reset/detekce driveru: AX=FFFF pokud nainstalovan, BX=pocet tlacitek
            regs.eax = 0xFFFF;
            regs.ebx = 2;
            break;
        case 0x01: // zobraz kurzor
            SDL_ShowCursor();
            break;
        case 0x02: // schovej kurzor - hra si kresli vlastni
            SDL_HideCursor();
            break;
        case 0x04: // nastav pozici kurzoru (CX = x, DX = y) - ve VIRTUALNIM
                   // rozsahu, ktery si hra nastavila pres fn 7/8. Prepocteme
                   // zpet na pixely okna a rekneme to SDL, aby herni a
                   // systemova pozice nebyly rozjete.
            // POZOR: pokus volat tady SDL_WarpMouseInWindow casove sedel na
            // zcernani obrazovky po zobrazeni menu, takze je ZATIM VYPNUTY.
            // Nez to zapneme znovu, je potreba overit, jestli cernou
            // obrazovku zpusobil warp, nebo neco jineho.
            break;
        case 0x0C: // registrace obsluzne rutiny myshi (ES:DX = callback, CX = maska)
        case 0x14: // vymena obsluzne rutiny - vraci puvodni v ES:DX a CX
        {
            const uint32_t oldHandler = g_mouseHandler;
            const uint16_t oldMask    = g_mouseMask;
            g_mouseHandler = regs.edx;
            g_mouseMask    = (uint16_t)regs.ecx;
            if (fn == 0x14) {
                regs.edx = oldHandler;
                regs.ecx = oldMask;
            }
            break;
        }
        case 0x1A: // nastav citlivost: BX = horiz, CX = vert, DX = prah zrychleni
            g_mouseSensX = (int)(uint16_t)regs.ebx;
            g_mouseSensY = (int)(uint16_t)regs.ecx;
            g_mouseSensD = (int)(uint16_t)regs.edx;
            break;
        case 0x1B: // precti citlivost - hra si ji uklada do dword_1B91F0/F4/F8
            // POZOR (vlna 26 pokr. 29): tohle port ignoroval, takze
            // `sub_1233B4` ulozilo same NULY a hra pak s nimi pocitala
            // meritko pohybu kurzoru -> kurzor nebyl videt a kliknuti
            // koncilo padem. Hra si citlivost sama nastavuje funkci 26
            // (100/100), takze ji jen zapamatujeme a vratime.
            regs.ebx = (uint32_t)g_mouseSensX;
            regs.ecx = (uint32_t)g_mouseSensY;
            regs.edx = (uint32_t)g_mouseSensD;
            break;
        case 0x07: // nastav rozsah X (CX = min, DX = max)
            g_mouseMaxX = (int)(int16_t)(uint16_t)regs.edx;
            break;
        case 0x08: // nastav rozsah Y (CX = min, DX = max)
            g_mouseMaxY = (int)(int16_t)(uint16_t)regs.edx;
            break;
        case 0x03: { // precti pozici a tlacitka: BX=tlacitka, CX=x, DX=y
            // POZOR (vlna 26 pokr. 29): hra si pres funkci 7 nastavuje rozsah
            // X na `2 * (sirka - 1)`, tedy 0..1278 pro 640 - dobovy zvyk DOS
            // ovladace, ktery X vraci ve dvojnasobnem rozliseni. Port vracel
            // syrove pixely okna, takze souradnice byly polovicni a testy
            // kliknuti se netrefily (a herni kurzor se kreslil mimo).
            // Vypocet je od vlny 26 pokr. 41 v ComputeVirtualMouse, aby dotaz
            // fn 3 i emulovany callback hlasily uplne totez.
            int vx = 0, vy = 0, buttons = 0;
            ComputeVirtualMouse(vx, vy, buttons);
            {
                static int s_on = -1, s_calls = 0;
                if (s_on < 0) s_on = SDL_getenv("REORION2_MOUSE_TRACE") ? 1 : 0;
                if (s_on && (s_calls++ % 200) == 0)
                    SDL_Log("INT33 fn3 #%d: x=%d y=%d  tlacitka=%d  rozsah=%d/%d",
                            s_calls - 1, vx, vy, buttons, g_mouseMaxX, g_mouseMaxY);
            }
            regs.ebx = (uint32_t)buttons;
            regs.ecx = (uint32_t)vx;
            regs.edx = (uint32_t)vy;
            break;
        }
        default:
            // 01/02 (zobraz/schovej kurzor), 04 (nastav pozici), 07/08
            // (rozsahy), 0Fh (mickey ratio)... - v SDL vrstve zatim neni
            // co nastavovat, tiche prijeti je bezpecne (DECOMP_TODO: az
            // hra bude kurzor skutecne ridit, napojit na Port::Mouse).
            break;
        }
    }

    // POZOR: zapisujeme jen 6 GP registru (24 B), NE cflag (ofset 24) -
    // dekompilovane volajici funkce mivaji vystupni buffer jen _BYTE[24]
    // (IDA rekonstrukce stacku) a zapis cflag by prepsal sousedni lokal
    // (Debug RTC guard -> "zamrznuti" v assert dialogu). Volajici, ktere
    // cflag ctou, maji vlastni (typicky nulou inicializovany) slot -
    // DECOMP_TODO: az bude nejaka sluzba potrebovat vracet chybu pres
    // cflag, vyresit cilene u ni.
    std::memcpy(outRegs, &regs, 24);
    return (int)regs.eax; // Watcom int386 vraci AX/EAX po preruseni
}

// ---------------------------------------------------------------------
// int386x - Watcom varianta int386 se segmentovymi registry. V originale
// (Debug/diss/Orion2.exe.asm, volajici sub_1237F3 / sub_12386C / sub_123926)
// se vola registrove: EAX = cislo preruseni, EDX = vstupni REGS,
// EBX = vystupni REGS, ECX = SREGS. IDA z toho videla jen dva argumenty
// (`int386x(51, &dword_1BB8E0)`), takze i tady bereme jen ty dva - vystupni
// buffer je jiny (byte_1BB8C4) a hra ho u techto volani stejne necte,
// proto ZAMERNE nic nezapisujeme zpet.
//
// Doted to byl v link_stubs.c stub `int int386x(void) { return 0; }`, takze
// registrace obsluzne rutiny myshi (fn 0x0C a 0x14) se nikam nedostala -
// viz komentar u g_mouseHandler vyse.
extern "C" int PortDos_Int386x(int intNum, const void* inRegs)
{
    // Ostatni preruseni (49 = DPMI v orion_part_21.c, VESA rezimy) se chovaji
    // presne jako drivejsi stub - vraci 0 a nic nemeni. Menit je tady by byla
    // neoverena zmena chovani; napoji se, az na ne kod skutecne narazi.
    if (intNum != 0x33)
        return 0;

    WatcomRegs regs{};
    std::memcpy(&regs, inRegs, sizeof(regs));
    const uint16_t fn = (uint16_t)regs.eax;
    switch (fn) {
    case 0x0C: // nastav obsluznou rutinu (ES:DX = rutina, CX = maska)
    case 0x14: // vymen obsluznou rutinu
        g_mouseHandler = regs.edx;
        g_mouseMask    = (uint16_t)regs.ecx;
        {
            static int s_on = -1;
            if (s_on < 0) s_on = SDL_getenv("REORION2_MOUSE_TRACE") ? 1 : 0;
            if (s_on)
                SDL_Log("INT33x fn 0x%02X: obsluzna rutina myshi = 0x%08X, maska = 0x%04X",
                        fn, (unsigned)g_mouseHandler, (unsigned)g_mouseMask);
        }
        break;
    default:
        break;
    }
    return (int)regs.eax;
}

// Emulace preruseni od myshi: v DOSu volal ovladac zaregistrovanou rutinu
// sam pri kazde zmene, v portu ji musime zavolat my. Vola se z
// Port::Vga::Present() (tedy z mist, kde hra beztak ceka na obraz - v
// originale prave tam preruseni chodila).
//   AX = maska udalosti, BX = stav tlacitek, CX = X (dvojnasobny rozsah),
//   DX = Y, SI/DI = prirustky v "mickey" jednotkach.
extern "C" void PortDos_ServiceMouse(void)
{
    // REORION2_MOUSE_CALLBACK=0 emulaci preruseni vypne. Hodi se pri dumpu
    // snimku pro `compare_frames`: kdyz kurzor pri porovnani s dosboxem lezi
    // nad oknem, hra ho vykresli do obrazu a snimky se lisi, i kdyz je jinak
    // vsechno spravne (referencni beh dosboxu mysi nehybal).
    {
        static int s_on = -1;
        if (s_on < 0) {
            const char* e = SDL_getenv("REORION2_MOUSE_CALLBACK");
            s_on = (e && *e == '0') ? 0 : 1;
        }
        if (!s_on)
            return;
    }
    if (!g_mouseHandler)
        return;
    // Zabrana proti rekurzi: kreslici cast rutiny muze skoncit dalsim
    // Present() a tedy dalsim volanim teto funkce (herni rutina ma vlastni
    // zabranu, ale nespolehame se na ni).
    static bool s_inService = false;
    if (s_inService)
        return;

    int vx = 0, vy = 0, buttons = 0;
    ComputeVirtualMouse(vx, vy, buttons);

    int events = 0;
    if (vx != g_lastVx || vy != g_lastVy)
        events |= 0x01; // pohyb
    if ((buttons & 1) && !(g_lastButtons & 1)) events |= 0x02; // leve stisknuto
    if (!(buttons & 1) && (g_lastButtons & 1)) events |= 0x04; // leve uvolneno
    if ((buttons & 2) && !(g_lastButtons & 2)) events |= 0x08; // prave stisknuto
    if (!(buttons & 2) && (g_lastButtons & 2)) events |= 0x10; // prave uvolneno

    const int dx = (g_lastVx < 0) ? 0 : vx - g_lastVx;
    const int dy = (g_lastVy < 0) ? 0 : vy - g_lastVy;
    g_lastVx = vx;
    g_lastVy = vy;

    // PORT (vlna 71): stav TLACITEK si smime zapamatovat teprve tehdy,
    // kdyz jsme jeho zmenu SKUTECNE DORUCILI hre. Hra si masku obsluhy
    // stridave prepina mezi 0x0001 (jen pohyb) a 0x002B (pohyb+tlacitka)
    // - viz vlna 53. Kdyz stisk padne do okna s maskou 0x0001, `events`
    // se sice spocitaji, ale callback se preskoci; pokud si pritom
    // ulozime `g_lastButtons = buttons`, HRANA SE ZTRATI a pri dalsim
    // volani uz zadna zmena neni - hra o kliknuti nikdy nezvi.
    // Presne tak se choval vyber rasy: kurzor po tlacitkach jezdil
    // (zvyraznovalo se, protoze to jde pres sub_114177 = prvek pod
    // kurzorem), ale kliknuti nikdy neprosla - `sub_1171AB` vracelo 0.
    // Kdyz hranu nespotrebujeme, dorucí se hned, jak maska prepne zpet.
    const int kButtonEdges = 0x02 | 0x04 | 0x08 | 0x10;
    const int deliverable = events & g_mouseMask;
    if (!(events & kButtonEdges) || (deliverable & kButtonEdges))
        g_lastButtons = buttons;

    if (!deliverable)
        return;

    {
        static int s_on = -1, s_calls = 0;
        if (s_on < 0) s_on = SDL_getenv("REORION2_MOUSE_TRACE") ? 1 : 0;
        if (s_on && (s_calls++ % 100) == 0) {
            static uint64_t s_lastTick = 0;
            const uint64_t now = SDL_GetTicks();
            SDL_Log("INT33 callback #%d: udalosti=0x%02X tlacitka=%d x=%d y=%d  (100 volani za %llu ms)",
                    s_calls - 1, events, buttons, vx, vy,
                    (unsigned long long)(s_lastTick ? now - s_lastTick : 0));
            s_lastTick = now;
        }
    }

    s_inService = true;
    ((MouseCallback)(uintptr_t)g_mouseHandler)(events, buttons, vx, vy, dx, dy);
    s_inService = false;
}

unsigned int PortDos_BiosTick(void)
{
    // Nahrada za BIOS tick counter na adrese 0x0040:006C (MEMORY[0x46C]),
    // ktery na PC inkrementuje 1193182/65536 = ~18.2065x za sekundu (vlna 15).
    // V portu je MEMORY[] mrtvy stub - herni cekaci smycky (intro sub_24ED3,
    // pacing sub_12C2C6, casovani v orion_part_23) se na nem tocily donekonecna
    // nebo hned protekly. Odvozeno z realneho casu (SDL_GetTicks, ms).
    return (unsigned int)((uint64_t)SDL_GetTicks() * 1193182ull / 65536000ull);
}

void PortDebug_Checkpoint(const char* name, int value)
{
    // Env-gated diagnostika (vlna 11) - viz deklarace v decomp_compat.h.
    // Staticka inicializace se vyhodnoti jen jednou pri prvnim volani.
    static const bool enabled = std::getenv("REORION2_TRACE") != nullptr;
    if (!enabled)
        return;
    std::fprintf(stderr, "DIAG %s %d\n", name ? name : "?", value);
    std::fflush(stderr);
}

// PORT (vlna 94): pripise radek do `reorion2_crash.log` v aktualnim adresari
// (a na stderr). Soubor prezije i to, kdyz beh skonci pod debuggerem, kde
// se konzolovy vypis ztraci - viz vlny 92/93, kde bylo potreba tri kola
// s uzivatelem jen kvuli tomu, ze hlaska nikam nedosla.
extern "C" void PortDebug_CrashLog(const char* fmt, ...)
{
    va_list ap;
    FILE* f = std::fopen("reorion2_crash.log", "a");
    if (f) {
        va_start(ap, fmt);
        std::vfprintf(f, fmt, ap);
        va_end(ap);
        std::fputc('\n', f);
        std::fclose(f);
    }
}

void PortDebug_Message(const char* text)
{
    // Vlna 58: hlaska z sub_126487 (JEDINY konec programu) se ztracela.
    // Slo o `printf` do bufferovaneho stdout + `fflush(0)`, jenze `fflush` je
    // v decomp_compat.h presmerovany na PortFile_Flush(handle) a s nulou
    // neudela nic. Kdyz pak uklidovy retez (sub_113DBD) spadne, uzivatel vidi
    // jen pad bez duvodu. Tady jde vypis primo na stderr a hned se flushne.
    std::fprintf(stderr, "KONEC (sub_126487): %s\n", text ? text : "(null)");
    std::fflush(stderr);
    // PORT (vlna 94): tataz hlaska JESTE DO SOUBORU `reorion2_crash.log`.
    // Pod Visual Studiem uzivatel stderr nevidi, a pritom je hlaska ze
    // `sub_126487` to JEDINE, co u "Memory Corruption!" rekne, co se rozbilo -
    // nasledny pad v uklidovem retezu (sub_113DBD -> sub_155E62) ji v
    // debuggeru prekryje (viz vlny 86 a 92).
    PortDebug_CrashLog("KONEC (sub_126487): %s", text ? text : "(null)");
}

int PortDebug_EnvInt(const char* name, int fallback)
{
    // Vlna 58: v dekompilovanem kodu neni <stdlib.h>, takze `getenv` tam ma jen
    // implicitni deklaraci vracejici int - na x64 by se ukazatel orezal na 32
    // bitu. Cteni hodnoty env promenne proto vzdy pres tenhle pomocnik.
    const char* v = std::getenv(name);
    if (!v || !*v)
        return fallback;
    return std::atoi(v);
}

void PortDebug_CheckpointPtr(const char* name, const void* value)
{
    static const bool enabled = std::getenv("REORION2_TRACE") != nullptr;
    if (!enabled)
        return;
    std::fprintf(stderr, "DIAG %s %p\n", name ? name : "?", value);
    std::fflush(stderr);
}

} // extern "C"
