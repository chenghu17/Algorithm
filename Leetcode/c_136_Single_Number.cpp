//
// Created by Mr.Hu on 2018/5/1.
//
// leetcode 136 single number
//
// 题目给定非空数组，数组中除了一个元素只出现一次，其他元素都出现两次，要求找出只出现一次的元素
// 这个题目基本就是练习使用hash table，使用map来存储元素值以及其出现的次数，最后使用迭代器来遍历map
// mapname->secode表示元素出现的次数，mapname->first表示对应的元素值。
// 但是这样的解题方式很慢，用了太多的封装好的数据结构以及两次遍历。
// 题目要求尽量不适用额外的空间...
//
// 在网上看到了另外一种optimal方法
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

    int singleNumber_optimal(vector<int> &nums) {
        int size = nums.size();
        int result = nums[0];
        for (int i = 1; i < size; i++) {
            result ^= nums[i];
        }
        return result;

    }

};

int main() {
    vector<int> nums = {1, 1, 2, 2, 4};
    Solution solution;
    int result = solution.singleNumber_optimal(nums);
    cout << result << endl;
    return 0;
}