//
// Created by Mr.Hu on 2018/4/23.
//
// leetcode 695 max area of island
//
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector <vector<int>> &grid) {
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

    int dfs(vector <vector<int>> &grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }
        int tmpMaxArea = 1;
        grid[i][j] = 0;
        tmpMaxArea += dfs(grid, i, j - 1) + dfs(grid, i, j + 1) + dfs(grid, i + 1, j) + dfs(grid, i - 1, j);
        return tmpMaxArea;
    }
};

int main(){
    vector<vector<int>> grid = {{1,0,0,0},{1,0,0,0},{1,0,0,0}};
    Solution solution;
    int maxArea = solution.maxAreaOfIsland(grid);
    cout<<maxArea<<endl;
    return 0;
}