#!/usr/bin/env python3
import re, os, sys, textwrap

SRC = "orig.c"
OUTDIR = "out"
os.makedirs(OUTDIR, exist_ok=True)

with open(SRC, "r", encoding="utf-8", errors="replace") as f:
    lines = f.readlines()

n = len(lines)

# --- najdi hranice tri hlavnich bloku ---
decl_start = None
data_start = None
for i, l in enumerate(lines):
    if l.startswith("// Function declarations"):
        decl_start = i
    if l.startswith("// Data declarations"):
        data_start = i
        break

# prvni funkce zacina prvnim radkem "//----- (0"
impl_start = None
for i, l in enumerate(lines):
    if l.startswith("//----- (0"):
        impl_start = i
        break

assert decl_start is not None and data_start is not None and impl_start is not None

decl_lines = lines[decl_start:data_start]
data_lines = lines[data_start:impl_start]
impl_lines = lines[impl_start:]

REG_AT = re.compile(r'@<[A-Za-z0-9_:]+>')
SPOILS = re.compile(r'__spoils<[^>]*>\s*')

# "unsigned __intN"/"signed __intN" nejsou v C platne kombinace (typedef
# nelze kombinovat s unsigned/signed) - nahrad primo za stdint typy,
# nejspecifictejsi vzory nejdrive.
INT_SUBS = [
    (r'\bunsigned\s+__int64\b', 'uint64_t'),
    (r'\bunsigned\s+__int32\b', 'uint32_t'),
    (r'\bunsigned\s+__int16\b', 'uint16_t'),
    (r'\bunsigned\s+__int8\b',  'uint8_t'),
    (r'\bsigned\s+__int64\b', 'int64_t'),
    (r'\bsigned\s+__int32\b', 'int32_t'),
    (r'\bsigned\s+__int16\b', 'int16_t'),
    (r'\bsigned\s+__int8\b',  'int8_t'),
    (r'\b__int64\b', 'int64_t'),
    (r'\b__int32\b', 'int32_t'),
    (r'\b__int16\b', 'int16_t'),
    (r'\b__int8\b',  'int8_t'),
]
INT_SUBS = [(re.compile(p), r) for p, r in INT_SUBS]

def clean_common(text):
    text = REG_AT.sub('', text)
    text = SPOILS.sub('', text)
    text = text.replace('::a1', 'a1')
    # sub_154D96 ("could not find valid save-restore pair for ebx"): MK_FP
    # vraci ukazatel na data, zde je ale pouzit jako trampolina - zavolan
    # primo jako funkce. Cast pres genericky ukazatel na funkci.
    text = text.replace(
        'MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr)(v13, v17, v16, v12)',
        '((int(*)())(void*)MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr))(v13, v17, v16, v12)'
    )
    # Hex-Rays casto oznaci parametr/ukazatel jako const na zaklade pouziti
    # jen v CASTI volani, ale jinde se do nej zapisuje - odstranit globalne,
    # aby nevznikaly "assignment of read-only location" chyby.
    text = re.sub(r'\bconst\b\s*', '', text)
    for pat, rep in INT_SUBS:
        text = pat.sub(rep, text)
    return text

# ---------- 1) DECLARATIONS BLOCK -> common.h ----------
# ---------- MSVC ma nektere identifikatory jako rezervovana klicova slova /
# vestavene intrinsiky (nelze je predefinovat jako typedef/funkci) - v
# generovanem kodu je proto prejmenujeme na vlastni jmena bez kolize.
MSVC_RESERVED_RENAME = {
    '__int128': 'hr_int128_t',
    '__readgsbyte': 'hr_readgsbyte',
    '__readgsword': 'hr_readgsword',
    '__writegsbyte': 'hr_writegsbyte',
    '__writegsword': 'hr_writegsword',
    '__writegsdword': 'hr_writegsdword',
    '__addgsword': 'hr_addgsword',
    '__inbyte': 'hr_inbyte',
    '__outbyte': 'hr_outbyte',
    '__readeflags': 'hr_readeflags',
    '__writeeflags': 'hr_writeeflags',
    '__getcallerseflags': 'hr_getcallerseflags',
    '__debugbreak': 'hr_debugbreak',
}
MSVC_RENAME_RE = re.compile(r'\b(' + '|'.join(re.escape(k) for k in MSVC_RESERVED_RENAME) + r')\b')

def rename_msvc_reserved(text):
    return MSVC_RENAME_RE.sub(lambda m: MSVC_RESERVED_RENAME[m.group(1)], text)

# C/MSVC "\x" pohlti VSECHNY nasledujici hex znaky, takze "\x1B0" (mysleno
# ESC + text "0") se prevede na jedno cislo 0x1B0 (mimo rozsah char) misto
# escape + literal. Opravime vlozenim rozdeleni retezce hned za 2 hex cislice.
HEX_ESCAPE_RE = re.compile(r'\\x([0-9A-Fa-f]{2})(?=[0-9A-Fa-f])')

def fix_hex_escapes_in_strings(text):
    out = []
    i = 0
    n = len(text)
    while i < n:
        c = text[i]
        if c == '"':
            j = i + 1
            buf = ['"']
            while j < n:
                if text[j] == '\\' and j + 1 < n:
                    buf.append(text[j]); buf.append(text[j+1]); j += 2; continue
                if text[j] == '"':
                    buf.append('"'); j += 1; break
                buf.append(text[j]); j += 1
            lit = ''.join(buf)
            lit = HEX_ESCAPE_RE.sub(r'\\x\1""', lit)
            out.append(lit)
            i = j
        else:
            out.append(c); i += 1
    return ''.join(out)

decl_text = clean_common(''.join(decl_lines))

# ---------- 2) DATA BLOCK -> data.c (definitions) + extern decls for common.h ----------
# Depth-aware rozdeleni na top-level statementy (podporuje viceradkove
# inicializatory poli, funkcni ukazatele apod.)
data_text_full = clean_common(''.join(data_lines))

def split_statements(text):
    stmts = []
    buf = []
    depth = 0
    in_str = None
    in_comment = False
    i, n = 0, len(text)
    while i < n:
        c = text[i]
        buf.append(c)
        if in_comment:
            if c == '\n':
                in_comment = False
            i += 1; continue
        if in_str:
            if c == '\\' and i + 1 < n:
                buf.append(text[i+1]); i += 2; continue
            if c == in_str:
                in_str = None
            i += 1; continue
        if c == '/' and i + 1 < n and text[i+1] == '/':
            in_comment = True; i += 1; continue
        if c in ('"', "'"):
            in_str = c
        elif c in '([{':
            depth += 1
        elif c in ')]}':
            depth -= 1
        elif c == ';' and depth == 0:
            stmts.append(''.join(buf)); buf = []
        i += 1
    if ''.join(buf).strip():
        stmts.append(''.join(buf))
    return stmts

# jmena datovych symbolu, ktera FLIRT rozpoznal jako funkce staticky
# linknute Watcom CRT knihovny, ale Hex-Rays je nedokazal dekompilovat
# jako kod (vystup je oznacil jako _UNKNOWN data). Pro tyto pouzijeme
# realnou deklaraci z <string.h>/<stdlib.h> apod. mista nasi vlastni.
LIBC_NAME_BLACKLIST = {'strstr'}

def split_decl_init(stmt):
    depth = 0
    in_str = None
    last_eq = -1
    i, n = 0, len(stmt)
    while i < n:
        c = stmt[i]
        if in_str:
            if c == '\\':
                i += 2; continue
            if c == in_str:
                in_str = None
            i += 1; continue
        if c in ('"', "'"):
            in_str = c
        elif c in '([{':
            depth += 1
        elif c in ')]}':
            depth -= 1
        elif c == '=' and depth == 0:
            if i + 1 < n and stmt[i+1] == '=':
                i += 2; continue
            last_eq = i
        i += 1
    if last_eq == -1:
        d = stmt.rstrip()
        if d.endswith(';'):
            d = d[:-1].rstrip()
        return d, None
    return stmt[:last_eq].rstrip(), stmt[last_eq+1:]

raw_statements = split_statements(data_text_full)

extern_decls = []
data_out_parts = []
skipped = []
declared_data_names = set()

def extract_symbol_name(core):
    # funkcni ukazatel / pole funkcnich ukazatelu: TYPE (CONV *name)(...) / (*name[N])(...)
    m = re.search(r'\(\s*(?:[A-Za-z_][\w ]*)?\*+\s*([A-Za-z_][A-Za-z0-9_]*)\s*(\[[^\]]*\])?\s*\)', core)
    if m:
        return m.group(1)
    m = re.search(r'([A-Za-z_][A-Za-z0-9_]*)\s*(\[[^;]*\])?\s*$', core)
    if m:
        return m.group(1)
    return None

for stmt in raw_statements:
    decl_part, init_part = split_decl_init(stmt)
    decl_stripped = decl_part.strip('\n').strip()
    # jen posledni (necomment) radek deklarace je relevantni - predchozi
    # radky jsou zbytky komentaru prilepene z konce predchoziho statementu
    core = decl_stripped.split('\n')[-1].strip() if '\n' in decl_stripped else decl_stripped
    if not core or core.startswith('//') or not re.search(r'[A-Za-z_]', core):
        data_out_parts.append(stmt)
        continue
    if not re.search(r'[A-Za-z_]\w*\s*[;\[(]|[A-Za-z_]\w*$', core):
        data_out_parts.append(stmt)
        continue
    sym_name = extract_symbol_name(core)
    if sym_name in LIBC_NAME_BLACKLIST:
        # nahrad jen posledni radek (definici) komentarem, zbytek (predchozi
        # prilepene komentare) zachovej
        prefix = decl_stripped[:decl_stripped.rfind('\n')+1] if '\n' in decl_stripped else ''
        note = (f"/* {sym_name}: FLIRT rozpoznal jako staticky linkovanou CRT funkci, "
                f"Hex-Rays ji ale nedekompiloval jako kod - pouziva se realna deklarace "
                f"z <string.h> misto vlastni extern deklarace. */\n")
        data_out_parts.append(prefix + note)
        continue
    extern_decls.append(f"extern {core};\n")
    if sym_name:
        declared_data_names.add(sym_name)
    data_out_parts.append(stmt)

data_out_lines = [fix_hex_escapes_in_strings(''.join(data_out_parts))]

# mapa nazev funkce -> (navratovy typ+konvence, parametry) z bloku deklaraci,
# aby stub-funkce (selhana dekompilace) mely stejnou signaturu jako deklarace
PROTO_RE = re.compile(
    r'^([A-Za-z_][\w \t\*]*?)\s+(sub_[0-9A-Fa-f]+)\s*\(([^;()]*)\)\s*;\s*(?://.*)?$'
)
proto_map = {}
for pl in decl_text.split('\n'):
    if pl.strip().startswith('//'):
        continue
    pm = PROTO_RE.match(pl.strip())
    if pm:
        proto_map[pm.group(2)] = (pm.group(1).strip(), pm.group(3).strip())

def extract_signature(text):
    """Vytahne hlavicku funkce (navratovy typ + jmeno + parametry) z textu
    definice - vse pred prvnim radkem obsahujicim jen '{'. Vraci None,
    pokud takovy radek nenajde (nemelo by nastat u nasich generovanych funkci)."""
    lines = text.split('\n')
    sig_lines = []
    started = False
    for ln in lines:
        s = ln.strip()
        if not started:
            if s.startswith('//') or s == '':
                continue
            started = True
        if s == '{':
            sig = ' '.join(x.strip() for x in sig_lines if x.strip())
            return re.sub(r'\s+', ' ', sig).strip()
        sig_lines.append(ln)
    return None

def promote_narrow_params(header):
    """V hlavicce funkce (pred prvnim radkem '{') prevede parametry predane
    hodnotou s 'uzkym' typem (int16_t, char, uint8_t...) na jejich vychozi
    promovany typ (int / unsigned int). Nutne, protoze K&R (bezparametrova)
    extern deklarace v common.h neni kompatibilni s definici, jejiz parametr
    ma typ podlehajici default argument promotion (C17 6.7.6.3p15). Ukazatele
    (char *, int16_t *, ...) se nemeni - promotion se tyka jen predani hodnotou."""
    m = re.search(r'\(', header)
    if not m:
        return header
    open_idx = m.start()
    depth = 0
    close_idx = None
    for i in range(open_idx, len(header)):
        if header[i] == '(':
            depth += 1
        elif header[i] == ')':
            depth -= 1
            if depth == 0:
                close_idx = i
                break
    if close_idx is None:
        return header
    params_text = header[open_idx+1:close_idx]
    if params_text.strip() in ('', 'void'):
        return header

    PROMOTE_MAP = {
        'int16_t': 'int', 'uint16_t': 'unsigned int',
        'int8_t': 'int', 'uint8_t': 'unsigned int',
        'char': 'int', 'signed char': 'int', 'unsigned char': 'unsigned int',
        'short': 'int', 'unsigned short': 'unsigned int',
        '_BOOL1': 'int', '_BOOL2': 'int',
    }
    # rozdel parametry na top-level carkach
    parts = []
    depth2 = 0
    buf = []
    for c in params_text:
        if c in '(<':
            depth2 += 1
        elif c in ')>':
            depth2 -= 1
        if c == ',' and depth2 == 0:
            parts.append(''.join(buf)); buf = []
        else:
            buf.append(c)
    parts.append(''.join(buf))

    new_parts = []
    changed = False
    for p in parts:
        stripped = p.strip()
        if '*' in stripped or '(' in stripped:
            new_parts.append(p)  # ukazatel / funkcni ukazatel - nemenit
            continue
        matched = False
        for narrow, wide in PROMOTE_MAP.items():
            pat = re.compile(r'^(' + re.escape(narrow) + r')\b(\s+[A-Za-z_]\w*(\s*\[[^\]]*\])?)?\s*$')
            mm = pat.match(stripped)
            if mm:
                rest = mm.group(2) or ''
                new_parts.append(' ' + wide + rest)
                matched = True
                changed = True
                break
        if not matched:
            new_parts.append(p)
    if not changed:
        return header
    new_params_text = ','.join(new_parts)
    return header[:open_idx+1] + new_params_text + header[close_idx:]

# Funkce, kde Hex-Rays odvodil navratovy typ 'void', ale na vetsine mist
# volani je vysledek pouzit jako hodnota (typicky zbytek v EAX, ktery
# analyza toku dat nespravne vyhodnotila jako nepouzivany). DECOMP_TODO:
# skutecnou navratovou hodnotu overit v IDA.
FORCE_RETURN_TYPE = {
    'sub_FE8BE': 'int', 'sub_97A2D': 'int', 'sub_C8DB8': 'int',
    'sub_F53D7': 'int', 'sub_158B50': 'int', 'sub_B6352': 'int',
}

FUNC_NAME_RE = re.compile(r'\b(sub_[0-9A-Fa-f]+|nullsub_\d+|j_\w+)\s*\(')

def promote_header_in_func_text(text):
    """Aplikuje promote_narrow_params jen na kodovou cast hlavicky (radky pred
    prvnim '{', s vynechanim uvodnich komentarovych/prazdnych radku - marker
    radek '//----- (ADDR) ---' obsahuje zavorku, ktera by matla parser)."""
    lines = text.split('\n')
    header_end = None
    for i, ln in enumerate(lines):
        if ln.strip() == '{':
            header_end = i
            break
    if header_end is None:
        return text
    code_start = 0
    for i in range(header_end):
        if lines[i].strip().startswith('//') or lines[i].strip().startswith('/*') or not lines[i].strip():
            code_start = i + 1
        else:
            break
    prefix_lines = lines[:code_start]
    code_header = '\n'.join(lines[code_start:header_end])
    new_code_header = promote_narrow_params(code_header)

    fnm = FUNC_NAME_RE.search(code_header)
    if fnm and fnm.group(1) in FORCE_RETURN_TYPE:
        new_code_header = re.sub(r'^\s*void\b', FORCE_RETURN_TYPE[fnm.group(1)], new_code_header)

    if new_code_header == code_header:
        return text
    return '\n'.join(prefix_lines) + ('\n' if prefix_lines else '') + new_code_header + '\n' + '\n'.join(lines[header_end:])

# ---------- 3) IMPLEMENTATION BLOCK: rozdel na funkce ----------
MARKER_RE = re.compile(r'^//----- \((0[0-9A-Fa-f]+)\) -+')
ERROR_RE = re.compile(r'^#error "([0-9A-Fa-f]+): (.*)"\s*$')

func_chunks = []   # list of (addr:int, text:str)
cur_addr = None
cur_lines = []

def flush():
    global cur_addr, cur_lines
    if cur_addr is not None:
        func_chunks.append((cur_addr, ''.join(cur_lines)))
    cur_addr = None
    cur_lines = []

def find_matching_paren(text, open_idx):
    depth = 0
    for i in range(open_idx, len(text)):
        if text[i] == '(':
            depth += 1
        elif text[i] == ')':
            depth -= 1
            if depth == 0:
                return i
    return None

def split_top_commas(text):
    parts = []
    depth = 0
    buf = []
    for c in text:
        if c in '([{':
            depth += 1
        elif c in ')]}':
            depth -= 1
        if c == ',' and depth == 0:
            parts.append(''.join(buf)); buf = []
        else:
            buf.append(c)
    parts.append(''.join(buf))
    return parts

TYPE_KEYWORDS_NO_NAME = {
    'int', 'char', 'short', 'long', 'void', 'float', 'double', 'unsigned', 'signed',
    '_DWORD', '_WORD', '_BYTE', '_QWORD', '_BOOL1', '_BOOL2', '_BOOL4', '_UNKNOWN',
    'int8_t', 'int16_t', 'int32_t', 'int64_t', 'uint8_t', 'uint16_t', 'uint32_t',
    'uint64_t', '__int128', '_OWORD',
}

def param_has_name(param):
    p = param.strip()
    if not p or p.endswith('*'):
        return False
    tokens = p.replace('*', ' ').split()
    if not tokens:
        return False
    return tokens[-1] not in TYPE_KEYWORDS_NO_NAME

i = 0
L = impl_lines
while i < len(L):
    line = L[i]
    m = MARKER_RE.match(line)
    if m:
        flush()
        cur_addr = int(m.group(1), 16)
        cur_lines = [line]
        i += 1
        continue
    if cur_addr is None:
        # trailing summary lines before first marker shouldn't happen
        i += 1
        continue
    em = ERROR_RE.match(line.strip())
    if em:
        addr_hex, reason = em.group(1), em.group(2)
        fname = f"sub_{cur_addr:X}"
        rettype, params = proto_map.get(fname, ('void', 'void'))
        if not params:
            params = 'void'
        if params.strip() != 'void':
            # C (na rozdil od C++) vyzaduje u DEFINICE pojmenovane parametry,
            # i kdyz se nepouzivaji - doplnit jmena _p0, _p1, ... jen tam,
            # kde jmeno chybi (jinak by vzniklo "int a1 _p0" - duplicitni id)
            parts = split_top_commas(params)
            named = []
            for idx2, p in enumerate(parts):
                p = p.strip()
                if param_has_name(p):
                    named.append(p)
                else:
                    named.append(f"{p} _p{idx2}")
            params = ', '.join(named)
        cur_lines.append(
            f"/* DECOMP_TODO: dekompilace selhala ({reason}) - nutno dohledat rucne v IDA @ 0x{addr_hex} */\n"
        )
        cur_lines.append(f"{rettype} {fname}({params})\n{{\n  DECOMP_TODO(\"{reason}\");\n}}\n")
        i += 1
        continue
    if line.startswith('#error'):
        # zaverecny souhrnny #error na konci souboru - jen komentar
        cur_lines.append('// ' + line.lstrip('#'))
        i += 1
        continue
    cur_lines.append(line)
    i += 1
flush()

# ---------- oprav __asm bloky uvnitr kazde funkce ----------
ASM_BLOCK_RE = re.compile(
    r'__asm\s*(\{[^{}]*\}|\{[^{}]*(?:\{[^{}]*\}[^{}]*)*\})', re.MULTILINE
)

def fix_asm(text):
    def repl(mo):
        body = mo.group(1).strip('{}').strip()
        body_oneline = ' '.join(x.strip() for x in body.splitlines() if x.strip())
        return f'/* __asm: {body_oneline} */ DECOMP_TODO("inline asm");'
    return ASM_BLOCK_RE.sub(repl, text)

func_chunks = [(a, clean_common(fix_asm(t))) for a, t in func_chunks]
func_chunks.sort(key=lambda p: p[0])
KNOWN_FIELD_MACROS = {
    'LOBYTE', 'HIBYTE', 'LOWORD', 'HIWORD', 'LODWORD', 'HIDWORD', 'SHIDWORD',
    'SLODWORD', 'SLOWORD', 'SHIWORD', 'SLOBYTE', 'SHIBYTE', 'BYTEn', 'WORDn',
    'DWORDn', 'SBYTEn', 'SWORDn', 'BYTE1', 'BYTE2', 'BYTE3', 'BYTE4', 'BYTE5',
    'BYTE6', 'BYTE7', 'BYTE14', 'WORD1', 'WORD2', 'WORD3', 'WORD4', 'WORD5',
    'WORD6', 'DWORD1', 'DWORD2', 'sizeof', 'DECOMP_TODO',
}
def wrap_wide_args(text):
    """MSVC nema nativni __int128/_OWORD (u nas nahrazeny structem) - pokud
    se takova lokalni promenna predava jako HOLY argument volani (ne pres
    field-extrakcni makro jako LODWORD/DWORD1/...), implicitni prevod na
    int/jiny skalar selze. Takove vyskyty obalime explicitnim LODWORD()."""
    wide_vars = set(re.findall(r'\b__int128\s+(\w+)', text))
    wide_vars.update(re.findall(r'\b_OWORD\s+(\w+)', text))
    if not wide_vars:
        return text

    result = []
    i = 0
    n = len(text)
    call_re = re.compile(r'([A-Za-z_]\w*)\s*\(')
    while i < n:
        m = call_re.match(text, i)
        if not m:
            result.append(text[i]); i += 1; continue
        fname = m.group(1)
        open_idx = m.end() - 1
        close_idx = find_matching_paren(text, open_idx)
        if close_idx is None:
            result.append(text[i]); i += 1; continue
        if fname in KNOWN_FIELD_MACROS:
            result.append(text[i:close_idx+1])
            i = close_idx + 1
            continue
        inner = text[open_idx+1:close_idx]
        args = split_top_commas(inner)
        new_args = []
        changed = False
        for a in args:
            s = a.strip()
            if s in wide_vars:
                new_args.append(f'(int)LODWORD({s})')
                changed = True
            else:
                new_args.append(a)
        if changed:
            result.append(text[i:open_idx+1] + ','.join(new_args) + ')')
        else:
            result.append(text[i:close_idx+1])
        i = close_idx + 1
    return ''.join(result)

func_chunks = [(a, promote_header_in_func_text(t)) for a, t in func_chunks]
func_chunks = [(a, wrap_wide_args(t)) for a, t in func_chunks]

# ---------- MSVC-specificke prejmenovani + oprava \xHH escape sekvenci ----------
func_chunks = [(a, fix_hex_escapes_in_strings(rename_msvc_reserved(t))) for a, t in func_chunks]



# prototypy odvozene primo z definic (vc. DECOMP_TODO stubu) - zarucuji
# 100% shodu typu mezi deklaraci a definici napric soubory

def extract_func_name(sig):
    m = FUNC_NAME_RE.search(sig)
    return m.group(1) if m else None

derived_protos = {}
addr_to_funcname = {}
for addr, text in func_chunks:
    sig = extract_signature(text)
    if sig:
        fname = extract_func_name(sig) or f"sub_{addr:X}"
        derived_protos[fname] = sig
        addr_to_funcname[addr] = fname

print(f"Celkem funkcnich bloku: {len(func_chunks)}")
print(f"Radku deklaraci: {len(decl_lines)}, dat: {len(data_lines)}, kod: {len(impl_lines)}")
print(f"Nerozpoznanych datovych radku (ponechano beze zmeny, bez extern): {len(skipped)}")
if skipped:
    print("Priklady nerozpoznanych:")
    for s in skipped[:10]:
        print("  ", s)

# ---------- rozdel funkce do souboru po adresnich blocich ----------
CHUNK_SIZE = 200  # pocet funkci na soubor - hruby prvni rez
parts = [func_chunks[i:i+CHUNK_SIZE] for i in range(0, len(func_chunks), CHUNK_SIZE)]

manifest = []
for idx, part in enumerate(parts, start=1):
    lo = part[0][0]
    hi = part[-1][0]
    fname = f"orion_part_{idx:02d}.c"
    manifest.append((fname, lo, hi, len(part)))
    with open(os.path.join(OUTDIR, fname), 'w', encoding='utf-8') as f:
        f.write(f'#include "orion_common.h"\n\n')
        f.write(f'/* Adresni rozsah: 0x{lo:05X} - 0x{hi:05X}  ({len(part)} funkci) */\n\n')
        for addr, text in part:
            f.write(text)
            f.write('\n')

# ---------- 4) doplneni chybejicich deklaraci (osirele adresy) ----------
FUNC_PREFIXES = ('sub_', 'nullsub_', 'j_')
DATA_PREFIXES = ('loc_', 'unk_', 'off_', 'byte_', 'word_', 'dword_', 'qword_',
                  'asc_', 'stru_', 'dbl_', 'flt_', 'locret_', 'algn_')
ALL_PREFIXES = FUNC_PREFIXES + DATA_PREFIXES
PREFIX_RE = re.compile(r'\b((?:' + '|'.join(re.escape(p) for p in ALL_PREFIXES) + r')[0-9A-Fa-f]+)\b')

declared_names = set()
declared_names.update(derived_protos.keys())
declared_names.update(declared_data_names)
declared_names.update(LIBC_NAME_BLACKLIST)

full_impl_text = ''.join(t for _, t in func_chunks)
used_names = set(PREFIX_RE.findall(decl_text))
used_names.update(PREFIX_RE.findall(data_text_full))
used_names.update(PREFIX_RE.findall(full_impl_text))

orphans = sorted(used_names - declared_names)
orphan_func_decls = []
orphan_data_decls = []
for name in orphans:
    if name.startswith(FUNC_PREFIXES):
        orphan_func_decls.append(f"extern int {name}();\n")
    else:
        orphan_data_decls.append(f"extern _UNKNOWN {name};\n")

print(f"Osirelych symbolu (adresa pouzita, ale nikde nedeklarovana/nedefinovana): {len(orphans)}")
if orphans:
    print("  ", ', '.join(orphans[:20]), '...' if len(orphans) > 20 else '')

# Symboly rozpoznane FLIRT signaturami (Watcom near-heap alokator apod.),
# ktere v puvodnim vystupu maji jen zakomentovanou deklaraci.
KNOWN_EXTRA_DECLS = [
    "extern int nmalloc(unsigned int);\n",
    "extern int nfree(unsigned int);\n",
    "extern void _no_support_loaded(void);\n",
]

# ---------- zapis vystupu ----------
with open(os.path.join(OUTDIR, 'orion_common.h'), 'w', encoding='utf-8') as f:
    f.write('#ifndef ORION_COMMON_H\n#define ORION_COMMON_H\n\n')
    f.write('/* Pri includovani z C++ (napr. .cpp wrapper volajici main__0)\n'
             '   potrebuji tyto deklarace C linkage, jinak se nenajdou symboly\n'
             '   z .c souboru prelozenych jako C. */\n'
             '#ifdef __cplusplus\nextern "C" {\n#endif\n\n')
    f.write('#include "hexrays_compat.h"\n\n')
    f.write('/* ==== deklarace vsech funkci - odvozene primo z definic, aby typy\n'
             '   vzdy presne sedely (puvodni Hex-Rays hlavicka byla u cca 700\n'
             '   funkci s registrovymi anotacemi jen v komentari a neshodovala\n'
             '   se vzdy s telem). Puvodni hlavicka je nize pro referenci v #if 0. ==== */\n')
    f.write('/* ==== deklarace vsech funkci - odvozene primo z definic. Pouzity\n'
             '   je zaverny K&R styl (bez seznamu parametru): Hex-Rays u mnoha\n'
             '   __usercall/__userpurge funkci generuje na ruznych mistech volani\n'
             '   ruzny pocet argumentu (typicky artefakt dekompilace registrovych\n'
             '   parametru), takze presny prototyp by odmital jinak platny kod.\n'
             '   Skutecna/plna signatura je v komentari nad kazdou deklaraci a v\n'
             '   tele prislusne definice. DECOMP_TODO: az bude potreba typova\n'
             '   kontrola, dohledat a sjednotit realny pocet parametru v IDA. ==== */\n')
    for addr, _ in func_chunks:
        fname = addr_to_funcname.get(addr)
        sig = derived_protos.get(fname) if fname else None
        if sig:
            head_m = re.search(r'^(.*?)\b' + re.escape(fname) + r'\s*\(', sig)
            head = head_m.group(1).strip() if head_m else ''
            f.write(f"// plna signatura: {sig};\n")
            # over, ze parametry funkce jsou az uplne na konci signatury
            # (jinak jde o slozity deklarator, napr. navratovy typ = ukazatel
            # na funkci - "int (**name(args))(void)" - tam K&R zkraceni
            # rozbije syntaxi, proto se ponecha plna signatura)
            paren_start = head_m.end() - 1 if head_m else -1
            simple = False
            if paren_start >= 0:
                depth = 0
                for j, ch in enumerate(sig[paren_start:]):
                    if ch == '(':
                        depth += 1
                    elif ch == ')':
                        depth -= 1
                        if depth == 0:
                            simple = (j == len(sig[paren_start:]) - 1)
                            break
            if simple:
                f.write(f"extern {head} {fname}();\n")
            else:
                f.write(f"extern {sig};\n")
    f.write('\n#if 0 /* puvodni Hex-Rays deklarace, jen pro referenci - nekompiluje se */\n')
    f.write(decl_text)
    f.write('\n#endif\n')
    f.write('\n/* ==== extern deklarace vsech globalnich dat (definice viz orion_data.c) ==== */\n')
    f.write(''.join(extern_decls))
    f.write('\n/* ==== osirele symboly: adresa je nekde pouzita (napr. jako cil skoku,\n'
             '   ukazatel v datech, nebo volani), ale Hex-Rays pro ni negeneroval\n'
             '   zadnou deklaraci ani telo - typicky adresy uvnitr staticky\n'
             '   linkovane knihovny nebo prekryvajicich se segmentu. DECOMP_TODO:\n'
             '   overit v IDA, co se na teto adrese skutecne nachazi. ==== */\n')
    f.write(''.join(orphan_func_decls))
    f.write(''.join(orphan_data_decls))
    f.write('\n/* ==== ruzne pojmenovane FLIRT-rozpoznane knihovni symboly ==== */\n')
    f.write(''.join(KNOWN_EXTRA_DECLS))
    f.write('\n#ifdef __cplusplus\n}\n#endif\n')
    f.write('\n#endif\n')

with open(os.path.join(OUTDIR, 'orion_data.c'), 'w', encoding='utf-8') as f:
    f.write('#include "orion_common.h"\n\n')
    f.write(''.join(data_out_lines))

with open(os.path.join(OUTDIR, 'MANIFEST.txt'), 'w', encoding='utf-8') as f:
    f.write("soubor\t\t\tadr_od\tadr_do\tpocet_funkci\n")
    for fname, lo, hi, cnt in manifest:
        f.write(f"{fname}\t0x{lo:05X}\t0x{hi:05X}\t{cnt}\n")

print(f"\nVygenerovano {len(parts)} souboru s funkcemi + orion_common.h + orion_data.c")
