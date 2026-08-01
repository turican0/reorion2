// port_mouse.h - nahrada za DOS mysi driver (int 33h sluzby). Az najdeme
// dekompilovane funkce volajici tento interrupt (typicky pres realmode
// callback / union registru), presmerujeme je sem.
#ifndef PORT_MOUSE_H
#define PORT_MOUSE_H

namespace Port::Mouse {

struct State {
    int x = 0;
    int y = 0;
    bool leftButton = false;
    bool rightButton = false;
};

bool Init();
void Shutdown();

// Zavolat jednou za snimek pred tim, nez se dekompilovany kod zepta na stav
// mysi - nahrazuje int 33h/AX=0003h (precti pozici a tlacitka).
void Poll();

const State& GetState();

// Presun kurzoru (INT 33h fn 4).
void WarpTo(int x, int y);

// Odebere priznak noveho stisku klavesy (nahrada za INT 9).
bool ConsumeKeyPress();

// Kod posledni stisknute klavesy (BIOS styl: scancode<<8 | ascii).
int LastKeyCode();

} // namespace Port::Mouse

#endif // PORT_MOUSE_H
