build:
	g++ -std=c++17 -Wall -Werror -pedantic -pedantic-errors -ggdb -o main main.cpp

test: build
	cat tests.txt | ./main

run: build
	./main
