//
// Created by Mr.Hu on 2018/4/6.
//
// leetcode 283 Move Zeros
// 题目要求将给定数组中所有非零数移到数组前面，所有零元素移动到数组后面
// 由于题目要求的是in-place，所以不能用一个新的数组进行存储
// 想到之前leetcode 26中的方法，如果数字为0，则无需操作，继续判断下一个数字，
// 如果数字不为0，则需要与第一个不为0的数字进行交换，所以解题思路就是当前数字不为0时，找到第一个为0的位置，交换
// 执行完之后查看了submission detail，发现该方法的运行时间只击败了1.18%的方法，累...
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                // get the first zero index
                int index = INT_MAX;
                for (int j = 0; j < size; j++) {
                    if (nums[j] == 0) {
                        index = j;
                        break;
                    }
                }
                // swap
                if (i > index) {
                    nums[index] = nums[i];
                    nums[i] = 0;
                }
            }
        }
    }
};

int main() {
    vector<int> nums = {0, 1, 2, 0, 12, 3};
    Solution solution;
    solution.moveZeroes(nums);
    auto it = nums.begin();
    for (it; it != nums.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}
