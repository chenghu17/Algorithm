//
// Created by Mr.Hu on 2019/1/20.
//
// leetcode 198 house robber
//
// 题目给定一个数组，表示一排房子中财物的数量，要求相邻的房子不能在一晚上同时被偷，否则会报警，求最多能够偷多少财物。
//
// 第一个想法就是递归的方式，简单的几行代码解决问题，但是...当数组比较大时，递归操作相当耗时。
//
// 于是用dp算法的memoization实现，即保存之前已经计算出来的结果，之后需要用到是，不需要重复计算。
// 这里使用和nums等大小的数组来表示每个位置上的最多财物数，然后在计算当前位置最大财物数时，即max(memory[i-1],nums[i]+memory[i-2])，
// 这个方法能够保证当前位置所能够偷到的是最大财物数，循环遍历所有位置，最后memory[nums.size()-1]即为所能偷到的财物数。
//
// 对于DP算法，应该尽量使用循环的方式来实现，毕竟递归方式对于简单的问题往往适得其反，时间复杂度太高。
//


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int rob_house(vector<int> &nums, int idx) {
        if (idx >= nums.size()) {
            return 0;
        }
        return max(rob_house(nums, idx + 1), nums[idx] + rob_house(nums, idx + 2));
    }

    int rob(vector<int> &nums) {
        return rob_house(nums, 0);
    }

    int rob_optimal(vector<int> &nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        if (size == 1) {
            return nums[0];
        }
        int memory[size];
        memory[0] = nums[0];
        memory[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            memory[i] = max(memory[i - 1], nums[i] + memory[i - 2]);
        }
        return memory[size - 1];
    }
};

int main() {
    vector<int> nums = {114, 117, 207, 117, 235, 82, 90, 67, 143, 146, 53, 108, 200, 91, 80, 223, 58, 170, 110, 236, 81,
                        90, 222, 160, 165, 195, 187, 199, 114, 235, 197, 187, 69, 129, 64, 214, 228, 78, 188, 67, 205,
                        94, 205, 169, 241, 202, 144, 240};

    Solution solution;
//    int max_count = solution.rob(nums);
    int max_count_optimal = solution.rob_optimal(nums);
//    cout << "recursion method result = " << max_count << endl;
    cout << "memoization method result = " << max_count_optimal << endl;
    return 0;
}