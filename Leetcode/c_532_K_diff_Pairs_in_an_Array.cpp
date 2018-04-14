//
// Created by Mr.Hu on 2018/4/14.
//
// leetcode 532 k diff pairs in an array
// 题目给定一个数组，一个目标数字，求出由数组中数字组成的数对，数对中两个数差的绝对值与目标数字相等，
// 且不考虑数对中两个数字的顺序，同一个数对只记录一次，数组中的每个数字只能使用一次。
//


#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        set<int> result;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (abs(nums[i] - nums[j]) == k) {
                    int diff = nums[i] + nums[j];
                    result.insert(diff);
                }
            }
        }
        return result.size();
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1, 4, 6, 2};
    int k = 2;
    Solution solution;
    int pairs = solution.findPairs(nums, k);
    cout<<pairs<<endl;
    return 0;
}