//
// Created by Mr.Hu on 2018/7/17.
//
// 题目要求判断给定字符串是否为回文串，只需要考虑字符串中的数组和字母，且忽略字母大小写
//
// 既然是回文串判断，则需要两个变量，分别指向字符串前后，并判断所指向的是否为字母或数字，
// 如果不是数字或字母，考虑下一位，继续判断，如果是数字或者字母，则继续判断，如果两个都是数字，则判断是否相等，
// 若两个都是字母，则判断是否相等，或者是否为大小写不同表示（ASCII码相差32）。
// 结束循环的条件就是letf>=right时，则表示已经将字符串遍历完毕
// 最后返回true。
//

#include<iostream>
using namespace std;

class Solution {
public:
    bool isnumber(char current) {
        return current >= '0' && current <= '9';
    }

    bool isalpha(char current) {
        return current >= 'a' && current <= 'z' || current >= 'A' && current <= 'Z';
    }

    bool isPalindrome(string s) {
        int length = s.size();
        if (length == 0) {
            return true;
        }
        int left = 0, right = length - 1;
        while (left < right) {
            if (!(isnumber(s[left]) || isalpha(s[left]))) {
                ++left;
                continue;
            }
            if (!(isnumber(s[right]) || isalpha(s[right]))) {
                --right;
                continue;
            }
            if (isnumber(s[left]) && isnumber(s[right])) {
                if (s[left] == s[right]) {
                    ++left;
                    --right;
                } else
                    return false;
            } else if (isalpha(s[left]) && isalpha(s[right])) {
                if (s[left] == s[right] || s[left] - s[right] == 32 || s[right] - s[left] == 32) {
                    ++left;
                    --right;
                } else
                    return false;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s = "abc";
    Solution solution;
    bool result = solution.isPalindrome(s);
    cout << result << endl;
    return 0;
}