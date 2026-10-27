"""Show an inline hook of ORION150.EXE (diss150_ida91/hooks.tsv) for wiring by hand.

For each SITE prints the 1.31 asm around it, the 1.50 asm at it, the stub the hook jumps to
(up to its endp) and the C function of the port with the lines that call the functions the
asm window calls.

usage: python tools/compare/inlsite.py SITE... [--before N] [--after N]
"""
import glob
import re
import sys

DISS = 'C:/prenos/reorion2Data/diss150_ida91/'
LST131 = 'C:/prenos/reorion2Data/diss/Orion2.exe.lst'
LST150 = DISS + 'ORION150.full.lst'
RX = re.compile(r'^(\w+):([0-9A-F]{8})\s(.*)$')


def load(path):
    out = []
    with open(path, encoding='latin-1') as f:
        for line in f:
            m = RX.match(line)
            if not m:
                continue
            body = re.sub(r'\s*;.*$', '', m.group(3)).rstrip()
            if not body.strip():
                continue
            out.append((int(m.group(2), 16), body))
    return out


def index_of(lst, addr):
    lo, hi = 0, len(lst)
    while lo < hi:
        mid = (lo + hi) // 2
        if lst[mid][0] < addr:
            lo = mid + 1
        else:
            hi = mid
    return lo


def is_ins(body):
    return body.startswith(' ') and not re.match(r'\s+(db|dw|dd|align)\b', body) and not re.match(r'^\s*\w+\s+=', body)


def window(lst, addr, before, after):
    i = index_of(lst, addr)
    j, n = i, 0
    while j > 0 and n < before:
        j -= 1
        if is_ins(lst[j][1]):
            n += 1
    k, n = i, 0
    while k < len(lst) and n <= after:
        if is_ins(lst[k][1]) and lst[k][0] >= addr:
            n += 1
        k += 1
    return lst[j:k]


def stub(lst, addr):
    i = index_of(lst, addr)
    out = []
    for a, b in lst[i:i + 120]:
        out.append((a, b))
        if 'endp' in b and a >= addr:
            break
    return out


def main():
    args = sys.argv[1:]
    before, after = 14, 10
    if '--before' in args:
        before = int(args[args.index('--before') + 1])
    if '--after' in args:
        after = int(args[args.index('--after') + 1])
    sites = [a for a in args if re.fullmatch(r'[0-9A-Fa-f]{5,6}', a)]
    rows = {int(r[0], 16): r for r in
            (l.rstrip('\n').split('\t') for l in open(DISS + 'hooks.tsv', encoding='latin-1')) if r[0] != 'site'}
    l131, l150 = load(LST131), load(LST150)
    cfiles = glob.glob('src/game/*.c')
    for s in sites:
        a = int(s, 16)
        r = rows.get(a)
        print('=' * 20, s, r[1:] if r else '(not in hooks.tsv)')
        print('--- 1.31')
        for x, b in window(l131, a, before, after):
            print('%s %06X %s' % ('>' if x == a else ' ', x, b))
        print('--- 1.50')
        for x, b in window(l150, a, 2, after):
            print('%s %06X %s' % ('>' if x == a else ' ', x, b))
        if r:
            t = int(r[4], 16)
            print('--- stub %06X' % t)
            for x, b in stub(l150, t):
                print('  %06X %s' % (x, b))
            func = r[1]
            calls = set()
            for x, b in window(l131, a, before, after):
                m = re.match(r'\s+call\s+(\w+)', b)
                if m:
                    calls.add(m.group(1))
            for p in cfiles:
                txt = open(p, encoding='latin-1').read().split('\n')
                for i, line in enumerate(txt):
                    if re.match(r'^\S.*\b%s(_131)?\s*\(' % func, line) and not line.rstrip().endswith(';'):
                        end = i + 1
                        while end < len(txt) and not txt[end].startswith('}'):
                            end += 1
                        print('--- C %s:%d-%d' % (p, i + 1, end + 1))
                        for k in range(i, end):
                            if any(re.search(r'\b%s\b' % c, txt[k]) for c in calls) or ('1.50' in txt[k]):
                                print('  %5d %s' % (k + 1, txt[k]))
                        break


if __name__ == '__main__':
    main()
