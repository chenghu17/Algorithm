//
// Created by Mr.Hu on 2018/6/12.
//
// leetcode 500 keyboard row
//
// 题目要求对于给定的string，判断是否能够在键盘上用单独的一行就能够写出来，是则输出该word
//
// 将每行字母的大小写用map<char,int>表示出来，然后对于每个word进行判断，每个char的value值是否相同
// 相同则继续，不相同则结束循环，继续下一个单词
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string> &words) {
        map<char, int> alphabet = {
                {'Q', 1},
                {'W', 1},
                {'E', 1},
                {'R', 1},
                {'T', 1},
                {'Y', 1},
                {'U', 1},
                {'I', 1},
                {'O', 1},
                {'P', 1},
                {'A', 2},
                {'S', 2},
                {'D', 2},
                {'F', 2},
                {'G', 2},
                {'H', 2},
                {'J', 2},
                {'K', 2},
                {'L', 2},
                {'Z', 3},
                {'X', 3},
                {'C', 3},
                {'V', 3},
                {'B', 3},
                {'N', 3},
                {'M', 3}};
        vector<string> result;
        for (int i = 0; i < words.size(); ++i) {
            int tmp = alphabet[toupper(words[i][0])];
            bool is = true;
            for (int j = 1; j < words[i].size(); ++j) {
                if (alphabet[toupper(words[i][j])] != tmp) {
                    is = false;
                    break;
                }
            }
            if (is)
                result.push_back(words[i]);
        }
        return result;
    }
};

int main() {
    vector<string> words;
    words.push_back("Hello");
    words.push_back("Alaska");
    words.push_back("Dad");
    words.push_back("Peace");

    Solution solution;
    vector<string> result = solution.findWords(words);
    for (auto it = result.begin(); it != result.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}