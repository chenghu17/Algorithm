//
// Created by Mr.Hu on 2018/7/23.
//
// leetcode 682 baseball game
//
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int calPoints(vector <string> &ops) {
        stack<int> points;
        stack<int> sum_points;
        int last_point, last_last_point;
        for (int i = 0; i < ops.size(); ++i) {
            if (ops[i] == "C") {
                sum_points.pop();
                points.pop();
                continue;
            } else if (ops[i] == "D") {
                points.push(points.top() * 2);
            } else if (ops[i] == "+") {
                last_point = points.top();
                points.pop();
                last_last_point = points.top();
                points.push(last_point);
                points.push(last_point + last_last_point);
            } else {
                points.push(stoi(ops[i]));
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

int main(){
    vector<string> ops;
    ops.emplace_back("5");
    ops.emplace_back("2");
    ops.emplace_back("D");
    ops.emplace_back("C");
    ops.emplace_back("+");
    Solution solution;
    int result = solution.calPoints(ops);
    cout<<result;
    return 0;
}