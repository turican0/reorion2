@echo off
REM Jednorazova priprava vcpkg pro tento projekt (spustit jednou na stroji).
REM Po tomto kroku Visual Studio pri kazdem buildu samo stahne a zkompiluje
REM SDL3 podle vcpkg.json v korenu repozitare - neni treba nic dalsiho.

setlocal

REM Kam se vcpkg nainstaluje. Klidne zmen, pokud uz vcpkg mas jinde -
REM v tom pripade jen preskoc klonovani a rovnou nastav VCPKG_ROOT.
set VCPKG_DIR=%~dp0..\..\vcpkg

if exist "%VCPKG_DIR%\vcpkg.exe" (
    echo vcpkg uz je pripraveny v "%VCPKG_DIR%".
    goto :integrate
)

if not exist "%VCPKG_DIR%" (
    echo Klonuji vcpkg do "%VCPKG_DIR%"...
    git clone https://github.com/microsoft/vcpkg.git "%VCPKG_DIR%"
    if errorlevel 1 (
        echo Klonovani selhalo - zkontroluj, ze mas nainstalovany git.
        exit /b 1
    )
)

echo Bootstrapuji vcpkg...
call "%VCPKG_DIR%\bootstrap-vcpkg.bat" -disableMetrics
if errorlevel 1 (
    echo Bootstrap selhal.
    exit /b 1
)

:integrate
echo Registruji vcpkg do Visual Studia (jednorazove, plati pro vsechny projekty na tomto stroji)...
"%VCPKG_DIR%\vcpkg.exe" integrate install

echo.
REM Poznamka: verze cmake/7zip/ninja se meni s aktualizacemi vcpkg samotneho
REM (scripts\vcpkg-tools.json) a verze SDL3 s bumpnutim portu - pokud po case
REM vcpkg zacne chtit jiny soubor, oprav URL/nazvy v teto sekci podle chyby
REM v Error listu (presny ocekavany nazev pozna z hlasky "won't retry
REM download from ...").
echo Kontroluji rucne stahovane assety (cmake/7zip/ninja/sdl3 zdrojaky)...
echo Pokud firewall blokuje automaticke stahovani, staz tyto soubory na
echo jinem pripojeni a poloz je (klidne pod puvodnim nazvem z URL) do
echo "%VCPKG_DIR%\downloads\" - skript je sam prejmenuje na nazev, ktery
echo vcpkg interne ocekava.

set DL=%VCPKG_DIR%\downloads
if not exist "%DL%" mkdir "%DL%"

call :ensure_asset "%DL%\cmake-4.3.3-windows-x86_64.zip" "%DL%\cmake-4.3.3-windows-x86_64.zip" "https://github.com/Kitware/CMake/releases/download/v4.3.3/cmake-4.3.3-windows-x86_64.zip"
REM POZOR: spravny nazev je "7z2602-x64.7z.exe" (ne "7z2602-x64.exe"),
REM ocekavana velikost 1 657 896 B - jinak jde o starou/spatne pojmenovanou kopii.
call :ensure_asset "%DL%\7z2602-x64.7z.exe" "%DL%\7z2602-x64.exe" "https://github.com/ip7z/7zip/releases/download/26.02/7z2602-x64.exe"
call :ensure_asset "%DL%\ninja-win-1.13.2.zip" "%DL%\ninja-win.zip" "https://github.com/ninja-build/ninja/releases/download/v1.13.2/ninja-win.zip"
call :ensure_asset "%DL%\libsdl-org-SDL-release-3.4.12.tar.gz" "%DL%\SDL-release-3.4.12.tar.gz" "https://github.com/libsdl-org/SDL/archive/release-3.4.12.tar.gz"
call :ensure_asset "%DL%\7zr.exe" "%DL%\7zr.exe" "https://github.com/ip7z/7zip/releases/download/26.02/7zr.exe"

goto :after_assets

:ensure_asset
if exist "%~1" (
    echo   [OK]     %~nx1
    goto :eof
)
if exist "%~2" (
    echo   [PREJMENOVAVAM] %~nx2  --^>  %~nx1
    copy /y "%~2" "%~1" >nul
    goto :eof
)
echo   [CHYBI]  %~nx1
echo            staz rucne z: %~3
echo            uloz do:      %~1
goto :eof

:after_assets

echo.
echo Hotovo. Ted staci projekt otevrit ve Visual Studiu a normalne buildnout -
echo SDL3 se podle vcpkg.json stahne a zkompiluje automaticky (prvni build
echo bude pomalejsi, dalsi uz jsou rychle - vcpkg vysledky cachuje).
echo.
echo Pokud mas vcpkg uz nainstalovany jinde, staci jen jednou spustit:
echo     cesta\k\vcpkg\vcpkg.exe integrate install
echo a tento skript uz nepotrebujes.

endlocal
