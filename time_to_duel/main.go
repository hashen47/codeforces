package main

import (
	"os"
	"fmt"
	"bufio"
	"strconv"
	"strings"
)

func main() {
	s := bufio.NewScanner(os.Stdin)

	s.Scan()
	rounds, _ := strconv.Atoi(s.Text())

	for i := 0; i < rounds; i++ {
		s.Scan()
		s.Text()

		winCount := 0
		lostCount := 0
		scores := make([]int, 0)
		s.Scan()
		for _, str := range strings.Split(s.Text(), " ") {
			n, _ := strconv.Atoi(str)
			if n == 1 {
				winCount++
			} else {
				lostCount++
			}
			scores = append(scores, n)
		}

		if len(scores) == winCount || len(scores) == lostCount {
			fmt.Println("YES")
			continue
		}

		if len(scores) == 2 {
			if scores[0] == scores[1] {
				fmt.Println("YES")
				continue
			}
			fmt.Println("NO")
			continue
		}

		shouldPrint := true
		for i := 0; i < len(scores)-1; i++ {
			if scores[i] == 0 && scores[i+1] == 0 {
				shouldPrint = false
				fmt.Println("YES")
				break
			}
		}

		if shouldPrint {
			fmt.Println("NO")
		}
	}
}
