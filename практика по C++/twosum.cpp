#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for(int i; i < nums.size(); i++){
            int complement = target - nums[i];
            if(numMap.find(complement) != numMap.end()){
                return{numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }

int main(){
   int target, n;
   cout << "Input: " << endl;
   cin >> n;
   vector <int> nums(n);
   cout << "Input element: "<< endl;
   for(int i; i < n; i++){
    cin >> nums[i];
   }
  cout << "Input tagest" ;
  cin >> target;
  vector<int> result = twoSum(nums, target);
  if(!result.empty()){
    cout << "Output" << result[0] << ", " << result[1] << endl;
  }else{
    cout << "ERROR";
  }
  return 0;
}
