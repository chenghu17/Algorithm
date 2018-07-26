//
// Created by Mr.Hu on 2018/7/26.
//
// 题目要求判断一个数能否被写成两个数的平方和形式
//
// 刚开始把这个题目想复杂了，以为是要考虑直角三角形的三条边的情况，
// 后来发现只需要遍历就行，将两个数值结果固定在0-sqrt(c)之间，
// 当两个数的平方和大于c，则--end;小于c，++begin；
// 为什么在--end之后，不需要考虑比begin小的值呢？因为--end说明结果>c，考虑比begin小的值只会更小；
// 对++begin不需要考虑比end大的值原因相同
//

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int begin = 0, end = sqrt(c);
        long result;
        while (begin <= end) {
            result = begin * begin + end * end;
            if (result == c) {
                return true;
            } else if (result > c) {
                --end;
            } else {
                ++begin;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
//    bool result = solution.judgeSquareSum(12345678);
    bool result = solution.judgeSquareSum(4);
    cout << result << endl;
    return 0;
}