//
// Created by Mr.Hu on 2019/1/12.
//
// leetcode 453 minimum moves to equal array elements
//
// 题目给定一个数组，要求每次对数组中n-1个数字加1，直到所有数字相等则停止，求最少需要多少次操作。
//
// 这个题目困扰了几天，因为它并不是靠堆叠一些数据结构就能够完成的。
// 一开始使用最直接的逐步求解的方式，即每次对最小的n-1个数字加一，直到最后所有数都相等，则返回操作的次数，执行时间超过；
// 然后进行更改，发现每次判断最大值和最小值的差值，是当前需要操作的次数，然后对较小的n-1个数字加上操作次数后，再重复上述操作，直到最大最小数相同；
// 前面的大部分的case都能通过，但是当数组比较大时，还是会出现时间超时的情况。
//
// 查了一下别人的解答，在这里我们可以使用逆向思维，既然是n-1个最小的值都加一，等价于最大值减去1，
// 那么最后的终止情况就是所有值等于数组中的最小值，于是我们可以对数组中的每个数减去最小值，差累加则为最小的操作次数。
//
// math类别的题型：1、找规律；2、逆向思维
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minMoves(vector<int> &nums) {
        int min_num = INT_MAX;
        int sum_num = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum_num += nums[i];
            min_num = min(min_num, nums[i]);
        }
        return sum_num - min_num * nums.size();
    }
};

int main() {
    vector<int> nums = {1, 2, 1, 3, 4, 6, 7, 8, 2};
    Solution solution;
    int min_moves = solution.minMoves(nums);
    cout << "min moves = " << min_moves << endl;
    return 0;
}