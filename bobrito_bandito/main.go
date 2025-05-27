package main

import (
	"os"
	"fmt"
	"bufio"
	"strconv"
	"strings"
)

func main() {
	s := bufio.NewScanner(os.Stdin)

	s.Scan()
	rounds, _ := strconv.Atoi(s.Text())

	for i := 0; i < rounds; i++ {
		s.Scan()

		arr := make([]int, 0)
		for _, ns := range strings.Split(s.Text(), " ") {
			n, _ := strconv.Atoi(ns)
			arr = append(arr, n)
		}

		n := arr[0]
		m := arr[1]
		l := arr[2]
		r := arr[3]

		if n == m {
			fmt.Printf("%d %d\n", l, r)
			continue
		}

		diff := n-m

		if l == 0 {
			fmt.Printf("%d %d\n", l, r-n+m)
			continue
		}

		if r == 0 {
			fmt.Printf("%d %d\n", l+n-m, r)
			continue
		}

		if l * -1 > diff {
			fmt.Printf("%d %d\n", l+diff, r)
			continue
		}

		if r > diff {
			fmt.Printf("%d %d\n", l, r-diff)
			continue
		}

		if l*-1 > r {
			l += diff

			if l > 0 {
				r -= l
				l = 0
			}
		} else {
			r -= diff

			if r < 0 {
				l += r * -1
				r = 0
			}
		}

		// for i := 0; i < diff; i++ {
		// 	if l < 0 {
		// 		l += 1
		// 	} else {
		// 		r -= 1
		// 	}
		// }

		fmt.Printf("%d %d\n", l, r)
	}
}
