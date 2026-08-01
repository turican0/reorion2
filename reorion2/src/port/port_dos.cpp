#include "port_dos.h"
#include "port_mouse.h"
#include "port_vga.h"

#include <SDL3/SDL.h>
#include <cstring>

#include <cstdio>
#include <cstdlib>
#include <filesystem>

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
// Citlivost myši - DOS ovladac ma vychozi 50/50/50; hra si ji stejne hned
// prenastavuje funkci 26 (viz sub_12xxxx v orion_part_19.c).
static int g_mouseSensX = 50;
static int g_mouseSensY = 50;
static int g_mouseSensD = 50;
static int g_mouseMaxX = 0;
static int g_mouseMaxY = 0;

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
            SDL_Log("INT33: hra registruje OBSLUZNOU RUTINU myshi, maska=0x%04X, "
                    "callback=0x%08X - port ji zatim nikdy nezavola!",
                    (unsigned)(uint16_t)regs.ecx, (unsigned)regs.edx);
            break;
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
            Port::Mouse::Poll();
            const Port::Mouse::State& s = Port::Mouse::GetState();
            regs.ebx = (s.leftButton ? 1u : 0u) | (s.rightButton ? 2u : 0u);
            // POZOR (vlna 26 pokr. 29): hra si pres funkci 7 nastavuje rozsah
            // X na `2 * (sirka - 1)`, tedy 0..1278 pro 640 - dobovy zvyk DOS
            // ovladace, ktery X vraci ve dvojnasobnem rozliseni. Port vracel
            // syrove pixely okna, takze souradnice byly polovicni a testy
            // kliknuti se netrefily (a herni kurzor se kreslil mimo).
            // Pocitadlo dotazu na pozici - abych videl, jestli se menu vubec
            // pta (uzivatel merenim zjistil, ze breakpoint se tu netrefil).
            {
                static int s_on = -1, s_calls = 0;
                if (s_on < 0) s_on = SDL_getenv("REORION2_MOUSE_TRACE") ? 1 : 0;
                if (s_on && (s_calls++ % 200) == 0) {
                    SDL_Log("INT33 fn3 #%d: SDL x=%d y=%d  tlacitka=%u  rozsah=%d/%d",
                            s_calls - 1, s.x, s.y,
                            (unsigned)((s.leftButton?1u:0u)|(s.rightButton?2u:0u)),
                            g_mouseMaxX, g_mouseMaxY);
                }
            }
            int vx = s.x, vy = s.y;
            if (g_mouseMaxX > 0)
                vx = s.x * (g_mouseMaxX + 1) / kPortModeWidth;
            if (g_mouseMaxY > 0)
                vy = s.y * (g_mouseMaxY + 1) / kPortModeHeight;
            if (g_mouseMaxX > 0 && vx > g_mouseMaxX) vx = g_mouseMaxX;
            if (g_mouseMaxY > 0 && vy > g_mouseMaxY) vy = g_mouseMaxY;
            if (vx < 0) vx = 0;
            if (vy < 0) vy = 0;
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

void PortDebug_CheckpointPtr(const char* name, const void* value)
{
    static const bool enabled = std::getenv("REORION2_TRACE") != nullptr;
    if (!enabled)
        return;
    std::fprintf(stderr, "DIAG %s %p\n", name ? name : "?", value);
    std::fflush(stderr);
}

} // extern "C"
