@echo off
REM Stahne a rozbali oficialni SDL3 "devel VC" balicek (hlavicky + .lib + .dll)
REM primo do third_party\SDL3 - zadny vcpkg, zadny CMake/Ninja/7zip toolchain.
REM
REM POZNAMKA k firewallu: pouziva se PowerShell (Invoke-WebRequest), ktery na
REM rozdil od curl.exe pouziva systemovy Windows certifikat store - pokud
REM firemni SSL inspekce funguje v prohlizeci, mela by fungovat i tady.

setlocal enabledelayedexpansion

REM Uprav pri vydani novejsi SDL3 verze (zkontroluj nazev assetu na
REM https://github.com/libsdl-org/SDL/releases - hleda se "*-VC.zip").
set SDL_VERSION=3.4.8
set SDL_URL=https://github.com/libsdl-org/SDL/releases/download/release-%SDL_VERSION%/SDL3-devel-%SDL_VERSION%-VC.zip

set SCRIPT_DIR=%~dp0
set PROJECT_DIR=%SCRIPT_DIR%..
set THIRD_PARTY_DIR=%PROJECT_DIR%\third_party
set SDL_DEST=%THIRD_PARTY_DIR%\SDL3
set TMP_ZIP=%TEMP%\SDL3-devel-%SDL_VERSION%-VC.zip
set TMP_EXTRACT=%TEMP%\sdl3_extract_%RANDOM%

if exist "%SDL_DEST%\include\SDL3\SDL.h" (
    echo SDL3 uz je pripraveny v "%SDL_DEST%".
    goto :done
)

echo Stahuji SDL3 %SDL_VERSION% ^(devel VC balicek^)...
echo   z: %SDL_URL%
powershell -NoProfile -Command "try { Invoke-WebRequest -Uri '%SDL_URL%' -OutFile '%TMP_ZIP%' -UseBasicParsing } catch { Write-Error $_; exit 1 }"
if errorlevel 1 (
    echo.
    echo Stahovani selhalo. Zkus stahnout rucne v prohlizeci a ulozit jako:
    echo     %TMP_ZIP%
    echo pak tento skript spust znovu - rozbaleni uz probehne z lokalniho souboru.
    if not exist "%TMP_ZIP%" exit /b 1
)

echo Rozbaluji...
if not exist "%THIRD_PARTY_DIR%" mkdir "%THIRD_PARTY_DIR%"
if exist "%TMP_EXTRACT%" rmdir /s /q "%TMP_EXTRACT%"
powershell -NoProfile -Command "Expand-Archive -Path '%TMP_ZIP%' -DestinationPath '%TMP_EXTRACT%' -Force"
if errorlevel 1 (
    echo Rozbaleni selhalo - zkontroluj, ze stazeny soubor neni poskozeny/nekompletni.
    exit /b 1
)

REM Archiv obsahuje jednu vnorenou slozku "SDL3-<verze>\..." - najdeme ji
REM a presuneme jeji obsah primo do third_party\SDL3.
if exist "%SDL_DEST%" rmdir /s /q "%SDL_DEST%"
for /d %%D in ("%TMP_EXTRACT%\SDL3-*") do (
    move "%%D" "%SDL_DEST%" >nul
)

if not exist "%SDL_DEST%\include\SDL3\SDL.h" (
    echo Neco se nepovedlo - "%SDL_DEST%\include\SDL3\SDL.h" neexistuje.
    echo Zkontroluj obsah "%TMP_EXTRACT%" rucne.
    exit /b 1
)

rmdir /s /q "%TMP_EXTRACT%" 2>nul
del /q "%TMP_ZIP%" 2>nul

:done
echo.
echo Hotovo. SDL3 je pripraveny v:
echo   %SDL_DEST%\include\SDL3\SDL.h
echo   %SDL_DEST%\lib\x64\SDL3.lib + SDL3.dll
echo   %SDL_DEST%\lib\x86\SDL3.lib + SDL3.dll
echo.
echo reorion2.vcxproj uz na tyto cesty ukazuje (AdditionalIncludeDirectories /
echo AdditionalLibraryDirectories / AdditionalDependencies) a po buildu
echo automaticky zkopiruje SDL3.dll vedle .exe - staci normalne buildnout.

endlocal
