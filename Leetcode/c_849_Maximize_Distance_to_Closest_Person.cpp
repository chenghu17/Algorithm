//
// Created by Mr.Hu on 2019/1/5.
//
// leetcode 849 maximize distance to closest person
//
// 题目给定一个场景：已知有一排座位，用数组表示，座位上有人的为1，没有人的为0，要求找出一个位置，使得该位置离其最近人之间的距离最大。
//
// 这个题目的思路就是找到最大值的情况，对数组从左向右进行遍历，用两个值分别记录当前最近左边人的位置和当前最近右边人的位置。
// 需要注意的是，在数组中，可能左边没有人，这只在搜索的第一次出现；也有可能右边没有人，这只在最后出现。
// 如果左边/右边没有人，那么坐在最边上会使得离最近的人距离最大；
// 如果左右都有人，那么坐在中间位置离最近人的距离最大。而此时的距离就是(right-left)/2，这里不需要考虑减1还是不减1。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int> &seats) {
        int seats_num = seats.size();
        int max_dist = 1;
        // 考虑起始为0的情况
        int left, right;
        if (seats[0] == 0) {
            left = -1;
        } else {
            left = 0;
        }
        for (int i = 1; i < seats_num; i++) {
            if (seats[i] == 0) {
                continue;
            } else {
                right = i;
                if (left == -1) {
                    max_dist = max(max_dist, right);
                    left = right;
                } else {
                    max_dist = max(max_dist, (right - left) / 2);
                    left = right;
                }
            }
        }
        // 考虑最后结尾为0，不为0也一并考虑了
        max_dist = max(max_dist, seats_num - 1 - left);
        return max_dist;
    }
};

int main() {
    vector<int> seats;
    seats.push_back(1);
    seats.push_back(0);
    seats.push_back(0);
    seats.push_back(1);
    seats.push_back(0);
    seats.push_back(1);
    seats.push_back(1);
    Solution solution;
    int max_dist = solution.maxDistToClosest(seats);
    cout << "max distance:" << max_dist << endl;
    return 0;
}