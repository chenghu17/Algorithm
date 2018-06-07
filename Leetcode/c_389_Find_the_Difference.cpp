//
// Created by Mr.Hu on 2018/6/7.
//
// leetcode 389 find the difference
//
// 题目要求比较给定的两个字符串，其中第二个字符串比第一个字符串多一个字符，输出该字符
//
// 这个题目的思路比较简单，先定义一个大小为26的数组，与小写字母一一对应（对应关系通过ASCII码进行匹配）
// 遍历字符串s中出现的所有字符，并将其出现的次数记录，然后遍历字符串t中出现的字符，在s的记录上进行更新。
// 如果某一个字符所对应的值小于0，则说明该值所对应的字符为多出来的字符，将该字符return
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