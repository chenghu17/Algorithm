//
// Created by Mr.Hu on 2018/6/23.
//
// leetcode 680 valid palindrome
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