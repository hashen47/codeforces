package main

import (
	"os"
	"fmt"
	"slices"
	"bufio"
	"strings"
	"strconv"
)

func isPossible(arr []int) bool {
	median := arr[0]
	length := len(arr)

	slices.Sort(arr)

	if arr[length/2] == median {
		fmt.Println("YES")
		return true
	}

	index := -1 
	for i, n := range arr {
		if n == median {
			index = i
			break
		}
	}

	if index < length/2 {
		if median >= 0 {
			fmt.Println("YES")
			return true
		}

		positiveCount := 0
		for i := index+1; i < length; i++ {
			if arr[i] * -1 < median {
				positiveCount++
			}
		}

		if positiveCount >= (length/2) - index {
			fmt.Println("YES")
			return true
		}
	} else {
		if median <= 0 {
			fmt.Println("YES")
			return true
		}

		negativeCount := 0
		for i := 0; i < index; i++ {
			if arr[i] * -1 > median {
				negativeCount++
			}
		}

		if negativeCount >= index - (length/2) {
			fmt.Println("YES")
			return true
		}
	}

	return false
}

func main() {
	r := bufio.NewReader(os.Stdin)

	str, _ := r.ReadString('\n')
	rounds, _ := strconv.Atoi(string(str[:len(str)-1]))
	for i := 0; i < rounds; i++ {
		str, _ = r.ReadString('\n')
		strconv.Atoi(string(str[:len(str)-1]))

		arr := make([]int, 0)
		str, _ = r.ReadString('\n')
		for _, str := range strings.Split(string(str[:len(str)-1]), " ") {
			n, _ := strconv.Atoi(str)
			arr = append(arr, n)
		}

		copyArr := make([]int, 0)
		copyArr = append(copyArr, arr...)
		// fmt.Println("copyArr", copyArr)
		if !isPossible(copyArr) {
			copyArr = make([]int, 0)
			copyArr = append(copyArr, arr...)
			copyArr[0] = copyArr[0] * -1
			// fmt.Println("copyArr", copyArr)
			if !isPossible(copyArr) {
				fmt.Println("NO")
			}
		}
	}
}
