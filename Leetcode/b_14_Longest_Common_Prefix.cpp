//
// Created by Mr.Hu on 2018/6/19.
//
// leetcode 14 longest common prefix
//
//
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