#include <iostream>
#include <cmath>
using namespace std;

int main(){
    setlocale(LC_ALL, "Ru");
    float a, b, c, D, x1, x2;
    cout << "Введите числа a, b, c ";
    cin >> a >> b >> c;
    D = b * b - 4*a*c;
    if(a==0){
        cout << "A должно быть больше 0!";
        return 0;
    }
    if(D > 0){
        x1 = (-b+sqrt(D)) / 2*a;
        x2 = (-b-sqrt(D)) / 2*a;
        cout << "Корни уравнения: " << x1 << x2;
    } else if(D == 0){
        x1=x2 = (-b) / 2*a;
        cout << "конеь уравнения: " << x1 << x2;
    } else {
        cout << "нет корней!";
    }
    return 0;
}