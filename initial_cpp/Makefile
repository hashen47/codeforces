build:
	g++ -std=c++17 -O2 -Wall -Werror -o main main.cpp

test: build
	cat tests.txt | ./main

run: build
	./main
