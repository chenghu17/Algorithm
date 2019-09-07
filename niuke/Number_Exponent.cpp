//
// Created by Mr.Hu on 2019/9/7.
//
// 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
// 保证base和exponent不同时为0
//
// 这个题目提交了好几次才ac，因为自己考虑不全，导致刚开始的解法有问题，刚开始认为可以以二分的方式，对exponent开方，然后去计算此时需要的base，
// 而这个base也是不断去开方，这就导致一个问题，开方后，还剩下的待乘结果比较大。。。就无法预估
//
// 这里我们需要主要几点：1、指数是所有整数，即负数、0、正数；2、为了快速的求得结果，肯定不能够循环乘上base，应该要巧用base；
// 分析：我们可以把base^exponent分解为：base*(base^2)*(base^4)*(base*8)...因为任意一个正整数，是肯定可以用2^0+2^1+2^2+2^3...来表示的，
// 因为任意一个正整数是可以用二进制表示，所以我们可以把exponent转换为二进制形式，而对应结果的乘数因子应该是base^(2^m)，而这个因子可以一步一步得到
// 实现如下
//

#include <iostream>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent == 0) {
            return 1;
        }
        int n = abs(exponent);
        double res = 1.0, cur = base;
        while (n) {
            if (n & 1) {
                res *= cur;
            }
            cur *= cur;
            n = n >> 1;
        }
        return exponent < 0 ? 1 / res : res;
    }
};

int main() {
    double base;
    int exponent;
    cin >> base >> exponent;
    Solution solution;
    double res = solution.Power(base, exponent);
    cout << res << endl;
    return 0;


}