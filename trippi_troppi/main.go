package main

import (
	"os"
	"fmt"
	"bufio"
	"strings"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin) 

	scanner.Scan()
	rounds, _ := strconv.Atoi(scanner.Text())

	for i := 0; i < rounds; i++ {
		scanner.Scan()

		for _, word := range strings.Split(scanner.Text(), " ") {
			fmt.Printf("%c", word[0])
		}
		fmt.Println()
	}
}
