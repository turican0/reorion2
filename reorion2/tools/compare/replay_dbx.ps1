# Wave 183: replays a record_dbx.ps1 session in my DOSBox-X and compares the saves it
# writes with the recorded ones.
#
#   .\replay_dbx.ps1 -Name regression001 [-Secs 900] [-Frames]
#
# Output: C:\prenos\reorion2Data\<Name>\replay\ (stderr, saves, frames with -Frames).
# The game dir saves are backed up and restored; the start state is the session's
# before\ (the game dir as it was when the record started).
#   -FromSave n  start from archived save n (CONTINUE), then the steps recorded after it
param(
    [Parameter(Mandatory = $true)][string]$Name,
    [int]$Secs = 900,
    [int]$FromSave = 0,
    [switch]$Frames,
    [switch]$StepFrames   # frame before each press (<label>_a.raw) and 300 ms after release (_b)
)
$ErrorActionPreference = "Stop"
$game = "C:\prenos\mastori2"
$dbx = "C:\prenos\dosbox-x-reorion2\bin\x64\Release\dosbox-x.exe"
$conf = "C:\prenos\reorion2\reorion2\tools\compare\moo2_sondy.conf"
$sess = "C:\prenos\reorion2Data\$Name"
$out = "$sess\replay"
if (-not (Test-Path "$sess\record.cfg")) { throw "no $sess\record.cfg" }
if (Test-Path $out) { Get-ChildItem $out -File -Recurse | ForEach-Object { [IO.File]::Delete($_.FullName) } }
New-Item -ItemType Directory -Force "$out\saves", "$out\keep" | Out-Null

# back up every small game file (saves, MOX.SET, lastrace.rac, HOF.M2), put the record's
# start state in
$tStart = Get-Date
Get-ChildItem $game -File | Where-Object { $_.Length -lt 1MB -and $_.Extension -ne ".LBX" } | ForEach-Object { Copy-Item $_.FullName "$out\keep\" -Force }
foreach ($f in (Get-ChildItem $game -File | Where-Object { $_.Name -match '^SAVE\d+\.GAM$' })) { [IO.File]::Delete($f.FullName) }
Get-ChildItem "$sess\before" -File | ForEach-Object { Copy-Item $_.FullName "$game\" -Force }

$o = $out.Replace("\", "/")
$lines = @("OUTPUT file=$o/ctl_log.txt", "RECORDINPUT file=$o/saves.txt saves=$($game.Replace('\', '/')) savedir=$o/saves")
if ($Frames) { New-Item -ItemType Directory -Force "$out\frames" | Out-Null; $lines += "DUMPFRAME cond=eip:0x00349814 framebuf=vram width=640 height=480 dir=$o/frames" }
$all = Get-Content "$sess\record.cfg"
$skipSteps = 0
$recSavesSkip = 0
if ($FromSave -gt 0) {
    $m = $all | Select-String -Pattern "^# SAVE n=$FromSave slot=(\S+) file=(\S+) after=(\d+)" | Select-Object -First 1
    if (-not $m) { throw "no save $FromSave in record.cfg" }
    Copy-Item "$sess\saves\$($m.Matches[0].Groups[2].Value)" "$game\SAVE10.GAM" -Force
    $skipSteps = [int]$m.Matches[0].Groups[3].Value
    $recSavesSkip = $FromSave
    # intro skip + CONTINUE, as r2rec.py dbx does
    $lines += "SENDKEY cond=cycle_ge:40000000 key=esc", "SENDKEY cond=cycle_ge:90000000 key=esc",
              "SENDCLICK seq=1 after=0x002A56F2 gapms=1000 key=c holdms=80 settlems=250 timeoutms=5000 label=kload"
}
$lines += ($all | Where-Object { $_ -match '^SENDCLICK' } | Select-Object -Skip $skipSteps)
Set-Content -Encoding ascii "$out\ctl.cfg" $lines
$env:DOSBOX_CTL_FILE = "$out\ctl.cfg"
if ($StepFrames) { New-Item -ItemType Directory -Force "$out\stepframes" | Out-Null; $env:DOSBOX_STEPFRAMES = "$out\stepframes" }
try {
    $p = Start-Process $dbx -ArgumentList "-conf", $conf -PassThru -RedirectStandardError "$out\dosbox_stderr.txt"
    $last = (Select-String -Path "$sess\record.cfg" -Pattern '^SENDCLICK').Count
    $t0 = Get-Date
    while (-not $p.HasExited -and ((Get-Date) - $t0).TotalSeconds -lt $Secs) {
        Start-Sleep 2
        if (Select-String -Path "$out\dosbox_stderr.txt" -Pattern "CHAIN done" -Quiet) { Start-Sleep 8; break }
    }
    if (-not $p.HasExited) { Stop-Process $p -Force }
} finally {
    Remove-Item env:DOSBOX_CTL_FILE -ErrorAction SilentlyContinue
    Remove-Item env:DOSBOX_STEPFRAMES -ErrorAction SilentlyContinue
    Start-Sleep 1
    foreach ($f in (Get-ChildItem $game -File)) {
        if (($f.Name -match '^SAVE\d+\.GAM$') -or ($f.LastWriteTime -ge $tStart -and -not (Test-Path (Join-Path "$out\keep" $f.Name)))) { [IO.File]::Delete($f.FullName) }
    }
    Get-ChildItem "$out\keep" -File | ForEach-Object { Copy-Item $_.FullName "$game\" -Force }
}

Select-String -Path "$out\dosbox_stderr.txt" -Pattern "CHAIN done|STUCK|NOLOOP|DIFF" | ForEach-Object { $_.Line }
"steps pressed: " + (Select-String -Path "$out\dosbox_stderr.txt" -Pattern "CHAIN [pk]\d+:").Count + " / $($last - $skipSteps)"
# saves: compare by order
$rec = Get-ChildItem "$sess\saves" -File | Sort-Object Name | Select-Object -Skip $recSavesSkip
$rep = Get-ChildItem "$out\saves" -File | Sort-Object Name
for ($i = 0; $i -lt [Math]::Max($rec.Count, $rep.Count); $i++) {
    $a = if ($i -lt $rec.Count) { $rec[$i] } else { $null }
    $b = if ($i -lt $rep.Count) { $rep[$i] } else { $null }
    if (-not $a -or -not $b) { "save $($i + 1): record $($a.Name) / replay $($b.Name) - missing"; continue }
    $x = [IO.File]::ReadAllBytes($a.FullName); $y = [IO.File]::ReadAllBytes($b.FullName)
    $d = 0; $first = -1
    for ($k = 0; $k -lt [Math]::Min($x.Length, $y.Length); $k++) { if ($x[$k] -ne $y[$k]) { $d++; if ($first -lt 0) { $first = $k } } }
    "save $($i + 1): " + $(if ($d -eq 0 -and $x.Length -eq $y.Length) { "identical" } else { "differs in $d bytes (first at 0x{0:X})" -f $first })
}
