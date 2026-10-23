"""Wave 185: wire a 1.50 call->call hook at one call site of the port.

The site's 1.31 instruction is "call X" inside function F (diss150_ida91/hooks.tsv). Its ordinal among the
calls of X in F (1.31 listing) picks the call in the port's C body of F - only when both counts agree. The
call "X(" becomes "HOOK(" and the line gets the marker "/* 1.50 SITE */" (tools/compare/hooks150_status.py).

usage: python tools/compare/hooksite.py SITE HOOK [SITE HOOK ...] [--dry]
"""
import glob
import re
import sys

DISS = 'C:/prenos/reorion2Data/diss150_ida91/'
L131 = open('C:/prenos/reorion2Data/diss/Orion2.exe.lst', encoding='latin-1').read().split('\n')
rows = {l.split('\t')[0]: l.rstrip('\n').split('\t') for l in open(DISS + 'hooks.tsv', encoding='latin-1')
        if l[:1] != 's' and l.strip()}
files = sorted(glob.glob('src/game/orion_part_*.c'))
dry = '--dry' in sys.argv
args = [a for a in sys.argv[1:] if a != '--dry']


def asm_calls(func, callee):
    """addresses of 'call callee' in the 1.31 function func, in order"""
    out, inside = [], False
    for l in L131:
        m = re.match(r'^cseg01:([0-9A-F]{8})\s+(\w+)\s+(proc|endp)\b', l)
        if m and m.group(2) == func:
            inside = m.group(3) == 'proc'
            if not inside:
                break
            continue
        if inside:
            m = re.match(r'^cseg01:([0-9A-F]{8})\s+call\s+%s\s*$' % re.escape(callee), l)
            if m:
                out.append(m.group(1)[2:])
    return out


for k in range(0, len(args), 2):
    site, hook = args[k].upper().zfill(6), args[k + 1]
    row = rows.get(site)
    if not row:
        print('%s: not in hooks.tsv' % site)
        continue
    func, ins = row[1], row[2].split()
    if len(ins) < 2 or ins[0] != 'call':
        print('%s: not a call (%s)' % (site, row[2]))
        continue
    callee = ins[1]
    order = asm_calls(func, callee)
    if site not in order:
        print('%s: call not found in %s' % (site, func))
        continue
    ordinal = order.index(site)
    done = False
    for p in files:
        raw = open(p, 'rb').read()
        crlf = b'\r\n' in raw
        t = raw.replace(b'\r\n', b'\n').decode('latin-1')
        m = re.search(r'//----- \(00%s\) -+\n' % func[4:].zfill(6), t)
        if not m:
            continue
        end = t.find('\n//----- (', m.end())
        end = len(t) if end < 0 else end
        body = t[m.end():end]
        # the port may name the callee (ServiceAudioTick_FE8BE for sub_FE8BE)
        cpat = r'\b(?:%s|\w+_%s)(?:_131)?\s*\(' % (re.escape(callee), callee[4:]) if callee.startswith('sub_') else \
            r'\b%s\s*\(' % re.escape(callee.rstrip('_'))
        # a call of X wired earlier (Hook150_* with the marker of a site that called X) still counts
        xsites = [s for s, r in rows.items() if r[1] == func and r[2].split()[1:2] == [callee]]
        hpat = r'\bHook150_\w+\s*\((?=[^\n]*1\.50 (?:%s)\b)' % '|'.join(xsites)
        calls = sorted(list(re.finditer(cpat, body)) + list(re.finditer(hpat, body)), key=lambda c: c.start())
        calls = [c for c in calls
                 if not body[:c.start()].rstrip().endswith('//')]
        calls = [c for c in calls if not re.match(r'.*//[^\n]*$', body[body.rfind('\n', 0, c.start()) + 1:c.start()])]
        if len(calls) != len(order):
            print('%s: %s calls %s %d times in asm, %d in C - by hand' % (site, func, callee, len(order), len(calls)))
            done = True
            break
        c = calls[ordinal]
        if '1.50 %s' % site in body:
            print('%s: already wired' % site)
            done = True
            break
        a = m.end() + c.start()
        eol = t.find('\n', a)
        line = t[t.rfind('\n', 0, a) + 1:eol]
        t = t[:a] + hook + '(' + t[m.end() + c.end():eol] + ('   /* 1.50 %s */' % site if '/*' not in line else '') + t[eol:]
        if '/*' in line:   # keep one comment: put the marker into it
            ls = t.rfind('\n', 0, a) + 1
            le = t.find('\n', a)
            t = t[:ls] + t[ls:le].replace('/*', '/* 1.50 %s;' % site, 1) + t[le:]
        print('%s: %s #%d of %d in %s (%s)' % (site, callee, ordinal + 1, len(order), func, p.split('\\')[-1]))
        if not dry:
            b = t.encode('latin-1')
            open(p, 'wb').write(b.replace(b'\n', b'\r\n') if crlf else b)
        done = True
        break
    if not done:
        print('%s: function %s not found in the port' % (site, func))
