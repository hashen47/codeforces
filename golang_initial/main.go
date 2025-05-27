package main

import (
	"os"
	"fmt"
	"bufio"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	scanner.Scan()
	rounds, _ := strconv.Atoi(scanner.Text())
	for i := 0; i < rounds; i++ {
		fmt.Println(i)
	}
}
