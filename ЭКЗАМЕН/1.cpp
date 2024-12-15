#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

// Класс Solution с методом merge
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int i = m - 1;
    int j = n - 1;
    int k = m + n;

    // Объединение массивов

    while(i >= 0 && j >= 0){
        if(nums1[i] > nums2[j]) {
            nums1[k--] = nums2[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
    while(j >= 0){
        nums1[k--] = nums2[j--];
    }
}



int main(){
    setlocale(LC_ALL, "RU");
    int n, m;
    cout << "Введите количество элементов для первого массива: ";
    cin >> n;
    cout << "Введите количество элементов для второго массива: ";
    cin >> m;
    vector<int> nums1(n+m, 0);
    vector<int> nums2(m);

    cout << "Введите" << n << "Элементы nums1: ";
    for(int i = 0; i < n; ++i){
        cin >> nums1[i];
    }

    cout << "Введите" << m << "Элементы nums1: ";
    for(int j = 0; j < m; ++j){
        cin >> nums2[m];
    }

    //Объединим массмивы
    merge(nums1, n, nums2, m);

    cout << "Ответ: ";
    for(int num : nums1){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}


//  Задача
// Вам даны два целочисленных массива nums1и nums2, отсортированных в неубывающем порядке , и два целых числа mи n, представляющие количество элементов в nums1и nums2соответственно.

//Объединить nums1 в nums2один массив, отсортированный в неубывающем порядке .

//Окончательный отсортированный массив не должен возвращаться функцией, а должен храниться внутри массиваnums1 . Чтобы учесть это, nums1имеет длину m + n, где первые mэлементы обозначают элементы, которые должны быть объединены, а последние nэлементы установлены в 0и должны игнорироваться. nums2имеет длину n.

 
