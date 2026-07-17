#include "port_dos.h"
#include "port_vga.h"

#include <cstdio>
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

} // extern "C"
