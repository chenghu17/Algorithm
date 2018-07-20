//
// Created by Mr.Hu on 2018/7/20.
//
// leetcode 278 first bad version
//
// 题目已知当前产品有[1,n]个版本，当其中一个版本出错以后，其后版本都是错误的，给定isBadVersion来判断版本是否错误，找出第一个出错的版本
//
// 这个题目可以用二分查找来解决，首先要规定二分查找的左右边界和中间位置的计算方法：
// 如果isBadVersion返回false，说明当前版本为正确的，所以需要将左边界设置为middle+1；
// 如果为true，则当前版本是错误的，将当前版本号与目前最小版本号比较，取最小值，然后将右边界设置为middle-1；
// 最后的判断终止条件是left>right，则终止，返回最后the_first_version中保存的值。
//
// 但是在计算middle时遇到了一个问题，就是n的值比较大，且第一个错误版本的版本号也比较大，导致middle计算的时候超过了int的范围。
// 最后采用 middle=(int)(left/2.0+right/2.0)的方式来解决这个问题，因为只有这样，才不会导致middle数和原来计算方法得到值有偏差。
// 二分查找确实需要注意数字超过取值范围这个问题。
//

#include <iostream>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version) {
//    int the_first_right = 4;
    int the_first_right = 1029374982;
    return version >= the_first_right;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int middle;
        int the_first_version = n;
        while (left <= right) {
            middle = int(left / 2.0 + right / 2.0);
            if (!isBadVersion(middle)) {
                left = middle + 1;
            } else {
                the_first_version = min(the_first_version, middle);
                right = middle - 1;
            }
        }
        return the_first_version;
    }
};

int main() {
    Solution solution;
//    int the_first_version = solution.firstBadVersion(8);
    int the_first_version = solution.firstBadVersion(2003829183);
    cout << the_first_version << endl;
    return 0;
}