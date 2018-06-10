//
// Created by Mr.Hu on 2018/6/10.
//
// leetcode 447 number of boomerangs
//
// 题目要求从给定的数对（点）中，找出(i,j,k)的个数，满足point i 与point j的欧式距离等于point i与point k的欧式距离
//
// 这个题目的解题思想就是对于每个点，算其与其他点的距离，然后距离相等的点则可以组成这样的三项式。
// 根据排列组合我们可以知道，如果存在m个点与点i的距离相等，则说明有m*(m-1)种(i,j,k)情况
//
// 所以我们的目标就是去计算每个点与其他点的欧式距离，通过一个双层循环来完整，对于每个基点i(我将点i命名为基点)，
// 与其他点的距离统计情况可以用一个map<int,int>来表示，key表示距离，value表示个数，最后对于每一个基点，
// 遍历其距离统计结果map，如果value值大于1，则说明存在多个点与基点距离相同，此时我们可以用上述排列组合的思想，
// 计算得到value*(value-1)中情况，累加到result上。对每个基点进行上述操作，循环结束，result即为目标结果。
//


#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>> &points) {
        int points_size = points.size();
        int result = 0;
        for (int i = 0; i < points_size; ++i) {
            int current_first = points[i].first;
            int current_second = points[i].second;
            map<int, int> tmp;
            for (int j = 0; j < points_size; ++j) {
                if (j == i) {
                    continue;
                }
                int another_first = points[j].first;
                int another_second = points[j].second;
                int res = pow((current_first - another_first), 2) + pow((current_second - another_second), 2);
                tmp[res]++;
            }
            for (auto it = tmp.begin(); it != tmp.end(); ++it) {
                int count = it->second;
                if (count > 1) {
                    result += count * (count - 1);
                }
            }
        }
        return result;
    }
};

int main() {
    pair<int, int> a(0, 0);
    pair<int, int> b(1, 0);
    pair<int, int> c(2, 0);
    vector<pair<int, int>> points;
    points.push_back(a);
    points.push_back(b);
    points.push_back(c);
    Solution solution;
    int result = solution.numberOfBoomerangs(points);
    cout << result << endl;
    return 0;
}