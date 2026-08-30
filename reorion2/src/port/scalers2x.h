#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdlib>

namespace Port::Vga {
namespace Scalers2x {

inline uint32_t Interpolate11(uint32_t a, uint32_t b) {
    return ((a & 0xFEFEFEFEu) >> 1) +
           ((b & 0xFEFEFEFEu) >> 1) +
           (a & b & 0x01010101u);
}

inline uint32_t Interpolate1111(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    const uint32_t x = ((a & 0xFCFCFCFCu) >> 2) +
                       ((b & 0xFCFCFCFCu) >> 2) +
                       ((c & 0xFCFCFCFCu) >> 2) +
                       ((d & 0xFCFCFCFCu) >> 2);
    const uint32_t y = ((a & 0x03030303u) + (b & 0x03030303u) +
                        (c & 0x03030303u) + (d & 0x03030303u)) >> 2;
    return x + (y & 0x03030303u);
}

inline uint32_t Interpolate31(uint32_t a, uint32_t b) {
    const uint32_t x = ((a & 0xFCFCFCFCu) >> 2) * 3u +
                       ((b & 0xFCFCFCFCu) >> 2);
    const uint32_t y = (((a & 0x03030303u) * 3u) +
                        (b & 0x03030303u)) >> 2;
    return x + (y & 0x03030303u);
}

inline uint32_t Interpolate611(uint32_t a, uint32_t b, uint32_t c) {
    const uint32_t x = ((a & 0xF8F8F8F8u) >> 3) * 6u +
                       ((b & 0xF8F8F8F8u) >> 3) +
                       ((c & 0xF8F8F8F8u) >> 3);
    const uint32_t y = (((a & 0x07070707u) * 6u) +
                        (b & 0x07070707u) +
                        (c & 0x07070707u)) >> 3;
    return x + (y & 0x07070707u);
}

inline uint32_t Pixel(const uint32_t *src, int w, int h, int x, int y) {
    if (x < 0) x = 0;
    if (x >= w) x = w - 1;
    if (y < 0) y = 0;
    if (y >= h) y = h - 1;
    return src[static_cast<size_t>(y) * static_cast<size_t>(w) +
               static_cast<size_t>(x)];
}

// ------------------------------------------------------------
// Normal 2x: nearest-neighbour. Kept as a useful baseline.
// ------------------------------------------------------------
inline void Normal2x(const uint32_t *src, int w, int h,
                     uint32_t *dst, int dp) {
    for (int y = 0; y < h; ++y) {
        const uint32_t *s = src + static_cast<size_t>(y) * w;
        uint32_t *d0 = dst + static_cast<size_t>(y * 2) * dp;
        uint32_t *d1 = d0 + dp;
        for (int x = 0; x < w; ++x) {
            const uint32_t p = s[x];
            d0[x * 2 + 0] = p;
            d0[x * 2 + 1] = p;
            d1[x * 2 + 0] = p;
            d1[x * 2 + 1] = p;
        }
    }
}

// ------------------------------------------------------------
// Bilinear / interpolation 2x.
//  [A B] -> [A, avg(A,B)]
//  [C D]    [avg(A,C), avg(A,B,C,D)]
// ------------------------------------------------------------
inline void Interpolation2x(const uint32_t *src, int w, int h,
                            uint32_t *dst, int dp) {
    for (int y = 0; y < h; ++y) {
        uint32_t *d0 = dst + static_cast<size_t>(y * 2) * dp;
        uint32_t *d1 = d0 + dp;
        for (int x = 0; x < w; ++x) {
            const uint32_t a = Pixel(src, w, h, x,     y);
            const uint32_t b = Pixel(src, w, h, x + 1, y);
            const uint32_t c = Pixel(src, w, h, x,     y + 1);
            const uint32_t d = Pixel(src, w, h, x + 1, y + 1);
            d0[x * 2 + 0] = a;
            d0[x * 2 + 1] = Interpolate11(a, b);
            d1[x * 2 + 0] = Interpolate11(a, c);
            d1[x * 2 + 1] = Interpolate1111(a, b, c, d);
        }
    }
}

// ------------------------------------------------------------
// AdvMAME2x / Scale2x.
// ------------------------------------------------------------
inline void AdvMame2x(const uint32_t *src, int w, int h,
                      uint32_t *dst, int dp) {
    for (int y = 0; y < h; ++y) {
        uint32_t *d0 = dst + static_cast<size_t>(y * 2) * dp;
        uint32_t *d1 = d0 + dp;
        for (int x = 0; x < w; ++x) {
            const uint32_t A = Pixel(src, w, h, x - 1, y - 1);
            const uint32_t B = Pixel(src, w, h, x,     y - 1);
            const uint32_t C = Pixel(src, w, h, x + 1, y - 1);
            const uint32_t D = Pixel(src, w, h, x - 1, y);
            const uint32_t E = Pixel(src, w, h, x,     y);
            const uint32_t F = Pixel(src, w, h, x + 1, y);
            const uint32_t G = Pixel(src, w, h, x - 1, y + 1);
            const uint32_t H = Pixel(src, w, h, x,     y + 1);
            const uint32_t I = Pixel(src, w, h, x + 1, y + 1);

            d0[x * 2 + 0] = (D == B && B != F && D != H) ? D : E;
            d0[x * 2 + 1] = (B == F && B != D && F != H) ? F : E;
            d1[x * 2 + 0] = (D == H && D != B && H != F) ? D : E;
            d1[x * 2 + 1] = (H == F && D != H && B != F) ? F : E;
            (void)A; (void)C; (void)G; (void)I;
        }
    }
}

inline int GetResult(uint32_t A, uint32_t B, uint32_t C, uint32_t D) {
    const bool ac = (A == C);
    const bool bc = (B == C);
    const bool ad = (A == D);
    const bool bd = (B == D);
    const int x = static_cast<int>(ac) + static_cast<int>(ad);
    const int y = static_cast<int>(bc && !ac) + static_cast<int>(bd && !ad);
    return (y >> 1) - (x >> 1);
}

// ------------------------------------------------------------
// 2xSaI (ScummVM SAI scaler, adapted to clamped addressing).
// ------------------------------------------------------------
inline void SAI2x(const uint32_t *src, int w, int h,
                  uint32_t *dst, int dp) {
    for (int y = 0; y < h; ++y) {
        uint32_t *d = dst + static_cast<size_t>(y * 2) * dp;
        for (int x = 0; x < w; ++x, d += 2) {
            const uint32_t I = Pixel(src,w,h,x-1,y-1);
            const uint32_t E = Pixel(src,w,h,x,  y-1);
            const uint32_t F = Pixel(src,w,h,x+1,y-1);
            const uint32_t J = Pixel(src,w,h,x+2,y-1);
            const uint32_t G = Pixel(src,w,h,x-1,y);
            const uint32_t A = Pixel(src,w,h,x,  y);
            const uint32_t B = Pixel(src,w,h,x+1,y);
            const uint32_t K = Pixel(src,w,h,x+2,y);
            const uint32_t H = Pixel(src,w,h,x-1,y+1);
            const uint32_t C = Pixel(src,w,h,x,  y+1);
            const uint32_t D = Pixel(src,w,h,x+1,y+1);
            const uint32_t L = Pixel(src,w,h,x+2,y+1);
            const uint32_t M = Pixel(src,w,h,x-1,y+2);
            const uint32_t N = Pixel(src,w,h,x,  y+2);
            const uint32_t O = Pixel(src,w,h,x+1,y+2);

            uint32_t p, p1, p2;
            if ((A == D) && (B != C)) {
                p  = ((A == E && B == L) ||
                      (A == C && A == F && B != E && B == J)) ? A : Interpolate11(A,B);
                p1 = ((A == G && C == O) ||
                      (A == B && A == H && G != C && C == M)) ? A : Interpolate11(A,C);
                p2 = A;
            } else if ((B == C) && (A != D)) {
                p  = ((B == F && A == H) ||
                      (B == E && B == D && A != F && A == I)) ? B : Interpolate11(A,B);
                p1 = ((C == H && A == F) ||
                      (C == G && C == D && A != H && A == I)) ? C : Interpolate11(A,C);
                p2 = B;
            } else if ((A == D) && (B == C)) {
                if (A == B) {
                    p = p1 = p2 = A;
                } else {
                    p1 = Interpolate11(A,C);
                    p = Interpolate11(A,B);
                    int r = 0;
                    r += GetResult(A,B,G,E);
                    r -= GetResult(B,A,K,F);
                    r -= GetResult(B,A,H,N);
                    r += GetResult(A,B,L,O);
                    p2 = (r > 0) ? A : (r < 0) ? B : Interpolate1111(A,B,C,D);
                }
            } else {
                p2 = Interpolate1111(A,B,C,D);
                if ((A == C) && (A == F) && (B != E) && (B == J))
                    p = A;
                else if ((B == E) && (B == D) && (A != F) && (A == I))
                    p = B;
                else
                    p = Interpolate11(A,B);
                if ((A == B) && (A == H) && (G != C) && (C == M))
                    p1 = A;
                else if ((C == G) && (C == D) && (A != H) && (A == I))
                    p1 = C;
                else
                    p1 = Interpolate11(A,C);
            }
            d[0] = A;
            d[1] = p;
            d[dp + 0] = p1;
            d[dp + 1] = p2;
        }
    }
}

// ------------------------------------------------------------
// Super2xSaI (ScummVM SuperSAI scaler, adapted to clamped addressing).
// ------------------------------------------------------------
inline void Super2xSaI(const uint32_t *src, int w, int h,
                       uint32_t *dst, int dp) {
    for (int y = 0; y < h; ++y) {
        uint32_t *d = dst + static_cast<size_t>(y * 2) * dp;
        for (int x = 0; x < w; ++x, d += 2) {
            const uint32_t B0 = Pixel(src,w,h,x-1,y-1);
            const uint32_t B1 = Pixel(src,w,h,x,  y-1);
            const uint32_t B2 = Pixel(src,w,h,x+1,y-1);
            const uint32_t B3 = Pixel(src,w,h,x+2,y-1);
            const uint32_t C4 = Pixel(src,w,h,x-1,y);
            const uint32_t C5 = Pixel(src,w,h,x,  y);
            const uint32_t C6 = Pixel(src,w,h,x+1,y);
            const uint32_t CS2= Pixel(src,w,h,x+2,y);
            const uint32_t C1 = Pixel(src,w,h,x-1,y+1);
            const uint32_t C2 = Pixel(src,w,h,x,  y+1);
            const uint32_t C3 = Pixel(src,w,h,x+1,y+1);
            const uint32_t CS1= Pixel(src,w,h,x+2,y+1);
            const uint32_t A0 = Pixel(src,w,h,x-1,y+2);
            const uint32_t A1 = Pixel(src,w,h,x,  y+2);
            const uint32_t A2 = Pixel(src,w,h,x+1,y+2);
            const uint32_t A3 = Pixel(src,w,h,x+2,y+2);

            uint32_t p1a,p1b,p2a,p2b;
            if (C2 == C6 && C5 != C3) {
                p1b = p2a = C2;
                p1a = (C1 == C2 || C6 == B2) ? Interpolate31(C2,C5) : Interpolate11(C5,C6);
                p2b = (C6 == CS2 || C2 == A1) ? Interpolate31(C2,C3) : Interpolate11(C2,C3);
            } else if (C5 == C3 && C2 != C6) {
                p2b = p1a = C5;
                p1b = (B1 == C5 || C3 == CS1) ? Interpolate31(C5,C6) : Interpolate11(C5,C6);
                p2a = (C3 == A2 || C4 == C5) ? Interpolate31(C5,C2) : Interpolate11(C2,C3);
            } else if (C5 == C3 && C2 == C6) {
                int r = 0;
                r += GetResult(C6,C5,C1,A1);
                r += GetResult(C6,C5,C4,B1);
                r += GetResult(C6,C5,A2,CS1);
                r += GetResult(C6,C5,B2,CS2);
                if (r > 0) {
                    p1b = p2a = C2;
                    p1a = p2b = Interpolate11(C5,C6);
                } else if (r < 0) {
                    p2b = p1a = C5;
                    p1b = p2a = Interpolate11(C5,C6);
                } else {
                    p2b = p1a = C5;
                    p1b = p2a = C2;
                }
            } else {
                p2b = p1a = Interpolate11(C2,C6);
                p2b = Interpolate611(C3,C3,p2b);
                p1a = Interpolate611(C5,C5,p1a);
                p2a = p1b = Interpolate11(C5,C3);
                p2a = Interpolate611(C2,C2,p2a);
                p1b = Interpolate611(C6,C6,p1b);
                (void)B0; (void)B3; (void)A0; (void)A3;
            }
            d[0] = p1a;
            d[1] = p1b;
            d[dp + 0] = p2a;
            d[dp + 1] = p2b;
        }
    }
}

// ------------------------------------------------------------
// SuperEagle 2x. This is the SuperEagle branch used by ScummVM.
// ------------------------------------------------------------
inline void SuperEagle2x(const uint32_t *src, int w, int h,
                         uint32_t *dst, int dp) {
    for (int y = 0; y < h; ++y) {
        uint32_t *d = dst + static_cast<size_t>(y * 2) * dp;
        for (int x = 0; x < w; ++x, d += 2) {
            const uint32_t B1  = Pixel(src,w,h,x,  y-1);
            const uint32_t B2  = Pixel(src,w,h,x+1,y-1);
            const uint32_t C4  = Pixel(src,w,h,x-1,y);
            const uint32_t C5  = Pixel(src,w,h,x,  y);
            const uint32_t C6  = Pixel(src,w,h,x+1,y);
            const uint32_t CS2 = Pixel(src,w,h,x+2,y);
            const uint32_t C1  = Pixel(src,w,h,x-1,y+1);
            const uint32_t C2  = Pixel(src,w,h,x,  y+1);
            const uint32_t C3  = Pixel(src,w,h,x+1,y+1);
            const uint32_t CS1 = Pixel(src,w,h,x+2,y+1);
            const uint32_t A1  = Pixel(src,w,h,x,  y+2);
            const uint32_t A2  = Pixel(src,w,h,x+1,y+2);

            uint32_t p1a,p1b,p2a,p2b;
            if (C5 != C3) {
                if (C2 == C6) {
                    p1b = p2a = C2;
                    p1a = (C1 == C2 || C6 == B2) ? Interpolate31(C2,C5) : Interpolate11(C5,C6);
                    p2b = (C6 == CS2 || C2 == A1) ? Interpolate31(C2,C3) : Interpolate11(C2,C3);
                } else {
                    p2b = Interpolate611(C3,C2,C6);
                    p1a = Interpolate611(C5,C2,C6);
                    p2a = Interpolate611(C2,C5,C3);
                    p1b = Interpolate611(C6,C5,C3);
                }
            } else if (C2 != C6) {
                p2b = p1a = C5;
                p1b = (B1 == C5 || C3 == CS1) ? Interpolate31(C5,C6) : Interpolate11(C5,C6);
                p2a = (C3 == A2 || C4 == C5) ? Interpolate31(C5,C2) : Interpolate11(C2,C3);
            } else {
                int r = 0;
                r += GetResult(C6,C5,C1,A1);
                r += GetResult(C6,C5,C4,B1);
                r += GetResult(C6,C5,A2,CS1);
                r += GetResult(C6,C5,B2,CS2);
                if (r > 0) {
                    p1b = p2a = C2;
                    p1a = p2b = Interpolate11(C5,C6);
                } else if (r < 0) {
                    p2b = p1a = C5;
                    p1b = p2a = Interpolate11(C5,C6);
                } else {
                    p2b = p1a = C5;
                    p1b = p2a = C2;
                }
            }
            d[0] = p1a;
            d[1] = p1b;
            d[dp + 0] = p2a;
            d[dp + 1] = p2b;
        }
    }
}

// ------------------------------------------------------------
// Pomocne funkce pro HQ2x-lite (viz nize).
// ------------------------------------------------------------

// Priblizna luma (BT.601) z ARGB8888 pixelu - jen pro info/pripadne
// budouci pouziti, samotny Hq2xLite pouziva primo RGB kanaly.
inline int LumaOf(uint32_t p) {
    const int r = static_cast<int>((p >> 16) & 0xFFu);
    const int g = static_cast<int>((p >> 8) & 0xFFu);
    const int b = static_cast<int>(p & 0xFFu);
    return (r * 299 + g * 587 + b * 114) / 1000;
}

// "Fuzzy" rovnost s prahem per-kanal - jadro rozdilu mezi 2xSaI/SuperEagle
// (presna rovnost pixelu ==) a HQ2x (rovnost "v ramci prahu"). Presna
// rovnost je krehka na dithering/antialiasing v puvodni DOS grafice -
// jeden odlisny bit uz SAI2x povazuje za "jinou barvu" a rozbije tim
// souvislou hranu na zbytecne segmenty. Prah dela vysledek odolnejsi.
inline bool NearlyEqual(uint32_t a, uint32_t b, int threshold = 24) {
    if (a == b) return true;
    const int dr = std::abs(static_cast<int>((a >> 16) & 0xFFu) - static_cast<int>((b >> 16) & 0xFFu));
    const int dg = std::abs(static_cast<int>((a >> 8) & 0xFFu) - static_cast<int>((b >> 8) & 0xFFu));
    const int db = std::abs(static_cast<int>(a & 0xFFu) - static_cast<int>(b & 0xFFu));
    return (dr <= threshold) && (dg <= threshold) && (db <= threshold);
}

// ------------------------------------------------------------
// HQ2x-lite. POZNAMKA: tohle NENI bajtove identicka reimplementace
// originalniho HQ2x (Maxim Stepin) - ten pouziva plnou tabulku 256
// vzoru z YUV-prahoveho porovnani 8 sousedu. Tady je stejna zakladni
// mySlenka (prahova, ne presna rovnost pixelu -> hrany se nerozbiji
// na kazdem drobnem rozdilu barvy zpusobenem ditheringem) aplikovana
// na uz existujici SAI2x kostru v tomto souboru - misto '==' pouziva
// NearlyEqual(). Ocekavej hladsi/spojitejsi hrany nez SAI2x na
// ditherovane DOS grafice, ale ne uplne stejny vysledek jako "opravdovy"
// HQ2x z jinych nastroju.
// ------------------------------------------------------------
inline void Hq2xLite(const uint32_t *src, int w, int h,
                     uint32_t *dst, int dp, int threshold = 24) {
    for (int y = 0; y < h; ++y) {
        uint32_t *d = dst + static_cast<size_t>(y * 2) * dp;
        for (int x = 0; x < w; ++x, d += 2) {
            const uint32_t I = Pixel(src,w,h,x-1,y-1);
            const uint32_t E = Pixel(src,w,h,x,  y-1);
            const uint32_t F = Pixel(src,w,h,x+1,y-1);
            const uint32_t J = Pixel(src,w,h,x+2,y-1);
            const uint32_t G = Pixel(src,w,h,x-1,y);
            const uint32_t A = Pixel(src,w,h,x,  y);
            const uint32_t B = Pixel(src,w,h,x+1,y);
            const uint32_t K = Pixel(src,w,h,x+2,y);
            const uint32_t H = Pixel(src,w,h,x-1,y+1);
            const uint32_t C = Pixel(src,w,h,x,  y+1);
            const uint32_t D = Pixel(src,w,h,x+1,y+1);
            const uint32_t L = Pixel(src,w,h,x+2,y+1);
            const uint32_t M = Pixel(src,w,h,x-1,y+2);
            const uint32_t N = Pixel(src,w,h,x,  y+2);
            const uint32_t O = Pixel(src,w,h,x+1,y+2);

            auto eq = [threshold](uint32_t a, uint32_t b) { return NearlyEqual(a, b, threshold); };

            uint32_t p, p1, p2;
            if (eq(A,D) && !eq(B,C)) {
                p  = ((eq(A,E) && eq(B,L)) ||
                      (eq(A,C) && eq(A,F) && !eq(B,E) && eq(B,J))) ? A : Interpolate11(A,B);
                p1 = ((eq(A,G) && eq(C,O)) ||
                      (eq(A,B) && eq(A,H) && !eq(G,C) && eq(C,M))) ? A : Interpolate11(A,C);
                p2 = A;
            } else if (eq(B,C) && !eq(A,D)) {
                p  = ((eq(B,F) && eq(A,H)) ||
                      (eq(B,E) && eq(B,D) && !eq(A,F) && eq(A,I))) ? B : Interpolate11(A,B);
                p1 = ((eq(C,H) && eq(A,F)) ||
                      (eq(C,G) && eq(C,D) && !eq(A,H) && eq(A,I))) ? C : Interpolate11(A,C);
                p2 = B;
            } else if (eq(A,D) && eq(B,C)) {
                if (eq(A,B)) {
                    p = p1 = p2 = A;
                } else {
                    p1 = Interpolate11(A,C);
                    p = Interpolate11(A,B);
                    int r = 0;
                    r += GetResult(A,B,G,E);
                    r -= GetResult(B,A,K,F);
                    r -= GetResult(B,A,H,N);
                    r += GetResult(A,B,L,O);
                    p2 = (r > 0) ? A : (r < 0) ? B : Interpolate1111(A,B,C,D);
                }
            } else {
                p2 = Interpolate1111(A,B,C,D);
                if (eq(A,C) && eq(A,F) && !eq(B,E) && eq(B,J))
                    p = A;
                else if (eq(B,E) && eq(B,D) && !eq(A,F) && eq(A,I))
                    p = B;
                else
                    p = Interpolate11(A,B);
                if (eq(A,B) && eq(A,H) && !eq(G,C) && eq(C,M))
                    p1 = A;
                else if (eq(C,G) && eq(C,D) && !eq(A,H) && eq(A,I))
                    p1 = C;
                else
                    p1 = Interpolate11(A,C);
            }
            d[0] = A;
            d[1] = p;
            d[dp + 0] = p1;
            d[dp + 1] = p2;
        }
    }
}

// Prevod ARGB8888 -> priblizne YUV (BT.601), jen pro ucely prahovaneho
// porovnani barev v Hq2xFull - presne konstanty nejsou kriticke, jde jen
// o to mit jas (Y) oddeleny od barevnosti (U/V).
inline void RgbToYuv(uint32_t p, int &y, int &u, int &v) {
    const int r = static_cast<int>((p >> 16) & 0xFFu);
    const int g = static_cast<int>((p >> 8) & 0xFFu);
    const int b = static_cast<int>(p & 0xFFu);
    y = (r * 299 + g * 587 + b * 114) / 1000;
    u = (r * -169 + g * -331 + b * 500) / 1000;
    v = (r * 500 + g * -419 + b * -81) / 1000;
}

// Rovnost s ODDELENYM prahem pro jas a barvu (YUV) - tohle je skutecny
// technicky rozdil originalniho HQ2x (Maxim Stepin) oproti nasi RGB-praho-
// ve NearlyEqual() vyse. Realny HQ2x pouziva vyrazne PRISNEJSI prah na
// barvu (U/V) nez na jas (Y): lidske oko je citlivejsi na zmenu barvy nez
// na zmenu jasu, takze dva pixely lisici se hlavne jasem (napr. AA/dither
// stejne barvy) projdou jako "stejne" snadneji nez pixely lisici se
// odstinem - coz plocha RGB prahu v NearlyEqual() nerozlisuje (bere
// R/G/B naprosto rovnocenne). Vysledek: Hq2xFull by mel lip drzet barevne
// hrany a zaroven byt jeste odolnejsi vuci ditheringu na jednobarevnych
// plochach nez Hq2xLite.
inline bool NearlyEqualYuv(uint32_t a, uint32_t b, int yThreshold, int uThreshold, int vThreshold) {
    if (a == b) return true;
    int ya, ua, va, yb, ub, vb;
    RgbToYuv(a, ya, ua, va);
    RgbToYuv(b, yb, ub, vb);
    return std::abs(ya - yb) <= yThreshold &&
           std::abs(ua - ub) <= uThreshold &&
           std::abs(va - vb) <= vThreshold;
}

// ------------------------------------------------------------
// HQ2x-full. Stejna strukturalni kostra (SAI2x-derived rohova logika)
// jako Hq2xLite vyse, ale rovnost pixelu resi NearlyEqualYuv() misto
// NearlyEqual() - viz komentar tam. Porad to NENI bajtove identicka
// reimplementace originalniho 256-vzoroveho Stepinova HQ2x (ten navic
// pouziva par specialnich tie-break pravidel u nekolika desitek vzoru),
// ale technicky principem (prahova YUV rovnost s prisnejsim prahem na
// barvu nez na jas) je bliz "opravdovemu" HQ2x nez Hq2xLite.
// Vychozi prahy (Y=48, U=7, V=6) odpovidaji radove tomu, co pouziva
// referencni HQ2x (skalovano na nasi 0-255 RGB reprezentaci).
// ------------------------------------------------------------
inline void Hq2xFull(const uint32_t *src, int w, int h,
                     uint32_t *dst, int dp,
                     int yThreshold = 48, int uThreshold = 7, int vThreshold = 6) {
    for (int y = 0; y < h; ++y) {
        uint32_t *d = dst + static_cast<size_t>(y * 2) * dp;
        for (int x = 0; x < w; ++x, d += 2) {
            const uint32_t I = Pixel(src,w,h,x-1,y-1);
            const uint32_t E = Pixel(src,w,h,x,  y-1);
            const uint32_t F = Pixel(src,w,h,x+1,y-1);
            const uint32_t J = Pixel(src,w,h,x+2,y-1);
            const uint32_t G = Pixel(src,w,h,x-1,y);
            const uint32_t A = Pixel(src,w,h,x,  y);
            const uint32_t B = Pixel(src,w,h,x+1,y);
            const uint32_t K = Pixel(src,w,h,x+2,y);
            const uint32_t H = Pixel(src,w,h,x-1,y+1);
            const uint32_t C = Pixel(src,w,h,x,  y+1);
            const uint32_t D = Pixel(src,w,h,x+1,y+1);
            const uint32_t L = Pixel(src,w,h,x+2,y+1);
            const uint32_t M = Pixel(src,w,h,x-1,y+2);
            const uint32_t N = Pixel(src,w,h,x,  y+2);
            const uint32_t O = Pixel(src,w,h,x+1,y+2);

            auto eq = [yThreshold, uThreshold, vThreshold](uint32_t a, uint32_t b) {
                return NearlyEqualYuv(a, b, yThreshold, uThreshold, vThreshold);
            };

            uint32_t p, p1, p2;
            if (eq(A,D) && !eq(B,C)) {
                p  = ((eq(A,E) && eq(B,L)) ||
                      (eq(A,C) && eq(A,F) && !eq(B,E) && eq(B,J))) ? A : Interpolate11(A,B);
                p1 = ((eq(A,G) && eq(C,O)) ||
                      (eq(A,B) && eq(A,H) && !eq(G,C) && eq(C,M))) ? A : Interpolate11(A,C);
                p2 = A;
            } else if (eq(B,C) && !eq(A,D)) {
                p  = ((eq(B,F) && eq(A,H)) ||
                      (eq(B,E) && eq(B,D) && !eq(A,F) && eq(A,I))) ? B : Interpolate11(A,B);
                p1 = ((eq(C,H) && eq(A,F)) ||
                      (eq(C,G) && eq(C,D) && !eq(A,H) && eq(A,I))) ? C : Interpolate11(A,C);
                p2 = B;
            } else if (eq(A,D) && eq(B,C)) {
                if (eq(A,B)) {
                    p = p1 = p2 = A;
                } else {
                    p1 = Interpolate11(A,C);
                    p = Interpolate11(A,B);
                    int r = 0;
                    r += GetResult(A,B,G,E);
                    r -= GetResult(B,A,K,F);
                    r -= GetResult(B,A,H,N);
                    r += GetResult(A,B,L,O);
                    p2 = (r > 0) ? A : (r < 0) ? B : Interpolate1111(A,B,C,D);
                }
            } else {
                p2 = Interpolate1111(A,B,C,D);
                if (eq(A,C) && eq(A,F) && !eq(B,E) && eq(B,J))
                    p = A;
                else if (eq(B,E) && eq(B,D) && !eq(A,F) && eq(A,I))
                    p = B;
                else
                    p = Interpolate11(A,B);
                if (eq(A,B) && eq(A,H) && !eq(G,C) && eq(C,M))
                    p1 = A;
                else if (eq(C,G) && eq(C,D) && !eq(A,H) && eq(A,I))
                    p1 = C;
                else
                    p1 = Interpolate11(A,C);
            }
            d[0] = A;
            d[1] = p;
            d[dp + 0] = p1;
            d[dp + 1] = p2;
        }
    }
}

// ------------------------------------------------------------
// Scale2xSmooth. Vlastni odvozenina od AdvMame2x/Scale2x vyse - stejna
// diagonalni-hrana podminka (D priblizne B, B jine nez F, D jine nez H),
// ale misto TVRDE nahrady rohu sousednim pixelem (klasicky Scale2x/EPX,
// odtud typicke "schody" na diagonalach) se roh jen PRIBLIZI k nemu
// 3:1 vahovanym blendem (Interpolate31). Vysledek: mekci diagonaly nez
// AdvMame2x, poradne ostrejsi nez bilinear (Interpolation2x), a bez
// rizika Eagle-stylu zmizeni izolovanych pixelu - fallback je vzdy
// stredovy pixel E, stejne konzervativne jako zbytek souboru.
// Prah (NearlyEqual, viz vyse) dela hranovou podminku odolnou vuci
// ditheringu, presne jako u Hq2xLite.
// ------------------------------------------------------------
inline void Scale2xSmooth(const uint32_t *src, int w, int h,
                          uint32_t *dst, int dp, int threshold = 32) {
    for (int y = 0; y < h; ++y) {
        uint32_t *d0 = dst + static_cast<size_t>(y * 2) * dp;
        uint32_t *d1 = d0 + dp;
        for (int x = 0; x < w; ++x) {
            const uint32_t B = Pixel(src, w, h, x,     y - 1);
            const uint32_t D = Pixel(src, w, h, x - 1, y);
            const uint32_t E = Pixel(src, w, h, x,     y);
            const uint32_t F = Pixel(src, w, h, x + 1, y);
            const uint32_t H = Pixel(src, w, h, x,     y + 1);

            auto eq = [threshold](uint32_t a, uint32_t b) { return NearlyEqual(a, b, threshold); };

            const uint32_t tl = (eq(D,B) && !eq(B,F) && !eq(D,H))
                ? Interpolate31(Interpolate11(D,B), E) : E;
            const uint32_t tr = (eq(B,F) && !eq(B,D) && !eq(F,H))
                ? Interpolate31(Interpolate11(B,F), E) : E;
            const uint32_t bl = (eq(D,H) && !eq(D,B) && !eq(H,F))
                ? Interpolate31(Interpolate11(D,H), E) : E;
            const uint32_t br = (eq(H,F) && !eq(D,H) && !eq(B,F))
                ? Interpolate31(Interpolate11(H,F), E) : E;

            d0[x * 2 + 0] = tl;
            d0[x * 2 + 1] = tr;
            d1[x * 2 + 0] = bl;
            d1[x * 2 + 1] = br;
        }
    }
}

} // namespace Scalers2x
} // namespace Port::Vga
