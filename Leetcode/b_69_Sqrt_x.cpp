//
// Created by Mr.Hu on 2018/6/25.
//
// leetcode 69 sqrt x
//
// 题目要求求x的平方根，如果非整数，则只返回其整数部分
//
// 这个题目就相等于搜索一个自然数数列，即符合二分查找的要求：有序且非重复
//
// 采用binary search的方法，循环终止条件为left>right，初始化left=0，right=x/2，
// 如果存在数mid的平方等于x，则return mid；否则一直循环，直到left>right，循环结束。
// 我们可以分析一下，在left>right之前，left==right，而此时mid也和它们相等，要么mid*mid>x，此时right-=1；
// 要么mid*mid<x，此时left+=1，所以最终的结果都是left*left>x并且right*right<x，因此最终的结果就是right的值，
// 或者说是left-1
//
// 但是有一个特殊情况，x=1时，我们需要单独判断。
//

#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) {
            return 1;
        }
        long left = 0;
        long right = x / 2;
        long mid;
        while (left <= right) {
            mid = (left + right) / 2;
            long result = mid * mid;
            if (result == x) {
                return mid;
            } else if (result < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left - 1;
    }
};

int main() {
    int x = 100;
    Solution solution;
    int result = solution.mySqrt(x);
    cout << result << endl;
    return 0;
}