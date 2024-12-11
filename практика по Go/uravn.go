package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b, c, D, x1, x2 float64

	fmt.Println("Введите числа a, b, c:")
	fmt.Scan(&a, &b, &c)

	if a == 0 {
		fmt.Println("A должно быть больше 0!")
		return
	}

	D = b*b - 4*a*c

	if D > 0 {
		x1 = (-b + math.Sqrt(D)) / (2 * a)
		x2 = (-b - math.Sqrt(D)) / (2 * a)
		fmt.Printf("Корни уравнения: x1 = %.2f, x2 = %.2f\n", x1, x2)
	} else if D == 0 {
		x1 = -b / (2 * a)
		fmt.Printf("Корень уравнения: x1 = x2 = %.2f\n", x1)
	} else {
		fmt.Println("Нет корней!")
	}
}