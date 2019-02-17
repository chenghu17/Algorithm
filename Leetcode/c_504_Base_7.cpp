//
// Created by Mr.Hu on 2019/2/17.
//
// leetcode 504 base 7
//
// 将给定数字转换为7进制的字符串形式
//
// 进制转换使用辗转相除法，将最终的余数从后向前拼接即可，注意如果是负数，对其非负部分转换，最后加上负号。
//

#include <iostream>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        string res = "";
        bool neg = num < 0;
        bool first = true;
        num = abs(num);
        while (num != 0 || first) {
            first = false;
            res = to_string(num % 7) + res;
            num /= 7;
        }
        return neg ? "-" + res : res;
    }
};

int main() {
    Solution solution;
    int num = 101;
    string res = solution.convertToBase7(num);
    cout << res;
    return 0;
}
