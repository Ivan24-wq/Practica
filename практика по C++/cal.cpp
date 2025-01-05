#include <iostream>
using namespace std;

int main(){
    setlocale(LC_ALL, "Ru");
    char op;
    float n1, n2;

    cout << "Выберете действие (+ - / *) " << endl;
    cin >> op;
    cout << "ответ: ";
    cin >> n1 >>n2;

    switch (op)
    {
    case '+' :
    cout << n1 + n2;
        break;
    case '-' :
    cout << n1 - n2;
    break;
    case '/' :
    if(n2 !=0){
        cout << n1 / n2;
    }else{
        cout << "На 0 делить запрещено";
    }
    break;
    case '*':
    cout << n1 * n2;
    break;
    
    default:
    
        break;
    }
    cout << endl;
    return 0;
}