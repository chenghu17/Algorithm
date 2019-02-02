//
// Created by Mr.Hu on 2019/2/2.
//
// leetcode 455 assign cookies
//
// 题目给定两个数组，一个表示每个小孩需要的糖果大小，一个表示现有的糖果大小，要求尽可能多的满足多的小孩，求最多可以满足多少个小孩。
//
// 既然要满足尽可能多的小孩，就不能存在浪费的情况，那么小的糖果就应该分配给需求小的小孩，所以先对小孩的需求和糖果的大小分别进行排序，
// 然后遍历糖果，当前糖果遇到满足条件且需求最小的小孩时，则分配给他，直到最后小孩都分配完或者糖果分配完。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        if (g.size() == 0) {
            return 0;
        }
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= g[child]) {
                count++;
                child++;
                if (child >= g.size()) {
                    break;
                }
            }
        }
        return count;
    }
};

int main() {
    vector<int> g = {2, 3};
    vector<int> s = {2, 1, 3};
    Solution solution;
    int count = solution.findContentChildren(g, s);
    cout << "max count = " << count << endl;
    return 0;
}