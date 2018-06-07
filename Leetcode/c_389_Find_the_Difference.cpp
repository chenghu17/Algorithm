//
// Created by Mr.Hu on 2018/6/7.
//
// leetcode 389 find the difference
//
// 题目要求比较给定的两个字符串，其中第二个字符串比第一个字符串多一个字符，输出该字符
//

#include <iostream>

using namespace std;


class Solution {
public:
    char findTheDifference(string s, string t) {
        int s_size = s.length();
        int alpha[26] = {};
        for (auto m:s)
            alpha[m - 97] += 1;
        for (auto m:t) {
            int result = alpha[m - 97] -= 1;
            if (result < 0) {
                return m;
            }
        }
    }
};

int main() {
    string s = "a";
    string t = "b";
    Solution solution;
    char difference = solution.findTheDifference(s, t);
    cout << difference << endl;
    return 0;
}