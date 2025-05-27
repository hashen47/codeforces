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
		min := 1000000001  
		max := 0 

		s.Scan()
		s.Text()

		s.Scan()
		for _, str := range strings.Split(s.Text(), " ") {
			n, _ := strconv.Atoi(str)
			if n > max {
				max = n
			}

			if n < min {
				min = n
			}
		}

		fmt.Println(max-min)
		// fmt.Printf("max: %d, min: %d\n", max, min)
	}
}
