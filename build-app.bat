@echo off 
set BAT_BASE_PATH=%~dp0
set PRJ_BASE_PATH=%BAT_BASE_PATH%

MD %PRJ_BASE_PATH%\bin
clang -I%PRJ_BASE_PATH%\filler-app\include -I%PRJ_BASE_PATH%\filler-core\include -o %PRJ_BASE_PATH%\bin\app.exe %PRJ_BASE_PATH%filler-app\src\*.c -L %PRJ_BASE_PATH%\bin -l filler-core