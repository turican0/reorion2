/* Watcom C library qsort_ as the original uses it (IDA 0x133EF4, collapsed in
   the listing - disassembled with tools/compare/disasm_range.py, together
   with its helpers: the swap at 0x133E76 and the median of three at
   0x133E9C).

   Why not the CRT qsort: equal keys come out in a different order (the
   sort is not stable, and every implementation is unstable differently),
   so lists with ties - ships of one design, planets of one size - were
   ordered differently from the original.

   Algorithm (Bentley-McIlroy): below 16 elements a gap insertion sort with
   gaps 3 and 1; otherwise the pivot is the median of three (a "ninther"
   above 42 elements), three-way partition with the equal keys moved to both
   ends and back, the larger part goes on an explicit stack and the loop
   continues with the smaller one. Comparator: cmp(a, b) like the CRT. */
#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef int (*PortQsortCmp)(const void *, const void *);

/* 0x133E76: swap n bytes (dwords first, then the rest) */
static void PortQsort_Swap(uint8_t *a, uint8_t *b, size_t n)
{
    size_t i;

    for (i = 0; i + 4 <= n; i += 4) {
        uint32_t t;
        memcpy(&t, a + i, 4);
        memcpy(a + i, b + i, 4);
        memcpy(b + i, &t, 4);
    }
    for (; i < n; ++i) {
        uint8_t t = a[i];
        a[i] = b[i];
        b[i] = t;
    }
}

/* 0x133E9C: median of three */
static uint8_t *PortQsort_Med3(uint8_t *a, uint8_t *b, uint8_t *c, PortQsortCmp cmp)
{
    if (cmp(a, b) > 0) {
        if (cmp(a, c) <= 0)
            return a;
        return cmp(b, c) > 0 ? b : c;
    }
    if (cmp(a, c) >= 0)
        return a;
    return cmp(b, c) > 0 ? c : b;
}

/* returns 0 - the original leaves an unrelated value in eax; some callers
   pass it on (`return qsort(...)`) */
int PortWatcom_Qsort(void *base_, size_t n, size_t size, PortQsortCmp cmp)
{
    uint8_t *base = (uint8_t *)base_;
    uint8_t *stackBase[32];
    size_t stackN[32];
    int sp = 0;
    /* swaptype: 0 = one aligned dword (swap in place, pivot copied), else
       the byte swap of 0x133E76 */
    int swaptype = (((uintptr_t)base | size) & 3) ? 2 : (size > 4);
    uint32_t pivotCopy;

    for (;;) {
        if (n > 1 && n < 16) {
            /* 0x133F54: gap insertion sort, gaps 3 * size and size */
            ptrdiff_t gap;
            uint8_t *end = base + n * size;
            for (gap = (ptrdiff_t)(3 * size); gap > 0; gap -= (ptrdiff_t)(2 * size)) {
                uint8_t *p;
                for (p = base + gap; p < end; p += gap) {
                    uint8_t *q;
                    for (q = p; q > base; q -= gap) {
                        uint8_t *r = q - gap;
                        if (cmp(r, q) <= 0)
                            break;
                        if (swaptype)
                            PortQsort_Swap(q, r, size);
                        else {
                            uint32_t t = *(uint32_t *)r;
                            *(uint32_t *)r = *(uint32_t *)q;
                            *(uint32_t *)q = t;
                        }
                    }
                }
            }
        } else if (n >= 16) {
            uint8_t *mid = base + (n >> 1) * size;
            uint8_t *pv, *a, *b, *c, *d, *pn;
            size_t r, s0, s1;
            if (n > 29) {
                uint8_t *lo = base;
                uint8_t *hi = base + (n - 1) * size;
                if (n > 42) {
                    size_t dd = (n >> 3) * size;
                    lo = PortQsort_Med3(base, base + dd, base + 2 * dd, cmp);
                    mid = PortQsort_Med3(mid - dd, mid, mid + dd, cmp);
                    hi = PortQsort_Med3(hi - 2 * dd, hi - dd, hi, cmp);
                }
                mid = PortQsort_Med3(lo, mid, hi, cmp);
            }
            if (swaptype) {
                pv = base;
                PortQsort_Swap(base, mid, size);
            } else {
                pivotCopy = *(uint32_t *)mid;
                pv = (uint8_t *)&pivotCopy;
            }
            a = b = base;
            c = d = base + (n - 1) * size;
            for (;;) {
                int res;
                while (b <= c && (res = cmp(b, pv)) <= 0) {
                    if (res == 0) {
                        if (swaptype)
                            PortQsort_Swap(a, b, size);
                        else {
                            uint32_t t = *(uint32_t *)b;
                            *(uint32_t *)b = *(uint32_t *)a;
                            *(uint32_t *)a = t;
                        }
                        a += size;
                    }
                    b += size;
                }
                while (b <= c && (res = cmp(c, pv)) >= 0) {
                    if (res == 0) {
                        if (swaptype)
                            PortQsort_Swap(d, c, size);
                        else {
                            uint32_t t = *(uint32_t *)d;
                            *(uint32_t *)d = *(uint32_t *)c;
                            *(uint32_t *)c = t;
                        }
                        d -= size;
                    }
                    c -= size;
                }
                if (b > c)
                    break;
                if (swaptype)
                    PortQsort_Swap(b, c, size);
                else {
                    uint32_t t = *(uint32_t *)c;
                    *(uint32_t *)c = *(uint32_t *)b;
                    *(uint32_t *)b = t;
                }
                b += size;
                c -= size;
            }
            /* 0x134200: move the equal keys from both ends to the middle */
            pn = base + n * size;
            r = (size_t)(a - base);
            if ((ptrdiff_t)(b - a) < (ptrdiff_t)r)
                r = (size_t)(b - a);
            if (r)
                PortQsort_Swap(base, b - r, r);
            r = (size_t)(d - c);
            if ((size_t)(pn - d) - size < r)
                r = (size_t)(pn - d) - size;
            if (r)
                PortQsort_Swap(b, pn - r, r);
            s1 = (size_t)(d - c);     /* right part, bytes */
            s0 = (size_t)(b - a);     /* left part, bytes */
            if (s1 >= s0) {
                stackN[sp] = s1 / size;
                stackBase[sp] = pn - s1;
                n = s0 / size;
                ++sp;
                continue;
            }
            if (s0 > size) {
                stackBase[sp] = base;
                stackN[sp] = s0 / size;
                base = pn - s1;
                n = s1 / size;
                ++sp;
                continue;
            }
        }
        /* 0x133FD8: next part from the stack */
        if (sp == 0)
            return 0;
        --sp;
        base = stackBase[sp];
        n = stackN[sp];
    }
}
