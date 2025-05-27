package main

import (
	"os"
	"fmt"
	"bufio"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	scanner.Scan()
	rounds, _ := strconv.Atoi(scanner.Text()) 

	for i := 0; i < rounds; i++ {
		scanner.Scan()
		number := scanner.Text()

		index := -1
		positiveDigitCount := 0
		for i := len(number)-1; i >= 0; i-- {
			if number[i] != '0' {
				if index == -1 {
					index = i
					continue
				}

				positiveDigitCount++
			}
		}

		if index == -1 {
			fmt.Println(len(number)-1)
			continue
		}

		fmt.Println(positiveDigitCount+(len(number)-1-index))
	}
}
