//
// Created by Mr.Hu on 26/03/2018.
//
// leetcode 35 Insert Position
// 在有序数组中，找出给定target的插入位置
// 相等则输出当前位置，属于两个数之前，则输出后一个数字的位置
// 若最大或者最小，则输出最后位置或第一个位置
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int size = nums.size();
        if (nums[0] > target)
            return 0;
        if (nums[size - 1] < target)
            return size;
        for (int i = 0; i < size; i++) {
            if (nums[i] == target)
                return i;
            else if (nums[i] > target) {
                return i;
            }
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int target = 1;
    Solution solution;
    int position = solution.searchInsert(nums, target);
    cout << position << endl;
    return 0;

}