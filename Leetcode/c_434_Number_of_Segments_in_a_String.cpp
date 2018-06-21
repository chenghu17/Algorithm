//
// Created by Mr.Hu on 2018/6/21.
//
// leetcode 434 number of segments in a string
//

#include <iostream>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        bool hasWord = false;
        int length = s.size();
        int count = 0;
        for (int i = 0; i < length; ++i) {
            if (s[i] == ' ') {
                if (hasWord) {
                    ++count;
                    hasWord = false;
                }
                continue;
            }
            hasWord = true;
        }
        return hasWord ? ++count : count;
    }
};

int main() {
    string s = " hi, how are you? ";
    Solution solution;
    int result = solution.countSegments(s);
    cout << result << endl;
    return 0;
}