//
// Created by Mr.Hu on 2018/6/19.
//
// leetcode 14 longest common prefix
//
// 题目要求识别出给定字符串集合中，所有字符串共有的最长前缀，如果不存在，则返回""
//
// 这个题目就是要逐个去筛选，而在筛选的过程中，如果我们从字串长度为1开始逐个递加，
// 则每次需要判断长度是否大于当前最短字符串的长度，并且还要将当前最长的进行保存，用于下一次最长判断。
// 所以我在这里就先将所有字符串中最小长度minimize_size筛选出来，然后以此长度来得到所有字符串的字串进行比较，
// 如果不相同，--minimize_size；如果相同，则当前最串为最长公共字串。
// 另外需要考虑字符串集合为空集的情况，直接返回""
//
// 这个题目让我复习来vector的长度使用vectorname.size()来计算
// vector中最小最大的数字使用auto smallest = min_element(max_element)(vectorname.begin(),vectorname.end())
// 最大最小值为：*biggest、*smallest
// vector中找到最小最大数字的索引位置 distance(vectorname.begin(),smallest)
//


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        vector<int> word_size;
        int word_number = strs.size();
        if (word_number == 0) {
            return "";
        }
        int count = 1;
        for (int i = 0; i < word_number; ++i) {
            word_size.push_back(strs[i].size());
        }
        auto min_size = min_element(word_size.begin(), word_size.end());
        int minimize_size = *min_size;
        string tmp;
        bool is_same_prefix;
        while (minimize_size >= 0) {
            tmp = strs[0].substr(0, minimize_size);
            is_same_prefix = true;
            for (int i = 1; i < word_number; ++i) {
                if (strs[i].substr(0, minimize_size) != tmp) {
                    is_same_prefix = false;
                    break;
                }
            }
            if (is_same_prefix) {
                return tmp;
            }
            --minimize_size;
        }
    }
};

int main() {
    vector<string> strs;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");
    Solution solution;
    string common_prefix = solution.longestCommonPrefix(strs);
    cout << common_prefix << endl;
    return 0;
}