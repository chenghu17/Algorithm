//
// Created by Mr.Hu on 2018/6/26.
//
// leetcode 215 kth largest element in an array
//
// 题目的要求是从数组中找出第k大的数字。这里的大小是基于不去重复的情况下。
//
// 在leetcode中这一题属于分治法中的一种，但是我想了一下，可以使用sort的方法解决，
// 对vector采用sort排序，默认从大到小，所以题目要求的第k大的数其所在位置为index=length-k；
// 最终accepted的结果超过了百分之七十多的accepted solution。
// 值得注意的是：vector的索引值如果越界，是不会报错的。
//
// 使用分治的思想解答也可以解答，即对于给定的第k大的数字，将原数组划分为k块，每块求其最大值，
// 最后输出k块中最小的那个数字。代码之后再更新。
// 今天考中特~

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int length = nums.size();
        sort(nums.begin(), nums.end());
        return nums[length - k];
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    int k = 3;
    Solution solution;
    int num = solution.findKthLargest(nums, k);
    cout << num << endl;
    return 0;
}