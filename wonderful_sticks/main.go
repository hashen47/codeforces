package main

import (
	"fmt"
)

func swap(a, b *int) {
	temp := *a
	*a = *b
	*b = temp
}

func main() {
	var rounds int
	fmt.Scan(&rounds)

	for i := 0; i < rounds; i++ {
		var stickC int
		var arragement string

		fmt.Scan(&stickC)
		fmt.Scan(&arragement)

		arr := make([]int, 0)
		for i := 1; i <= stickC; i++ {
			arr = append(arr, i)
		}

		for i := len(arragement); i >= 1; i-- {
			if arragement[i-1] == '<' {
				for j := 0; j < i; j++ {
					if arr[j] < arr[i] {
						swap(&arr[i], &arr[j])
					}
				}
				continue
			}

			if arragement[i-1] == '>' {
				for j := 0; j < i; j++ {
					if arr[j] > arr[i] {
						swap(&arr[i], &arr[j])
					}
				}
			}
		}

		for i := 0; i < len(arr); i++ {
			fmt.Printf("%d ", arr[i])
		}
		fmt.Println("")
	}
}
