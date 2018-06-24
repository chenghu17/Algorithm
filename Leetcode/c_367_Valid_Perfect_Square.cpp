//
// Created by Mr.Hu on 2018/6/24.
//
// leetcode 367 valid perfect square
//
// 题目要求判断正整数num是否能写成某个数的平方
//
// 第一种想法：想要判断是否为某个数的平方，那么可以计算每个数的平方，直到结果等于num或者大于num就能得到最终的结果；
// 但是考虑到每次计算i的平方比较耗时，而相邻两个数之间的平方存在关系，即对于i的平方result=i*i；i+1的平方等于result+(i+i-1)；
// 随意每次保留上一个数的平方，然后采用加减法即可得到当前数字的平方和，与num进行比较即可。
// 但是这种方法的耗时还是相当高。
//
// 查看了一下别人的实现方法，采用二分查找的方式，num的开方结果只会存在与[0,(num+1)/2]这个区间，
// 所以初始化left=0；right=(num+1)/2；mid=(left+right)/2，判断mid*mid与num的大小，如果相等，则我们比较幸运，return true；
// 如果mid*mid>num，则更新right=mid-1，注意这里是mid-1，因为mid的平方已经大于num了，所以右边界设置为mid-1；
// 如果mid*mid<num，则更新left=mid+1，理由同时，
// 而上述循环的条件就是left<=right，因为到最后一个数字，即left=right时，如果还是不想等，要么left+1，要么right-1；
// 会导致left>right的情况，而此情况就表面最终不存在这样一个值，其平方等于num，最后返回false。
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int result = 0;
        for (int i = 1; i <= num / 2 + 1; ++i) {
            result += 2 * i - 1;
            if (result == num) {
                return true;
            }
            if (result > num) {
                return false;
            }
        }
        return false;
    }

    bool isPerfectSquare_optimal(int num) {
        long left = 0;
        long right = (num + 1) / 2;
        long mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            long result = mid * mid;
            if (result == num) {
                return true;
            } else if (result < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    int num = 16;
    Solution solution;
//    bool valid_square = solution.isPerfectSquare(num);
    bool valid_square = solution.isPerfectSquare_optimal(num);
    cout << valid_square << endl;
    return 0;
}