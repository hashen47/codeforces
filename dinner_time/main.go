package main

import (
	"os"
	"fmt"
	"bufio"
	"strings"
	"strconv"
)

func main() {
	s := bufio.NewScanner(os.Stdin)
	s.Scan()

	rounds, _ := strconv.Atoi(s.Text()) 
	for i := 0; i < rounds; i++ {
		s.Scan()

		parts := strings.Split(s.Text(), " ")
		n, _ := strconv.Atoi(parts[0])
		m, _ := strconv.Atoi(parts[1])
		p, _ := strconv.Atoi(parts[2])
		q, _ := strconv.Atoi(parts[3])

		if n%p == 0 {
			if m % q != 0 {
				fmt.Println("NO")
				continue
			}

			if n/p != m/q {
				fmt.Println("NO")
				continue
			}
		}

		fmt.Println("YES")
	}
}
