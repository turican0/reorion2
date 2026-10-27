"""Show the changes of ORION150.EXE in a 1.31 function (diss150_ida91/funcdiff.tsv) with the hooks in it.

For each changed range prints the 1.31 and the 1.50 asm around it; hooks jumping out of the
range print their stub.

usage: python tools/compare/fdiff150.py FUNC [--ctx N]
"""
import re
import sys

sys.path.insert(0, 'tools/compare')
from inlsite import DISS, LST131, LST150, load, window, stub   # noqa: E402


def main():
    func = sys.argv[1]
    ctx = int(sys.argv[sys.argv.index('--ctx') + 1]) if '--ctx' in sys.argv else 4
    row = None
    for l in open(DISS + 'funcdiff.tsv', encoding='latin-1'):
        r = l.rstrip('\n').split('\t')
        if r[0] == func:
            row = r
    if not row:
        print('no funcdiff row for', func)
        return
    ranges = []
    for x in row[5].split() if len(row) > 5 else []:
        a, b = x.split('-')
        ranges.append((int(a, 16), int(b, 16)))
    hooks = {}
    for l in open(DISS + 'hooks.tsv', encoding='latin-1'):
        r = l.rstrip('\n').split('\t')
        if r[0] != 'site' and r[1] == func:
            hooks[int(r[0], 16)] = r
    l131, l150 = load(LST131), load(LST150)
    print(func, row[1:5])
    shown = set()
    for a, b in ranges:
        span = max(1, (b - a) // 2)
        print('=' * 12, '%06X-%06X' % (a, b))
        print('--- 1.31')
        for x, t in window(l131, a, ctx, span + ctx):
            print('%s %06X %s' % ('*' if a <= x <= b else ' ', x, t))
        print('--- 1.50')
        for x, t in window(l150, a, ctx, span + ctx):
            print('%s %06X %s' % ('*' if a <= x <= b else ' ', x, t))
            m = re.search(r'\b(?:call|jmp)\s+(?:near ptr )?(sub_1E[0-9A-F]{4}|sub_1F[0-9A-F]{4}|sub_20[0-9A-F]{4})', t)
            if m and m.group(1) not in shown:
                shown.add(m.group(1))
                for y, u in stub(l150, int(m.group(1)[4:], 16)):
                    print('      | %06X %s' % (y, u))
    for a in sorted(hooks):
        if not any(x <= a <= y for x, y in ranges):
            print('hook outside the ranges: %06X %s -> %s' % (a, hooks[a][2], hooks[a][5]))


if __name__ == '__main__':
    main()
