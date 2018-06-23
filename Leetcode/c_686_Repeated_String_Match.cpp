//
// Created by Mr.Hu on 2018/6/23.
//
// leetcode 686 repeated string match
//
// 题目要求对于字符串A、B，将字符串A定义为模式串，求最少重复拼接多少次，可以使得字符串B为拼接后字符串的子串，
// 返回重复次数，如果不存在，则返回-1。
//
// 这个题目的突破点在于：如果字符串B的size为字符串A的整数n倍，那么字符串A最小的重复次数为n或者n+1，否则为-1；
// 所以我们先将字符串A重复n次，然后判断重复后的字符串all是否包含字符串B，是则返回n；否则再将字符串A多重复一次，
// 继续判断当前字符串all是否包含字符串B，是则返回n+1，否则返回-1。
//
// 在coding过程中，了解了STL中对string判断是否为子串的另一种方法：stringname.find(substring)!=string::npos，
// 则说明substring为stringname的子串，否则不是子串。
//

#include <iostream>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        if (A == B) {
            return 1;
        }
        auto length_a = (int) A.size();
        auto length_b = (int) B.size();
        int count = length_b / length_a;
        if (length_b % length_a != 0) {
            count += 1;
        }
        if (length_a > length_b) {
            count = 1;
        }
        string all;
        for (int i = 0; i < count; ++i) {
            all += A;
        }
        for (int i = 0; i <= all.size() - length_b; ++i) {
            string sub = all.substr(i, length_b);
            if (sub == B) {
                return count;
            }
        }
        all += A;
        for (int i = 0; i <= all.size() - length_b; ++i) {
            string sub = all.substr(i, length_b);
            if (sub == B) {
                return count + 1;
            }
        }
        return -1;
    }

    int repeatedStringMatch_optional(string A, string B) {
        string all = A;
        int count = 1;
        while (all.size() < B.size()) {
            count += 1;
            all += A;
        }
        if (all.find(B) != string::npos) {
            return count;
        } else if ((all += A).find(B) != string::npos) {
            return count + 1;
        }
        return -1;
    }
};

int main() {
    string A = "abc";
    string B = "abcabc";
    Solution solution;
//    int count = solution.repeatedStringMatch(A, B);
    int count = solution.repeatedStringMatch_optional(A, B);
    cout << count << endl;
    return 0;
}