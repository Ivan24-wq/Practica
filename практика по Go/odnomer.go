package main

import (
	"fmt"
)

func main() {
	var n int
	var sum float64 = 0.0
	var num [100]float64
	fmt.Println("Количество элементов: ")
	fmt.Scan(&n)

	if n <= 0 || n > 100 {
		fmt.Println("кол-во элементов массива долно быть от 1 до 100 !")

		return
	}
	fmt.Println("Введите элементы массива: ")
	for i := 0; i < n; i++ {
		fmt.Scan(&num[i])
		sum += num[i]

	}
	average := sum / float64(n)
	fmt.Println("Среднее значение: ", average)
}
