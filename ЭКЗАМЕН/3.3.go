package main

import (
	"fmt"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	// Ввод массива a
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	// Ввод массива b
	b := make([]int, k)
	for i := 0; i < k; i++ {
		fmt.Scan(&b[i])
	}

	// Срез для хранения результата
	c := make([]int, 0, n+k)

	// Слияние двух массивов
	i, j := 0, 0
	for i < n && j < k {
		if a[i] <= b[j] {
			c = append(c, a[i])
			i++
		} else {
			c = append(c, b[j])
			j++
		}
	}

	// Добавление оставшихся элементов массива a (если есть)
	for i < n {
		c = append(c, a[i])
		i++
	}

	// Добавление оставшихся элементов массива b (если есть)
	for j < k {
		c = append(c, b[j])
		j++
	}

	// Вывод результата
	for _, num := range c {
		fmt.Print(num, " ")
	}

	fmt.Println()
}
