"""Classify every JUMPOUT(addr) in the port by what the asm tail at addr does."""
import re, glob, os, sys
os.chdir(r'C:\prenos\reorion2\reorion2')
LST = 'C:/prenos/reorion2Data/diss/Orion2.exe.lst'
ins = []   # (addr, text)
for l in open(LST, encoding='utf-8', errors='replace'):
    m = re.match(r'cseg01:([0-9A-F]{8})\s{3,}(\S.*)$', l.rstrip('\n'))
    if not m:
        continue
    s = m.group(2).split(';')[0].strip()
    if not s or s.endswith(':') or re.match(r'^(sub_\w+|\w+)\s+(proc|endp)\b', s) or re.match(r'^\w+\s+=\s', s) or s.startswith(('db ', 'dd ', 'dw ', 'align')):
        continue
    ins.append((int(m.group(1), 16), s))
addrs = [a for a, _ in ins]
import bisect
def tail(a):
    i = bisect.bisect_left(addrs, a)
    out = []
    while i < len(ins) and len(out) < 14:
        s = ins[i][1]
        out.append(s)
        if s.startswith(('retn', 'jmp ')):
            break
        i += 1
    return out
EPI = re.compile(r'^(leave|pop\s+\w+|retn.*|lea\s+esp, \[ebp\+\w+\]|add\s+esp, \w+)$')
verbose = '-v' in sys.argv
for p in sorted(glob.glob('src/game/orion_part_*.c')):
    lines = open(p, encoding='latin-1').read().replace('\r\n', '\n').split('\n')
    func = '?'
    for n, l in enumerate(lines, 1):
        fm = re.match(r'^//----- \(([0-9A-F]{8})\)', l)
        if fm:
            func = 'sub_%X' % int(fm.group(1), 16)
        m = re.search(r'\bJUMPOUT\((0x[0-9A-Fa-f]+)\)', l)
        if not m or l.strip().startswith('//'):
            continue
        t = tail(int(m.group(1), 16))
        body = [s for s in t if not EPI.match(s)]
        kind = 'EPILOG' if not body else ('RET ' + body[0] if len(body) == 1 and body[0].startswith('mov eax,') else 'CODE')
        if kind == 'EPILOG' and not verbose:
            continue
        print('%s:%d %s %s -> %s' % (os.path.basename(p), n, func, m.group(1), kind))
        if kind == 'CODE':
            print('      ' + ' | '.join(t))
