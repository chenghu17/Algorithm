//
// Created by Mr.Hu on 2019/9/5.
//
// 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
//
// f(n) = f(n-2) + f(n-1)
// 注意n=1或n=2的特殊情况
//

#include <iostream>

using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        int first = 1, second = 2;
        if (number <= 0) {
            return 0;
        }
        if (number == 1 || number == 2) {
            return number;
        }
        number -= 2;
        int cur = 0;
        while (number > 0) {
            cur = first + second;
            first = second;
            second = cur;
            --number;
        }
        return cur;
    }
};

int main() {
    int number;
    cin >> number;
    Solution solution;
    int method_num = solution.jumpFloor(number);
    cout << method_num << endl;
    return 0;
}