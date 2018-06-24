//
// Created by Mr.Hu on 2018/6/24.
//
// leetcode 551 student attendance record I
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int Absent = 0;
        int Late = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'A') {
                ++Absent;
            }
        }
        if (Absent >= 2) {
            return false;
        }
        if (s.find("LLL") != string::npos) {
            return false;
        }
        return true;
    }
};

int main() {
    string s = "LLLL";
    Solution solution;
    bool reward = solution.checkRecord(s);
    cout << reward << endl;
    return 0;
}