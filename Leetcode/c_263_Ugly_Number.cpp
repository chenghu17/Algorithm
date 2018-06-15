//
// Created by Mr.Hu on 2018/6/15.
//
// leetcode 263 ugly number
//
// 题目定一个了一种数字：ugly，其因子只包含2、3、5
//
// 这个题目的解法比较直观，先判断数字是否为小于等于0的数字，是则返回false；
// 否则，判断数字能否被2、3、5整除，如果能整除，则将该数调整为除以2、3、5后的结果
// 如果最后不等于1或-1，则继续判断，如果数字不能被2、3、5整除，则return false；
// 如果能一直被2、3、5整除，直到最后结果为1，则结束循环，return true；
//


#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        } else {
            while (num != 1) {
                if (num % 2 == 0) {
                    num /= 2;
                } else if (num % 3 == 0) {
                    num /= 3;
                } else if (num % 5 == 0) {
                    num /= 5;
                } else {
                    return false;
                }
            }
            return true;
        }
    }
};

int main() {
    int n = 1111000;
    Solution solution;
    bool isugly = solution.isUgly(n);
    cout << isugly << endl;
    return 0;
}