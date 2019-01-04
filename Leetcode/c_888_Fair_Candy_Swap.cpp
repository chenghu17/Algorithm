//
// Created by Mr.Hu on 2019/1/4.
//
// leetcode 888 fair candy swap
//
// 这个题目给定一个场景，两个小女孩各有很多糖果，每个糖果的大小不一样，她们两个之间交换一个糖果，使得两个人拥有总量相同。
//
// 这个题目的关键在于，交换两个糖果a,b，实际带来的绝对变化是abs(a-b)*2，
// 而这个变化其实就等于原来两个女孩糖果的差量。
// 注意有一个两倍的关系存在。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B) {
        // A与B的差值，即交换的candy bars的size差值
        vector<int> exchange;
        int count_A = 0, count_B = 0, dif = 0;
        bool get_ans = false;
        for (auto i:A) {
            count_A += i;
        }
        for (auto j:B) {
            count_B += j;
        }
        dif = count_A - count_B;

        for (auto i:A) {
            for (auto j:B) {
                if (i - j == dif / 2) {
                    exchange.push_back(i);
                    exchange.push_back(j);
                    get_ans = true;
                    break;
                }
            }
            if (get_ans) break;
        }
        return exchange;
    }
};

int main() {
    vector<int> A, B;
    A.push_back(1);
    A.push_back(1);
    B.push_back(2);
    B.push_back(2);
    Solution solution;
    vector<int> ans = solution.fairCandySwap(A, B);
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}