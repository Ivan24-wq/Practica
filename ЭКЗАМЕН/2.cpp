#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    setlocale(LC_ALL, "RU");
    int ourArr[10] = {};
    const int loverLimit = 7;
    const int upperLimit = 14;

    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        ourArr[i] = loverLimit + rand() % (upperLimit - loverLimit + 1);
        cout << ourArr[i] << " | ";
    }

    cout << endl << endl;

    for(int i = 0; i < 10; i++){
        if(ourArr[i] >= 10){
            ourArr[i] -= 10;
        }
        cout << ourArr[i] << " | ";
    }

    cout << endl << endl;
    return 0;
}