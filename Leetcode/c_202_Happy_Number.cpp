//
// Created by Mr.Hu on 2018/5/12.
//
// leetcode 202 happy number
// 题目要求对于给定的数字，计算数字上每一位的平方和，对结果继续上述操作，如果存在平方和等于1，则该数为happy number。
//
// 根据题目要求可以发现，这是一个多次迭代的过程，如果当前平方和为1，则return true，
// 如果不等于1，则继续结果各个位数的平方和。在这个过程中，可能会出现平方和不等于1，且在之前出现过，
// 则说明出现了"死循环"，这个数是一定不可能称为happy number，此时就要结束迭代，return false。
// 根据这个思路，则需要把之前出现的数字记录下来，所以使用map进行存储，如果key所对应的value值为1，则说明出现过。
//
// 写完这个代码之后没有像之前那样直接提交，先自己审查了一遍，发现自己在编写的时候有结果小问题，比如拼写问题。
// 测试的时候出现了一个错误，就是我将mapname直接写成了map，糊涂了...更改后顺利通过测试，并且超过了85%的答案
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