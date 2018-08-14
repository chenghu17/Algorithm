//
// Created by Mr.Hu on 2018/8/14.
//
// leetcode 200 number of islands
//
// 题目给定一个二维的数组来表示一块区域，其中1表示岛屿，0表示海洋，要求求出岛屿的个数。
// 其中如果在垂直或水平方向上有连续的1，则说明是一个岛屿
//
// 这个题目之前遇到过，大致解题思想还记得。
// 对于这样一个区域，如果存在某个位置为1，则我们需要继续去判断其上下左右是否也为1，
// 如果其上下左右在这个区域内，且存在为1，则继续判断当前位置的上下左右是否为1。很容易想到用递归的思想。
//
// 既然是每次判断上下左右是否为1，我们也可以把这个思路转换为图来考虑，这样解题的本质就是一个深度优先搜索。
// 其中值得注意的是，每次判断一个位置为1后，我们需要将这个位置赋值为0，这样避免重复死循环操作。
//
// 最后我在写代码的时候，发现一个影响执行效率的地方：在numIslands方法的双层for循环中，刚开始如果
// 区域为1，我会去调用四次islands()方法，即去判断其上下左右位置上是否存在连续的1。
// 但其实这个操作在islands中也会执行，所以我这样做导致递归操作并不是很完整。
// 所以在numslands()中，只是去判断当前位置是否为1，一旦为1，则进入islands方法中，将该位置赋值为0，
// 同时判断其他位置的情况。这样执行效率击败比例从2%提高到98%。
// 这样做之所以奏效，可能是因为我在不同的地方调用多次islands方法，会在内存中产生多个存储区，
// 而如果直接用递归，则可能会在原来存储区的基础上进行执行。
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