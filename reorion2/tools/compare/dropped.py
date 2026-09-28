"""List call statements of given callees whose result is dropped; suggest the
eax-variable the next lines read (declared '// ax'/'// eax', not yet assigned)."""
import re, sys, glob, os
os.chdir(r'C:\prenos\reorion2\reorion2')
names = sys.argv[1].split(',')
apply = '--fix' in sys.argv
for p in sorted(glob.glob('src/game/orion_part_*.c')):
    d = open(p, 'rb').read()
    crlf = b'\r\n' in d
    lines = d.replace(b'\r\n', b'\n').decode('latin-1').split('\n')
    changed = False
    func_start = 0
    for i, ln in enumerate(lines):
        if re.match(r'^[a-zA-Z_].*\b(sub_[0-9A-F]+)\s*\(.*\)\s*$', ln) and i + 1 < len(lines) and lines[i + 1] == '{':
            func_start = i
        m = re.match(r'^(\s*)(sub_[0-9A-F]+)\((.*)\);\s*$', ln)
        if not m or m.group(2) not in names:
            continue
        # locals with register comment
        decl = {}
        for j in range(func_start, i):
            dm = re.match(r'^\s+[\w ]+?\s\*?(v\d+|result); // (e?[a-d]x)\b', lines[j])
            if dm:
                decl[dm.group(1)] = dm.group(2)
        body = '\n'.join(lines[func_start:i])
        cand = None
        for k in range(i + 1, min(i + 6, len(lines))):
            for v in re.findall(r'\b(v\d+|result)\b', lines[k]):
                if v in decl and not re.search(r'\b%s\s*=[^=]' % v, body):
                    cand = v
                    break
            if cand:
                break
        print('%s:%d  %s' % (p, i + 1, ln.strip()))
        print('      next: %s' % ' | '.join(l.strip() for l in lines[i + 1:i + 3]))
        print('      cand: %s (%s)' % (cand, decl.get(cand)))
