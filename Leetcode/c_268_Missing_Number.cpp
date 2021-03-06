//
// Created by Mr.Hu on 2018/4/11.
//
// leetcode 268 missing number
// 问题描述为给定一个数组，数组由0,1,2,3,...,n组成，但是这个数组当中存在一个数字丢失，
// 请使用线性复杂度、常数量的空间复杂度进行解决
//
// 已经由四五天没有做题了，清明回家了几天，这几天时间过的好快，让我颇感压力，刷题速度要提高了
// 拿到这一题，最直白的想法就是嵌套循环，从0到n判断，不存在的即为missing number，则输出。
// 但是考虑的题目对时间和空间复杂度的要求，必然不能这么做，于是想到如果要找出missing number，
// 则可以先把给定的数组进行排序，哪个数字不在即为所求；用空间代时间的方式，用一个数组来存储给定数组的值，
// 由于初始化数组所有数默认为0，但是如果恰好是第一个数不存在，则无法区分是不存在还是存在，所以初始化时将第一个数字初始化为-1，或其他不为0的数
// 然后再判断，时间复杂度O(n)。leetcode编译器和本机编译器环境不同，本机需要动态声明数组，而leetcode可以直接用变量设置为数组空间。
// 所以需要注意c++和c各种不同编译版本情况
//
// 查看了一下执行时间，发现只超过来9%左右，发现自己无法沉下来去想新方法，就去查了一下好的方法
// 查了方法之后，发现原来...如此简单，因为每次只丢失一个数字，那丢失的数字应该就是原连续数组和减去现在的数组和
// ...心酸...这都没想到...
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int n = nums.size();
        int *tmp = new int[n + 1];
        tmp[0] = -1;
        for (int i = 0; i < n; i++) {
            int index = nums[i];
            tmp[index] = index;
        }
        for (int i = 0; i <= n; i++) {
            if (tmp[i] == 0 && i != 0 || tmp[i] == -1)
                return i;
        }
    }

    int missingNumber_optimal(vector<int> &nums) {
        int n = nums.size();
        int std_sum = 0;
        int sum = 0;
        for (int i = 0; i <= n; i++) {
            std_sum += i;
        }
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        return std_sum - sum;
    }
};

int main() {
    vector<int> nums = {3, 0, 1};
    Solution solution;
    int result = solution.missingNumber(nums);
    cout << result << endl;
    int result_optimal = solution.missingNumber_optimal(nums);
    cout << result_optimal << endl;
    return 0;

}