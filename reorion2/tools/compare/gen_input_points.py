"""gen_input_points.py LST - wave 183.

Lists the places where the original game reads the outside world, from the IDA
listing (Orion2.exe.lst): every `lodsd` right after `mov esi, 46Ch` (BIOS tick) -
the address of the next instruction, where EAX holds the tick - and the entry of
the accessor functions whose return value is an input (mouse, keys, time, AIL ms).
Prints a C table for my DOSBox (engine.cpp GAMEREC): IDA addresses (+0x224000 at
run time).
"""
import re
import sys

FUNCS = [
    # mouse: position, click latch, current buttons (INT 33h fn 3)
    ('sub_123ABA', 'mouse x'), ('sub_123AE7', 'mouse y'),
    ('sub_123BC1', 'click x'), ('sub_123BEE', 'click y'), ('sub_123C1B', 'click buttons'),
    ('sub_123C48', 'click flag 2'), ('sub_123C84', 'click flag'), ('sub_124075', 'buttons now'),
    # keys
    ('sub_12C392', 'key ready'), ('sub_12C2E1', 'key read'), ('sub_12C35B', 'key peek'),
    # AIL millisecond counter
    ('sub_149B10', 'ail ms'), ('sub_149B30', 'ail ms 2'),
]


def main():
    lines = open(sys.argv[1], encoding='latin1').read().splitlines()
    addr = re.compile(r'^\w+:([0-9A-F]{8})\s+(.*)$')
    ticks = []
    pending = False
    after_lodsd = False
    for ln in lines:
        m = addr.match(ln)
        if not m:
            continue
        a, ins = int(m.group(1), 16), m.group(2).strip()
        if not ins or ins.startswith(';') or ins.endswith(':') or ' proc' in ins or ' endp' in ins:
            continue
        if after_lodsd:
            ticks.append(a)
            after_lodsd = False
        if re.match(r'mov\s+esi,\s*46Ch', ins):
            pending = True
        elif pending and ins.startswith('lodsd'):
            after_lodsd = True
            pending = False
        elif pending and not ins.startswith(('push', 'mov', 'pop')):
            pending = False
    entries = {}
    for ln in lines:
        m = addr.match(ln)
        if not m:
            continue
        for name, _ in FUNCS:
            if re.match(r'%s\s+proc\b' % name, m.group(2).strip()):
                entries[name] = int(m.group(1), 16)
    print('// tick reads: EAX after lodsd from 0x46C (IDA addresses)')
    print('static const uint32_t kTickPoints[] = { %s };' % ', '.join('0x%X' % a for a in ticks))
    print('// accessor functions: EAX at their return is the input (IDA entry addresses)')
    print('static const struct { uint32_t entry; const char* what; } kInputFuncs[] = {')
    for name, what in FUNCS:
        print('    { 0x%X, "%s" },   // %s' % (entries.get(name, 0), what, name))
    print('};')


if __name__ == '__main__':
    main()
