//
// Created by Mr.Hu on 2018/6/4.
//
// leetcode 231 power of two
//
// 题目要求判断整数n是否为2的乘方，即2的m次方能否等于n
//
// 这个题目的思路基本就是先判断数字的范围，<0则直接return false;
// 大于0，则进行循环，每次判断n是否能整除2，即if(n%2==0)，能整除则更新n=n/2，继续该循环。
// 如果不能整除，则说明无法用2的乘方来进行表示，即return false；
// 循环判断的条件即为n==1，如果n不断除以2后，最后等于1，说明最后一步为n=2/2，
// 即n是可以表示为2的乘方形式，则结束循环，最后return true
//


#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        while (n != 1) {
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n = 32;
    Solution solution;
    bool isornot = solution.isPowerOfTwo(n);
    cout << isornot << endl;
    return 0;
}