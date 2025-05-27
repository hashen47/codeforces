package main

import (
	"os"
	"fmt"
	"bufio"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// TODO: i try with different implementations, only works is sorted approach
	// but implement sorting got slow the program 
	// so try with different language to know is that work (which more faster language rust or c or c++)
	s := bufio.NewScanner(os.Stdin) 

	s.Scan()
	rounds, _ := strconv.Atoi(s.Text())

	for i := 0; i < rounds; i++ {
		s.Scan()
		strength, _ := strconv.Atoi(strings.Split(s.Text(), " ")[1])

		teamCount := 0
		smallNumbers := make([]int, 0)

		s.Scan()
		for _, str := range strings.Split(s.Text(), " ") {
			n, _ := strconv.Atoi(str)
			if n < strength {
				smallNumbers = append(smallNumbers, n)
				continue
			}
			teamCount++
		}

		sort.Ints(smallNumbers)

		count := 0
		remainingCount := len(smallNumbers)

		for i := len(smallNumbers)-1; i >= 0; i-- {
			n := smallNumbers[i]
			if n * remainingCount < strength {
				remainingCount--
				continue
			}

			count++

			if n * count >= strength {
				teamCount++
				remainingCount -= count
				count = 0
			}
		}

		fmt.Println(teamCount)
	}
}
