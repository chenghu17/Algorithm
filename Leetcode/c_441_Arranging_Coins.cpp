//
// Created by Mr.Hu on 2018/6/18.
//
// leetcode 441 arranging coins
//
// 题目要求对于给定的n个coins，用来摆出楼梯形状，第k行又k个coins，求最多能够摆出多少行。
//
// 第一个想法就是用高斯求和的方法k*(k+1)/2>n来判断，我使用了一个很大的数字（大概一千万左右），执行出来没问题，
// 本以为这样没问题就说明可以了，但是提交之后还是提示error，当n取MAX_INT时报错；
// 所以我就用n每次去减去增加的那一行，即k个coins，来循环，这样下来越到最后n的值越小，就不会出现越界的情况，
// 而且减法运算相比乘除法快的多，所以有了一下code，accteped
//

#include <iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int k = 0;
        while (n - k >= 0) {
            n -= k;
            ++k;
        }
        return --k;
    }
};

int main() {
    int n = 111111111;
    Solution solution;
    int k = solution.arrangeCoins(n);
    cout << k << endl;
    return 0;
}