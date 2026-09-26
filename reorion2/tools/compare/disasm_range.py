"""Disassemble a range of the original code object that IDA left collapsed
(library functions like qsort_), with Visual Studio's tools only: the bytes
go into a MASM file as `db`, ml.exe assembles it, dumpbin prints it.
Addresses in the output are offsets from the start; add the IDA address.

usage: python tools/compare/disasm_range.py <ida_hex> <size_hex> <out.txt>
"""
import glob
import os
import subprocess
import sys
import tempfile

sys.path.insert(0, 'tools/compare')
from gen_cseg import code_image  # noqa: E402

VS = r'C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC'


def tool(name, host):
    c = sorted(glob.glob(os.path.join(VS, '*', 'bin', host, 'x86', name)))
    return c[-1]


def main():
    a, n, out = int(sys.argv[1], 16), int(sys.argv[2], 16), sys.argv[3]
    base, vs, img = code_image()
    data = img[a - base:a - base + n]
    d = tempfile.mkdtemp()
    asm = os.path.join(d, 'r.asm')
    lines = ['.386', '.model flat', '_TEXT SEGMENT USE32 PUBLIC \'CODE\'', 'start:']
    for i in range(0, len(data), 16):
        lines.append('  db ' + ','.join('0%02Xh' % b for b in data[i:i + 16]))
    lines += ['_TEXT ENDS', 'END']
    open(asm, 'w').write('\n'.join(lines) + '\n')
    subprocess.check_call([tool('ml.exe', 'Hostx64'), '/nologo', '/c', '/Fo' + os.path.join(d, 'r.obj'), asm],
                          cwd=d, stdout=subprocess.DEVNULL)
    txt = subprocess.check_output([tool('dumpbin.exe', 'Hostx64'), '/nologo', '/disasm', os.path.join(d, 'r.obj')],
                                  cwd=d).decode('latin-1')
    res = []
    for line in txt.splitlines():
        s = line.strip()
        if len(s) > 10 and s[8] == ':' and all(ch in '0123456789ABCDEF' for ch in s[:8]):
            off = int(s[:8], 16)
            body = s[9:].strip()
            # jump / call targets are offsets from the start - make them absolute
            parts = body.split(None, 1)
            import re
            m = re.search(r'\b(j\w+|call|loop\w*)\s+([0-9A-F]{8})$', body)
            if m:
                body = body[:m.start(2)] + 'loc_%X' % ((a + int(m.group(2), 16)) & 0xFFFFFFFF)
            res.append('%06X %s' % (a + off, body))
    open(out, 'w').write('\n'.join(res) + '\n')
    print('%d lines -> %s' % (len(res), out))


if __name__ == '__main__':
    main()
