#include <iostream>
using namespace std;

void printF(int n){
    if(n<=0){
        cout << "Количество чисел должно быть больше 0!" << endl;
        return;
    }
    long long first = 0, second = 1;
    cout << "Число Фибоначичи: " << endl;
    for(int i; i < n; ++i){
        cout << first << " ";
        long long next = first + second;
        first=second;
        second=next;
    }
    cout << endl;
}

int main(){
    setlocale(LC_ALL, "RU");
    int count;
    cout << "Введите количество чисел Фибонначи: ";
    cin >> count;
    printF(count);
    return 0;
}
