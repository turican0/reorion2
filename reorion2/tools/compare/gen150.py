"""Wave 185: the 1.50 patch block (ORION150.EXE, appended "binary extension") as C for the port.

Input   C:/prenos/reorion2Data/diss150_ida91/ORION150.full.c    Hex-Rays 9.1 output of the database built by
        .../ORION150.full.lst                                     run_ida91.ps1 (block at 0x1E0000, relocated)
        .../ext/ext150.bin, .../ORION150.EXE                      block image and its relocation table
Output  src/game150/orion150.h            macros of the block data (eseg), of data kept in the block's code
                                           area (ecode) and of game data the port does not declare yet;
                                           prototypes of the block functions
        src/game150/orion150_eseg.c        eseg = block data 0x22A600..end, ecode = block code area image,
                                           pointer slot tables, InitEseg150()
        src/game150/orion150_code_NN.c     the patch functions (core + glue that does not call into Lua)
        src/game150/orion150_lua_pending.c stubs of the functions that call into Lua directly
Functions with a //----- (ADDR) marker in src/game150/orion150_manual.c (hand written) are not generated.
Regenerate: python tools/compare/gen150.py

GOAL (Tomas, 2026-10-22): the hook stubs of 1.50 (call/jmp patched into 1.31 code, stubs that jump back
into the middle of a game function, constants patched into game code via ccode) are a first step only.
They are to be rewritten cleanly later: the 1.50 behaviour as normal C functions called from the game
functions, config values as normal variables - no ccode, no stubs, no jumps back into game code.
"""
import glob, os, re, struct, collections

DISS = 'C:/prenos/reorion2Data/diss150_ida91/'
ROOT = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..'))
GAME = os.path.join(ROOT, 'src', 'game')
OUT = os.path.join(ROOT, 'src', 'game150')
BB = 0x1E0000                     # block base in the database
DATA = 0x22A600                   # block data start (code before it)
RANGES = [(0x1E0000, 0x203A2F), (0x21504F, 0x222A47), (0x22997F, 0x22A598)]   # patch core + glue
LUA = [(0x203A2F, 0x21504F), (0x222A47, 0x22997F), (0x22A598, 0x22A600)]
# Functions that call into Lua directly use its 32-bit internals (the glue and Lua were one GCC unit and
# the lua_* API got inlined): they get a stub in orion150_lua_pending.c until they are rewritten on the
# official Lua API (third_party/lua-5.3.2).


def in_ranges(a, rr):
    return any(lo <= a < hi for lo, hi in rr)


# ---------------------------------------------------------------- Hex-Rays text cleanup (as split.py)
INT_SUBS = [(re.compile(p), r) for p, r in [
    (r'\bunsigned\s+__int64\b', 'uint64_t'), (r'\bunsigned\s+__int32\b', 'uint32_t'),
    (r'\bunsigned\s+__int16\b', 'uint16_t'), (r'\bunsigned\s+__int8\b', 'uint8_t'),
    (r'\bsigned\s+__int64\b', 'int64_t'), (r'\bsigned\s+__int32\b', 'int32_t'),
    (r'\bsigned\s+__int16\b', 'int16_t'), (r'\bsigned\s+__int8\b', 'int8_t'),
    (r'\b__int64\b', 'int64_t'), (r'\b__int32\b', 'int32_t'), (r'\b__int16\b', 'int16_t'),
    (r'\b__int8\b', 'int8_t')]]
MSVC = {'__readgsbyte': 'hr_readgsbyte', '__readgsword': 'hr_readgsword', '__writegsbyte': 'hr_writegsbyte',
        '__writegsword': 'hr_writegsword', '__writegsdword': 'hr_writegsdword', '__addgsword': 'hr_addgsword',
        '__inbyte': 'hr_inbyte', '__outbyte': 'hr_outbyte', '__readeflags': 'hr_readeflags',
        '__writeeflags': 'hr_writeeflags', '__getcallerseflags': 'hr_getcallerseflags',
        '__debugbreak': 'hr_debugbreak', '__int128': 'hr_int128_t'}
MSVC_RE = re.compile(r'\b(' + '|'.join(re.escape(k) for k in MSVC) + r')\b')
HEX_ESC = re.compile(r'\\x([0-9A-Fa-f]{2})(?=[0-9A-Fa-f])')


def clean(text):
    text = re.sub(r'@<[A-Za-z0-9_:]+>', '', text)
    text = re.sub(r'__spoils<[^>]*>\s*', '', text)
    text = re.sub(r'\b(__fastcall|__cdecl|__stdcall|__usercall|__userpurge|__thiscall|__noreturn|__hidden|__return_ptr|__struct_ptr)\b\s*', '', text)
    text = re.sub(r'\bconst\b\s*', '', text)
    for p, r in INT_SUBS:
        text = p.sub(r, text)
    text = MSVC_RE.sub(lambda m: MSVC[m.group(1)], text)
    out, i = [], 0
    while i < len(text):             # "\x1B0" in a literal: split after two hex digits
        if text[i] == '"':
            j = i + 1
            while j < len(text) and text[j] != '"':
                j += 2 if text[j] == '\\' else 1
            out.append(HEX_ESC.sub(r'\\x\1""', text[i:j + 1]))
            i = j + 1
        elif text[i] == "'":
            j = i + 1
            while j < len(text) and text[j] != "'":
                j += 2 if text[j] == '\\' else 1
            out.append(text[i:j + 1])
            i = j + 1
        else:
            out.append(text[i])
            i += 1
    return ''.join(out)


def split_args(s):
    out, depth, buf, q = [], 0, '', None
    for c in s:
        if q:
            buf += c
            if c == q:
                q = None
            continue
        if c in '"\'':
            q = c
        elif c in '([{':
            depth += 1
        elif c in ')]}':
            depth -= 1
        if c == ',' and depth == 0:
            out.append(buf)
            buf = ''
        else:
            buf += c
    if buf.strip():
        out.append(buf)
    return out


# ---------------------------------------------------------------- input
# ORION150.full_w.c: the same database with Watcom register prototypes of the called game functions
# (tools/compare/watcom150.py); without it Hex-Rays loses register arguments and results of those calls
_src = 'ORION150.full_w.c' if os.path.exists(DISS + 'ORION150.full_w.c') else 'ORION150.full.c'
full = open(DISS + _src, encoding='latin1').read()
d0, d1 = full.index('// Function declarations'), full.index('// Data declarations')
f0 = full.index('//----- (')
fdecl, ddecl, impl = full[d0:d1], full[d1:f0], full[f0:]

# symbol addresses from the listing: name -> address, and which names are code (procs / labels)
symaddr, code_syms = {}, set()
for l in open(DISS + 'ORION150.full.lst', encoding='latin1'):
    m = re.match(r'^(?:ext150|dseg02|cseg01):([0-9A-F]{8}) (\w+)\s+(proc|d[bwdq]|dt|struc|=)\b', l)
    if m and m.group(3) != '=':
        symaddr.setdefault(m.group(2), int(m.group(1), 16))
        if m.group(3) == 'proc':
            code_syms.add(m.group(2))
        continue
    m = re.match(r'^(?:ext150|dseg02|cseg01):([0-9A-F]{8}) (\w+):', l)
    if m:
        symaddr.setdefault(m.group(2), int(m.group(1), 16))
        code_syms.add(m.group(2))

# data declarations: name -> C declaration (without initializer)
datadecl = {}
for st in re.split(r';[ \t]*(?://[^\n]*)?\n', ddecl):
    st = '\n'.join(l for l in st.split('\n') if not l.strip().startswith('//')).strip()
    if not st:
        continue
    depth, cut = 0, len(st)
    for i, c in enumerate(st):
        if c in '([{':
            depth += 1
        elif c in ')]}':
            depth -= 1
        elif c == '=' and depth == 0:
            cut = i
            break
    st = st[:cut].strip()
    m = re.search(r'\b([A-Za-z_]\w*)\s*((?:\[[^\]]*\])*)\s*$', st)
    if m and '(' not in st:
        datadecl[m.group(1)] = clean(st)
# pointers to functions kept in data ("int (*off_X)()", "int (*funcs_X[5])()"): name -> slot count (0 = one)
fptrdecl = {}
for m in re.finditer(r'(?m)^(?!//)[^;\n]*?\(\*\s*([A-Za-z_]\w*)\s*(?:\[(\d+)\])?\)\s*\([^;\n]*\)\s*(?:=[^;\n]*)?;', ddecl):
    fptrdecl[m.group(1)] = int(m.group(2) or 0)

# functions of the block
chunks = re.split(r'(?m)^(?=//----- \([0-9A-F]{8}\) )', impl)
funcs = []
for c in chunks:
    m = re.match(r'//----- \(([0-9A-F]{8})\)', c)
    if m and in_ranges(int(m.group(1), 16), RANGES):
        funcs.append((int(m.group(1), 16), c))

# port: address -> function name (renamed ones like ServiceAudioTick_FE8BE included)
portname = {}
for p in glob.glob(os.path.join(GAME, 'orion_part_*.c')):
    lines = open(p, encoding='latin1').read().split('\n')
    for i, l in enumerate(lines):
        m = re.match(r'^//----- \(([0-9A-F]{8})\)', l)
        if m:
            for k in range(i + 1, min(i + 40, len(lines))):
                d = re.match(r'^[A-Za-z_][\w \*]*?\b(\w+)\s*\([^;]*$', lines[k])
                if d and not lines[k].startswith(('//', '/*', '#', ' ', '\t')):
                    portname[int(m.group(1), 16)] = d.group(1)
                    break
# link_stubs.c defines some game functions without a //----- marker
for m in re.finditer(r'(?m)^[A-Za-z_][\w \*]*?\b(sub_([0-9A-F]{5,6}))\s*\([^;{]*\)\s*\{', open(os.path.join(GAME, 'link_stubs.c'), encoding='latin1').read()):
    portname.setdefault(int(m.group(2), 16), m.group(1))
dseg_h = open(os.path.join(GAME, 'orion_dseg.h'), encoding='latin1').read()
dseg_names = set(re.findall(r'^#define (\w+) ', dseg_h, re.M))
common = open(os.path.join(GAME, 'orion_common.h'), encoding='latin1').read()
common_names = set(re.findall(r'\b(\w+)\s*\(', common)) | set(re.findall(r'\bextern\b[^;\n]*?\b(\w+)\s*(?:\[[^\]]*\])?\s*;', common))
# full prototypes of the port (a call with another argument count does not compile)
nparams = {}
for m in re.finditer(r'(?m)^(?!//)(?!extern\b)[A-Za-z_][\w \*]*?\b(\w+)\s*\(([^;()]*(?:\([^()]*\)[^;()]*)*)\)\s*;', common):
    ps = [x for x in split_args(m.group(2)) if x.strip() and x.strip() != 'void']
    if m.group(2).strip() and '...' not in m.group(2):
        nparams[m.group(1)] = len(ps)

manual = set()
mp = os.path.join(OUT, 'orion150_manual.c')
if os.path.exists(mp):
    manual = set(int(x, 16) for x in re.findall(r'^//----- \(([0-9A-F]{8})\)', open(mp, encoding='latin1').read(), re.M))

# ---------------------------------------------------------------- code
own = {}                          # block function name -> address
def own_name(c):
    """name and parameter count of a Hex-Rays definition (header found on the cleaned text)"""
    t = clean(c)
    m = re.search(r'(?m)^[^/\n][^\n]*?\b(sub_[0-9A-F]+|nullsub_\d+)\s*\(', t)
    if not m:
        return None, None
    depth, j = 1, m.end()
    while j < len(t) and depth:
        depth += {'(': 1, ')': -1}.get(t[j], 0)
        j += 1
    ps = [x for x in split_args(t[m.end():j - 1]) if x.strip() and x.strip() != 'void']
    return m.group(1), len(ps)


variadic = set()
for a, c in funcs:
    n, k = own_name(c)
    if n:
        own[n] = a
        if re.search(r'\b%s\s*\([^)]*\.\.\.\)' % n, clean(c)):
            variadic.add(n)      # (a1, a2, ...): calls keep all their arguments
        else:
            nparams[n] = k
stats = collections.Counter()
used = set()


# game functions the port wraps for the 1.50 hooks (X -> wrapper, body X_131): the block calls the bodies,
# as in ORION150.EXE its own calls bypass the hooked call sites
wrapped131 = set(re.findall(r'\b(\w+)_131\s*\(', open(os.path.join(GAME, '..', 'game150', 'orion150_hooks.h'),
                                                      encoding='latin1').read()))
for _m in re.finditer(r'\b(\w+_131)\s*\(([^;]*)\)\s*;', open(os.path.join(GAME, '..', 'game150', 'orion150_hooks.h'),
                                                            encoding='latin1').read()):
    nparams[_m.group(1)] = len([x for x in split_args(_m.group(2)) if x.strip() and x.strip() != 'void'])


def rename_calls(text):
    def fn(m):
        n = m.group(1)
        a = int(n[4:], 16)
        if a < BB and a in portname:
            return portname[a] + ('_131(' if portname[a] in wrapped131 else '(')
        if a < BB:
            stats['game function not in port: ' + n] += 1
        return n + '('
    # loc_: game code labels IDA did not make functions (called by the block like functions)
    text = re.sub(r'\bloc_([0-9A-F]{5,6})\s*\(', lambda m: ('sub_' + m.group(1) + '(') if int(m.group(1), 16) in portname else m.group(0), text)
    return re.sub(r'\b(sub_[0-9A-F]{5,6})\s*\(', fn, text)


def fit_args(text):
    """calls to functions with a known parameter count: extra arguments dropped, missing ones = 0"""
    out, i = [], 0
    rx = re.compile(r'\b(\w+)\s*\(')
    while True:
        m = rx.search(text, i)
        if not m:
            out.append(text[i:])
            break
        name = m.group(1)
        if name not in nparams:
            out.append(text[i:m.end()])
            i = m.end()
            continue
        # skip definitions / declarations: "name(" at line start after a type
        line_start = text.rfind('\n', 0, m.start()) + 1
        if re.match(r'^[A-Za-z_][\w \*]*\b' + name + r'\s*\(', text[line_start:m.end()]) and not \
                re.search(r'[=(,]|return\b', text[line_start:m.start()]):
            out.append(text[i:m.end()])
            i = m.end()
            continue
        depth, j = 1, m.end()
        while j < len(text) and depth:
            if text[j] == '(':
                depth += 1
            elif text[j] == ')':
                depth -= 1
            j += 1
        args = split_args(text[m.end():j - 1])
        n = nparams[name]
        if len(args) > n:
            stats['args dropped'] += 1
            args = args[:n]
        elif len(args) < n:
            stats['args padded'] += 1
            args = args + [' 0'] * (n - len(args))
        out.append(text[i:m.end()] + ','.join(a if k == 0 else a for k, a in enumerate(args)).strip() + ')')
        i = j
    return ''.join(out)


PROMOTE = {'int16_t': 'int', 'uint16_t': 'unsigned int', 'int8_t': 'int', 'uint8_t': 'unsigned int',
           'char': 'int', 'unsigned char': 'unsigned int', '_BOOL1': 'int', '_BOOL2': 'int', '_WORD': 'unsigned int',
           '_BYTE': 'unsigned int', 'bool': 'int'}
own_ret, own_full = {}, {}


def func_header(t):
    """(start, end, return type, name, params text) of the definition header (up to and with '\\n{\\n')"""
    b = t.find('\n{\n')
    if b < 0:
        return None
    # the header may span several lines (one parameter per line): back to the line with the name
    k = t.rfind('\n', 0, b)
    while k > 0 and t[k + 1:k + 3] == '  ':
        k = t.rfind('\n', 0, k)
    s = k + 1
    head = t[s:b]
    m = re.match(r'^(.*?)\b(sub_[0-9A-F]+|nullsub_\d+)\s*\((.*)\)\s*$', head, re.S)
    if not m:
        return None
    return s, b + 3, m.group(1).strip() or 'int', m.group(2), m.group(3)


def promote(t):
    """K&R prototypes (RET name();) need promoted parameters: int16_t a2 -> int a2 + 'a2 = (int16_t)a2;'
    at the top of the body (the original reads only the narrow part). Also records the return type."""
    fh = func_header(t)
    if not fh:
        return t
    hs, he, ret, name, ptext = fh
    own_ret[name] = ret
    if '(' in ret:      # returns a function pointer: the prototype needs the whole declarator
        own_full[name] = t[hs:he - 3].strip()

    class M:
        pass
    m = M()
    m.start, m.end = (lambda: hs), (lambda: he)
    m.group = lambda i: {1: ret + ' ', 2: name, 3: ptext}[i]
    params, casts = [], []
    for p in split_args(m.group(3)):
        q = p.strip()
        pm = re.match(r'^(.*?)\s*\b([A-Za-z_]\w*)$', q)
        if pm and '*' not in q and pm.group(1) in PROMOTE:
            params.append(PROMOTE[pm.group(1)] + ' ' + pm.group(2))
            casts.append('  %s = (%s)%s;\n' % (pm.group(2), 'uint8_t' if pm.group(1) in ('_BOOL1', 'bool') else pm.group(1), pm.group(2)))
        else:
            params.append(q)
    head = m.group(1) + m.group(2) + '(' + ', '.join(params) + ')\n{\n'
    body = t[m.end():]
    if casts:      # after the local declarations at the top of the body
        k = 0
        for line in body.split('\n'):
            if re.match(r'^  [A-Za-z_][\w \*]*?\b[A-Za-z_]\w*(\[[^\]]*\])*;( *//.*)?$', line):
                k += len(line) + 1
            elif line.strip() == '' and k:
                k += len(line) + 1
                break
            else:
                break
        body = body[:k] + ''.join(casts) + body[k:]
    return t[:m.start()] + head + body


# fopen (Watcom: eax = name, edx = mode) lost its mode in Hex-Rays: take edx from the listing, per call order
lst_lines = open(DISS + 'ORION150.full.lst', encoding='latin1').read().split('\n')
lst_func = {}
cur = None
for l in lst_lines:
    m = re.match(r'^ext150:([0-9A-F]{8}) (\w+)\s+proc\b', l)
    if m:
        cur = int(m.group(1), 16)
        lst_func[cur] = []
        continue
    if cur is not None:
        if re.search(r'\sendp\b', l):
            cur = None
        else:
            lst_func[cur].append(l)


def fix_crt(a, t):
    modes = []
    body = lst_func.get(a, [])
    for i, l in enumerate(body):
        if re.search(r'\scall\s+fopen_\b', l):
            mode = None
            for b in range(i - 1, max(0, i - 12), -1):
                mm = re.search(r'\smov\s+edx,\s*(?:offset\s+)?([0-9A-F]+h|\w+)', body[b])
                if mm:
                    mode = mm.group(1)
                    break
            modes.append(mode)
    k = [0]

    def fo(m):
        i = k[0]
        k[0] += 1
        mode = modes[i] if i < len(modes) else None
        if mode and mode.endswith('h') and re.match(r'^[0-9A-F]+h$', mode):
            v = int(mode[:-1], 16)
            if DATA <= v < BB + len(open(DISS + 'ext/ext150.bin', 'rb').read()):
                return 'fopen(%s, (char *)(eseg + 0x%X))' % (m.group(1), v - DATA)
        if mode and mode in symaddr:
            return 'fopen(%s, (char *)&%s)' % (m.group(1), mode)
        stats['fopen mode not found'] += 1
        return m.group(0)
    t = re.sub(r'\bfopen\(([^(),]*(?:\([^()]*\)[^(),]*)*)\)', fo, t)
    t = re.sub(r'\bftell\(([^(),]+),[^()]*\)', r'ftell(\1)', t)
    return t


# port functions returning void used as a value: "return f(..);" -> "f(..); return 0;"
port_void = set(re.findall(r'(?m)^(?:extern\s+)?void\s+(\w+)\s*\(', common)) | \
    set(re.findall(r'(?m)^void\s+(\w+_131)\s*\(', open(os.path.join(GAME, '..', 'game150', 'orion150_hooks.h'),
                                                       encoding='latin1').read()))


def fix_void_return(t):
    def rv(m):
        if m.group(2) in port_void:
            return '%s%s(%s); return 0;' % (m.group(1), m.group(2), m.group(3))
        return m.group(0)
    return re.sub(r'(?m)^(\s*)return (\w+)\((.*)\);$', rv, t)


# game functions the block calls that the port never needed: generated from the same Hex-Rays output
full_chunks = {}
for c in chunks:
    m = re.match(r'//----- \(([0-9A-F]{8})\)', c)
    if m:
        full_chunks[int(m.group(1), 16)] = c
todo = [a for a, c in funcs]
extra = []
while todo:
    a = todo.pop()
    c = full_chunks.get(a, '')
    for n in re.findall(r'\bsub_([0-9A-F]{5,6})\s*\(', c):
        x = int(n, 16)
        if x < BB and x not in portname and x in full_chunks and x not in extra:
            extra.append(x)
            todo.append(x)
for x in sorted(extra):
    funcs.append((x, full_chunks[x]))
    n, k = own_name(full_chunks[x])
    if n:
        own[n] = x
        nparams[n] = k
# absolute addresses the block's code gets from its relocations: Hex-Rays prints most of them as plain
# numbers ("4 * i + 2353214"); in the port they become expressions on eseg / ecode / dseg / ccode
_img_len = len(open(DISS + 'ext/ext150.bin', 'rb').read())
_exe = open(DISS + 'ORION150.EXE', 'rb').read()
_size, _rs, _cs = struct.unpack_from('<III', _exe, 0x285B6A)
_blk = _exe[0x285B6A + 12:0x285B6A + 12 + _size]
reloc_vals = {}
for _r in range(_rs, _cs, 11):
    _typ, _sb, _tb, _so, _add = struct.unpack_from('<BBBII', _blk, _r)
    if _typ or _sb != 0 or BB + _so >= DATA:
        continue
    if _tb == 0:
        v = BB + _add
        reloc_vals[v] = '((int)(intptr_t)(eseg + 0x%X))' % (v - DATA) if v >= DATA else \
            '((int)(intptr_t)(ecode + 0x%X))' % (v - BB)
    elif _tb == 1:
        v = 0x178000 + _add
        reloc_vals[v] = '((int)(intptr_t)(dseg + 0x%X))' % _add
    else:
        v = 0x10000 + _add
        reloc_vals[v] = '((int)(intptr_t)(ccode + 0x%X))' % _add


# arrays (game data in dseg, block data in eseg): Hex-Rays writes "arr + 188" for a BYTE offset (the
# array name stands for its address as an integer; element addresses are always "&arr[i]")
array_names = set(re.findall(r'(?m)^#define (\w+) \(\*\([^()]*\(\*\)\[', dseg_h))
for _n, _d in datadecl.items():
    if re.search(r'\]\s*$', _d):
        array_names.add(_n)
array_names = {n for n in array_names if not re.match(r'^[av]\d+$', n)}


def data_type(n):
    """(type, array suffix) of a data symbol from its Hex-Rays declaration"""
    decl = datadecl.get(n)
    dm = re.match(r'^(.*?)\b' + re.escape(n) + r'\s*((?:\[[^\]]*\])*)\s*$', decl) if decl else None
    if not dm:
        return None, ''
    return re.sub(r'\b(extern|static)\b\s*', '', dm.group(1)).strip(), dm.group(2)


# data pointers of the block (and of the game data the port does not name): 32-bit slots
ptr_globals, ptr_garrays = {}, {}
for _n in datadecl:
    if _n in dseg_names or _n in common_names or re.match(r'^[av]\d+$', _n):
        continue
    _t, _a = data_type(_n)
    if not _t or not _t.endswith('*'):
        continue
    if not _a:
        ptr_globals[_n] = _t
    elif re.match(r'^\[\d+\]$', _a):
        _b = _t[:-1].strip()
        ptr_garrays[_n] = (_b.rstrip(' *'), 2 + _b.count('*'))


def fix_gptr(t):
    """data pointers and function pointers live in 32-bit slots: their macros are uint32_t lvalues"""
    fh = func_header(t)
    if not fh:
        return t
    head, code = t[:fh[1]], t[fh[1]:]
    for n, typ in ptr_globals.items():
        if n in code and re.search(r'\b%s\b' % n, code):
            code = slot_uses(code, n, typ, n, '(&%s)' % n)
            stats['ptr32 global uses'] += 1
    for n in fptrdecl:
        if n in code:
            # calls through the slot (fix_values made them "((int (*)())n)(")
            code = re.sub(r'\(\(int \(\*\)\(\)\)%s\)\(' % n, '((int (*)())(uintptr_t)%s)(' % n, code)
            code = re.sub(r'(?<![\w(])\b%s\[([^\[\]]+)\]\s*\(' % n, r'((int (*)())(uintptr_t)%s[\1])(' % n, code)
    return head + code


def fix_array_arith(t):
    def ar(m):
        stats['array address arithmetic'] += 1
        return '((int)(intptr_t)%s)' % m.group(2)
    names = [n for n in set(re.findall(r'\b([A-Za-z_]\w*)\b', t)) if n in array_names]
    for n in names:
        # "n + x", "n - x", "x + n", "x - n": not "&n", not "n[", not a declaration
        t = re.sub(r'(?<![&\w.])()(%s)(?=\s*[-+]\s*[^=+\-])' % n, ar, t)
        t = re.sub(r'(?<=[-+]\s)()(%s)\b(?!\s*\[)' % n, ar, t)
    return t


def fix_addr_literals(t):
    def lit(m):
        s = m.group(0)
        v = int(s[:-1] if s.endswith(('u', 'U')) else s, 0) if not s.startswith('0x') else int(s.rstrip('uU'), 16)
        if v in reloc_vals:
            stats['address literals'] += 1
            return reloc_vals[v]
        return s
    out = []
    for line in t.split('\n'):
        if line.lstrip().startswith('//'):
            out.append(line)
            continue
        line = re.sub(r'(?<![\w.])(?:0x[0-9A-Fa-f]{5,8}|\d{6,8})[uU]?\b', lit, line)
        # game code addresses below 100000 only where they are added to an index ("(i + 76937)")
        out.append(re.sub(r'(?<=\+ )\d{5}(?=\))', lit, line))
    return '\n'.join(out)


# port globals declared as pointers: Hex-Rays does integer arithmetic on them
port_ptrs = set(re.findall(r'(?m)^extern\s+[\w ]+?\*+\s*(\w+)\s*;', common))


def fix_values(t):
    # a game function the port does not have, used as an address: the block patches its code -> ccode
    def ga(m):
        a = int(m.group(2), 16)
        # "(_BYTE *)sub_93D4B + 2": a code byte the block patches, even where the port has the function
        data_cast = re.search(r'\((?:const )?(?:_BYTE|_WORD|_DWORD|char|int|__int16|unsigned \w+|u?int\d+_t|void) \*\)\s*&?$',
                              m.string[max(0, m.start() - 24):m.start()])
        if a < BB and m.group(1) not in own and (a not in portname or data_cast):
            return '((_BYTE *)ccode + 0x%X)' % (a - 0x10000)
        if BB <= a < DATA and m.group(1) not in own:     # block code without a function: data there
            return '((_BYTE *)ecode + 0x%X)' % (a - BB)
        return m.group(0)
    t = re.sub(r'\b(sub_([0-9A-F]{5,6}))\b(?!\s*\()', ga, t)
    # call through a pointer kept in data
    t = re.sub(r'(?<![\w)])\b((?:off|dword|funcs)_[0-9A-F]{5,6})\s*\(', r'((int (*)())\1)(', t)
    # integer arithmetic on port pointer globals
    for n in port_ptrs:
        if n in t:
            t = re.sub(r'\b' + n + r'\b(?!\s*=[^=])', '((int)(intptr_t)%s)' % n, t)
    # value of a port function returning void
    def va(m):
        if m.group(3) in port_void:
            return '%s%s(%s);\n%s%s = 0;' % (m.group(1), m.group(3), m.group(4), m.group(1), m.group(2))
        return m.group(0)
    t = re.sub(r'(?m)^(\s*)([^\n=;]+?)\s*=\s*(\w+)\((.*)\);$', va, t)
    return t


# "functions" Hex-Rays made of bytes the block uses as data (written through *(T *)sub_X): no code
alltext = ''.join(c for a, c in funcs)
data_like = set()
for n in set(re.findall(r'\*\s*\(\s*_?[A-Za-z]\w*\s*\*\s*\)\s*&?(sub_[0-9A-F]{6})\b', alltext)):
    if n in own and BB <= own[n] < DATA:
        data_like.add(own[n])
        del own[n]
funcs = [(a, c) for a, c in funcs if a not in data_like]
asm_pending = []


def fix_asm(a, t):
    """inline DOS calls Hex-Rays left as __asm: an explicit marker call + asm_pending.txt"""
    def rp(m):
        asm_pending.append('%06X %s' % (a, m.group(1).strip()))
        return 'Dos150_AsmPending(0x%X);   /* %s - registers not wired yet (asm_pending.txt) */' % (a, m.group(1).strip())
    return re.sub(r'__asm \{ ([^}]*) \}', rp, t)


# Every pointer the block keeps in memory is a 32-bit slot (LARGEADDRESSAWARE:NO keeps the port's addresses
# below 2 GB). Hex-Rays types them as T ** and *(T **)(addr): on x64 those read 8 bytes and step by 8.
# Casts become 32-bit slot reads/writes, T ** variables become uint32_t * with converting uses.
PP_CAST = re.compile(r'\*\(((?:const |unsigned |signed )*[A-Za-z_]\w*) (\*{2,})\)\s*')
STMT_START = r'(^|[;{}(,:]|\belse|\bdo)\s*$'      # an assignment that begins a statement
BYTE_MACRO = r'\b(?:S?(?:LO|HI)BYTE|BYTE\d|(?:LO|HI)WORD|WORD\d|S?HIDWORD|S?LODWORD)\(\s*$'
PP_FCAST = re.compile(r'(\*+)\(((?:const |unsigned |signed )*[A-Za-z_]\w*(?: \*)?) \((\*{2,})\)(\([^()]*\))\)\s*')
PP_ARR = re.compile(r'(?m)^  ((?:const |unsigned |signed )*[A-Za-z_]\w*) (\*+)(\w+)(\[\d+\]);')
PP_DECL = re.compile(r'(?m)^  ((?:const |unsigned |signed )*[A-Za-z_]\w*) (\*{2,})(\w+);')
LOCAL_DECL = re.compile(r'^  (?!return\b)[A-Za-z_][^=;(]*(?:\(\*\w+(?:\[[^\]]*\])*\)\([^;=]*\))?(?:\[[^\]]*\])*;( *//.*)?$')


def pp_group(t, i):
    """end of the operand at t[i]: a parenthesised group or &name"""
    if i < len(t) and t[i] == '(':
        d = 0
        for k in range(i, len(t)):
            if t[k] == '(':
                d += 1
            elif t[k] == ')':
                d -= 1
                if d == 0:
                    return k + 1
    m = re.match(r'&?\w+', t[i:])
    if not m:
        return None
    e = i + m.end()
    while e < len(t) and t[e] == '[':      # &arr[k]: the cast takes the element address
        e = pp_close(t, e, '[', ']')
    return e


def pp_close(t, i, o, c):
    """index after the bracket that closes t[i] == o"""
    d = 0
    for k in range(i, len(t)):
        if t[k] == o:
            d += 1
        elif t[k] == c:
            d -= 1
            if d == 0:
                return k + 1
    return None


def pp_rhs_end(t, i):
    d = 0
    for k in range(i, len(t)):
        ch = t[k]
        if ch in '([{':
            d += 1
        elif ch in ')]}':
            if d == 0:
                return k
            d -= 1
        elif ch in ';,' and d == 0:
            return k
    return None


def pp_slot(typ, stars):
    """type of the value one slot holds: T * for T **, a slot array for T ***"""
    return typ + ' *' if stars == 2 else 'uint32_t *'


def pp_elem(typ, stars):
    return 'uint32_t' if stars > 2 else '_BYTE' if typ == 'void' else typ


def pp_assign(t, k):
    """('=', end) / ('+=', end) for an assignment at t[k], else None"""
    m = re.match(r'\s*(=|\+=|-=)(?!=)', t[k:])
    if not m:
        return None
    return m.group(1), k + m.end()


def fix_ptr32(t):
    # *(T **)(ADDR): right to left, so an outer operand already holds its rewritten inner accesses
    for m in reversed(list(PP_CAST.finditer(t))):
        a1 = pp_group(t, m.end())
        if a1 is None:
            stats['ptr32 cast left'] += 1
            continue
        addr, typ, stars = t[m.end():a1], m.group(1), len(m.group(2))
        # **(T **)A = R writes through the pointer the slot holds: the slot itself is only read
        asg = pp_assign(t, a1) if t[m.start() - 1:m.start()] != '*' else None
        if asg and asg[0] == '=':
            r1 = pp_rhs_end(t, asg[1])
            t = t[:m.start()] + '*(uint32_t *)%s = (uint32_t)(uintptr_t)(%s)' % (addr, t[asg[1]:r1].strip()) + t[r1:]
        elif asg:
            r1 = pp_rhs_end(t, asg[1])
            t = t[:m.start()] + '*(uint32_t *)%s %s (uint32_t)((%s) * sizeof(%s))' % (
                addr, asg[0], t[asg[1]:r1].strip(), pp_elem(typ, stars)) + t[r1:]
        else:
            t = t[:m.start()] + '((%s)(uintptr_t)*(uint32_t *)%s)' % (pp_slot(typ, stars), addr) + t[a1:]
        stats['ptr32 casts'] += 1
    # function pointer slots: *(R (**)(A))ADDR, **(R (***)(A))ADDR
    for m in reversed(list(PP_FCAST.finditer(t))):
        a1 = pp_group(t, m.end())
        derefs, stars = len(m.group(1)), len(m.group(3))
        if a1 is None or derefs > stars or pp_assign(t, a1):
            stats['ptr32 function slot left'] += 1
            continue
        v = t[m.end():a1]
        for i in range(derefs):
            v = '*(uint32_t *)(uintptr_t)(%s)' % v if i else '*(uint32_t *)%s' % v
        left = stars - derefs
        typ = '%s (%s)%s' % (m.group(2), '*' * left, m.group(4)) if left == 1 else 'uint32_t *' if left else None
        t = t[:m.start()] + ('((%s)(uintptr_t)%s)' % (typ, v) if typ else v) + t[a1:]
        stats['ptr32 function slots'] += 1
    t = re.sub(r'\((?:const |unsigned |signed )*[A-Za-z_]\w* ?\*? \(\*{2,}\)\([^()]*\)\)', '(uint32_t *)', t)
    fh = func_header(t)
    if not fh:
        return t
    hs, he, ret, name, ptext = fh
    vars_ = {}
    for pm in re.finditer(r'((?:const |unsigned |signed )*[A-Za-z_]\w*) (\*{2,})(a\d+)\b', ptext):
        vars_[pm.group(3)] = (pm.group(1), len(pm.group(2)))
    ptext = re.sub(r'(?:const |unsigned |signed )*[A-Za-z_]\w* \*{2,}(a\d+)\b', r'uint32_t *\1', ptext)
    body = t[he:]
    k = 0
    for line in body.split('\n'):
        if LOCAL_DECL.match(line):
            k += len(line) + 1
        else:
            break
    decls, code = body[:k], body[k:]
    for dm in PP_DECL.finditer(decls):
        vars_[dm.group(3)] = (dm.group(1), len(dm.group(2)))
    decls = PP_DECL.sub(r'  uint32_t *\3;', decls)
    # arrays of pointers on the stack (the callee walks 32-bit slots)
    for dm in PP_ARR.finditer(decls):
        vars_[dm.group(3)] = (dm.group(1), len(dm.group(2)) + 1)
    decls = PP_ARR.sub(r'  uint32_t \3\4;', decls)
    for n, ts in ptr_garrays.items():       # global arrays of pointers (uint32_t slots in orion150.h)
        if n in code and re.search(r'\b%s\b' % n, code):
            vars_[n] = ts
    # a pointer local whose address is handed on: the callee writes only its low 32 bits
    def zi(dm):
        if re.search(r'&%s\b(?!\s*\[)' % dm.group(2), code):
            stats['ptr32 address-taken local zeroed'] += 1
            return '  %s%s = 0;%s' % (dm.group(1), dm.group(2), dm.group(3))
        return dm.group(0)
    decls = re.sub(r'(?m)^  ((?:const |unsigned |signed )*[A-Za-z_]\w* \*)(\w+);(.*)$', zi, decls)
    for n, (typ, stars) in vars_.items():
        slot = pp_slot(typ, stars)
        for m in reversed(list(re.finditer(r'(\*\*|\*|&)?\b%s\b' % n, code))):
            pre, e = m.group(1) or '', m.end()
            rest = code[e:]
            if rest.lstrip().startswith('['):
                b0 = e + len(rest) - len(rest.lstrip())
                b1 = pp_close(code, b0, '[', ']')
                # &v[i][j]: the address of an element behind the slot - the slot itself is only read
                if b1 is None or (pre == '&' and not code[b1:].lstrip().startswith('[')):
                    continue
                acc = code[m.start() + len(pre):b1]
                asg = pp_assign(code, b1)
                if not pre and re.search(BYTE_MACRO, code[:m.start()][-12:]):
                    continue     # BYTE1(v[2]) = 1: bits of the slot itself
                if asg and asg[0] == '=' and not pre:
                    r1 = pp_rhs_end(code, asg[1])
                    new, end = '%s = (uint32_t)(uintptr_t)(%s)' % (acc, code[asg[1]:r1].strip()), r1
                elif asg and not pre:
                    stats['ptr32 var compound left'] += 1
                    continue
                else:
                    new, end = '%s((%s)(uintptr_t)%s)' % (pre, slot, acc), b1
            elif pre == '**':
                new, end = '*((%s)(uintptr_t)*%s)' % (slot, n), e
            elif pre == '*':
                inc = re.match(r'(\+\+|--)', rest)
                asg = pp_assign(code, e)
                if inc:
                    new, end = '((%s)(uintptr_t)*%s%s)' % (slot, n, inc.group(1)), e + 2
                elif asg and asg[0] == '=':
                    r1 = pp_rhs_end(code, asg[1])
                    new, end = '*%s = (uint32_t)(uintptr_t)(%s)' % (n, code[asg[1]:r1].strip()), r1
                elif asg:
                    stats['ptr32 var compound left'] += 1
                    continue
                else:
                    new, end = '((%s)(uintptr_t)*%s)' % (slot, n), e
            elif pre == '&':
                stats['ptr32 var address taken'] += 1
                continue
            else:
                asg = pp_assign(code, e)
                if not asg or asg[0] != '=' or not re.search(STMT_START, code[:m.start()][-40:]):
                    continue
                r1 = pp_rhs_end(code, asg[1])
                new, end = '%s = (uint32_t *)(%s)' % (n, code[asg[1]:r1].strip()), r1
            code = code[:m.start()] + new + code[end:]
            stats['ptr32 var uses'] += 1
    # remaining casts to T ** (values handed on): slot arrays
    code = re.sub(r'\((?:const |unsigned |signed )*[A-Za-z_]\w* \*{2,}\)', '(uint32_t *)', code)
    return t[:hs] + t[hs:he].replace(fh[4], ptext, 1) + decls + code


# Locals whose address is handed on (Hex-Rays BYREF) are often one structure on the 32-bit stack that
# Hex-Rays split into variables (sub_1FB173: v11 +0, v12 +4, v13[4] +8). On x64 the compiler places them
# freely and pointers take 8 bytes: from the lowest BYREF local up they live in a byte array with the
# original offsets (frame150), pointers as 32-bit slots.
FRAME_DECL = re.compile(r'^  ([^=;/]*?)\b(\w+)((?:\[[^\]]*\])*)(?: = 0)?; // (.*)$')
SIZE32 = {'char': 1, '_BYTE': 1, 'uint8_t': 1, 'int8_t': 1, '_BOOL1': 1, 'bool': 1, '__int8': 1, 'unsigned __int8': 1,
          'int16_t': 2, 'uint16_t': 2, '_WORD': 2, '__int16': 2, 'unsigned __int16': 2,
          'int': 4, '_DWORD': 4, 'unsigned int': 4, 'signed int': 4, 'uint32_t': 4, 'int32_t': 4, 'float': 4, '_BOOL4': 4,
          '_QWORD': 8, '__int64': 8, 'unsigned __int64': 8, 'int64_t': 8, 'uint64_t': 8, 'double': 8}


def slot_uses(code, n, typ, slot, addr):
    """uses of n, a pointer of type typ kept in the 32-bit slot `slot` (an lvalue uint32_t, &n == addr):
    reads widen the slot, writes and pointer arithmetic store 32 bits"""
    pt = typ[:-1].strip()
    sz = '1' if pt in ('void', 'const void', '_UNKNOWN') else 'sizeof(%s)' % pt
    for m in reversed(list(re.finditer(r'(?<![.>\w])(&|\+\+|--)?\b%s\b' % n, code))):
        pre, e = m.group(1) or '', m.end()
        rest = code[e:]
        post = re.match(r'(\+\+|--)', rest)
        asg = pp_assign(code, e)
        if not pre and re.search(BYTE_MACRO, code[:m.start()][-12:]):
            new, end = slot, e     # BYTE1(v) = 1: bits of the slot itself
        elif pre == '&' and not rest.lstrip().startswith('['):
            new, end = addr, e
        elif pre in ('++', '--'):
            new, end = '((%s)(uintptr_t)(%s %s= %s))' % (typ, slot, pre[0], sz), e
        elif post:
            inv = '-' if post.group(1) == '++' else '+'
            new, end = '((%s)(uintptr_t)((%s %s= %s) %s %s))' % (typ, slot, post.group(1)[0], sz, inv, sz), e + 2
        elif asg and asg[0] != '=':
            r1 = pp_rhs_end(code, asg[1])
            new, end = '(%s %s (uint32_t)((%s) * %s))' % (slot, asg[0], code[asg[1]:r1].strip(), sz), r1
        elif asg and not pre and re.search(STMT_START, code[:m.start()][-40:]):
            r1 = pp_rhs_end(code, asg[1])
            new, end = '%s = (uint32_t)(uintptr_t)(%s)' % (slot, code[asg[1]:r1].strip()), r1
        else:
            new, end = '%s((%s)(uintptr_t)%s)' % ('&' if pre == '&' else '', typ, slot), e
        code = code[:m.start()] + new + code[end:]
    return code


def fix_frame(t):
    fh = func_header(t)
    if not fh:
        return t
    he = fh[1]
    body = t[he:]
    lines = body.split('\n')
    locs, k = [], 0
    for line in lines:
        if not line.strip():
            break
        k += 1
        m = FRAME_DECL.match(line)
        if not m:
            continue
        cm = m.group(4)
        om = re.search(r'\[ebp([+-][0-9A-F]+)h\]', cm)
        locs.append((int(om.group(1), 16) if om else None, m.group(2), m.group(1).strip(), m.group(3), 'BYREF' in cm, line))
    byref = [x[0] for x in locs if x[4] and x[0] is not None and x[0] < 0 and x[1] != 'savedregs']
    if not byref:
        return t
    lo = min(byref)
    grp = [x for x in locs if x[0] is not None and lo <= x[0] < 0 and x[2] != 'va_list']
    if len(grp) < 2:
        return t
    vars_ = []
    for off, n, typ, arr, b, line in grp:
        dims = [int(d, 0) for d in re.findall(r'\[([^\]]*)\]', arr)]
        if typ.endswith('*'):
            size = 4
        elif typ in SIZE32:
            size = SIZE32[typ]
        else:
            stats['frame left (type %s)' % typ] += 1
            return t
        if len(dims) > 1:
            stats['frame left (2D array)'] += 1
            return t
        vars_.append((off - lo, n, typ, dims[0] if dims else None, size))
    fsize = max(o + s * (d or 1) for o, n, typ, d, s in vars_)
    fsize = (fsize + 3) & ~3
    gnames = {x[1] for x in grp}
    decl_lines = [l for l in lines[:k] if not (FRAME_DECL.match(l) and FRAME_DECL.match(l).group(2) in gnames)]
    decl_lines.append('  uint8_t frame150[0x%X] = { 0 };   // 32-bit stack frame from [ebp%sh]' % (fsize, '-%X' % -lo))
    code = '\n'.join(lines[k:])
    for o, n, typ, d, s in vars_:
        if typ.endswith('*') and d is None:
            code = slot_uses(code, n, typ, '(*(uint32_t *)(frame150 + 0x%X))' % o, '((uint32_t *)(frame150 + 0x%X))' % o)
        elif d is not None:
            code = re.sub(r'\bsizeof\(\s*%s\s*\)' % n, '0x%X' % (d * s), code)
            code = re.sub(r'(?<![.>\w])&%s\b(?!\s*\[)' % n, '((%s *)(frame150 + 0x%X))' % (typ, o), code)
            code = re.sub(r'(?<![.>\w])\b%s\b' % n, '((%s *)(frame150 + 0x%X))' % (typ, o), code)
        else:
            code = re.sub(r'(?<![.>\w])\b%s\b' % n, '(*(%s *)(frame150 + 0x%X))' % (typ, o), code)
    stats['frame150 functions'] += 1
    return t[:he] + '\n'.join(decl_lines) + '\n' + code


def fix_va(t):
    """The block walks variadic arguments itself as 32-bit stack slots ((unsigned int *)va, ++). On x64 every
    argument takes an 8-byte slot: the low 32 bits of the first 32 slots are copied to va32 (garbage in the
    upper half of an int argument does not matter) and the function hands va32 on."""
    m = re.search(r'(?m)^(\s*)va_start\(va, \w+\);\n', t)
    if not m:
        return t
    ind = m.group(1)
    copy = ('%suint32_t va32[32];   // the 32-bit argument slots of the original\n'
            '%sfor ( int va32i = 0; va32i < 32; ++va32i )\n%s  va32[va32i] = (uint32_t)va_arg(va, uintptr_t);\n') % (ind, ind, ind)
    head, rest = t[:m.end()], t[m.end():]
    rest = re.sub(r'(?<!va_end\()\bva\b', 'va32', rest)
    rest = re.sub(r'\bvsprintf\(', 'Vsprintf150(', rest)
    stats['va32 functions'] += 1
    return head + copy + rest


# Hex-Rays mistakes in single functions, fixed after the generic passes: address -> [(old, new, count)]; old
# must be there exactly count times
FIXES = {
    # (the Watcom pass fixed 1ED647: its text argument comes out right now)
}


def fix_partial(t):
    """'variable is possibly undefined' when Hex-Rays only set a part of it (LOBYTE(v) = call() / LOWORD(v) =
    call(), the whole register used afterwards): the whole variable is set - a byte zero-extended, a word
    sign-extended (movsx), as the callers use them"""
    for v in sorted(set(re.findall(r"^// [0-9A-F]+: variable '(\w+)' is possibly undefined", t, re.M))):
        if re.search(r'(?<![\w.>])%s\s*=(?!=)' % v, t):
            continue
        n0 = t
        t = re.sub(r'(?m)^(\s*)LOBYTE\(%s\) = (.*);$' % v, r'\1%s = (uint8_t)(\2);' % v, t)
        t = re.sub(r'(?m)^(\s*)LOWORD\(%s\) = (.*);$' % v, r'\1%s = (int16_t)(\2);' % v, t)
        if t != n0:
            t = re.sub(r"(?m)^(// [0-9A-F]+: variable '%s') is possibly undefined" % v, r'\1 was only partly set (gen150: widened)', t)
            stats['partly set variables widened'] += 1
    return t


def fix_single(a, t):
    for old, new, count in FIXES.get(a, []):
        if t.count(old) != count:
            raise SystemExit('FIXES %06X: %r found %d times' % (a, old, t.count(old)))
        t = t.replace(old, new)
        stats['single fixes'] += 1
    return t


gen_head, reg_params = {}, {}
# block code addresses kept in block data (callback tables)
fix_c_targets = set()
for _r in range(_rs, _cs, 11):
    _typ, _sb, _tb, _so, _add = struct.unpack_from('<BBBII', _blk, _r)
    if not _typ and _sb == 0 and _tb == 0 and BB + _so >= DATA and BB + _add < DATA:
        fix_c_targets.add(BB + _add)

lua_bound = []
for a, c in funcs:
    if any(in_ranges(int(n, 16), LUA) for n in re.findall(r'\bsub_(2[0-9A-F]{5})\s*\(', c)):
        lua_bound.append(a)
outs = []
for a, c in funcs:
    if a in manual or a in lua_bound:
        continue
    t = clean(c)
    t = re.sub(r'(?m)^#error .*$', '', t)
    t = rename_calls(t)
    t = fit_args(t)
    t = fix_crt(a, t)
    t = fix_void_return(t)
    t = fix_values(t)
    t = fix_addr_literals(t)
    t = fix_array_arith(t)
    t = fix_asm(a, t)
    t = fix_ptr32(t)
    t = fix_frame(t)
    t = fix_gptr(t)
    t = fix_va(t)
    t = fix_partial(t)
    t = fix_single(a, t)
    t = promote(t)
    fh = func_header(t)
    if fh and '...' not in fh[4] and '(' not in fh[2]:
        gen_head[fh[3]] = (fh[2], [p.strip() for p in split_args(fh[4])] if fh[4].strip() not in ('', 'void') else [])
        oh = c.split('\n')[1] if c.startswith('//-----') else ''
        om = re.match(r'^.*?\b%s(?:@<\w+>)?\((.*)\)\s*$' % fh[3], oh)
        if om and '@<' in om.group(1):
            reg_params[fh[3]] = ['@<' in p for p in split_args(om.group(1))]
    for n in set(re.findall(r'\b([A-Za-z_]\w*)\b', t)):
        sm = re.match(r'^(?:byte|word|dword|qword|unk|off|asc|stru|flt|dbl|algn)_([0-9A-F]{5,6})$', n)
        if n not in symaddr and sm and n in datadecl or n not in symaddr and sm and int(sm.group(1), 16) >= BB:
            symaddr[n] = int(sm.group(1), 16)     # unnamed in the listing (e.g. a plain "db 2")
        lm = re.match(r'^(?:loc|locret|def|algn|byte|word|dword|off|unk)_([0-9A-F]{5,6})$', n)
        if n not in symaddr and lm and (int(lm.group(1), 16) < 0x170695 or BB <= int(lm.group(1), 16) < DATA) \
                and not re.search(r'\b' + n + r'\s*\(', t):
            symaddr[n] = int(lm.group(1), 16)     # label inside game code (address taken / patched)
            code_syms.add(n)
        if n in symaddr and n not in code_syms or n in symaddr and symaddr[n] >= DATA:
            used.add(n)
        elif n in code_syms and n not in own and n not in portname.values() and not n.startswith('sub_'):
            stats['code label used as data: ' + n] += 1
            used.add(n)
    outs.append(t)

# A function with register parameters (Hex-Rays: a1@<esi>, mostly a register it only saves) whose address is
# handed on is called through the pointer with the stack arguments alone: it gets a wrapper without them.
cb_wrapped = set()
for n, regs in reg_params.items():
    ret, params = gen_head[n]
    if len(params) != len(regs) or all(regs):
        continue
    if any(re.search(r'\b%s\b(?!\s*\()' % n, t) for t in outs) or own.get(n) in fix_c_targets:
        cb_wrapped.add(n)
        args = ', '.join('0' if r else re.match(r'.*?(\w+)$', p).group(1) for p, r in zip(params, regs))
        decl = ', '.join(p for p, r in zip(params, regs) if not r) or 'void'
        outs.append('//----- wrapper: %s called through a pointer (stack arguments only)\n%s %s_cb(%s)\n{\n  %s%s(%s);\n}\n\n'
                    % (n, ret, n, decl, '' if ret == 'void' else 'return ', n, args))
        gen_head[n + '_cb'] = (ret, [p for p, r in zip(params, regs) if not r])
for i, t in enumerate(outs):
    for n in cb_wrapped:
        if n in t:
            t = re.sub(r'\b%s\b(?!\s*\()' % n, n + '_cb', t)
    outs[i] = t
stats['callback wrappers'] = len(cb_wrapped)
os.makedirs(OUT, exist_ok=True)
for k in range(0, len(outs), 150):
    with open(os.path.join(OUT, 'orion150_code_%02d.c' % (k // 150 + 1)), 'w', encoding='latin1', newline='\r\n') as f:
        f.write('/* Generated by tools/compare/gen150.py from the 1.50 block (ORION150.EXE) - do not edit,\n'
                '   hand fixes go to orion150_manual.c */\n#include "orion150.h"\n\n')
        f.write(''.join(outs[k:k + 150]))

# ---------------------------------------------------------------- data: eseg, ecode
img = open(DISS + 'ext/ext150.bin', 'rb').read()
END = BB + len(img)
eseg, ecode = img[DATA - BB:], img[:DATA - BB]
exe = open(DISS + 'ORION150.EXE', 'rb').read()
size, rstart, cstart = struct.unpack_from('<III', exe, 0x285B6A)
blk = exe[0x285B6A + 12:0x285B6A + 12 + size]
fix_e, fix_d, fix_c, fix_miss = [], [], [], collections.Counter()
fix_ec, fix_cc = [], []
for r in range(rstart, cstart, 11):
    typ, sb, tb, so, add = struct.unpack_from('<BBBII', blk, r)
    src = BB + so
    if sb != 0 or typ != 0 or src < DATA:
        continue
    slot = src - DATA
    if tb == 0:
        tgt = BB + add
        if tgt >= DATA:
            fix_e.append((slot, tgt - DATA))
        else:
            name = 'sub_%X' % tgt
            if (name in own and tgt not in lua_bound) or tgt in manual:
                fix_c.append((slot, name + '_cb' if name in cb_wrapped else name))
            elif in_ranges(tgt, LUA) or tgt in lua_bound:
                fix_miss['lua or unported block code'] += 1
            else:
                fix_ec.append((slot, tgt - BB))     # jump tables and data inside the block's code area
    elif tb == 1:
        fix_d.append((slot, add))
    else:
        tgt = 0x10000 + add
        if tgt in portname:
            fix_c.append((slot, portname[tgt]))
        else:
            fix_cc.append((slot, add))     # a site in the game code the block patches (config values)

h = ['/* Generated by tools/compare/gen150.py - the 1.50 patch block for the port. */',
     '#ifndef ORION150_H', '#define ORION150_H', '#include <stdarg.h>', '#include "../game/orion_common.h"', '',
     '#define __ROL2__(x, n) ((uint16_t)(((uint16_t)(x) << (n)) | ((uint16_t)(x) >> (16 - (n)))))', '',
     '/* Hex-Rays treats _DWORD as a signed int: a plain "<" between _DWORDs is jl/jge in the block (1EC090,',
     '   1FF83F, 200B40), unsigned compares carry an explicit (unsigned int) */',
     '#undef _DWORD', '#define _DWORD int32_t', '',
     '/* block data 0x%X..0x%X (block at 0x1E0000): eseg offset = address - 0x%X;' % (DATA, END, DATA),
     '   data the block keeps inside its code area: ecode offset = address - 0x%X */' % BB,
     '/* ccode = the game code object of ORION150.EXE (0x10000..0x170695): the block patches constants of the',
     '   game code at run time (config values); the C code of the port reads them from here at those sites */',
     'extern uint8_t eseg[0x%X];' % len(eseg), 'extern uint8_t ecode[0x%X];' % len(ecode), 'extern uint8_t ccode[0x160695];',
     'void InitEseg150(void);',
     '/* vsprintf on 32-bit argument slots (orion150_manual.c) */',
     'int Vsprintf150(char *buf, const char *fmt, uint32_t *va);', '']
unplaced, ccode_syms = [], []
for n in sorted(used):
    if re.match(r'^[av]\d+$', n):      # same names as Hex-Rays parameters / locals: never a macro
        continue
    a = symaddr[n]
    decl = datadecl.get(n)
    typ, arr = '_BYTE', ''
    if decl:
        dm = re.match(r'^(.*?)\b' + re.escape(n) + r'\s*((?:\[[^\]]*\])*)\s*$', decl)
        if dm:
            typ, arr = dm.group(1).strip(), dm.group(2)
    typ = re.sub(r'\b(extern|static)\b\s*', '', typ).strip()
    if not typ or typ == '_UNKNOWN' or '(' in typ:
        typ = '_BYTE'
    if arr == '[]':
        arr = '[1]'
    if n in ptr_globals or n in ptr_garrays or n in fptrdecl:
        typ = 'uint32_t'      # pointers are 32-bit slots (fix_ptr32 / fix_gptr convert the uses)
        if n in fptrdecl:
            arr = '[%d]' % fptrdecl[n] if fptrdecl[n] else ''
    if DATA <= a < END:
        base, off = 'eseg', a - DATA
    elif BB <= a < DATA:
        base, off = 'ecode', a - BB
    elif 0x178000 <= a < 0x1D5CD0:
        if n in dseg_names or n in common_names:
            continue
        base, off = 'dseg', a - 0x178000
    elif 0x10000 <= a < 0x170695:
        base, off = 'ccode', a - 0x10000
        ccode_syms.append((a, n))
    else:
        unplaced.append('%s@%X' % (n, a))
        continue
    if arr:
        h.append('#define %s (*(%s (*)%s)(%s + 0x%05X))' % (n, typ, arr, base, off))
    else:
        h.append('#define %s (*(%s *)(%s + 0x%05X))' % (n, typ, base, off))
h.append('')
for n, a in sorted(own.items(), key=lambda kv: kv[1]):
    if n not in common_names:
        if own[n] in manual:
            mm = re.search(r'(?m)^([A-Za-z_][\w \*]*?)\s*\b' + n + r'\s*\(([^;{]*)\)\s*$', open(mp, encoding='latin1').read())
            # without a parameter list: Hex-Rays' calls may still carry register arguments the hand written
            # function does not take
            h.append('%s %s();' % (mm.group(1).strip() if mm else 'int', n))
        elif n in own_full:
            h.append(own_full[n] + ';')
        elif n in gen_head:
            # full prototypes: an int argument for a pointer parameter must be widened by the caller
            h.append('%s %s(%s);' % (gen_head[n][0], n, ', '.join(gen_head[n][1]) or 'void'))
        else:
            h.append('%s %s();' % (own_ret.get(n, 'int'), n))
for n in sorted(cb_wrapped):
    h.append('%s %s_cb(%s);' % (gen_head[n][0], n, ', '.join(p for p, r in zip(gen_head[n][1], reg_params[n]) if not r) or 'void'))
h += ['', '#endif', '']
open(os.path.join(OUT, 'orion150.h'), 'w', encoding='latin1', newline='\r\n').write('\n'.join(h))


def le_code(path):
    """code object image of an LE exe (data pages are relative to the bound app's MZ header)"""
    b = open(path, 'rb').read()
    off = b.find(b'LE\x00\x00')
    h = b[off:]
    mz = [i for i in range(off) if b[i:i + 2] == b'MZ' and struct.unpack_from('<I', b, i + 0x3C)[0] + i == off][0]
    pagesz, npages, last = struct.unpack_from('<I', h, 0x28)[0], struct.unpack_from('<I', h, 0x14)[0], struct.unpack_from('<I', h, 0x2C)[0]
    datapg = struct.unpack_from('<I', h, 0x80)[0] + mz
    vsize, base, flags, pidx, pcnt, _ = struct.unpack_from('<IIIIII', h, struct.unpack_from('<I', h, 0x40)[0])
    img = bytearray(vsize)
    for p in range(pcnt):
        pg = pidx + p - 1
        n = min(pagesz, vsize - p * pagesz, last if pg == npages - 1 else pagesz)
        img[p * pagesz:p * pagesz + n] = b[datapg + pg * pagesz:datapg + pg * pagesz + n]
    return bytes(img)


def bytes_c(name, data):
    e = ['uint8_t %s[0x%X] = {' % (name, len(data))]
    for k in range(0, len(data), 32):
        e.append('  ' + ','.join(str(x) for x in data[k:k + 32]) + ',')
    return e + ['};', '']


e = ['/* Generated by tools/compare/gen150.py - data of the 1.50 block and its pointer slots. */',
     '#include "orion150.h"', ''] + bytes_c('eseg', eseg) + bytes_c('ecode', ecode) + bytes_c('ccode', le_code(DISS + 'ORION150.EXE'))
e += ['static const uint32_t esegDataFixups[][2] = {'] + ['  { 0x%X, 0x%X },' % x for x in fix_e] + ['};', '',
      'static const uint32_t esegDsegFixups[][2] = {'] + ['  { 0x%X, 0x%X },' % x for x in fix_d] + ['};', '',
      'static const uint32_t esegEcodeFixups[][2] = {'] + ['  { 0x%X, 0x%X },' % x for x in fix_ec] + ['};', '',
      'static const uint32_t esegCcodeFixups[][2] = {'] + ['  { 0x%X, 0x%X },' % x for x in fix_cc] + ['};', '',
      'static const struct { uint32_t slot; void *target; } esegCodeFixups[] = {']
e += ['  { 0x%X, (void *)%s },' % x for x in fix_c] + ['};', '',
      '/* the block stores 32-bit addresses; the port image lies below 4 GB (LARGEADDRESSAWARE:NO) */',
      'void InitEseg150(void)', '{', '  uint32_t i;', '',
      '  for ( i = 0; i < sizeof(esegDataFixups) / sizeof(esegDataFixups[0]); ++i )',
      '    *(uint32_t *)(eseg + esegDataFixups[i][0]) = (uint32_t)(uintptr_t)(eseg + esegDataFixups[i][1]);',
      '  for ( i = 0; i < sizeof(esegDsegFixups) / sizeof(esegDsegFixups[0]); ++i )',
      '    *(uint32_t *)(eseg + esegDsegFixups[i][0]) = (uint32_t)(uintptr_t)(dseg + esegDsegFixups[i][1]);',
      '  for ( i = 0; i < sizeof(esegEcodeFixups) / sizeof(esegEcodeFixups[0]); ++i )',
      '    *(uint32_t *)(eseg + esegEcodeFixups[i][0]) = (uint32_t)(uintptr_t)(ecode + esegEcodeFixups[i][1]);',
      '  for ( i = 0; i < sizeof(esegCcodeFixups) / sizeof(esegCcodeFixups[0]); ++i )',
      '    *(uint32_t *)(eseg + esegCcodeFixups[i][0]) = (uint32_t)(uintptr_t)(ccode + esegCcodeFixups[i][1]);',
      '  for ( i = 0; i < sizeof(esegCodeFixups) / sizeof(esegCodeFixups[0]); ++i )',
      '    *(uint32_t *)(eseg + esegCodeFixups[i].slot) = (uint32_t)(uintptr_t)esegCodeFixups[i].target;',
      '}', '']
open(os.path.join(OUT, 'orion150_eseg.c'), 'w', encoding='latin1', newline='\r\n').write('\n'.join(e))

p = ['/* Generated by tools/compare/gen150.py - the 1.50 functions that call into Lua directly. Their',
     '   Hex-Rays body works on the 32-bit internals of the Lua build inside ORION150.EXE, which the x64',
     '   official Lua (third_party/lua-5.3.2) does not share: until each one is rewritten on the Lua API',
     '   (moved to orion150_manual.c) it only reports itself once and returns 0. */',
     '#include "orion150.h"', '', 'void Lua150_Pending(uint32_t addr);', '']
for a in lua_bound:
    if a not in manual:
        p += ['//----- (%08X) --------------------------------------------------------' % a,
              'int sub_%X()' % a, '{', '  Lua150_Pending(0x%X);' % a, '  return 0;', '}', '']
open(os.path.join(OUT, 'orion150_lua_pending.c'), 'w', encoding='latin1', newline='\r\n').write('\n'.join(p))

print('functions %d (manual %d, lua pending %d), files %d' % (len(outs), len(manual), len(lua_bound), (len(outs) + 149) // 150))
print('eseg %d B, ecode %d B; fixups data %d, dseg %d, code %d, ecode %d, ccode %d; unresolved %s' % (
    len(eseg), len(ecode), len(fix_e), len(fix_d), len(fix_c), len(fix_ec), len(fix_cc), dict(fix_miss)))
print('data symbols %d, in game code (ccode) %d, not placeable %d %s' % (len(used), len(ccode_syms), len(unplaced), unplaced[:12]))
with open(os.path.join(OUT, 'asm_pending.txt'), 'w') as f:
    for x in asm_pending:
        f.write(x + '\n')
with open(os.path.join(OUT, 'ccode_sites.txt'), 'w') as f:
    for a, n in sorted(ccode_syms):
        f.write('%06X %s\n' % (a, n))
for k, v in sorted(stats.items(), key=lambda kv: -kv[1])[:30]:
    print('  %4d %s' % (v, k))
