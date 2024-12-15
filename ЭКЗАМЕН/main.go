package main

import "fmt"

func main() {
	arrary := [3][4]int{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}
	fmt.Println(arrary)
	fmt.Println(arrary[1][2])
}
