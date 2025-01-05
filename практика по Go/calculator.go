package main
import(
	"fmt"

)
func main(){
	var op string
	var n1, n2, flat64
	fmt.Println("выберите действие (+ - * /) ")
	fmt.Scan(&op)
	fmt.Println("Введите два числа: ")
	fmt.Scan(&n1, &n2)
	fmt.Println("ответ ")

	switch op{
	case '+':
		fmt.Println("n1+n2")
	case '-':
		fmt.Println("n1-n2")
	case '/':
	
		if n2 != 0 {
			fmt.Println("n1/n2")
		} else {
			fmt.Println("На 0 делить нельзя!")
		}
	case '*':
		fmt.Println("n1*n2")
	default:
		fmt.Println("недопустимая операция!")
	}
}
