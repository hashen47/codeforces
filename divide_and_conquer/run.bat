@echo off

g++ -pedantic -std=c++17 -Wall -Werror -Wextra -o bin\main.exe src\main.cpp
.\bin\main.exe < data\input.txt
