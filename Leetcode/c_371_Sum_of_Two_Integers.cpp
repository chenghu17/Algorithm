//
// Created by Mr.Hu on 2019/3/29.
//
// leetcode 371 sum of two integers
//
// 题目要求不使用+/-求两个整数的和，这里使用位运算的方式。
// 分别计算不进位和进位的结果，然后将进位的结果整体左移一位，即表示已进位，
// 然后继续计算进位结果和不进位结果的和，知道进位值为0。
//

#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {

        while (b != 0) {
            // 不考虑进位，对位累加
            int res = a ^b;
            // 考虑进位，这里(~(1<<31))很重要，
            // a=-1，b=1时需要考虑符号位，然后会得到-0的情况
            b = (a & b & (~(1 << 31))) << 1;
            a = res;
        }
        return a;
    }
};

int main() {
    int a, b;
    cin >> a >> b;
    Solution solution;
    cout << solution.getSum(a, b) << endl;
    return 0;
}