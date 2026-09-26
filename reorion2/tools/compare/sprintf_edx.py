"""The edx half of `vN = sprintf(...)` (wave 182).

Hex-Rays types sprintf as returning int64 (edx:eax) and then feeds
HIDWORD(vN) / WORD2(vN) into the next calls. Watcom's sprintf_ keeps edx,
so the high half is the value the caller put into edx before the call -
usually a constant the port loses (sub_BD434: `mov edx, offset unk_17AC2E /
call sprintf_ / ... call sub_120CCB` became sub_120CCB(2, SHIDWORD(v14)),
the font colour table was garbage).

For every `vN = sprintf(` of a function the tool finds the matching
`call sprintf_` in the asm (by the format: sub_CDF5C(N) or the string
label; by order when there is no format hint and the counts agree), takes
the last write of edx before it in the same block and replaces
HIDWORD(vN) / SHIDWORD(vN) / WORD2(vN) / SWORD2(vN) up to the next
assignment of vN.

usage: python tools/compare/sprintf_edx.py [--fix]
"""
import glob
import re
import sys

sys.path.insert(0, 'tools/compare')
import lst_block  # noqa: E402

LST = 'C:/prenos/reorion2Data/diss/Orion2.exe.lst'
fix = '--fix' in sys.argv
LF, CRLF = b'\n', b'\r\n'


def load_asm():
    funcs, cur, body = {}, None, []
    for line in open(LST, encoding='utf-8', errors='replace'):
        if not line.startswith('cseg01:'):
            continue
        m = re.match(r'cseg01:([0-9A-F]{8})\s+(\S.*)$', line.rstrip('\n'))
        if not m:
            continue
        ins = m.group(2).split(';')[0].strip()
        pm = re.match(r'^(sub_[0-9A-F]+)\s+proc\b', ins)
        if pm:
            cur, body = pm.group(1), []
            continue
        if cur is None:
            continue
        if re.match(r'^%s\s+endp\b' % cur, ins):
            funcs[cur] = body
            cur = None
            continue
        if ins:
            body.append((m.group(1), ins))
    return funcs


def edx_before(body, k):
    """Value of edx at body[k] (a call sprintf_), or None."""
    for j in range(k - 1, max(-1, k - 40), -1):
        a, ins = body[j]
        if re.match(r'^[\w$?@]+:$', ins) or (ins.startswith('j') and not ins.startswith('call')):
            return None           # a join point or a jump; Watcom callees keep edx
        m = re.match(r'^(\w+)\s+(.*)$', ins)
        if not m:
            continue
        op, ops = m.group(1), m.group(2)
        dst = ops.split(',')[0].strip()
        if dst not in ('edx', 'dx', 'dl', 'dh'):
            continue
        if op == 'xor' and ops.replace(' ', '') == 'edx,edx':
            return '0'
        if op == 'lea' and dst == 'edx':
            src = ops.split(',', 1)[1].strip()
            # the buffer sprintf writes into (`lea eax, [same]` / push eax)
            for jj in range(k - 1, max(-1, k - 10), -1):
                if body[jj][1].replace(' ', '') == 'leaeax,' + src.replace(' ', ''):
                    return 'BUF'
            return None
        if op == 'mov' and dst == 'edx':
            src = ops.split(',', 1)[1].strip()
            mm = re.match(r'^offset\s+([\w$?@]+)$', src)
            if mm:
                return '(int)&%s' % lst_block.cname(mm.group(1))
            if re.match(r'^[0-9A-F]+h$', src):
                return str(int(src[:-1], 16))
            if re.match(r'^\d+$', src):
                return src
        return None
    return None


def hint_asm(body, k):
    """Format hint of the call sprintf_ at body[k]: ('cdf', N) or ('lab', C name)."""
    for j in range(k - 1, max(-1, k - 14), -1):
        a, ins = body[j]
        m = re.match(r'^call\s+sub_CDF5C$', ins)
        if m:
            for jj in range(j - 1, max(-1, j - 6), -1):
                mm = re.match(r'^mov\s+eax,\s*([0-9A-F]+h|\d+)$', body[jj][1])
                if mm:
                    v = mm.group(1)
                    return ('cdf', int(v[:-1], 16) if v.endswith('h') else int(v))
            return None
        m = re.match(r'^(?:push|mov\s+\w+,)\s*offset\s+([\w$?@]+)$', ins)
        if m and not m.group(1).startswith(('unk_', 'byte_', 'word_', 'dword_')):
            return ('lab', lst_block.cname(m.group(1)))
    return None


def hint_port(stmt, before):
    m = re.search(r'sprintf\(\s*[^,]+,\s*([^,)]+)', stmt)
    fmt = m.group(1).strip() if m else ''
    fmt = re.sub(r'^\(\w+ \*\)', '', fmt).strip()
    if re.match(r'^a\w+$', fmt):
        return ('lab', fmt)
    mm = re.search(r'\b%s = \([^)]*\)sub_CDF5C\((\d+)\)|\b%s = sub_CDF5C\((\d+)\)' % (re.escape(fmt), re.escape(fmt)), before)
    if mm:
        return ('cdf', int(mm.group(1) or mm.group(2)))
    mm = re.search(r'sub_CDF5C\((\d+)\)', stmt)
    if mm:
        return ('cdf', int(mm.group(1)))
    return None


def main():
    asm = load_asm()
    total = done = 0
    for p in sorted(glob.glob('src/game/orion_part_*.c')):
        raw = open(p, 'rb').read()
        crlf = CRLF in raw
        t = raw.replace(CRLF, LF).decode('latin-1')
        heads = list(re.finditer(r'^[A-Za-z_][^\n;]*\b(sub_[0-9A-F]+)\s*\([^;{]*\)\s*\n\{', t, re.M))
        edits = []
        for hi, h in enumerate(heads):
            name = h.group(1)
            s = h.end()
            e = t.index('\n}\n', s)
            body = t[s:e]
            sps = list(re.finditer(r'\b(v\d+) = sprintf\(([^;]*)\);', body))
            if not sps or name not in asm:
                continue
            ab = asm[name]
            calls = [k for k, (a, ins) in enumerate(ab) if re.match(r'^call\s+sprintf_$', ins)]
            ahints = [hint_asm(ab, k) for k in calls]
            allp = list(re.finditer(r'\bsprintf\(', body))
            for m in sps:
                v = m.group(1)
                # uses of the high half up to the next assignment of v
                rest = body[m.end():]
                stop = re.search(r'\b(?:%s|(?:S?HIDWORD|S?WORD2)\(%s\)) = ' % (v, v), rest)
                span = rest[:stop.start()] if stop else rest
                uses = list(re.finditer(r'\b(S?HIDWORD|S?WORD2)\(%s\)' % v, span))
                if not uses:
                    continue
                total += 1
                ph = hint_port(m.group(0), body[max(0, m.start() - 400):m.start()])
                k = None
                if ph and ahints.count(ph) == 1:
                    k = calls[ahints.index(ph)]
                elif len(allp) == len(calls):
                    k = calls[[x.start() for x in allp].index(m.start() + m.group(0).index('sprintf('))]
                val = edx_before(ab, k) if k is not None else None
                where = '%s %s %s' % (p.split('\\')[-1], name, v)
                if val is None:
                    print('?? %s: edx unknown (hint %s, asm call %s)' % (where, ph, ab[k][0] if k is not None else '-'))
                    continue
                if val == 'BUF':
                    buf = re.match(r'sprintf\(\s*([^,]+),', m.group(0)[m.group(0).index('sprintf('):]).group(1).strip()
                    val = '(int)(intptr_t)%s' % buf
                done += 1
                print('%s: edx = %s (asm %s)' % (where, val, ab[k][0]))
                for u in uses:
                    rep = val if u.group(1).endswith('HIDWORD') else '(int16_t)(%s)' % val
                    edits.append((s + m.end() + u.start(), s + m.end() + u.end(), rep))
        if fix and edits:
            for a, b, r in sorted(edits, reverse=True):
                t = t[:a] + r + t[b:]
            b = t.encode('latin-1')
            open(p, 'wb').write(b.replace(LF, CRLF) if crlf else b)
    print('sites %d, resolved %d' % (total, done))


if __name__ == '__main__':
    main()
