#!/usr/bin/env python
# -*- coding: ascii -*-
"""csdata_scan.py - najde tabulky ulozene v KODOVEM segmentu, ktere si funkce
kopiruji instrukci `movsd`/`movsw`/`movsb` do lokalky (barevne rampy, tabulky
velikosti spritu apod.), a rekne, kolik bajtu se doopravdy kopiruje.

Proc to existuje (vlna 89c): IDA u techto adres nema datovy symbol, takze
z nich udela retezec (`asc_81C68 "'!!"`), konstantu nebo cteni z navesti.
V portu pak vznikne objekt SPATNE VELIKOSTI a kopie cte mimo nej:

  vlna 86: dword_81C78 - barevna rampa textu, IDA z prvniho dwordu udelala
           konstantu a druhy nechala jako cteni z navesti
  vlna 89c: asc_81C68 - tabulka CTYR int16_t (velikost spritu podle
           priblizeni), v portu wchar_t[3] = jen sest bajtu

Pouziti:
    python tools/csdata_scan.py                 # jen prehled
    python tools/csdata_scan.py --bytes         # + skutecne bajty z .lst

Cte Debug/diss/Orion2.exe.lst, ktery ma u KAZDEHO radku adresu - samotny .asm
nestaci (IDA tam obcas vypise dvojici hodnot jako `offset jpt_XXXX+0A8h`).
"""

import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
LST = os.path.join(ROOT, 'Debug', 'diss', 'Orion2.exe.lst')
SRC = os.path.join(ROOT, 'src', 'game')

ADDR_RE = re.compile(r'^cseg\d+:([0-9A-F]{8})\s\s(.*)$')
MOVESI_RE = re.compile(r'\bmov\s+esi,\s+offset\s+([A-Za-z_][A-Za-z0-9_]*)')
MOVS_RE = re.compile(r'\b(movsd|movsw|movsb)\b')
LABEL_RE = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*)\s')

MOVS_SIZE = {'movsd': 4, 'movsw': 2, 'movsb': 1}


def load_lines():
    rows = []
    with open(LST, 'rb') as fh:
        for raw in fh:
            line = raw.decode('latin-1').rstrip('\n')
            m = ADDR_RE.match(line)
            if m:
                rows.append((int(m.group(1), 16), m.group(2)))
    return rows


def build_symbols(rows):
    """adresa -> jmeno navesti (prvni sloupec radku)"""
    syms = {}
    for addr, text in rows:
        m = LABEL_RE.match(text)
        if m:
            name = m.group(1)
            if name not in syms:
                syms[name] = addr
    return syms


def collect_sites(rows):
    """Najde `mov esi, offset X` a spocita movs* v nasledujicich radcich."""
    sites = []
    for i, (addr, text) in enumerate(rows):
        m = MOVESI_RE.search(text)
        if not m:
            continue
        sym = m.group(1)
        total = 0
        # Kopirovaci instrukce chodi v jednom bloku hned za nastavenim ESI;
        # povolime par mezilehlych instrukci (lea/mov/call na jine registry).
        gap = 0
        for addr2, text2 in rows[i + 1:i + 12]:
            mm = MOVS_RE.search(text2)
            if mm:
                total += MOVS_SIZE[mm.group(1)]
                gap = 0
            elif total:
                break
            else:
                gap += 1
                if gap > 8:
                    break
        if total:
            sites.append((addr, sym, total))
    return sites


def port_decl(sym):
    """Najde deklaraci symbolu v portu (orion_data.c / orion_common.h)."""
    for fname in ('orion_data.c', 'orion_common.h'):
        path = os.path.join(SRC, fname)
        if not os.path.exists(path):
            continue
        with open(path, 'rb') as fh:
            for line in fh:
                t = line.decode('utf-8', 'replace').strip()
                if re.search(r'\b%s\b\s*(\[|=|;)' % re.escape(sym), t) and not t.startswith('//'):
                    return fname, t
    return None, None


def bytes_at(rows, start, count):
    """Vytahne pole bajtu z .lst od adresy start (jen pro prehled)."""
    out = []
    for addr, text in rows:
        if addr < start:
            continue
        if addr >= start + count:
            break
        body = text.split(';')[0]
        out.append('%08X %s' % (addr, body.strip()))
    return out


# Data ulozena UVNITR kodoveho segmentu maji adresu pod zacatkem dseg.
# Nad touto hranici uz jsou bezne datove symboly (retezce nazvu LBX apod.),
# ktere se kopiruji uplne legitimne a IDA je typuje spravne.
CSEG_LIMIT = 0x170000


def main():
    show_bytes = '--bytes' in sys.argv
    show_all = '--all' in sys.argv
    rows = load_lines()
    syms = build_symbols(rows)
    sites = collect_sites(rows)

    if not show_all:
        sites = [s for s in sites
                 if syms.get(s[1]) is not None and syms[s[1]] < CSEG_LIMIT]

    print('csdata_scan: %d radku s adresou, %d kopirovacich mist'
          '%s' % (len(rows), len(sites),
                  '' if show_all else ' v KODOVEM segmentu (--all = vse)'))
    print('')
    suspect = 0
    for addr, sym, nbytes in sites:
        target = syms.get(sym)
        fname, decl = port_decl(sym)
        flag = ''
        if decl is None:
            flag = '  <-- V PORTU NENI'
            suspect += 1
        else:
            # hruba kontrola velikosti: [N] v deklaraci
            m = re.search(r'\[\s*(\d+)\s*\]', decl)
            if m:
                n = int(m.group(1))
                elem = 1
                if 'int16_t' in decl or 'wchar_t' in decl or '_WORD' in decl:
                    elem = 2
                elif 'int ' in decl or '_DWORD' in decl:
                    elem = 4
                if n * elem < nbytes:
                    flag = '  <-- PORT MA JEN %d B' % (n * elem)
                    suspect += 1
        print('%-16s cil=%s  kopiruje=%d B  %s%s' % (
            sym,
            ('%08X' % target) if target else '?',
            nbytes,
            (decl[:70] if decl else '(nenalezeno)'),
            flag))
        if show_bytes and target:
            for b in bytes_at(rows, target, nbytes):
                print('        %s' % b)
    print('')
    print('podezrelych: %d' % suspect)


if __name__ == '__main__':
    main()
