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
	tcCount, _ := strconv.Atoi(scanner.Text())

	for range tcCount {
		// code goes here
		scanner.Scan()
		n, _ := strconv.Atoi(scanner.Text())

		scanner.Scan()
		permutation := getNumbersArr(scanner.Text())
		visitedChairsMap := make(map[int]bool, 0)

		totalSittedChairs := 0
		for i := 0; i < n; i++ {
			if (*permutation)[i] <= i+1 {
				if _, ok := visitedChairs[i+1]; ok {
					break
				} else {
					visitedChairs[(*permutation)[i]] = true
					totalSittedChairs++
				}
			}

			if (*permutation)[i] >= n {
				if _, ok := visitedChairs[i+1]; ok {
					break
				} else {
					visitedChairs[(*permutation)[i]] = true
					totalSittedChairs++
				}
			}
		}

		fmt.Println(totalSittedChairs)
	}
}

func getNumbersArr(text string) *[]int {
	numStrs := strings.Split(text, " ")
	nums := make([]int, len(numStrs))
	for i, str := range numStrs {
		temp, _ := strconv.Atoi(str)
		nums[i] = temp
	}
	return &nums
}
