# Wave 183: reorion2 versus the original on a record_dbx.ps1 session, turn by turn.
# For turn n: the port loads archived save n (CONTINUE), plays the steps the player
# made in the original until save n+1 (REORION2_CHAIN, pressed when the structures
# equal the original's), and its autosave is compared with the original's save n+1
# (bytes 0x257-0x25A = the RNG seed, taken from the running generator - skipped).
#
#   .\test_port_chain.ps1 -Name regression001 [-Turns 1,2,3] [-Secs 300]
param(
    [Parameter(Mandatory = $true)][string]$Name,
    [int[]]$Turns = @(),
    [int]$Secs = 300,
    [string]$Exe = "C:\prenos\reorion2\reorion2\x64\Debug\reorion2.exe"
)
$ErrorActionPreference = "Stop"
$sess = "C:\prenos\reorion2Data\$Name"
$all = Get-Content "$sess\record.cfg"
$marks = @{}
foreach ($m in ($all | Select-String -Pattern "^# SAVE n=(\d+) slot=\S+ file=(\S+) after=(\d+)")) {
    $marks[[int]$m.Matches[0].Groups[1].Value] = @{ file = $m.Matches[0].Groups[2].Value; after = [int]$m.Matches[0].Groups[3].Value }
}
$steps = @($all | Where-Object { $_ -match '^SENDCLICK' })
if (-not $Turns.Count) { $Turns = 1..($marks.Count - 1) }
$summary = @()
foreach ($n in $Turns) {
    if (-not $marks.ContainsKey($n) -or -not $marks.ContainsKey($n + 1)) { "turn ${n}: no saves $n/$($n + 1)"; continue }
    $a = $marks[$n].after; $b = $marks[$n + 1].after
    $run = "$sess\port\turn$n"
    New-Item -ItemType Directory -Force $run | Out-Null
    Get-ChildItem $run -File | ForEach-Object { [IO.File]::Delete($_.FullName) }
    Copy-Item "$sess\MOX.SET" "$run\MOX.SET" -Force
    Copy-Item "$sess\saves\$($marks[$n].file)" "$run\SAVE10.GAM" -Force
    Set-Content -Encoding ascii "$run\chain.cfg" ($steps[$a..($b - 1)])
    foreach ($v in "REORION2_CLICK", "REORION2_INPUT_LOG", "REORION2_BLIT_DUMP_DIR", "REORION2_RNG_LOG", "REORION2_DUMP_DIR",
                   "REORION2_DUMP_EVERY_MS", "REORION2_RECORD", "REORION2_REPLAY", "REORION2_REPLAY_EXTRACT",
                   "REORION2_REPLAY_FAST", "REORION2_REPLAY_FRAMES") { [Environment]::SetEnvironmentVariable($v, $null) }
    $env:REORION2_SKIPINTRO = "1"
    $env:REORION2_SENDKEY = "67:9000"
    $env:REORION2_VIDEO_AUDIO = "0"
    $env:REORION2_IGNORE_REAL_INPUT = "1"
    $env:REORION2_CHAIN = "$run\chain.cfg"
    $env:REORION2_CHAIN_EXIT = "1"
    New-Item -ItemType Directory -Force "$run\frames" | Out-Null
    $env:REORION2_CHAIN_FRAMES = "$run\frames"
    $p = Start-Process $Exe -WorkingDirectory $run -PassThru -RedirectStandardError "$run\stderr.txt"
    if (-not $p.WaitForExit($Secs * 1000)) { Stop-Process $p -Force; $how = "killed after $Secs s" } else { $how = "exit $($p.ExitCode)" }
    foreach ($v in "REORION2_CHAIN", "REORION2_CHAIN_EXIT", "REORION2_CHAIN_FRAMES", "REORION2_SENDKEY", "REORION2_SKIPINTRO") { [Environment]::SetEnvironmentVariable($v, $null) }
    $log = Get-Content "$run\chain_log.txt" -ErrorAction SilentlyContinue
    $ok = @($log | Where-Object { $_ -match '^OK ' }).Count
    $diffs = @($log | Where-Object { $_ -match '^DIFF ' })
    $x = [IO.File]::ReadAllBytes("$sess\saves\$($marks[$n + 1].file)")
    $y = [IO.File]::ReadAllBytes("$run\SAVE10.GAM")
    $d = 0; $first = @()
    for ($k = 0; $k -lt [Math]::Min($x.Length, $y.Length); $k++) {
        if ($k -ge 0x257 -and $k -le 0x25A) { continue }
        if ($x[$k] -ne $y[$k]) { $d++; if ($first.Count -lt 6) { $first += ("{0:X}:{1:X2}/{2:X2}" -f $k, $x[$k], $y[$k]) } }
    }
    $save = if ($d -eq 0) { "save $($n + 1) identical" } else { "save $($n + 1) differs in $d bytes (orig/port): $($first -join ' ')" }
    $line = "turn ${n}: steps $($a + 1)-$b, $ok OK, $($diffs.Count) DIFF, $how, $save"
    $line
    $diffs | Select-Object -First 3 | ForEach-Object { "    $_" }
    $summary += $line
}
"----"
$summary
