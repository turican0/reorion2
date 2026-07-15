#include "port_dos.h"
#include "port_vga.h"

#include <cstdio>

namespace Port::Dos {

namespace {
bool g_terminalReady = false;
int g_cursorRow = 0;
int g_cursorCol = 0;
} // namespace

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
