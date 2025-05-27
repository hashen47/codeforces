package main

import (
	"fmt"
	"bufio"
	"os"
	"strconv"
	"strings"
	"time"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	startT := time.Now()
	tcCount, _ := strconv.Atoi(scanner.Text())

	for i := 0; i < tcCount; i++ {
		scanner.Scan()
		n, _ := strconv.Atoi(scanner.Text())

		m := make(map[string]bool, 0)
		ans := make([]string, 2*n)

		k := 1
		for i := 0; i < n; i++ {
			scanner.Scan()
			line := scanner.Text()

			for _, str := range strings.Split(line, " ") {
				if _, ok := m[str]; !ok {
					m[str] = true
					ans[k] = str
					k++
				}
			}
		}

		k = 0
		for i := 1; i <= 2*n; i++ {
			str := strconv.Itoa(i) 
			if _, ok := m[str]; !ok {
				m[str] = true
				ans[k] = str 
				k++
			}
		}

		for _, ch := range ans {
			fmt.Printf("%s ", ch)
		}
		fmt.Println("")
	}

	fmt.Println(time.Since(startT))
}

