//
// Created by Mr.Hu on 2018/7/26.
//
// leetcode 594 longest harmonious subsequence
//
// 题目定义 harmonious subsequence 为最大值与最小值相差1的序列，不要求连续子序列
//
// 刚拿到这个题目的思想是对数组进行排序，然后排序数组中相邻变化为1的即满足条件，计算出现的次数，
// 但是我对于这种方法在边界问题上考虑欠缺，所以转向另外一种：
// 用map来存储每个数字出现的次数，然后遍历map，如果当前比当前pairwise中的key值大一的键值存在，
// 即map.count(cur.first+1)为true，则记录两个key出现的次数，并与当前最长序列数进行比较
// 这里主要是活用map的first,second，以及count()方法
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findLHS(vector<int> &nums) {
        map<int, int> n;
        int longest = 0;
        for (auto d:nums) {
            ++n[d];
        }
        for (auto m:n) {
            if (n.count(m.first + 1)) {
                longest = max(longest, m.second + n[m.first + 1]);
            }
        }
        return longest;
    }
};

int main() {
    vector<int> nums;
    int range = 80;
    for (int i = 0; i < range; ++i) {
        int number = rand() % (20 - 5 + 1) + 5;
        nums.emplace_back(number);
    }
    Solution solution;
    int longest = solution.findLHS(nums);
    cout << longest << " ";
    return 0;
}