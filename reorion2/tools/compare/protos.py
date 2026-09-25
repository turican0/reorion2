"""Register assignment of every function's parameters, from the prototypes
Hex-Rays wrote into Orion2.exe.c:

    // void __usercall sub_E36DF(char *a1@<eax>, int a2@<edi>);
    char __fastcall sub_D896F(int a1, __int16 *a2);      (watcall: eax, edx, ebx, ecx)

    params(name) -> [(param_name, register or None for a stack argument)]
    reg_of(name, param) -> register or None

Registers are the 32-bit names (eax, edx, ...); `@<bx>` counts as ebx.
"""
import re

SRC = 'C:/prenos/reorion2Data/diss/Orion2.exe.c'
WATCALL = ['eax', 'edx', 'ebx', 'ecx']
FULL = {'ax': 'eax', 'al': 'eax', 'ah': 'eax', 'dx': 'edx', 'dl': 'edx', 'dh': 'edx', 'bx': 'ebx', 'bl': 'ebx',
        'bh': 'ebx', 'cx': 'ecx', 'cl': 'ecx', 'ch': 'ecx', 'si': 'esi', 'di': 'edi', 'bp': 'ebp'}

_map = None


def _split(args):
    out, cur, d = [], '', 0
    for ch in args:
        if ch == '(':
            d += 1
        elif ch == ')':
            d -= 1
        if ch == ',' and d == 0:
            out.append(cur.strip())
            cur = ''
        else:
            cur += ch
    if cur.strip():
        out.append(cur.strip())
    return out


def _load():
    global _map
    if _map is not None:
        return _map
    _map = {}
    pat = re.compile(r'^(?://\s*)?[\w\s\*]*?\b(__usercall|__fastcall|__cdecl|__stdcall|__watcall|__userpurge)\s+'
                     r'(sub_[0-9A-F]+)(?:@<\w+>)?\((.*)\);?\s*$')
    for line in open(SRC, encoding='latin-1'):
        m = pat.match(line.strip())
        if not m or m.group(2) in _map:
            continue
        conv, name, args = m.group(1), m.group(2), m.group(3)
        ps = [] if args.strip() in ('', 'void') else _split(args)
        out = []
        for i, a in enumerate(ps):
            if a == '...':
                break
            rm = re.search(r'@<(\w+)>', a)
            nm = re.findall(r'(\w+)\s*(?:@<\w+>)?\s*$', a)
            pname = nm[0] if nm else 'a%d' % (i + 1)
            if rm:
                r = FULL.get(rm.group(1), rm.group(1))
            elif conv in ('__fastcall', '__watcall') and i < 4:
                r = WATCALL[i]
            else:
                r = None
            out.append((pname, r))
        _map[name] = out
    return _map


def params(name):
    return _load().get(name)


def reg_of(name, param):
    for p, r in params(name) or []:
        if p == param:
            return r
    return None


def param_of(name, reg):
    for p, r in params(name) or []:
        if r == reg:
            return p
    return None


if __name__ == '__main__':
    import sys
    for n in sys.argv[1:]:
        print(n, params(n))
