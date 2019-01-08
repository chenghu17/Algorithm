//
// Created by Mr.Hu on 2019/1/8.
//
// leetcode uncommon words from two sentences
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {

        string word;
        map<string, int> word_count;
        vector<string> result;

        int left = 0;
        for (int i = 0; i < A.length(); i++) {
            if (A[i] == ' ') {
                word = A.substr(left, i - left);
                word_count[word]++;
                left = i + 1;
            }
        }
        word = A.substr(left, A.length() - left);
        word_count[word]++;

        left = 0;
        for (int i = 0; i < B.length(); i++) {
            if (B[i] == ' ') {
                word = B.substr(left, i - left);
                word_count[word]++;
                left = i + 1;
            }
        }
        word = B.substr(left, B.length() - left);
        word_count[word]++;

        for (auto it = word_count.begin(); it != word_count.end(); it++) {
            if (it->second == 1) result.push_back(it->first);
        }

        return result;
    }
};

int main() {
    string A = "there is an apple";
    string B = "Apple is not an apple";
    Solution solution;
    vector<string> result = solution.uncommonFromSentences(A, B);
    for (auto str:result) {
        cout << str << " ";
    }
    return 0;
}