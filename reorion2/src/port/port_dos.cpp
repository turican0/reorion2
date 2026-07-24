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

extern "C" int PortDos_Int386(int intNum, const void* inRegs, void* outRegs)
{
    WatcomRegs regs{};
    std::memcpy(&regs, inRegs, sizeof(regs));
    regs.cflag = 0;

    if (intNum == 0x33) {
        const uint16_t fn = (uint16_t)regs.eax;
        switch (fn) {
        case 0x00: // reset/detekce driveru: AX=FFFF pokud nainstalovan, BX=pocet tlacitek
            regs.eax = 0xFFFF;
            regs.ebx = 2;
            break;
        case 0x03: { // precti pozici a tlacitka: BX=tlacitka, CX=x, DX=y
            Port::Mouse::Poll();
            const Port::Mouse::State& s = Port::Mouse::GetState();
            regs.ebx = (s.leftButton ? 1u : 0u) | (s.rightButton ? 2u : 0u);
            regs.ecx = (uint32_t)s.x;
            regs.edx = (uint32_t)s.y;
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

} // extern "C"
