//
// Created by Mr.Hu on 2018/9/2.
//
// leetcode 807 max increase to keep city skyline
//
// 
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