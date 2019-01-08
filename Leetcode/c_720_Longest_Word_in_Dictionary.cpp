//
// Created by Mr.Hu on 2019/1/8.
//
// leetcode 720 longest word in dictionary
//
// 题目给定一些字符串，要求找出最长字符串，该字符串满足能够从其他字符串中依次得到，类似于查字典操作，如果存在相同长度的最长字符串，输出字符最小的那个一个。
//
// 刚开始并没有理解这个题目的意思，其本质就是查字典操作。
// 我们的目标就是从长度为1的字符串开始，然后查找长度为2的字符串，判断是否存在长度为1的前缀在字符串长度等于1的集合中，如果存在，则当前最长字符串更新。
// 依次类推。其实这中间存在一些trick，如果当前字符串的前缀没在某个长度的集合中出现，则该字符串应该从当前集合中删除，避免其为下一个长度的前缀，而扰乱结果。
// 如果遍历完一个集合，最后该集合所有的字符串都被删除了，或者说当前最长字符串没有更新，那说明之后不会存在更长的字符串，中间隔断了，因此整个循环可以结束。
//

#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    string longestWord(vector<string> &words) {
        map<int, set<string>> str_map;
        string result = "";
        str_map[0].insert("");
        for (string word:words) {
            str_map[word.length()].insert(word);
        }

        for (int i = 1; i <= 30; i++) {
            if (str_map[i].empty()) {
                break;
            }
            for (auto it = str_map[i].begin(); it != str_map[i].end(); it++) {
                string tmp = *it;
                if (str_map[i - 1].count(tmp.substr(0, i - 1))) {
                    // 字符较小，或者是第一个出现的时候
                    if (tmp < result || result.length() == i - 1) {
                        result = tmp;
                    }
                } else {
                    // 如果不存在该词的前缀，则该词也无法继续
                    str_map[i].erase(it);
                }
            }
            if (result.length() == i - 1) break;
        }
        return result;
    }
};

int main() {
    vector<string> words = {"w", "wo", "wor", "worl", "world"};
//    vector<string> words = {"yo", "ew", "fc", "zrc", "yodn", "fcm", "qm", "qmo", "fcmz", "z", "ewq", "yod", "ewqz", "y"};
    Solution solution;
    string longest = solution.longestWord(words);
    cout << longest << endl;
    return 0;
}