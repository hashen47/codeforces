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

		numbers := make([]int, 0) 
		for _, str := range strings.Split(scanner.Text(), " ") {
			n, _ := strconv.Atoi(str)
			numbers = append(numbers, n)
		}

		diff := numbers[1] - numbers[0]
		if diff > numbers[2] {
			fmt.Println("NO")
			continue
		}

		numbers[0] += diff
		numbers[2] -= diff

		if numbers[2] < numbers[1] {
			fmt.Println("NO")
			continue
		}

		diff = numbers[2] - numbers[1]

		if diff % 3 == 0 {
			fmt.Println("YES")
			continue
		}

		fmt.Println("NO")
	}
}
