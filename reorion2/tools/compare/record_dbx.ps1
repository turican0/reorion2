# Wave 183: a recorded game in the original (my DOSBox-X, RECORDINPUT).
#
#   .\record_dbx.ps1 -Name regression001            play; packs when DOSBox closes
#   .\record_dbx.ps1 -Name regression001 -PackOnly  only pack an existing session
#
# Session dir (outside TEMP): C:\prenos\reorion2Data\<Name>
#   input.txt       GAMEREC: every value the game read from the outside world (tick,
#                   mouse / key accessors, AIL ms, time) - replay_dbx.ps1 -Gameplay
#   record.cfg      every click / key as a SENDCLICK seq=1 chain step (replayable in
#                   DOSBox), "# SAVE" lines mark after which step a save was written
#   saves\          every new version of SAVE1..10.GAM (autosave each turn = SAVE10)
#   before\         every small game file before the session - saves, MOX.SET,
#                   lastrace.rac ("Last Race" reads it), HOF.M2 - restored afterwards
# Pack: <repo>\test\<Name>\<Name>.binz (MC2DATZ1, remc2 datapack): record.cfg,
#       MOX.SET, saves\*, before\ (the game state the record starts from).
param(
    [Parameter(Mandatory = $true)][string]$Name,
    [switch]$PackOnly
)
$ErrorActionPreference = "Stop"
$game = "C:\prenos\mastori2"
$dbx = "C:\prenos\dosbox-x-reorion2\bin\x64\Release\dosbox-x.exe"
$conf = "C:\prenos\reorion2\reorion2\tools\compare\moo2_sondy.conf"
$pack = "C:\prenos\dosbox-x-remc2\mc2replay\datapack.exe"
$sess = "C:\prenos\reorion2Data\$Name"
$repo = Split-Path -Parent (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))
$outDir = Join-Path $repo "test\$Name"

function SmallGameFiles { Get-ChildItem $game -File | Where-Object { $_.Length -lt 1MB -and $_.Extension -ne ".LBX" } }

if (-not $PackOnly) {
    if (Test-Path "$sess\record.cfg") { throw "$sess\record.cfg exists - use another name or -PackOnly" }
    New-Item -ItemType Directory -Force "$sess\saves", "$sess\before", "$sess\frames", "$sess\grframes" | Out-Null
    $t0 = Get-Date
    SmallGameFiles | ForEach-Object { Copy-Item $_.FullName "$sess\before\" -Force }
    Copy-Item "$game\MOX.SET" "$sess\MOX.SET" -Force
    $s = $sess.Replace("\", "/")
    Set-Content -Encoding ascii "$sess\ctl.cfg" @(
        "OUTPUT file=$s/ctl_log.txt",
        "RECORDINPUT file=$s/record.cfg saves=$($game.Replace('\', '/')) savedir=$s/saves frames=$s/frames",
        "GAMEREC file=$s/input.txt frames=$s/grframes"
    )
    $env:DOSBOX_CTL_FILE = "$sess\ctl.cfg"
    $p = Start-Process $dbx -ArgumentList "-conf", $conf -PassThru -RedirectStandardError "$sess\dosbox_stderr.txt"
    "DOSBox pid $($p.Id) - recording to $sess"
    $p.WaitForExit()
    [Environment]::SetEnvironmentVariable("DOSBOX_CTL_FILE", $null)
    # the game dir gets its state back: files the session created go, the rest is copied back
    foreach ($f in (Get-ChildItem $game -File)) {
        if ($f.LastWriteTime -ge $t0 -and -not (Test-Path (Join-Path "$sess\before" $f.Name))) { [IO.File]::Delete($f.FullName) }
    }
    Get-ChildItem "$sess\before" -File | ForEach-Object { Copy-Item $_.FullName "$game\" -Force }
}

New-Item -ItemType Directory -Force $outDir | Out-Null
$files = @("record.cfg", "input.txt", "MOX.SET") + (Get-ChildItem "$sess\saves" -File | Sort-Object Name | ForEach-Object { "saves/" + $_.Name })
$files += (Get-ChildItem "$sess\before" -File | Where-Object { $_.Name -match '^(SAVE\d+\.GAM|MOX\.SET|lastrace\.rac|HOF\.M2)$' } | ForEach-Object { "before/" + $_.Name })
& $pack pack "$outDir\$Name.binz" $sess @files
& $pack check "$outDir\$Name.binz" $sess
# the frames the player saw (<label>_a before each press, _b 300 ms after release) - own pack
$fr = @(Get-ChildItem "$sess\frames" -File -ErrorAction SilentlyContinue | Sort-Object Name | ForEach-Object { "frames/" + $_.Name })
$fr += @(Get-ChildItem "$sess\grframes" -File -Filter *.raw -ErrorAction SilentlyContinue | Sort-Object Name | ForEach-Object { "grframes/" + $_.Name })
if ($fr.Count) { & $pack pack "$outDir\${Name}_frames.binz" $sess @fr | Select-Object -Last 1 }
"steps: " + (Select-String -Path "$sess\record.cfg" -Pattern '^SENDCLICK').Count + ", saves: " + (Get-ChildItem "$sess\saves" -File).Count
