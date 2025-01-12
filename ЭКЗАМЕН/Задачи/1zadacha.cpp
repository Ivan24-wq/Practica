#include <iostream>
#include <vector>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int* arr;
    int size;
    cout << "Введите количество элементов массива: ";
    cin >> size;
    if (size == 0) {
        cout << "ОШИБКА !!!";
        return 1;
    }

    arr = new int[size];
    cout << "Введите жлементы массива: ";
    for (int i = 0; i < size; i++) {
        
        cin >> arr[i];
    }
    int max = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];

        }
    }

    cout << "Отсортированный массив: " << max << endl;
    delete arr;
    return 0;
}