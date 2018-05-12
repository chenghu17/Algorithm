//
// Created by Mr.Hu on 2018/5/12.
//
// leetcode 202 happy number
// 题目要求对于给定的数字，计算数字上每一位的平方和，对结果继续上述操作，如果存在平方和等于1，则该数为happy number。
//
//

#include <iostream>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        map<int, int> tmp;
        tmp[n] = 1;
        while (1) {
            int m = 0;
            int result = 0;
            while (n != 0) {
                m = n % 10;
                n /= 10;
                result += pow(m, 2);
            }
            if (result == 1) {
                return true;
            } else {
                if (tmp[result] == 1) {
                    return false;
                } else {
                    tmp[result] = 1;
                    n = result;
                }
            }
        }
    }
};

int main() {
    int n = 10;
    Solution solution;
    bool isHappyNumber = solution.isHappy(n);
    cout << isHappyNumber << endl;
}