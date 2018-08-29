//
// Created by Mr.Hu on 2018/8/29.
//
// 题目要求找出最小长度连续子数组，使得子数组的和大于等于给定的s值，返回子数组的长度
//
// 方法一、（BF方法）使用双层循环，第一层表示子数组开始的位置，第二层表示连续子数组累加过程，知道累加和大于等于s，
// 则比较当前长度与之前最小长度，取最小情况。
//
// 方法二：（使用二分法）
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int length = nums.size();
        if (length == 0) {
            return 0;
        }
        int min_length = length;
        int tmp, sum_num;
        for (int i = 0; i < length; ++i) {
            tmp = 1;
            sum_num = nums[i];
            if (sum_num >= s) {
                return 1;
            }
            for (int j = i + 1; j < length; ++j) {
                sum_num += nums[j];
                tmp += 1;
                if (sum_num >= s) {
                    break;
                }
            }
            if (sum_num >= s) {
                min_length = tmp < min_length ? tmp : min_length;
            } else if (i == 0) {
                return 0;
            }
        }
        return min_length;
    }
};

int main() {
    vector<int> nums;
    nums.emplace_back(2);
    nums.emplace_back(1);
    nums.emplace_back(3);
    nums.emplace_back(5);
    nums.emplace_back(2);
    nums.emplace_back(3);
    nums.emplace_back(1);
    int s = 7;
    Solution solution;
    int min_length = solution.minSubArrayLen(s, nums);
    cout << min_length << endl;
    return 0;
}