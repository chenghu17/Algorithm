//
// Created by Mr.Hu on 2018/8/28.
//
// 题目已知一个数组，每个元素表示一个房子内的金钱数目，且房子排列成环形，即第一个房子和最后一个房子相连。
// 现有一名强盗想要偷盗这些房子，若相邻两个房子子同一晚上被偷盗，则会除法警报。要求在不触发警报的前提下，
// 使得强盗能够尽可能多的偷到钱，求最大的金钱数。
//
// 不难发现，这是一道动态规划（dynamic programming）的题目，即"偷与不偷"（"选与不选"）的问题。
// 当前的状态影响这下一个状态，且要求最后求最大值。
// 我们可以得出这样一个公式 g(v) = max(f(a)+g(v-{a+b}),g(v-{a}))
// 其中a为某个房子，f(a)表示该房子内的金钱数，v为所有房子的集合，a，b为相邻的房子。
// 使用这样一个递推式，就可以求出最后的结果。
//
// 注意：这里第一个房子与最后一个房子是相连的，如果直接使用上面的递推公式，则不会考虑到这样一个前提条件，
// 因为题目给出的格式表示房子是连排的。所以我们需要在外部考虑两种情况：1、有第一个房子，但是没有最后一个房子；
// 2、没有第一个房子，但是有最后一个房子；所以我们在rot_or_not加入了一个length参数来规定是否考虑最后一个房子，
// 而index的初始化情况则可以规定是否考虑第一个房子。最后把这两种情况进行比较，取最大值。
//
// 采用这种递归的方式来解答问题有一个众所周知的问题：复杂度太高。这是因为子问题经常重复计算。
// 所以在处理动态规划的问题上，尽管递归可以使得代码简单，但手写循环并memorization的方式可以大大简化计算过程。
// 循环的方法这里还没有写，稍加研究后再update
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 这其实是一道选与不选的问题
    // 公式：g(v) = max{ a+g(v-{a+b}) , g(v-{a}) }

    int rob_or_not(vector<int> &nums, int index, int length) {
        if (index >= length) {
            return 0;
        }
        return max(nums[index] + rob_or_not(nums, index + 2, length), rob_or_not(nums, index + 1, length));
    }

    int rob(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        // 存在第一个房子,不存在最后一个房子
        int money1 = rob_or_not(nums, 0, nums.size() - 1);
        // 不存在第一个房子，存在最后一个房子
        int money2 = rob_or_not(nums, 1, nums.size());
        return max(money1, money2);
    }
};

int main() {
    vector<int> nums;
    nums.emplace_back(2);
    nums.emplace_back(16);
    nums.emplace_back(32);
    nums.emplace_back(12);
    nums.emplace_back(8);
    nums.emplace_back(6);
    nums.emplace_back(15);
    nums.emplace_back(1);
    nums.emplace_back(2);
    Solution solution;
    int max_money = solution.rob(nums);
    cout << max_money << endl;
    return 0;
}