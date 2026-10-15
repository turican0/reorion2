# Runs the port on a session's GAMEPLAY record (REORION2_GAMEPLAY) and compares it
# with the original: the saves the port writes against the record's saves.
#
#   .\port_gameplay.ps1 -Name regression002 [-FromSave 16] [-Secs 600] [-Out <dir>]
#
# -FromSave n: the port loads the record's save n (as SAVE10.GAM) and continues from
# the TURN that wrote it; the reads per source at that save come from the session's
# savepos.txt (DOSBOX_GR_SAVEPOS, written by replay_dbx.ps1 -Gameplay / record_dbx.ps1).
# Without it the port plays the record from boot.
# Extra REORION2_* variables of the caller (rings, probes) are passed through.
param(
    [Parameter(Mandatory = $true)][string]$Name,
    [int]$FromSave = 0,
    [int]$Secs = 900,
    [string]$Out = ""
)
$ErrorActionPreference = "Stop"
$sess = "C:\prenos\reorion2Data\$Name"
$exe = Join-Path $PSScriptRoot "..\..\x64\Debug\reorion2.exe"
if (-not $Out) { $Out = Join-Path $env:TEMP "reorion2_gameplay_$Name" }
$run = $Out
New-Item -ItemType Directory -Force $run, "$run\frames", "$run\saves" | Out-Null
Get-ChildItem $run -File -Recurse | ForEach-Object { [IO.File]::Delete($_.FullName) }
Get-ChildItem "$sess\before" -File | ForEach-Object { Copy-Item $_.FullName "$run\" -Force }

$set = @{
    REORION2_IGNORE_REAL_INPUT = "1"
    REORION2_GAMEPLAY = "$sess\input.txt"
    REORION2_GAMEPLAY_FRAMES = "$run\frames"
    REORION2_GAMEPLAY_SAVES = "$run\saves"
}
if ($FromSave -gt 0) {
    $save = Get-ChildItem "$sess\saves" -File | Where-Object { $_.Name -match ('^save{0:D3}_' -f $FromSave) } | Select-Object -First 1
    if (-not $save) { throw "save $FromSave is not in $sess\saves" }
    if (-not (Test-Path "$sess\savepos.txt")) { throw "$sess\savepos.txt is missing - run replay_dbx.ps1 -Name $Name -Gameplay" }
    Copy-Item $save.FullName "$run\SAVE10.GAM" -Force
    $set.REORION2_GAMEPLAY_FROM = "$FromSave"
    $set.REORION2_GAMEPLAY_SAVEPOS = "$sess\savepos.txt"
    $set.REORION2_SKIPINTRO = "1"
}
foreach ($v in "REORION2_CLICK", "REORION2_SENDKEY", "REORION2_INPUT_LOG", "REORION2_RECORD", "REORION2_REPLAY",
               "REORION2_CHAIN", "REORION2_CHAIN_FRAMES", "REORION2_CHAIN_SAVES", "REORION2_CHAIN_EXIT") {
    [Environment]::SetEnvironmentVariable($v, $null)
}
foreach ($k in $set.Keys) { [Environment]::SetEnvironmentVariable($k, $set[$k]) }
$t0 = Get-Date
try {
    $p = Start-Process $exe -WorkingDirectory $run -PassThru -RedirectStandardError "$run\stderr.txt"
    # done when three sources ran out (the record ended) or the port exited
    while (-not $p.HasExited -and ((Get-Date) - $t0).TotalSeconds -lt $Secs) {
        Start-Sleep 2
        if ((Select-String -Path "$run\stderr.txt" -Pattern "END source" -ErrorAction SilentlyContinue).Count -ge 3) { Start-Sleep 10; break }
    }
    if (-not $p.HasExited) { Stop-Process $p -Force; "stopped after $([int]((Get-Date) - $t0).TotalSeconds) s" }
    else { "port exited ($($p.ExitCode)) after $([int]((Get-Date) - $t0).TotalSeconds) s" }
} finally {
    foreach ($k in $set.Keys) { [Environment]::SetEnvironmentVariable($k, $null) }
}
Select-String -Path "$run\stderr.txt" -Pattern "GAMEPLAY FROM|END source" | Select-Object -First 2 | ForEach-Object { $_.Line }

# the saves: port <n>_SAVE10.GAM against the record's save<n>_SAVE10.GAM
$rec = @{}
Get-ChildItem "$sess\saves" -File | ForEach-Object { if ($_.Name -match '^save(\d+)_') { $rec[[int]$Matches[1]] = $_.FullName } }
foreach ($f in (Get-ChildItem "$run\saves" -File | Sort-Object Name)) {
    if ($f.Name -notmatch '^(\d+)_') { continue }
    $n = [int]$Matches[1]
    if (-not $rec.ContainsKey($n)) { "save {0}: not in the record" -f $n; continue }
    $a = [IO.File]::ReadAllBytes($rec[$n]); $b = [IO.File]::ReadAllBytes($f.FullName)
    $d = 0; $first = -1
    for ($i = 0; $i -lt [Math]::Min($a.Length, $b.Length); $i++) { if ($a[$i] -ne $b[$i]) { $d++; if ($first -lt 0) { $first = $i } } }
    if ($d -eq 0 -and $a.Length -eq $b.Length) { "save {0}: identical" -f $n }
    else { "save {0}: {1} bytes differ (first 0x{2:X})" -f $n, $d, $first }
}
"run dir: $run"
