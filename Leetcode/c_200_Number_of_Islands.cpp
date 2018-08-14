//
// Created by Mr.Hu on 2018/8/14.
//
// leetcode 200 number of islands
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 递归
    // 深度优先搜索
    void Islands(vector<vector<char>> &grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
            return;
        }
        if (grid[row][col] == '1') {
            grid[row][col] = '0';
            Islands(grid, row + 1, col);
            Islands(grid, row - 1, col);
            Islands(grid, row, col + 1);
            Islands(grid, row, col - 1);
        }
    }


    int numIslands(vector<vector<char>> &grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++result;
                    Islands(grid, i, j);
                }
            }
        }
        return result;
    }
};

int main() {
    vector<vector<char>> grid;
    vector<char> grid_row;
    for (int i = 0; i < 4; ++i) {
        grid_row.emplace_back('1');
        grid_row.emplace_back('1');
        grid_row.emplace_back('1');
        grid_row.emplace_back('1');
        grid_row.emplace_back('0');
        grid.emplace_back(grid_row);
        grid_row.clear();
    }
    Solution solution;
    int numsofislands = solution.numIslands(grid);
    cout << "the count of islands is " << numsofislands << endl;
    return 0;
}