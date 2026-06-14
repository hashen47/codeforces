build:
	gcc -ggdb -pedantic -std=c11 -Wall -Werror -Wextra -o bin/main src/main.c

run: build
	cat data/input.txt | ./bin/main
