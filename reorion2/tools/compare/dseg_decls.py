"""Top-level declarations of orion_data.c, parsed, with their addresses.

    decls(text) -> [Decl]   (start, end offsets in the text, name, type,
                             pointer flag, dims, has initializer)
    addr_map()  -> {C name: C address} for every labelled object in the
                   listing (asm address + 0x8000)

Used by the wave 180 generator; as a script it prints statistics.
"""
import re

import lst_block

DSEG_C0 = 0x178000          # data object: IDA 0x170000 + 0x8000
DSEG_C1 = 0x178000 + 0x5DCD0


class Decl(object):
    __slots__ = ('start', 'end', 'text', 'name', 'type', 'ptr', 'dims', 'init', 'func')

    def __repr__(self):
        return '<%s %s%s%s%s>' % (self.type, '*' if self.ptr else '', self.name, ''.join('[%s]' % d for d in self.dims),
                                  ' = ...' if self.init else '')


def statements(t):
    """Top-level statements: (start, end) of text ending in ';' or '}' of a function."""
    i, n = 0, len(t)
    depth = 0
    start = 0
    out = []
    while i < n:
        c = t[i]
        if c == '/' and t.startswith('//', i):
            j = t.find('\n', i)
            i = n if j < 0 else j
            continue
        if c == '/' and t.startswith('/*', i):
            j = t.find('*/', i + 2)
            i = n if j < 0 else j + 2
            continue
        if c == '#' and depth == 0 and (i == 0 or t[i - 1] == '\n'):
            j = t.find('\n', i)
            while j > 0 and t[j - 1] == '\\':
                j = t.find('\n', j + 1)
            i = n if j < 0 else j
            start = i
            continue
        if c in '"\'':
            j = i + 1
            while j < n and t[j] != c:
                j += 2 if t[j] == '\\' else 1
            i = j + 1
            continue
        if c == '{':
            depth += 1
        elif c == '}':
            depth -= 1
            if depth == 0:
                # a function body ends here unless a ';' follows (initializer)
                k = i + 1
                while k < n and t[k] in ' \t\r\n':
                    k += 1
                if k < n and t[k] != ';' and t[k] != ',':
                    out.append((start, i + 1))
                    start = i + 1
        elif c == ';' and depth == 0:
            out.append((start, i + 1))
            start = i + 1
        i += 1
    return out


def strip_comments(s):
    s = re.sub(r'/\*.*?\*/', ' ', s, flags=re.S)
    return re.sub(r'//[^\n]*', ' ', s)


HEAD = re.compile(r'^\s*(?P<type>(?:(?:static|const|volatile|unsigned|signed|struct|enum)\s+)*[A-Za-z_]\w*(?:\s+(?:int|char|short|long))*)'
                  r'\s*(?P<ptr>[\*\s]*)(?P<name>[A-Za-z_]\w*)\s*(?P<dims>(?:\[[^\]]*\]\s*)*)(?P<init>=.*)?;\s*$', re.S)


def decls(t):
    out = []
    for s, e in statements(t):
        raw = t[s:e]
        code = strip_comments(raw)
        if not code.strip() or '(' in code.split('=')[0]:
            continue        # function, function pointer or prototype
        m = HEAD.match(code)
        if not m or m.group('type').startswith(('typedef', 'extern', 'return')):
            continue
        d = Decl()
        # exclude leading comment/whitespace from the removed span: start at the type
        lead = len(raw) - len(raw.lstrip())
        cstart = s + lead
        while t.startswith('//', cstart) or t.startswith('/*', cstart):
            if t.startswith('//', cstart):
                cstart = t.find('\n', cstart) + 1
            else:
                cstart = t.find('*/', cstart) + 2
            while cstart < e and t[cstart] in ' \t\r\n':
                cstart += 1
        d.start, d.end = cstart, e
        d.text = t[cstart:e]
        d.name = m.group('name')
        d.type = ' '.join(m.group('type').split())
        d.ptr = '*' in m.group('ptr')
        d.dims = re.findall(r'\[([^\]]*)\]', m.group('dims'))
        d.init = bool(m.group('init'))
        d.func = False
        out.append(d)
    return out


_amap = None


def addr_map():
    global _amap
    if _amap is None:
        _amap = {}
        for a, lab, kind, ops in lst_block._load():
            if lab:
                _amap.setdefault(lst_block.cname(lab), a + lst_block.DELTA)
    return _amap


def address(name):
    m = re.search(r'_([0-9A-F]{5,6})$', name)
    if m and not name.startswith(('sub_', 'loc_', 'nullsub_')):
        return int(m.group(1), 16)
    return addr_map().get(name)


if __name__ == '__main__':
    t = open('src/game/orion_data.c', encoding='latin-1').read()
    ds = decls(t)
    inseg = [d for d in ds if address(d.name) is not None and DSEG_C0 <= address(d.name) < DSEG_C1]
    ptr = [d for d in inseg if d.ptr]
    print('declarations %d, in the data segment %d, pointer-typed %d' % (len(ds), len(inseg), len(ptr)))
    types = {}
    for d in inseg:
        if not d.ptr:
            types[d.type] = types.get(d.type, 0) + 1
    print(sorted(types.items(), key=lambda x: -x[1]))
    other = [d for d in ds if d not in inseg]
    print('outside / unknown address: %d, e.g. %s' % (len(other), other[:15]))
