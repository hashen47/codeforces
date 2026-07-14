@echo off

g++ -pedantic -std=c++17 -Wall -Wextra -Werror -o bin\main.exe src\main.cpp
.\bin\main.exe < data\input.txt
