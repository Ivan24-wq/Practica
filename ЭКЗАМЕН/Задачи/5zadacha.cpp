#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int Summamassiva(vector<int>& arr){
    return accumulate(arr.begin(), arr.end(), 0);
    
}

int main(){
    setlocale(LC_ALL, "RU");
    
    int size;
    cout << "Введите жлементы массива: ";
    cin >> size;
    if(size == 0){
        cout << "ОШИБКА";
        return 1;

    }

    vector<int> arr(size);
    
    cout << "Введите элементы массива: ";
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
   int sum = Summamassiva(arr);
   cout << "Сумма элементов массива: " << sum;
   return 0;

}