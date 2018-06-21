//
// Created by Mr.Hu on 2018/6/21.
//
// leetcode 58 length of last word
//

#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.size();
        int result = 0;
        for (int i = length - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                if (result > 0) {
                    break;
                } else {
                    continue;
                }
            }
            ++result;
        }
        return result;
    }
};

int main() {
    string s = "helloworld";
    Solution solution;
    int result = solution.lengthOfLastWord(s);
    cout << result << endl;
    return 0;
}
