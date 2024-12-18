#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int i = m - 1;  // Указываем на последний элемент первого массива
        int j = n - 1;  // Указываем на последний элемент второго массива
        int k = m + n - 1;  // Указываем на последний индекс в объединенном массиве

        // Объединение массивов
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];  // Копируем из nums1
            } else {
                nums1[k--] = nums2[j--];  // Копируем из nums2
            }
        }

        // Если остались элементы в nums2
        while(j >= 0){
            nums1[k--] = nums2[j--];  // Копируем оставшиеся элементы из nums2
        }
    }
};

int main(){
    setlocale(LC_ALL, "RU");
    int n, m;
    cout << "Введите количество элементов для первого массива: ";
    cin >> n;
    cout << "Введите количество элементов для второго массива: ";
    cin >> m;

    // Инициализируем массивы
    vector<int> nums1(n + m, 0);  // Первый массив с дополнительным пространством
    vector<int> nums2(m);

    // Ввод первого массива
    cout << "Введите " << n << " элементов nums1: ";
    for(int i = 0; i < n; ++i){
        cin >> nums1[i];
    }

    // Ввод второго массива
    cout << "Введите " << m << " элементов nums2: ";
    for(int j = 0; j < m; ++j){
        cin >> nums2[j];
    }

    // Создаем объект класса Solution
    Solution solution;

    // Объединяем массивы
    solution.merge(nums1, n, nums2, m);

    // Выводим результат
    cout << "Ответ: ";
    for(int num : nums1){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}