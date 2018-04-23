//
// Created by Mr.Hu on 2018/4/23.
//
// leetcode 695 max area of island
//
// 题目要求对于给定的矩阵，1表示岛屿，0表示海洋，对于上下左右连续的1，则表示为同一座岛屿，求最大岛屿的面积数
//
// 看到这个题目，第一个想法就是觉得要用递归或者是回溯的方法，使用深度优先搜索来解决。
// 想到这里我就有点惧怕来，因为对于递归或回溯，我有点难以下手去做，不知道如何去coding...
// 而且对于这个题目，让我想到16年五月份，我给我旦的某个老师发邮件后获得的一次在线面试机会，
// 这个面试是老师的一个学生进行的，当时就让我给我出了一个题目，题目就是这到那个题目！对于当时的我，
// 数据结构和算法已经交给老师了，再加上c++也有几年没写了，当时只会写个二维数组，就连vector都不会用...惭愧
// 话不扯开，回到这个题目。当看到这个题目，虽然直到用什么方法来解，但是一直有个困惑，就是用递归或者回溯，遇到
// 不满足的条件，回到最开的点时，重复算两遍该怎么办？？这个问题卡住了我，从昨天想到今天都没想出来，于是去网上查了
// 一下解决办法：对于每次计算过的点，我们将其值改为0，这样就避免了重复计算的可能，如正方形的四个点都是1，
// 这样就成了死循环...没错，就是这种处理是解题的关键。
//
// 然后看着别人的代码，思考了一下，自己再重新编写。其实对于递归方法，就是要把这个递归的过程抽象出来：
// 比如这个题目，就是先判断该点的位置以及该点的值，满足为1则将当前面积值赋值为1，然后向其上下左右发散，
// 例如到上面的点，此时又要判断点的位置以及该点的值，满足为1则把当前的面积值赋值为1，如果不满足，则终止，
// 返回0，回到上一层递归中，并将结果传递给上一层，一层增加的值最多为4，即四个方向都是1，然后继续发散。
// 递归和回溯的思想确实是一个重要而且基础的点，继续练习。
// 当然这个题目最妙的地方还是对点判断之后，如果为1，则记录并赋值为0的方法。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int row = grid.size();
        int column = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (grid[i][j] == 1) {
                    // int tmp = dfs(grid,i,j);
                    // maxArea = maxArea>tmp?maxArea:tmp;
                    maxArea = max(maxArea, dfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }

    int dfs(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }
        int tmpMaxArea = 1;
        grid[i][j] = 0;
        tmpMaxArea += dfs(grid, i, j - 1) + dfs(grid, i, j + 1) + dfs(grid, i + 1, j) + dfs(grid, i - 1, j);
        return tmpMaxArea;
    }
};

int main() {
    vector<vector<int>> grid = {{1, 0, 0, 0},
                                {1, 0, 0, 0},
                                {1, 0, 0, 0}};
    Solution solution;
    int maxArea = solution.maxAreaOfIsland(grid);
    cout << maxArea << endl;
    return 0;
}