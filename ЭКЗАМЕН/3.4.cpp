#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main(){
    // чтения кол-ва слов
    int l, k;
    cin >> l;
    set<string> set1;

    // Чтение первой последовательности
    for(int i = 0; i < l; ++i){
        string word;
        cin >> word;
        set1.insert(word);

    }

    //Чтение воторой последовательности
    cin >> k;
    set<string> set2;
    for(int i = 0; i < k; ++i){
        string word;
        cin >> word;
        set2.insert(word);
    }

    // Пересечение последовательностей
    vector<string> common_word;
    for(const auto& word : set1){
        if(set2.find(word) != set2.end()){
            common_word.push_back(word);
        }
    }
    // Проверка есть ли общие слова и выводим их
    if(common_word.empty()){
        cout << -1;
    } else {
        for(const auto& word : common_word){
            cout << word << " ";
        }
    }
    return 0;

}