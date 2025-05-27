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
		s.Scan()

		parts := strings.Split(s.Text(), " ")
		wordLen, _ := strconv.Atoi(parts[0])
		turns, _ := strconv.Atoi(parts[1])

		s.Scan()
		word := s.Text()

		if wordLen == 1 {
			fmt.Println("NO")
			continue
		}

		if word[0] < word[wordLen-1] {
			fmt.Println("YES")
			continue
		}

		if turns == 0 {
			fmt.Println("NO")
			continue
		}

		wordArr := make([]byte, 0)
		for i := wordLen-1; i >= 0; i-- {
			wordArr = append(wordArr, word[i])
		}

		if len(word) == 2 && word[0] != word[1] && turns > 0 {
			fmt.Println("YES")
			continue
		}

		isPossible := false
		index := -1
		for i := 0; i < wordLen; i++ {
			if isPossible {
				break
			}

			if turns <= 0 {
				isPossible = false
				break
			}

			for j := i; j < wordLen; j++ {
				if wordArr[j] < word[wordLen-1-i] {
					temp := wordArr[i]
					wordArr[i] = wordArr[j]
					wordArr[j] = temp
					index = -1
					isPossible = true
					break
				}

				if wordArr[j] == word[wordLen-1-i] && i != j && wordArr[j] != wordArr[i] { 
					if index == -1 {
						index = j
					}
				}
			}

			if index != -1 {
				temp := wordArr[i]
				wordArr[i] = wordArr[index]
				wordArr[index] = temp
				index = -1
				turns--
			}
		}

		if isPossible {
			fmt.Println("YES")
			// revWord := make([]byte, 0)
			// for i := wordLen-1; i >= 0; i-- {
			// 	revWord = append(revWord, word[i])
			// }
			// fmt.Println(string(wordArr))
			// fmt.Println(string(revWord))
			continue
		}

		fmt.Println("NO")
	}
}
