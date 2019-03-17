//
// Created by Mr.Hu on 2019/3/17.
//
// 统计字符串中回文子串的个数，不同的回文子串即起点索引值和终点索引值不同。

// 从子串长度为1到长度为n分别计算，而长度为k的子串可以通过起点和终点是否相同且k-2内部子串是否回文。

// 这里使用一个n*n的矩阵来表示起点终点子串的状态，该矩阵只有上三角需要状态更新。


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int s_length = s.length();
        vector<vector<int>> state(s_length, vector<int>(s_length));

        // 回文串长度
        for (int len = 1; len <= s_length; len++) {
            // 回文串起点
            for (int start = 0; start < s_length; start++) {
                int end = start + len - 1;
                if (end >= s_length) {
                    break;
                }
                if (start + 1 <= end - 1) {
                    if (s[start] == s[end] && state[start + 1][end - 1]) {

                        state[start][end] = 1;
                    }

                } else if (s[start] == s[end]) {
                    state[start][end] = 1;
                }
            }
        }

        // 计算状态中有多少个1即为回文子串的长度
        int count = 0;
        for (int i = 0; i < s_length; i++) {
            for (int j = i; j < s_length; j++) {
                if (state[i][j] == 1) {
                    count += 1;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
//    string s = "abc";
    string s = "aaa";
    int num = solution.countSubstrings(s);
    cout << "palindromic substrings number = " << num << endl;
    return 0;
}