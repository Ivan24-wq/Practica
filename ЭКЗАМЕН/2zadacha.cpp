#include <iostream>
#include <vector>
using namespace std;

int main(){
    setlocale(LC_ALL, "RU");
    int* arr;
    int size;
    cout << "Введите количество элементов массива: ";
    cin >> size;
    if(size == 0){
        cout << "ОШИБКА!";
        return 1;
    }

    arr = new int[size];
    cout << "Введите элементы массива: " << endl;
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    vector<int> unique_elements;
    for(int i = 0; i < size; i++){
        bool is_duplicate = false;
        for(int j = 0; j < unique_elements.size(); j++){
            if(arr[i] == unique_elements[j]){
                is_duplicate = true;
                break;
            }
        }
        if(!is_duplicate){
            unique_elements.push_back(arr[i]);
        }
        cout << "Ответ: ";
        for(int i = 0; i < unique_elements.size(); i++){
            cout << unique_elements[i] << " ";   
        }
        cout << endl;
    }
    delete[] arr;
    return 0;
}