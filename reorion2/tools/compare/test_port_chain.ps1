# Wave 183: reorion2 versus the original on a record_dbx.ps1 session.
# The port loads archived save -FromSave (CONTINUE) and plays every step the player
# made after it in one go (REORION2_CHAIN: pressed when the 10 structures equal the
# original's at that press, the original's RNG written before it). Each autosave
# the port writes is compared with the original's next save, in order (bytes
# 0x257-0x25A = the RNG seed, taken from the running generator, are skipped).
# A load is not a turn boundary: the autosave is written while the turn is still
# being processed, so only one continuous run from a save is comparable.
#
#   .\test_port_chain.ps1 -Name regression001 [-FromSave 1] [-Secs 1800]
#
# Output: C:\prenos\reorion2Data\<Name>\port\ - chain_log.txt (OK / DIFF / LATE /
# SAVE per step), saves\, frames\ (<label>_a.raw before each press, _b after).
param(
    [Parameter(Mandatory = $true)][string]$Name,
    [int]$FromSave = 1,
    [int]$Secs = 1800,
    [string]$Exe = "C:\prenos\reorion2\reorion2\x64\Debug\reorion2.exe"
)
$ErrorActionPreference = "Stop"
$sess = "C:\prenos\reorion2Data\$Name"
$all = Get-Content "$sess\record.cfg"
$m = $all | Select-String -Pattern "^# SAVE n=$FromSave slot=\S+ file=(\S+) after=(\d+)" | Select-Object -First 1
if (-not $m) { throw "no save $FromSave in record.cfg" }
$after = [int]$m.Matches[0].Groups[2].Value
$steps = @($all | Where-Object { $_ -match '^SENDCLICK' })

$run = "$sess\port"
if (Test-Path $run) { Get-ChildItem $run -File -Recurse | ForEach-Object { [IO.File]::Delete($_.FullName) } }
New-Item -ItemType Directory -Force $run, "$run\saves", "$run\frames" | Out-Null
Copy-Item "$sess\MOX.SET" "$run\MOX.SET" -Force
Copy-Item "$sess\saves\$($m.Matches[0].Groups[1].Value)" "$run\SAVE10.GAM" -Force
if (Test-Path "$sess\before\lastrace.rac") { Copy-Item "$sess\before\lastrace.rac" "$run\" -Force }
Set-Content -Encoding ascii "$run\chain.cfg" ($steps[$after..($steps.Count - 1)])

foreach ($v in "REORION2_CLICK", "REORION2_INPUT_LOG", "REORION2_BLIT_DUMP_DIR", "REORION2_RNG_LOG", "REORION2_DUMP_DIR",
               "REORION2_DUMP_EVERY_MS", "REORION2_RECORD", "REORION2_REPLAY", "REORION2_REPLAY_EXTRACT",
               "REORION2_REPLAY_FAST", "REORION2_REPLAY_FRAMES") { [Environment]::SetEnvironmentVariable($v, $null) }
$env:REORION2_SKIPINTRO = "1"
$env:REORION2_SENDKEY = "67:9000"
$env:REORION2_VIDEO_AUDIO = "0"
$env:REORION2_IGNORE_REAL_INPUT = "1"
$env:REORION2_CHAIN = "$run\chain.cfg"
$env:REORION2_CHAIN_EXIT = "1"
$env:REORION2_CHAIN_FRAMES = "$run\frames"
$env:REORION2_CHAIN_SAVES = "$run\saves"
try {
    $p = Start-Process $Exe -WorkingDirectory $run -PassThru -RedirectStandardError "$run\stderr.txt"
    if (-not $p.WaitForExit($Secs * 1000)) { Stop-Process $p -Force; $how = "killed after $Secs s" } else { $how = "exited" }
} finally {
    foreach ($v in "REORION2_CHAIN", "REORION2_CHAIN_EXIT", "REORION2_CHAIN_FRAMES", "REORION2_CHAIN_SAVES", "REORION2_SENDKEY", "REORION2_SKIPINTRO") {
        [Environment]::SetEnvironmentVariable($v, $null)
    }
}

$log = Get-Content "$run\chain_log.txt" -ErrorAction SilentlyContinue
"port $how; steps $($after + 1)-$($steps.Count): " + @($log | Where-Object { $_ -match '^OK ' }).Count + " OK, " +
    @($log | Where-Object { $_ -match '^DIFF ' }).Count + " DIFF, " + @($log | Where-Object { $_ -match '^LATE ' }).Count + " LATE"
$log | Where-Object { $_ -match '^DIFF ' } | Select-Object -First 1 | ForEach-Object { "first: $_" }
$rec = Get-ChildItem "$sess\saves" -File | Sort-Object Name | Select-Object -Skip $FromSave
$rep = Get-ChildItem "$run\saves" -File | Sort-Object Name
for ($i = 0; $i -lt [Math]::Max($rec.Count, $rep.Count); $i++) {
    $a = if ($i -lt $rec.Count) { $rec[$i] } else { $null }
    $b = if ($i -lt $rep.Count) { $rep[$i] } else { $null }
    if (-not $a -or -not $b) { "save $($FromSave + $i + 1): " + $(if ($a) { "port did not write it" } else { "extra port save $($b.Name)" }); continue }
    $x = [IO.File]::ReadAllBytes($a.FullName); $y = [IO.File]::ReadAllBytes($b.FullName)
    $d = 0; $first = @()
    for ($k = 0; $k -lt [Math]::Min($x.Length, $y.Length); $k++) {
        if ($k -ge 0x257 -and $k -le 0x25A) { continue }
        if ($x[$k] -ne $y[$k]) { $d++; if ($first.Count -lt 5) { $first += ("{0:X}:{1:X2}/{2:X2}" -f $k, $x[$k], $y[$k]) } }
    }
    "save $($FromSave + $i + 1): " + $(if ($d -eq 0) { "identical" } else { "differs in $d bytes (orig/port) $($first -join ' ')" })
}
