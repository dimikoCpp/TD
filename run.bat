::@echo off
chcp 65001 > NUL

del bin\td.exe 2>NUL

:: компиляция .cpp файлов в .exe
scons

bin\td.exe