package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
	"strconv"
	"strings"
)

func main() {
	file, _ := os.Open("data/input.txt")
	defer file.Close()

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()

	tcCount, _ := strconv.Atoi(scanner.Text())
	for range tcCount {
		scanner.Scan()
		n, _ := strconv.Atoi(scanner.Text())

		nums := make([]int, 0)
		scanner.Scan()
		for _, intStr := range strings.Split(scanner.Text(), " ") {
			num, _ := strconv.Atoi(intStr)
			nums = append(nums, num)
		}

		slices.Sort(nums)

		callCount := 0 
		for i := 0; i < n/2; i++ {
			if nums[i] != nums[n/2] || nums[n-i-1] != nums[n/2] {
				callCount++
			}
		}

		fmt.Println(callCount)
	}
}
