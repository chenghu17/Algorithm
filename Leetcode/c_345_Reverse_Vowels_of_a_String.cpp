//
// Created by Mr.Hu on 2018/6/20.
//
// leetcode reverse vowels of a string
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        set<int> voewls = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<int> tmp;
        for (int i = 0; i < s.size(); ++i) {
            if (voewls.count(s[i])) {
                tmp.push_back(s[i]);
            }
        }
        if (tmp.size() == 0) {
            return s;
        }
        reverse(tmp.begin(), tmp.end());
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (voewls.count(s[i])) {
                s[i] = tmp[count];
                ++count;
            }
        }
        return s;
    }
};

int main() {
    string s = "leetcode";
    Solution solution;
    string result = solution.reverseVowels(s);
    cout << result << endl;
    return 0;
}