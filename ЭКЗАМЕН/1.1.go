package main
import("fmt")

func main(){
	var limit int
	fmt.Println("Введите предел числа:")
	fmt.Scan(&limit)
	if limit <= 0 {
		fmt.Println("Число должно быть положительным")
	} else {
	for i := 1; i <= limit; i += 2{
		fmt.Println(i, " * ", i, " = ", i * i)
	}
	}
}