#include <iostream>
using namespace std;

int main(void){
    setlocale(LC_ALL, "RU");
    int arr[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int left = 0;
    int right = 15;
    int middle = 0;
    int num = 0;
    int bsearch = false;
    int i = 0;
    cout << "Массив: ";

    for(int i = 0; i < 15; i++){
        cout << arr[i] << " ";
    }
    cout << "\n Поиск числа: ";
    cin >> num;

    while(bsearch == false && left <= right){
        middle = (right+left) / 2;
        
        if(num == arr[middle]){
            bsearch == true;
            cout << "Найдено!";
        } else {
            if(num < arr[middle]) right = middle -1;
            if(num > arr[middle]) right = middle +1;
        }
    }

    if(bsearch == false){
        cout << "😭 Ничего не найдено";
    }
    return 0;


}
