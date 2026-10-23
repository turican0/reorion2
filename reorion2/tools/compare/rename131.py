"""Wave 185: rename the definitions of game functions the 1.50 hooks wrap: X -> X_131 (the 1.31 body); the
wrapper X lives in src/game150/orion150_hooks.c. Idempotent.

usage: python tools/compare/rename131.py NAME [NAME ...]
"""
import glob
import re
import sys

files = sorted(glob.glob('src/game/orion_part_*.c')) + ['src/game/link_stubs.c']
for name in sys.argv[1:]:
    done = False
    for p in files:
        raw = open(p, 'rb').read()
        crlf = b'\r\n' in raw
        t = raw.replace(b'\r\n', b'\n').decode('latin-1')
        if re.search(r'(?m)^[^\n;/#]*?\b%s_131\s*\((?:[^()]|\([^()]*\))*\)\s*\n\{' % re.escape(name), t):
            print('%s already renamed (%s)' % (name, p))
            done = True
            break
        m = re.search(r'(?m)^([^\n;/#]*?\b)%s(\s*\((?:[^()]|\([^()]*\))*\)\s*\n\{)' % re.escape(name), t)
        if not m:
            continue
        t = t[:m.start()] + m.group(1) + name + '_131' + m.group(2) + t[m.end():]
        b = t.encode('latin-1')
        open(p, 'wb').write(b.replace(b'\n', b'\r\n') if crlf else b)
        print('%s -> %s_131 in %s' % (name, name, p))
        done = True
        break
    if not done:
        print('%s: definition NOT FOUND' % name)
