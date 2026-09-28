"""List Hex-Rays 'variable is possibly undefined' notes whose variable is still never
assigned in the port function (= a dropped call result or a lost register)."""
import re, glob, os, sys
os.chdir(r'C:\prenos\reorion2\reorion2')
flt = sys.argv[1] if len(sys.argv) > 1 else None
total = 0
for p in sorted(glob.glob('src/game/orion_part_*.c')):
    t = open(p, encoding='latin-1').read().replace('\r\n', '\n')
    for m in re.finditer(r'//----- \(([0-9A-F]{8})\) -+\n(.*?)(?=//----- \(|\Z)', t, re.S):
        addr, blk = m.group(1), m.group(2)
        notes = re.findall(r"^// ([0-9A-F]+): variable '(\w+)' is possibly undefined", blk, re.M)
        if not notes:
            continue
        bm = re.search(r'\n\{\n(.*?)\n\}\n', blk, re.S)
        if not bm:
            continue
        body = bm.group(1)
        # drop declarations
        code = '\n'.join(l for l in body.split('\n') if not re.match(r'^\s+[\w ]+\*?\s*\**(\w+)(\[\d+\])?; //', l))
        bad = []
        for ea, v in notes:
            assigned = re.search(r'(?<![\w.>])%s\s*(=[^=]|\+=|-=|\+\+|--)|(\+\+|--)%s\b|&%s\b|LOWORD\(%s\)\s*=|LOBYTE\(%s\)\s*=|HIWORD\(%s\)\s*=|HIBYTE\(%s\)\s*=|BYTE\d\(%s\)\s*=' % ((v,) * 8), code)
            if not assigned:
                bad.append('%s@%s' % (v, ea))
        if bad:
            fm = re.search(r'^\S.*\b(sub_\w+)\(', body and blk, re.M)
            name = 'sub_%X' % int(addr, 16)
            if flt and flt not in p:
                continue
            total += len(bad)
            print('%s %s: %s' % (os.path.basename(p), name, ' '.join(bad)))
print('total', total)
