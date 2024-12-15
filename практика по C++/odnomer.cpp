#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "RU");
    int n, i;
    float num[100], sum = 0.0, average;
    cout << "Введите количество элементов массива: ";
    cin >> n;
    while(n > 100 || n <=0){
        cout << "Колво-элементов массива должно быть  от 1 до 100!!!" << endl;
        cout << "Введите повторно кол-во массива!" << endl;
        cin >> n;
    }
    for(i = 0; i < n; ++i){
        cout << i + 1 << "Введите элементы массива: ";
        cin >> num[i];
        sum += num[i];
    }
    average = sum / n;
    cout << "Среднее= " << average;
    return 0;
}
