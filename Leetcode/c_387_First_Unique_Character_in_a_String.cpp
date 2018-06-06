//
// Created by Mr.Hu on 2018/6/6.
//
// leetcode 387 first unique character in a string
//
// 这个题目要求对于给定的字符串，寻找第一个只出现一次的字符，返回其index，如果不存在，则返回-1
//
//
//

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int index = -1;
        map<char, int> result;
        for (auto m:s) {
            result[m]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (result[s[i]] == 1) {
                index = i;
                break;
            }
        }
        return index;
    }
};

int main() {
    string s = "loveyouloveyou";
    Solution solution;
    int index = solution.firstUniqChar(s);
    cout << index << endl;
    return 0;
}