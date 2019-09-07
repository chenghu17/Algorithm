//
// Created by Mr.Hu on 2019/9/7.
//
// 题目要求对于给定的数字，确定其二进制表示中存在多少个1
// 注意，对于正数来说，每次左移，然后与1做与操作，则可以记录该值二进制表示存在多少1，
// 但是对于负数，每次左移，高位会补1，这样就会导致死循环。
//
// 第一种方法：既然给定数字左移无法解决问题，那么可以把与之做运算的1进行右移，这样对于正负数字来说，都是适用的。
//
// 第二种方法：n = (n-1) & n ??? n为负数的时候还是没太想明白二进制在处理减法时的方式，其实纯从二进制数的角度来考虑还是很直观的结果。
//
//

#include <iostream>

using namespace std;

class Solution {
public:
    int NumberOf1(int n) {
        int count = 0;
        if (n == 0) {
            return count;
        }
        int flag = 1;
        while (flag) {
            if ((n & flag)) {
                ++count;
            }
            flag = flag << 1;
        }
        return count;

    }

    int NumberOf1_2(int n) {
        int count = 0;
        while (n) {
            n = (n - 1) & n;
            ++count;
        }
        return count;

    }
};

int main() {

//    int n;
//    Solution solution;
//    int count;
//    while (cin >> n) {
//        count = solution.NumberOf1(n);
//        cout << "the number of one in binary: " << count << endl;
//    }
    return 0;
}