#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    int size;
    cout << " Введите количество элементов массива: ";
    cin >> size;
    if (size == 0) {
        cout << "ERROR!";
        return 1;
    }

    int* arr = new int[size];
    cout << "Введите элементы массива: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    bool Vozrast = true;
    bool Ubuv = true;

    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            Vozrast = false;
        }
    }

    if (Vozrast) {
        cout << "YES";

    }
    else if (Ubuv) {
        cout << "NO";
    }

    delete[] arr;
    return 0;

}