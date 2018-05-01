//
// Created by Mr.Hu on 2018/5/1.
//
// leetcode 136 single number
//
//
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        map<int, int> sum;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            int tmp = nums[i];
            if (sum.count(tmp)) {
                sum[tmp]++;
            } else {
                sum[tmp] = 1;
            }
        }
        for (auto it = sum.begin(); it != sum.end(); it++) {
            if (it->second == 1) {
                return it->first;
            }
        }
    }
};

int main(){
    vector<int> nums = {1,1,2,2,4};
    Solution solution;
    int result = solution.singleNumber(nums);
    cout<<result<<endl;
    return 0;
}