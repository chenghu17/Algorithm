//
// Created by Mr.Hu on 2018/6/5.
//
// leetcode 258 add digits
//
// 题目要求对于给定的数字n，计算其各个位置上数字之和，如果和大于10，则继续上述操作，直到最后结果小于10
//
// 最直观的一种解法：对数字求模十求余累加，判断结果是否大于10，大于则重复该操作，直到结果小于10
// 双while循环，第一个while为判断结果是否大于10，第二个while则是对数字求每位上的值然后累加。
//
// 第二种方法复杂度为O(1)，使用的是同余定理
//


#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int tmp = num;
            int result = 0;
            while (tmp != 0) {
                result += tmp % 10;
                tmp /= 10;
            }
            num = result;
        }
        return num;
    }

    int addDigits_optimal(int num) {
        return 1 + (num - 1) % 9;
    }
};

int main() {
    int n = 100;
    Solution solution;
    int result = solution.addDigits(n);
    cout << result << endl;
    return 0;
}