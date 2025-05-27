package main

import (
	"fmt"
	"time"
)

func main() {
	var tcCount int
	fmt.Scan(&tcCount)
	startT := time.Now()

	for i := 0; i < tcCount; i++ {
		var n int
		fmt.Scan(&n)

		m := make(map[int]bool, 0) 
		ans := make([]int, 2*n)

		k := 1
		for j := 0; j < n*n; j++ {
			var num int
			fmt.Scan(&num)

			if _, ok := m[num]; !ok {
				m[num] = true
				ans[k] = num
				k++
			}
		}

		k = 0
		for i := 1; i <= 2*n; i++ {
			if _, ok := m[i]; !ok {
				ans[k] = i
				k++
			}
		}

		for _, v := range ans {
			fmt.Printf("%d ", v)
		}
		fmt.Println("")
	}

	fmt.Println(time.Since(startT))
}

