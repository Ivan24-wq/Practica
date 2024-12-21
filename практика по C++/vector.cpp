#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
vector<string> names = {"john", "bobby", "dear", "test1", "catherine",  "nomi", "shinta"};
sort(names.begin(), names.end() );
for(const auto& currentName : names){
    cout << currentName << endl;
}

for(int y = 0; y < names.size(); ++y){
    cout << names[y];
}
return 0;
}