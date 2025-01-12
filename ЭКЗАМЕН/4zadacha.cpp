#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void SdvigMassiva(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n; // Убираем лишние сдвиги
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}

int main() {
    setlocale(LC_ALL, "RU");

    int size, k;
    cout << "Введите количество элементов массива: ";
    cin >> size;
    if (size == 0) {
        cout << "ОШИБКА!";
        return 1;
    }

    vector<int> arr(size);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Введите количество сдвигов: ";
    cin >> k;

    SdvigMassiva(arr, k);
    cout << "Массив после сдвига: ";
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
