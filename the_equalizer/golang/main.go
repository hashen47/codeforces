package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()

	// get the testcases count
	tcCount, _ := strconv.Atoi(scanner.Text())

	for range tcCount {
		scanner.Scan()
		_ = scanner.Err()

		nAndK := strings.Split(scanner.Text(), " ")
		n, _ := strconv.ParseInt(nAndK[0], 10, 64)
		k, _ := strconv.ParseInt(nAndK[1], 10, 64)

		scanner.Scan()
		numsStrArr := strings.Split(scanner.Text(), " ")

		total := int64(0)
		for _, str := range numsStrArr {
			num, _ := strconv.ParseInt(str, 10, 64)
			total += num
		}

		// fmt.Printf("n: %v, k: %v, total: %v\n", n, k, total)

		if total % 2 == 1 || (n * k) % 2 == 0 {
			fmt.Printf("YES\n")
			continue
		}

		fmt.Printf("NO\n")
	}
}
