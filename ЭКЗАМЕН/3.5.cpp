#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    int m;
    cin >> m; // Количество пользователей
    unordered_map<string, int> UserBalanses;

    // Считываем статус пользователя
    string login;
    int balance;
    string line;
    std::getline(cin, line);

    for(int i = 0; i < m; ++i){
        getline(cin, line);
        size_t  separstorPos = line.find(';');
        login = line.substr(0, separatorPos);
        balance = stoi(line.substr(separstorPos + 1));
        
    }
}