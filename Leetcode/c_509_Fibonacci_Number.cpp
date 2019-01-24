//
// Created by Mr.Hu on 2019/1/24.
//
// leetcode 509 fibonacci number
//
// 题目为斐波那契数列，求解第N个数字，要求N在[0,30]闭区间内。
//
// fibonacci数列的递推公式给出 F(N) = F(N-1) + F(N-2)
// 我们可以使用递归的方式进行计算，但是递归方法的时间复杂度很高，所以我们这里采用循环的方式，
// 不难发现，每个数等于前两个数字的和，那么只需要每次保留前两个数字即可，
// 从2开始，每次保留前两个数字，直到N，最后的数字即为第N个数字。
// 这样做时间复杂度远远小于递归方式。
// 需要注意的是，这里N给定的范围比较小，所以我们可以直接用加法，当N比较大时，会超过int范围，我们就要考虑大数加法操作。
//

#include <iostream>

using namespace std;


class Solution {
public:
    int fib(int N) {
        if (N == 0) {
            return 0;
        }
        if (N == 1) {
            return 1;
        }
        int last1 = 0, last2 = 1, tmp;
        for (int i = 2; i <= N; i++) {
            tmp = last1 + last2;
            last1 = last2;
            last2 = tmp;
        }
        return last2;
    }
};

int main() {
    int N = 20;
    Solution solution;
    int num_N = solution.fib(N);
    cout << num_N << endl;
    return 0;
}