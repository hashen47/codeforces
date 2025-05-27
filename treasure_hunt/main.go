package main

import (
	"fmt"
	"os"
	"strings"
	"bufio"
	"strconv"
)

func main() {
	s := bufio.NewScanner(os.Stdin)

	s.Scan()
	rounds, _ := strconv.Atoi(s.Text())

	for i := 0; i < rounds; i++ {
		s.Scan()

		arr := make([]int, 0)
		for _, ch := range strings.Split(s.Text(), " ") {
			n, _ := strconv.Atoi(ch)
			arr = append(arr, n)
		}

		if arr[0] > arr[2] {
			fmt.Println("NO")
			continue
		}

		if arr[0] == arr[2] || arr[1] > arr[2] {
			fmt.Println("YES")
			continue
		}

		remainder := arr[2] % (arr[0] + arr[1]) 
		if remainder == 0 {
			fmt.Println("NO")
			continue
		}

		if remainder < arr[0] {
			fmt.Println("NO")
			continue
		}

		if remainder >= arr[0] {
			fmt.Println("YES")
			continue
		}
	}
}
