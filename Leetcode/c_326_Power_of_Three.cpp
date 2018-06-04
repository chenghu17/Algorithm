//
// Created by Mr.Hu on 2018/6/4.
//
// leetcode 326 power of three
//
// 这个题目要求判断n是否能否被3的乘方进行表示
// 和231题方法一模一样，不做过多解释，似乎存在位运算使得执行效率更高
//


#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        while (n != 1) {
            if (n % 3 == 0) {
                n /= 3;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n = 9;
    Solution solution;
    bool isornot = solution.isPowerOfThree(n);
    cout << isornot << endl;
    return 0;
}