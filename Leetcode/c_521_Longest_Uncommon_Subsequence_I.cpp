//
// Created by Mr.Hu on 2019/1/15.
//
// leetcode 521 longest uncommon subsequence
//
// 题目给定两个字符串，要求找出两个字符串的最长非公共字符串，如果不存在，则返回-1；空串是任意字符串的子串。
//
// 从题目分析，不存在的情况即两个字符串相同时，找不到一个非公共子串。
// 如果两个字符串不相等，则最长的公共字符串即两个字符串中最长的字符串，因为该字符串肯定不是另外一个字符串的子串，且最长
// 所以这个题目就很简单啦。
//
// 这个题目刚开始给我一种最长公共子序列的恐惧，所以刚拿到题目就开始很复杂的考虑，这种先入为主的想法让我刚开始没有发现这个题目的潜在意思。
// 其实现在很多题目都暗含着非常简单的答案，需要我们仔细分析。
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        int a_len = a.length(), b_len = b.length();
        if (a != b) {
            return max(a_len, b_len);
        } else {
            return -1;
        }
    }
};

int main() {
    string a = "abstract", b = "introduction";
    Solution solution;
    int len = solution.findLUSlength(a, b);
    cout << "longest uncommon subsequence = " << len << endl;
    return 0;
}