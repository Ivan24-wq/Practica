package main

import(
	"fmt"
)

func main(){
	var n int
	fmt.Println("Введите чмсло: ")
	fmt.Scan(&n)

	num := make([]int, n)
	fmt.Println("введите числа ")
	for i := 0; i < n; i++ {
		fmt.Scan(&num[i])
	} 
	result := 0

	for _, num := range num{
		result ^=  num
	}
	fmt.Println("Числа без пары ")

}