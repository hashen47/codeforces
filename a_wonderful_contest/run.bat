@echo off

g++ -Wall -Werror -Wextra -pedantic -std=c++17 -o bin\main.exe src\main.cpp
.\bin\main.exe < data\input.txt
