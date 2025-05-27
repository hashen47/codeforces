package main

import (
	"os"
	"fmt"
	"bufio"
	"strings"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	scanner.Scan()
	rounds, _ := strconv.Atoi(scanner.Text())

	for i := 0; i < rounds; i++ {
		scanner.Scan()
		length, _ := strconv.Atoi(scanner.Text())

		arr := make([]int, length)
		output := make([]int, length)

		scanner.Scan()
		for i, ns := range strings.Split(scanner.Text(), " ") {
			arr[i], _ = strconv.Atoi(ns)
			output[i] = 1
		}

		groupTwo := make([]int, 0)
		for i := 1; i < length; i++ {
			n := gcd(arr[0], arr[i])
			if n == -1 {
				groupTwo = append(groupTwo, arr[i])
				output[i] = 0
				continue
			}
		}

		if length

		fmt.Println(arr)
		fmt.Println(output)
	}
}

func gcd(sn, ln int) int {
	if sn == ln {
		return sn
	}

	if sn > ln {
		t := sn
		sn = ln
		ln = t
	}

	if ln % sn == sn {
		return -1 // mean no gcd between two numbers
	}

	r := 1
	for r != 0 {
		r = ln % sn
		ln = sn
		sn = r
	}

	return ln
}
