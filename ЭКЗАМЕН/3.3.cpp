/*  Даны две отсортированные по неубыванию последовательности целых чисел. 
Объедините их в одну последовательность отсортированную по неубыванию. */
#include <iostream>
#include <vector>
using namespace std;

int main(){
// Размер первого массива
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    // Размер второго массива
    int k;
    cin >> k;
    vector<int> b(k);
    for(int i = 0; i < k; ++i){
        cin >> b[i];
    }

// Итоговый массив
vector<int> c;
c.reserve(n+k);

int i = 0, j = 0;
while(i < n && j < k){
    if(a[i] <= b[j]){
        c.push_back(a[i]);
        ++i;
    } else {
        c.push_back(b[j]);
        ++j;
    }
}

// Отсортированный элемент массива
while(j < k){
    c.push_back(b[j]);
    ++j;
}

for(int num : c ){
    cout << num << " ";
}

cout << endl;
return 0;

}