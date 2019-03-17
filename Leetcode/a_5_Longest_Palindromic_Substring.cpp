//
// Created by Mr.Hu on 2019/3/17.
//
// 这里使用判断字符串回文子串的方法来找最长的回文串
//
// 还有一种方法就是假设每个点作为中间节点，然后左右指针往两边延伸，遍历每个点作为中间节点的最长回文串情况即可。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        int s_length = s.length();
        if (s_length == 0) {
            return s;
        }

        vector<vector<int>> state(s_length, vector<int>(s_length));

        int max_len = 0;
        string max_s = "";

        for (int len = 1; len <= s_length; len++) {
            for (int start = 0; start < s_length; start++) {

                int end = start + len - 1;

                if (end >= s_length) {
                    break;
                }

                if (start + 1 <= end - 1) {
                    if (s[start] == s[end] && state[start + 1][end - 1]) {
                        state[start][end] = 1;
                        if (len > max_len) {
                            max_len = len;
                            max_s = s.substr(start, len);
                        }
                    }
                } else if (s[start] == s[end]) {
                    state[start][end] = 1;
                    if (len > max_len) {
                        max_len = len;
                        max_s = s.substr(start, len);
                    }
                }
            }
        }

        return max_s;
    }
};

int main() {
    Solution solution;
    string s = "babad";
//    string s = "cbbd";
    string longest_s = solution.longestPalindrome(s);
    cout << longest_s << endl;
    return 0;
}