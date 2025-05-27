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
		index := 0
		fullLength := 8
		m := map[string]int{
			"0": 3,
			"1": 1,
			"2": 2,
			"3": 1,
			"5": 1,
		}

		s.Scan()
		s.Text()

		s.Scan()
		for _, n := range strings.Split(s.Text(), " ") {
			index++

			val, ok := m[n]
			if !ok {
				continue
			}

			if val > 0 {
				m[n]--
				fullLength--
			}

			if fullLength == 0 {
				fmt.Println(index)
				break
			}
		}

		if fullLength != 0 {
			fmt.Println(0)
		}
	}
}
