//
// Created by Mr.Hu on 2018/7/20.
//
// leetcode 704 binary search
//
// 题目是最基础的二分查找，对于有序数组，如果目标值存在与数组中，则返回该值在数组中的index值，如果不存在，则返回-1。
//
// 题目比较简单，但是在取middle值的时候，学到来一种新的方法 middle = left + (right-left)/2，
// 相比于之前直接 middle = (left + right)/2，这种方法可以避免当left和right都比较大时导致的取值范围超过int范围的情况。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int index = -1;
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        while (left <= right) {
//            middle = (left + right) / 2;
            // 这种写法更加灵活，可以避免之前在278中遇到的left+right超过int取值范围的情况
            middle = left + (left - right) / 2;
            if (nums[middle] == target) {
                index = middle;
                break;
            } else if (nums[middle] > target) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return index;
    }
};

int main() {
    vector<int> nums;
    nums.emplace_back(-1);
    nums.emplace_back(1);
    nums.emplace_back(11);
    nums.emplace_back(31);
    nums.emplace_back(51);
    nums.emplace_back(81);
    nums.emplace_back(121);
    Solution solution;
    int index = solution.search(nums, 11);
    cout << "the index is " << index << endl;
    return 0;
}