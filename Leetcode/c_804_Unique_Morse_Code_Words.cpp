//
// Created by Mr.Hu on 2019/1/17.
//
// leetcode 804 unique morse code words
//
// 题目给定摩丝密码编码规则，要求对于给定的一些words，转换为摩丝密码编码，然后判断存在几个完全不同的编码内容。
//
// 先将每个词用摩丝密码加密，存入set中，因为set会自动去重，所以最后保留的个数即为非重复的个数。
//
// ⚠️：c++中数组初始化，使用的{...}，并不是[]
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string> &words) {
        string alphabet_morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
                                   ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
                                   "-..-", "-.--", "--.."};
        set<string> words_morse;
        for (auto str:words) {
            string tmp = "";
            for (int i = 0; i < str.length(); i++) {
                tmp += alphabet_morse[str[i] - 97];
            }
            words_morse.insert(tmp);
        }
        return words_morse.size();
    }
};

int main() {
    vector<string> words = {"gin", "zen", "gig", "msg"};
    Solution solution;
    int unique_size = solution.uniqueMorseRepresentations(words);
    cout << unique_size << endl;
    return 0;
}