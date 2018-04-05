//
// Created by Mr.Hu on 2018/4/5.
//
// leetcode 217 contains duplicate
// 题目给定一个数组，判断数组中是否出现任意重复数字，如果存在重复情况，则输出true，即存在重复情况，
// 反之则输出false，不存在情况。
// 对于这个题目想到昨天解决169题的众数方法，使用map进行存储，一旦当前存储的值在map中，则说明该数字重复，
// 即输出true，否则一直到遍历结束，程序都没有return，则输出false，不存在重复数字的情况。
//
// 需要注意，对于输出false和true的情况，不要弄反了。
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        map<int, int> result;
        for (auto it = nums.begin(); it != nums.end(); it++) {
            if (result.count(*it) > 0) {
                return true;
            } else {
                result[*it] = 1;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Solution solution;
    bool result = solution.containsDuplicate(nums);
    cout << result << endl;
    return 0;
}