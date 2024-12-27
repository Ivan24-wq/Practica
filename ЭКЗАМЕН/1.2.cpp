#include <iostream>
#include <cmath>
using namespace std;

int main(){
    setlocale(LC_ALL, "RU");
    unsigned count = {};
    int sum = {};

    while(true){
        cout << "Введите число: ";
        int n;
        cin >> n;
        sum += n;
        ++count;

        char yesno  {};
        cout << "Завершить (y/Y)";
        cin >> yesno;
        if(yesno == 'y' || yesno == 'Y' )break;

    }
    cout << "сумма чисел: " << sum << endl;
    cout << "Среднее арифметическое: " << (static_cast<double>(sum) / count) << endl;
}