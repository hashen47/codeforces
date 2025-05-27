package main

import (
	"os"
	"fmt"
	"strconv"
	"bufio"
)

func main() {
	s := bufio.NewScanner(os.Stdin)

	s.Scan()
	rounds, _ := strconv.Atoi(s.Text())

	for i := 0; i < rounds; i++ {
		s.Scan()
		n, _ := strconv.Atoi(s.Text())
		fmt.Println(n * 2)
	}
}
