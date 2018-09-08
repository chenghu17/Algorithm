//
// Created by Mr.Hu on 2018/9/8.
//
// 题目要求求出给定数字的最长连续数字和的表达式，如n=15，输出15= 1+2+3+4+5
//
// 刚开始把这个题目想复杂了，想着用高斯求和公式，固定开始的数字i，求长度，从而得到最长连续数列。
// 最后发现这个方法无法求解最终的结果。
// 其实这个题目的思路很简单，直接从1开始遍历循环，如果能够找到连续数列和==n，则该数列就是最长数列，因为它从一个很小的数字开始，
// 则说明需要更多的数字才能够达到==n的效果，此时无需继续往后遍历。
//
// 证明：如果存在两个开始值a,b(a<b)，使得连续数列和等于n，那么有n=a+(a+1)+(a+2) ... ; n = b+(b+1)+(b+2) ...
// 由于a<b，那么对应后面的每一项前者都要小于后者，而最终的和为n，则说明前者数列中需要更多的数字才能够达到和为n这一条件。
// 因此如果只需要返回最长数列，只需要遇到a这种情况即可，后面情况无需遍历。
//

#include <iostream>
using namespace std;

int main() {
    int n, i, count;
    bool exist = false;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        count = 0;
        for (int j = i; j <= n; ++j) {
            count += j;
            if (count == n) {
                exist = true;
                break;
            }
            if (count > n) {
                break;
            }
        }
        if (exist) {
            break;
        }
    }
    cout << n << "=";
    count = 0;
    for (; i <= n; ++i) {
        count += i;
        if (count < n) {
            cout << i << "+";
        } else if (count == n) {
            cout << i;
            break;
        }
    }
    return 0;
}
