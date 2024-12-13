package main

import (
	"fmt"
)

// Сортировка прямым включением по возрастанию
func insertionSortAscending(arr []int) {
	fmt.Println("\nСортировка по возрастанию:")
	for i := 1; i < len(arr); i++ {
		key := arr[i]
		j := i - 1

		// Перемещаем элементы, которые больше key, на одну позицию вперёд
		for j >= 0 && arr[j] > key {
			arr[j+1] = arr[j]
			j--
		}
		arr[j+1] = key

		// Промежуточный вывод
		fmt.Printf("Итерация %d: %v\n", i, arr)
	}
}

// Сортировка прямым включением по убыванию
func insertionSortDescending(arr []int) {
	fmt.Println("\nСортировка по убыванию:")
	for i := 1; i < len(arr); i++ {
		key := arr[i]
		j := i - 1

		// Перемещаем элементы, которые меньше key, на одну позицию вперёд
		for j >= 0 && arr[j] < key {
			arr[j+1] = arr[j]
			j--
		}
		arr[j+1] = key

		// Промежуточный вывод
		fmt.Printf("Итерация %d: %v\n", i, arr)
	}
}

func main() {
	// Ввод массива
	var n int
	fmt.Print("Введите размер массива: ")
	fmt.Scan(&n)

	if n <= 0 {
		fmt.Println("Размер массива должен быть положительным.")
		return
	}

	arr := make([]int, n)
	fmt.Println("Введите элементы массива:")
	for i := 0; i < n; i++ {
		fmt.Scan(&arr[i])
	}

	// Создаем копию массива для сортировки в другом порядке
	arrCopy := make([]int, n)
	copy(arrCopy, arr)

	// Сортировка по возрастанию
	insertionSortAscending(arr)

	// Сортировка по убыванию
	insertionSortDescending(arrCopy)
}
