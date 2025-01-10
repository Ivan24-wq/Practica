#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    setlocale(LC_ALL, "RU");
    int n;
    cout << "введите число: " << endl;
    cin >> n;

    //Создадим массив
    vector<int> number(n);
    cout << " Введите число: ";
    for(int i = 0; i < n; i++){
        cin >> number[i];
    }
    int result = 0;
    for(int num : number){
        result ^= num;
    }
    cout << "Ответ: " << result << endl;
    return 0;


}