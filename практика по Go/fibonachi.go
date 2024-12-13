package main

import (
	"fmt"
)

func fibbonachi(n int) []int {
	if n <= 0 {
		return []int{}
	}
	fib := make([]int, n)
	fib[0] = 0
	if n > 1 {
		fib[1] = 1
	}
	for i := 2; i < n; i++ {
		fib[i] = fib[i-1] + fib[i-2]
	}
	return fib
}
func main() {
	var n int
	fmt.Println("Введите количество чисел Фибоначии:")
	_, err := fmt.Scan(&n)
	if err != nil || n < 0 {
		fmt.Println("Ошибка, число не должно быть 0: ")
		return
	}
	sequence := fibbonachi(n)
	fmt.Println("Число Фибоначии: ", sequence)

}
