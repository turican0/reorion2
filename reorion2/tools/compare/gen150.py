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
full = open(DISS + 'ORION150.full.c', encoding='latin1').read()
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
dseg_h = open(os.path.join(GAME, 'orion_dseg.h'), encoding='latin1').read()
dseg_names = set(re.findall(r'^#define (\w+) ', dseg_h, re.M))
common = open(os.path.join(GAME, 'orion_common.h'), encoding='latin1').read()
common_names = set(re.findall(r'\b(\w+)\s*\(', common)) | set(re.findall(r'\bextern\b[^;\n]*?\b(\w+)\s*(?:\[[^\]]*\])?\s*;', common))
# full prototypes of the port (a call with another argument count does not compile)
nparams = {}
for m in re.finditer(r'(?m)^(?!//)(?!extern\b)[A-Za-z_][\w \*]*?\b(\w+)\s*\(([^;()]*(?:\([^()]*\)[^;()]*)*)\)\s*;', common):
    ps = [x for x in split_args(m.group(2)) if x.strip() and x.strip() != 'void']
    if m.group(2).strip():
        nparams[m.group(1)] = len(ps)

manual = set()
mp = os.path.join(OUT, 'orion150_manual.c')
if os.path.exists(mp):
    manual = set(int(x, 16) for x in re.findall(r'^//----- \(([0-9A-F]{8})\)', open(mp, encoding='latin1').read(), re.M))

# ---------------------------------------------------------------- code
own = {}                          # block function name -> address
for a, c in funcs:
    m = re.search(r'(?m)^[^/\n][^\n]*?\b(sub_[0-9A-F]+|nullsub_\d+)\s*\(', c)
    if m:
        own[m.group(1)] = a
        hm = re.search(r'\b' + m.group(1) + r'\s*\(([^)]*)\)\s*\n\{', clean(c))
        if hm:
            nparams[m.group(1)] = len([x for x in split_args(hm.group(1)) if x.strip() and x.strip() != 'void'])
stats = collections.Counter()
used = set()


def rename_calls(text):
    def fn(m):
        n = m.group(1)
        a = int(n[4:], 16)
        if a < BB and a in portname:
            return portname[a] + '('
        if a < BB:
            stats['game function not in port: ' + n] += 1
        return n + '('
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
    for n in set(re.findall(r'\b([A-Za-z_]\w*)\b', t)):
        sm = re.match(r'^(?:byte|word|dword|qword|unk|off|asc|stru|flt|dbl|algn)_([0-9A-F]{5,6})$', n)
        if n not in symaddr and sm and n in datadecl or n not in symaddr and sm and int(sm.group(1), 16) >= BB:
            symaddr[n] = int(sm.group(1), 16)     # unnamed in the listing (e.g. a plain "db 2")
        if n in symaddr and n not in code_syms or n in symaddr and symaddr[n] >= DATA:
            used.add(n)
        elif n in code_syms and n not in own and n not in portname.values() and not n.startswith('sub_'):
            stats['code label used as data: ' + n] += 1
            used.add(n)
    outs.append(t)
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
                fix_c.append((slot, name))
            else:
                fix_miss['lua or unported block code' if in_ranges(tgt, LUA) or tgt in lua_bound else 'block code without function'] += 1
    elif tb == 1:
        fix_d.append((slot, add))
    else:
        tgt = 0x10000 + add
        if tgt in portname:
            fix_c.append((slot, portname[tgt]))
        else:
            fix_miss['game code not in port'] += 1

h = ['/* Generated by tools/compare/gen150.py - the 1.50 patch block for the port. */',
     '#ifndef ORION150_H', '#define ORION150_H', '#include "../game/orion_common.h"', '',
     '/* block data 0x%X..0x%X (block at 0x1E0000): eseg offset = address - 0x%X;' % (DATA, END, DATA),
     '   data the block keeps inside its code area: ecode offset = address - 0x%X */' % BB,
     '/* ccode = the game code object of ORION150.EXE (0x10000..0x170695): the block patches constants of the',
     '   game code at run time (config values); the C code of the port reads them from here at those sites */',
     'extern uint8_t eseg[0x%X];' % len(eseg), 'extern uint8_t ecode[0x%X];' % len(ecode), 'extern uint8_t ccode[0x160695];',
     'void InitEseg150(void);', '']
unplaced, ccode_syms = [], []
for n in sorted(used):
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
        h.append('extern int %s();' % n)
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
      'static const struct { uint32_t slot; void *target; } esegCodeFixups[] = {']
e += ['  { 0x%X, (void *)%s },' % x for x in fix_c] + ['};', '',
      '/* the block stores 32-bit addresses; the port image lies below 4 GB (LARGEADDRESSAWARE:NO) */',
      'void InitEseg150(void)', '{', '  uint32_t i;', '',
      '  for ( i = 0; i < sizeof(esegDataFixups) / sizeof(esegDataFixups[0]); ++i )',
      '    *(uint32_t *)(eseg + esegDataFixups[i][0]) = (uint32_t)(uintptr_t)(eseg + esegDataFixups[i][1]);',
      '  for ( i = 0; i < sizeof(esegDsegFixups) / sizeof(esegDsegFixups[0]); ++i )',
      '    *(uint32_t *)(eseg + esegDsegFixups[i][0]) = (uint32_t)(uintptr_t)(dseg + esegDsegFixups[i][1]);',
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
print('eseg %d B, ecode %d B; fixups data %d, dseg %d, code %d; unresolved %s' % (len(eseg), len(ecode), len(fix_e), len(fix_d), len(fix_c), dict(fix_miss)))
print('data symbols %d, in game code (ccode) %d, not placeable %d %s' % (len(used), len(ccode_syms), len(unplaced), unplaced[:12]))
with open(os.path.join(OUT, 'ccode_sites.txt'), 'w') as f:
    for a, n in sorted(ccode_syms):
        f.write('%06X %s\n' % (a, n))
for k, v in sorted(stats.items(), key=lambda kv: -kv[1])[:30]:
    print('  %4d %s' % (v, k))
