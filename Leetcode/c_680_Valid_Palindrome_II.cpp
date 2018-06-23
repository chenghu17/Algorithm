//
// Created by Mr.Hu on 2018/6/23.
//
// leetcode 680 valid palindrome
//
// 题目要求判断给定的字符串能否通过删除最多一个字符使其为回文串，能则返回true，否则返回false；
//
// 这个题目的蛮力解法是先判断字符串是否为回文串，是则返回true；不是，则通过删除从第一个字符到最后一个字符，
// 每次判断剩下的子串是否为回文串，但是这样做的时间复杂度可以达到n square。
//
// 第二种方式是先判断当前字符串首尾是否相等即i与length-i-1，如果相等，则继续判断i+1与length-i-2是否相等，
// 如果一直相等，循环结束后返回true。如果存在不等的情况，则存在两种可能的情况：
// 第一种为i为多余字符，第二种为length-i-1为多余字符，所以将除去这两个位置的子串其实位置分别传入isPalindrome的方法中，
// 继续判断剩下的字符串是否能构成回文串，如果两种情况中有一种可以，则最终返回true，如果都不可以，则返回false。
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int begin, int end) {
        for (int j = begin; j < (end + begin + 1) / 2; ++j) {
            if (s[j] != s[end + begin - j]) {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int length = s.size();
        bool palindrome = true;
        for (int i = 0; i < length / 2; ++i) {
            if (s[i] != s[length - 1 - i]) {
                return isPalindrome(s, i + 1, length - 1 - i) || isPalindrome(s, i, length - 2 - i);
            }
        }
        return true;
    }
};

int main() {
    string s = "abcdedcbae";
    Solution solution;
    bool valid_palindrome = solution.validPalindrome(s);
    cout << valid_palindrome << endl;
    return 0;
}