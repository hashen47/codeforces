package main

import (
	"os"
	"fmt"
	"bufio"
	"strconv"
	"strings"
)

func printGrid(rows, cols int, grid *[][]int) {
	for y := 0; y < rows; y++ {
		for x := 0; x < cols; x++ {
			val := (*grid)[y][x]
			if val == 1 {
				fmt.Printf("%c ", 'X')
			} else {
				fmt.Printf("%c ", '.')
			}
		}
		fmt.Println("")
	}
	fmt.Println("")
}

func main() {
	s := bufio.NewScanner(os.Stdin)

	s.Scan()
	rounds, _ := strconv.Atoi(s.Text())

	for i := 0; i < rounds; i++ {
		numbers := make([]int, 0)

		s.Scan()
		for _, str := range strings.Split(s.Text(), " ") {
			n, _ := strconv.Atoi(str)
			numbers = append(numbers, n)
		}

		a := numbers[2]-1
		b := numbers[3]-1
		rows := numbers[0]
		cols := numbers[1]

		grid := make([][]int, 0)
		for y := 0; y < rows; y++ {
			row := make([]int, 0)
			for x := 0; x < cols; x++ {
				row = append(row, 0)
			}
			grid = append(grid, row)
		}
		grid[a][b] = 1

		numberOfTurns := 0
		for !(rows == 1 && cols == 1) {
			max := -1 
			verticalMax := -1 
			horizontalMax := -1 
			verticalDiff := rows-1-a
			horizontalDiff := cols-1-b
			verticalDir := "top"
			horizontalDir := "left"
			dir := "top"

			// printGrid(rows, cols, &grid)
			// fmt.Printf("a: %d, b: %d, rows: %d, cols: %d\n", a, b, rows, cols)

			if verticalMax < a {
				verticalDir = "top"
				verticalMax = a
			}

			if verticalMax < verticalDiff {
				verticalDir = "bottom"
				verticalMax = verticalDiff 
			}

			if horizontalMax < b {
				horizontalDir = "left"
				horizontalMax = b
			}

			if horizontalMax < horizontalDiff {
				horizontalDir = "right"
				horizontalMax = horizontalDiff
			}

			vM := int64(verticalMax) 
			hM := int64(horizontalMax) 
			_cols := int64(cols) 
			_rows := int64(rows) 

			if vM * _cols > hM * _rows {
				max = verticalMax
				dir = verticalDir
			} else if vM * _cols < hM * _rows {
				max = horizontalMax
				dir = horizontalDir
			} else {
				max = verticalMax
				dir = verticalDir
				if max < horizontalMax {
					max = horizontalMax
					dir = horizontalDir
				}

				if verticalMax == horizontalMax {
					switch dir {
					case verticalDir:
						if rows > cols {
							// fmt.Println("upper")
							dir = horizontalDir
						}
					case horizontalDir:
						if cols > rows {
							// fmt.Println("lower")
							dir = verticalDir
						}
					}
				}
			}

			if max == verticalMax && dir == verticalDir {
				if dir == "top" {
					grid[a][b] = 0
					rows -= a 
					a = 0
					grid[a][b] = 1
				} else if dir == "bottom" {
					rows = a+1 
				}
			} else if max == horizontalMax && dir == horizontalDir {
				if dir == "left" {
					grid[a][b] = 0
					cols -= b
					b = 0
					grid[a][b] = 1
				} else if dir == "right" {
					cols = b+1
				}
			}

			// fouad's move
			grid[a][b] = 0
			a = rows/2
			grid[a][b] = 1

			grid[a][b] = 0
			b = cols/2
			grid[a][b] = 1

			numberOfTurns++
			// printGrid(rows, cols, &grid)
			// fmt.Printf("a: %d, b: %d, rows: %d, cols: %d, dir: %s\n", a, b, rows, cols, dir)
			// fmt.Printf("grid: %v\n", grid)
			// isMoufTurn = !isMoufTurn
		}
	
		// fmt.Println(numbers)
		// fmt.Println(grid)
		fmt.Println(numberOfTurns)
	}
}
