build:
	g++ -std=c++17 -Wall -Werror -pedantic -pedantic-errors -O2 -o main main.cpp

test: build
	cat tests.txt | ./main

run: build
	./main
