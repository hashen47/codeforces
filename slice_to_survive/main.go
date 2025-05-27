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
		rows, _ := strconv.Atoi(parts[0])
		cols, _ := strconv.Atoi(parts[1])
		y, _ := strconv.Atoi(parts[2])
		x, _ := strconv.Atoi(parts[3])
		y -= 1
		x -= 1

		totalTurns := 0

		for {
			// fmt.Printf("x: %d, y: %d, colI: %d, rowI: %d, cols: %d, rows: %d\n", x, y, colI, rowI, cols, rows)

			leftArea   := int64(x) * int64(rows)
			rightArea  := int64(cols-1-x) * int64(rows)
			topArea    := int64(y) * int64(cols)
			bottomArea := int64(rows-1-y) * int64(cols)

			// fmt.Printf("left: %d, right: %d, top: %d, bottom: %d\n", leftArea, rightArea, topArea, bottomArea)

			max := rightArea
			if max < leftArea {
				max = leftArea
			}

			if max < topArea {
				max = topArea
			}

			if max < bottomArea {
				max = bottomArea
			}

			switch max {
			case leftArea:
				cols = cols-x
				x = 0
			case rightArea:
				cols = x+1
			case topArea:
				rows = rows-y
				y = 0
			case bottomArea:
				rows = y+1
			}

			x = cols/2
			y = rows/2

			totalTurns++

			if cols == 1 && rows == 1 { 
				break
			}
		}

		fmt.Println(totalTurns)
	}
}
