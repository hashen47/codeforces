package main

import (
	"fmt"
)

func main() {
	var rounds int
	fmt.Scan(&rounds)

	for i := 0; i < rounds; i++ {
		var word string
		fmt.Scan(&word)

		length := len(word)
		if length > 10 {
			fmt.Printf("%c%d%c\n", word[0], length-2, word[length-1])
			continue
		}
		fmt.Println(word)
	}
}
