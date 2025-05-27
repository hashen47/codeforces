package main

import (
    "os"
	"fmt"
    "bufio"
    "strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	scanner.Scan()
	c, _ := strconv.Atoi(scanner.Text())

    for i := 0; i < c; i++ {
		scanner.Scan()
		inputs := strings.Split(scanner.Text(), " ")

		length, _ := strconv.Atoi(inputs[0])
		n, _ := strconv.Atoi(inputs[1])

		if n >= length {
			for i := 0; i < length; i++ {
				fmt.Printf("%d ", i)
			}
			continue
		}

		for i := 0; i < length; i++ {
			if i == n {
				continue
			}
			fmt.Printf("%d ", i)
		}
		fmt.Printf("%d ", n)
    }
}
