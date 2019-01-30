//
// Created by Mr.Hu on 2019/1/30.
//
// leetcode 883 projection area of 3D shapes
//
// 这个题目和892很像，但是又有区别，892是求所有表面的面积，而这个题目求的是三种映射后的面积。
//
// 这个题目的解题思想比较简单，就是对每行取最大值进行累加，然后对每列取最大值累加，最后加上有立方体的位置个数，即为映射面积。
// 每一次按列或者按行就是一个嵌套循环，只是两种循环的先后正好相反，最后加一遍存在立方体的位置个数，即俯视图面积。
//


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int projectionArea(vector<vector<int>> &grid) {
        // 按列取最大，累加
        // 按行取最大，累加
        // 有多少位置有cube，就有多少面
        int sum = 0;
        int max_col = 0, max_row = 0;

        // 按列
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] != 0) {
                    max_col = max(grid[row][col], max_col);
                }
            }
            sum += max_col;
            max_col = 0;
        }

        // 按行
        for (int col = 0; col < grid[0].size(); col++) {
            for (int row = 0; row < grid.size(); row++) {
                if (grid[row][col] != 0) {
                    sum++;
                    max_row = max(grid[row][col], max_row);
                }
            }
            sum += max_row;
            max_row = 0;
        }
        return sum;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {{2, 2, 2},
                                {2, 2, 2},
                                {2, 1, 2}};
    int projectArea = solution.projectionArea(grid);
    cout << "projection area : " << projectArea << endl;
    return 0;
}