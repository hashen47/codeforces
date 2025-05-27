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
		scanner.Scan()
		n, _ := strconv.Atoi(scanner.Text())

		if n % 2 == 0 {
			fmt.Println("NO")
			continue
		}

		fmt.Println("YES")
	}
}
