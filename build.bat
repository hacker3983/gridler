@echo off
echo Building grilder...
gcc gridler.c -lmingw32 -lSDL2main -lSDL2 -o gridler
echo Running grilder...
gridler.exe
