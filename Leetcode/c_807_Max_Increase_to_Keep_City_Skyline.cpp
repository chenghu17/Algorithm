//
// Created by Mr.Hu on 2018/9/2.
//
// leetcode 807 max increase to keep city skyline
//
// 题目给定了一个城市各个位置的建筑高度，现要求对所有建筑尽可能的提高高度，但是要求城市的空中轮廓线(skyline)不变，
// 即保持城市之前每行每列的最高高度。
//
// 根据题目的定义，第一步我们需要找到对城市的每行每列的最高度，
// 第二步我们需要去对每个建筑判断是否能够提高其高度，最高能提高多少。而这个提高的判断条件即提高后横向不大于之前的横行最大值，
// 纵向不大于之前的纵向最大值，即不大于他们中的最小值。所以提高的高度即他们中最小值与原来高度的差值。
// 累加所有提高的高度，即可得到最终提高的最大值。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
        int grid_side = grid.size();
        int count = 0;
        int top_bottom[grid_side], left_right[grid_side];
        // 使用memset来初始化数组
        memset(top_bottom, 0, sizeof(top_bottom));
        memset(left_right, 0, sizeof(left_right));
        // vector<int> top_bottom(grid_side,0);
        // vector<int> left_right(grid_side,0);
        // 求出从上到下，每列的最大值
        // 求出从左到右，每行的最大值
        for (int i = 0; i < grid_side; ++i) {
            for (int j = 0; j < grid_side; ++j) {
                left_right[i] = max(left_right[i], grid[i][j]);
                top_bottom[i] = max(top_bottom[i], grid[j][i]);
            }
        }

        for (int i = 0; i < grid_side; ++i) {
            for (int j = 0; j < grid_side; ++j) {
                count += min(left_right[i], top_bottom[j]) - grid[i][j];
            }
        }
        return count;
    }
};

int main() {
    int grid_size = 4;
    vector<vector<int>> grid(grid_size, vector<int>(grid_size));
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            grid[i][j] = rand() % 100 + 1;
        }
    }
    Solution solution;
    int max_increase = solution.maxIncreaseKeepingSkyline(grid);
    cout << "max_increase:" << max_increase << endl;
    return 0;
}