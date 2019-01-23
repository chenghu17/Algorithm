//
// Created by Mr.Hu on 2019/1/23.
//
// leetcode 892 surface area of 3D shapes
//
// 题目给定一个二维矩阵，矩阵中每个位置的值表示该位置有多少个标准立方体（边长为1），堆砌成塔状。
// 求所有立方体构成立体图形的面积。
//
// 要求这个立体图形的面积，可以分为求所有标准立方体的面积，然后减去重叠面的部分，最后得到的即为该立体图形的面积。
// 重叠部分分两种：1、某位置上多个立方体堆砌而重叠的部分；2、相邻位置重叠部分；
// 所以我们对该矩阵进行遍历，每个位置有右边和下边相邻部分，而相邻部分所包含的面即两者中较小数，
// 某位置重叠面即为该位置立方体个数-1，但是要注意，若该位置没有立方体，则为0，而不是-1。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int surfaceArea(vector<vector<int>> &grid) {
        // 每个cube为6个面
        // 任何相邻的位置重叠的面为min(a,b)
        // 自身重叠的面为a-1
        int sum_cube = 0;
        int duplicate_surface = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                sum_cube += grid[i][j];
                if (grid[i][j] > 0) {
                    duplicate_surface += grid[i][j] - 1;
                    // 向下
                    if (i + 1 < grid.size()) {
                        duplicate_surface += min(grid[i][j], grid[i + 1][j]);
                    }
                    // 向右
                    if (j + 1 < grid[0].size()) {
                        duplicate_surface += min(grid[i][j], grid[i][j + 1]);
                    }
                }
            }
        }
        return sum_cube * 6 - duplicate_surface * 2;
    }
};

int main() {
    vector<vector<int>> grid1 = {{1, 1, 1},
                                 {1, 0, 1},
                                 {1, 0, 0}};
    vector<vector<int>> grid2 = {{2, 2, 2},
                                 {2, 2, 2},
                                 {2, 2, 2}};
    Solution solution;
    int res1 = solution.surfaceArea(grid1);
    int res2 = solution.surfaceArea(grid2);
    cout << "surface area of grid1 = " << res1 << endl;
    cout << "surface area of grid2 = " << res2 << endl;
    return 0;
}