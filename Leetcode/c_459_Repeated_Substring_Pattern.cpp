//
// Created by Mr.Hu on 2018/6/22.
//
// leetcode 459 repeated substring pattern
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int length = s.size();
        int pattern_size;
        string pattern, next_pattern;
        bool isPattern = false;
        for (int i = 2; i <= length; ++i) {
            if (length % i == 0) {
                pattern_size = length / i;
            } else {
                continue;
            }
            pattern = s.substr(0, pattern_size);
            for (int j = 0; j < i; ++j) {
                next_pattern = s.substr(j * pattern_size, pattern_size);
                if (pattern == next_pattern) {
                    isPattern = true;
                } else {
                    isPattern = false;
                    break;
                }
            }
            if (isPattern) {
                return true;
            }
        }
        return false;
    }
};

int main(){
    string s = "abcabcabc";
    Solution solution;
    bool result = solution.repeatedSubstringPattern(s);
    cout<<result<<endl;
    return 0;
}