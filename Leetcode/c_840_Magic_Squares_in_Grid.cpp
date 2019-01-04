//
// Created by Mr.Hu on 2019/1/4.
//
// leetcode 840 Magic Squares in Grid
//
// 题目给定一个数字型的矩阵，要求从该矩阵中找出3x3的矩阵，要求满足子矩阵是每行每列为连续，每行每列以及对角线上值的和相等，
// 以及整个3x3矩阵由1-9不同的数组组成，不能出现其他的数组，该子矩阵称为magic square
//
// 这个题目其实就是需要我们仔细的取遍历矩阵，注意边界，以及理解题目的几个限定条件即可。
// 刚开始没注意到magic square需要是9不同的数字组成，然后没有注意到不能是1-9之外的其他数字。
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>> &grid) {
        int magic_num = 0;
        int row = grid.size();
        int column = grid.size();
        if (row < 3 || column < 3) {
            return magic_num;
        }
        for (int i = 0; i <= row - 3; i++) {
            for (int j = 0; j <= column - 3; j++) {
                if (is_magic_square(grid, i, j)) magic_num++;
            }
        }
        return magic_num;
    }

    bool is_magic_square(vector<vector<int>> &grid, int row, int column) {
        bool is_true = true;
        set<int> numbers;
        for (int i = row; i < row + 3; i++) {
            for (int j = column; j < column + 3; j++) {
                if (grid[i][j] < 1 || grid[i][j] > 9) {
                    is_true = false;
                    break;
                }
                numbers.insert(grid[i][j]);
            }
            if (!is_true) {
                break;
            }
        }
        if (numbers.size() != 9 || !is_true) return false;

        // 按行
        int a = grid[row][column] + grid[row][column + 1] + grid[row][column + 2];
        if (a != grid[row + 1][column] + grid[row + 1][column + 1] + grid[row + 1][column + 2]) return false;
        if (a != grid[row + 2][column] + grid[row + 2][column + 1] + grid[row + 2][column + 2]) return false;
        // 按列
        if (a != grid[row][column] + grid[row + 1][column] + grid[row + 2][column]) return false;
        if (a != grid[row][column + 1] + grid[row + 1][column + 1] + grid[row + 2][column + 1]) return false;
        if (a != grid[row][column + 2] + grid[row + 1][column + 2] + grid[row + 2][column + 2]) return false;
        // 按对角
        if (a != grid[row][column] + grid[row + 1][column + 1] + grid[row + 2][column + 2]) return false;
        if (a != grid[row][column + 2] + grid[row + 1][column + 1] + grid[row + 2][column]) return false;
        return true;
    }
};

int main() {
    vector<int> a;
    vector<int> b;
    vector<int> c;
    a.push_back(5);
    a.push_back(5);
    a.push_back(5);
    b.push_back(5);
    b.push_back(5);
    b.push_back(5);
    c.push_back(5);
    c.push_back(5);
    c.push_back(5);
    vector<vector<int>> grid;
    grid.push_back(a);
    grid.push_back(b);
    grid.push_back(c);
    Solution solution;
    int magic_num = solution.numMagicSquaresInside(grid);
    cout << magic_num << endl;
    return 0;
}