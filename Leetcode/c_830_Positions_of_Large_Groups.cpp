//
// Created by Mr.Hu on 2018/6/30.
//
// leetcode 830 positions of large groups
//
// 题目要求对于字符串s，找出所有连续出现超过三次的字符的起始位置
//
// 题目的思路比较清楚，需要注意的地方一方面是初始化，一方面是字符串结尾，这两部分处理好后，
// 不会存在什么难点，然后就是vector的clear()操作，刚开始写成了clean()操作。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector <vector<int>> largeGroupPositions(string S) {
        vector<int> tmp;
        vector <vector<int>> result;
        char current = S[0];
        int left = 0, right = 0;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] != current || i == S.size() - 1) {
                if (S[i] != current) {
                    right = i - 1;
                } else {
                    right = i;
                }
                if (right - left >= 2) {
                    tmp.push_back(left);
                    tmp.push_back(right);
                    result.push_back(tmp);
                    tmp.clear();
                }
                left = i;
                current = S[i];
            }
        }
        return result;
    }
};

int main(){
    string S = "abccccxxxxcfddsssw";
    Solution solution;
    vector<vector<int>> result = solution.largeGroupPositions(S);
    return 0;
}