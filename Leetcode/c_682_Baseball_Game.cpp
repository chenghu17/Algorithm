//
// Created by Mr.Hu on 2018/7/23.
//
// leetcode 682 baseball game
//
// 题目指定网球得分规则，要求返回最后的总分
//
// 由于每次记分需要用到之前单场的points，且是最近场次，因此使用stack来存储每场比赛的得分，
// 然后按照题目指定的规则进行计算。
// 当前code对最后的result也使用stack进行存储，其实只需记录当前result和最后一场的point，因为
// 规则中的特殊情况是"C"，即违规撤销分数，也只与最后一场的比分有关。
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int calPoints(vector<string> &ops) {
        stack<int> points;
        stack<int> sum_points;
        int last_point, last_last_point;
        for (auto val:ops) {
            if (val == "C") {
                sum_points.pop();
                points.pop();
                continue;
            } else if (val == "D") {
                points.push(points.top() * 2);
            } else if (val == "+") {
                last_point = points.top();
                points.pop();
                last_last_point = points.top();
                points.push(last_point);
                points.push(last_point + last_last_point);
            } else {
                points.push(stoi(val));
                if (sum_points.empty()) {
                    sum_points.push(points.top());
                    continue;
                }
            }
            sum_points.push(sum_points.top() + points.top());
        }
        return sum_points.top();
    }
};

int main() {
    vector<string> ops;
    ops.emplace_back("5");
    ops.emplace_back("2");
    ops.emplace_back("D");
    ops.emplace_back("C");
    ops.emplace_back("+");
    Solution solution;
    int result = solution.calPoints(ops);
    cout << result;
    return 0;
}