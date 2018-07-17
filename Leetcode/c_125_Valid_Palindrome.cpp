//
// Created by Mr.Hu on 2018/7/17.
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