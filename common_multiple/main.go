package main

import (
	"fmt"
	"bufio"
	"strconv"
	"strings"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()

	tcCount, _ := strconv.Atoi(scanner.Text())

	for i := 0; i < tcCount; i++ {
		scanner.Scan()
		scanner.Text()

		total := 0
		m := make(map[string]bool, 0)

		scanner.Scan()
		for _, str := range strings.Split(scanner.Text(), " ") {
			if _, ok := m[str]; !ok {
				m[str] = true
				total++
			}
		}

		fmt.Println(total)
	}
}
