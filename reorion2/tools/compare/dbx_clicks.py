"""Run the original under my DOSBox with a list of clicks and keep the frames.

New game with `c` (like REORION2_SENDKEY=67; DBX_MENU_KEY=h picks another
main-menu key), then the clicks; each click
is x,y@Mcycles after the key (the port's @ms timing is different - the
emulated CPU is slower). The last frame is copied to <out>/last.raw.

usage: python tools/compare/dbx_clicks.py <out_dir> <stop_Mcycles> x,y@M [x,y@M ...]
example: python tools/compare/dbx_clicks.py C:/tmp/dbx_leaders 260 275,258@24 48,446@60 35,47@110 590,437@160
Never uses the DOSBox of C:/prenos/fixDosBoxMC2.
"""
import os
import shutil
import subprocess
import sys

DOSBOX = r'C:\prenos\dosbox-x-reorion2\bin\x64\Release\dosbox-x.exe'
CONF = r'C:\prenos\reorion2\reorion2\tools\compare\moo2_sondy.conf'


def main():
    out, stop = sys.argv[1], int(sys.argv[2])
    menu_key = os.environ.get('DBX_MENU_KEY', 'c')   # main-menu key (c = continue, h = hall of fame, ...)
    os.makedirs(out, exist_ok=True)
    for f in os.listdir(out):
        os.remove(os.path.join(out, f))
    lines = ['OUTPUT file=%s/log.txt' % out,
             'SENDKEY   cond=cycle_ge:40000000 key=esc',
             'SENDKEY   cond=cycle_ge:90000000 key=esc',
             'SENDKEY   cond=eip:0x002A56F2 key=%s' % menu_key]
    for k, c in enumerate(sys.argv[3:]):
        xy, m = c.split('@')
        if ',' not in xy:            # key@M: a key (letters, backspace, enter, esc ...)
            lines.append('SENDKEY after=0x002A56F2 delay=%d key=%s label=K%d' % (int(float(m) * 1000000), xy, k))
            continue
        x, y = xy.split(',')
        hold = 4000000
        if ':' in m:                 # x,y@M:0 = move only (hover)
            m, h = m.split(':')
            hold = int(h)
        lines.append('SENDCLICK after=0x002A56F2 delay=%d x=%s y=%s hold=%d label=C%d'
                     % (int(float(m) * 1000000), x, y, hold, k))
    lines.append('DUMPFRAME cond=eip:0x00349814 framebuf=0x452044 width=640 height=480 dir=%s' % out)
    lines.append('STOP cond=cycle_ge:%d' % (stop * 1000000))
    cfg = os.path.join(out, 'run.cfg')
    open(cfg, 'w').write('\n'.join(lines) + '\n')
    env = dict(os.environ, DOSBOX_CTL_FILE=cfg)
    p = subprocess.Popen([DOSBOX, '-conf', CONF], env=env)
    try:
        p.wait(timeout=600)
    except subprocess.TimeoutExpired:
        p.kill()
        print('killed')
    frames = sorted(f for f in os.listdir(out) if f.startswith('frame_') and f.endswith('.raw'))
    if frames:
        shutil.copy(os.path.join(out, frames[-1]), os.path.join(out, 'last.raw'))
    print('frames: %d' % len(frames))


if __name__ == '__main__':
    main()
