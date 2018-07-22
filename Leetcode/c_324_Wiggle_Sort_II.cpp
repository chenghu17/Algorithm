//
// Created by Mr.Hu on 2018/7/22.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        stack<int> numbers;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            numbers.push(nums[i]);
        }
        int index = 1, i = 1;
        while (index < size) {
            nums[index] = numbers.top();
            numbers.pop();
            ++i;
            index = 2 * i - 1;
        }
        index = 0, i = 1;
        while (index < size) {
            nums[index] = numbers.top();
            numbers.pop();
            ++i;
            index = 2 * i - 2;
        }
    }
};

int main(){
    vector<int> nums;
    nums.emplace_back(1);
    nums.emplace_back(3);
    nums.emplace_back(2);
    nums.emplace_back(1);
    nums.emplace_back(9);
    nums.emplace_back(8);
    nums.emplace_back(5);
    Solution solution;
    solution.wiggleSort(nums);
    for(auto it = nums.begin();it!=nums.end();++it){
        cout<<*it<<" ";
    }
    return 0;
    
}