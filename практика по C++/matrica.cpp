#include <iostream>
using namespace std;

void enterData(int firstM[][10], int secondM[][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond);
void multiplyMatricws(int firstM[][10], int secondM[][10], int multResult[][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond);
void display(int milt[][10], int rowFirst, int columnSecond);
 
 int main(){
    setlocale(LC_ALL, "RU");
    int firstM[10][10], secondM[10][10], mult[10][10], rowFirst, columnFirst, rowSecond, columnSecond, i, j, k;
    cout << "Введите строки и колонки первой матрицы: ";
    cin >> rowFirst;
    cout << "Введите строки и колонки матрицы: ";
    cin >> rowSecond >> columnSecond;

    // Проверка возможно ли умножить матрицы
    while (columnFirst != rowSecond){
        
    }
 }