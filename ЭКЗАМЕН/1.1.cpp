#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "RU");
    int limit;
    cout << "Введите предел чисел: ";
    cin >> limit;
    if(limit <= 0){
        cout << "Введите положительные числа!"<< endl;
    }
    for(int i = 1; i <+ limit; i+= 2){
            cout << i << " * " << i << " = " << i * i << endl;
        }
    
    return 0;
}
