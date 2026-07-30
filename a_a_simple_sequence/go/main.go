package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	tcCount, _ := strconv.Atoi(scanner.Text())

	for range tcCount {
		// code goes here
		scanner.Scan()
		n, _ := strconv.Atoi(scanner.Text())

		for i := n; i >= 1; i-- {
			fmt.Printf("%d ", i)
		}
		fmt.Println()
	}
}
