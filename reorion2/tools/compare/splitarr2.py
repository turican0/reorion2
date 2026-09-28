"""Find memset/memcpy/qmemcpy/memmove whose constant size exceeds the declared local array/scalar."""
import re, glob, os
os.chdir(r'C:\prenos\reorion2\reorion2')
SZ = {'char': 1, '_BYTE': 1, 'uint8_t': 1, 'int8_t': 1, '_BOOL1': 1, 'int16_t': 2, '_WORD': 2, 'uint16_t': 2,
      'int': 4, '_DWORD': 4, 'unsigned int': 4, 'int32_t': 4, 'uint32_t': 4, 'signed int': 4, '__int16': 2,
      'int64_t': 8, '_QWORD': 8, 'double': 8, 'float': 4}
for p in sorted(glob.glob('src/game/orion_part_*.c')):
    t = open(p, encoding='latin-1').read().replace('\r\n', '\n')
    for m in re.finditer(r'//----- \(([0-9A-F]{8})\) -+\n(.*?)(?=//----- \(|\Z)', t, re.S):
        blk = m.group(2)
        decl = {}
        for d in re.finditer(r'^\s+((?:unsigned |signed )?\w+) (v\d+)(?:\[(\d+)\])?; //', blk, re.M):
            ty, v, n = d.group(1), d.group(2), d.group(3)
            if ty in SZ:
                decl[v] = SZ[ty] * (int(n) if n else 1)
        for c in re.finditer(r'\b(memset|qmemcpy|memcpy|memmove)\(([^;]*)\);', blk):
            args = [a.strip() for a in c.group(2).split(',')]
            if len(args) < 3:
                continue
            nm = re.match(r'^\(?(0x[0-9A-Fa-f]+|\d+)u?\)?$', args[-1])
            if not nm:
                continue
            size = int(nm.group(1), 0)
            for a in args[:2]:
                vm = re.match(r'^(?:\([^)]*\))?\s*&?(v\d+)$', a)
                if vm and vm.group(1) in decl and size > decl[vm.group(1)]:
                    line = t[:m.start(2) + c.start()].count('\n') + 1
                    print('%s:%d sub_%X %s(%s) size %d > %d' % (os.path.basename(p), line, int(m.group(1), 16), c.group(1), a, size, decl[vm.group(1)]))
