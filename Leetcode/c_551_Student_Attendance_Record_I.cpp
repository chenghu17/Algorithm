//
// Created by Mr.Hu on 2018/6/24.
//
// leetcode 551 student attendance record I
//
// 题目要去根据给定的学生出勤情况，L(late)A(Absent)P(Present)来判断是否为学习进行奖励；
// 如果学生出现两次及以上的Absent，则返回false，或者有连续！连续！两次以上的late，则返回false；
//
// 这个题目解法比较直观，对于Absent，使用for循环统计次数，
// 对于Late，使用stringname.find("LLL")==string::npos?的方法来判断。
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