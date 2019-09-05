//
// Created by Mr.Hu on 2019/9/5.
//
// 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
//
// f(1) = 1
// f(2) = f(1) + 1 = 2*f(1)
// f(3) = f(2) + f(1) + 1 = f(2) + f(2) = 2*f(2) = 2*2*f(1) = 2^2
// f(4) = f(3) + f(2) + f(1) + 1 = f(3) + f(3) = 2*f(3) = 2*2*f(2) = 2*2*2*f(1) = 2^3
// ...
// f(n) = 2^(n-1)
//

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        return pow(2, number - 1);
    }
};

int main() {
    int number;
    cin >> number;
    Solution solution;
    int solution_num = solution.jumpFloorII(number);
    cout << solution_num << endl;
    return 0;
}