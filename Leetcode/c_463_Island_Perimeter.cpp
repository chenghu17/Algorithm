//
// Created by Mr.Hu on 2018/6/11.
//
// leetcode 463 island perimeter
//
// 题目给出一个小岛和其周围海域的网格图，小岛由连续的网格组成，只考虑水平和垂直方向，
// 相邻陆地之间没有围栏，要求计算小岛所有围栏的长度。
//
// 第一种想法就是遍历所有的陆地块，判断其上下左右的情况，如果挨着的为陆地，则没有围栏，如果为海洋或者超过该海域，则为围栏。
// 双层循环加四个if判断即可，但是执行效率只超过了百分之二十多的accepted solution。
//
// 现在这种方法可以说是暴力解法，联想到之前做的695题，计算最大island的面积，这个题目也可以用同样的递归方式，
// 只是需要在判断结束条件即可。
// 下面给出了optimal的方法，使用递归的方式来计算
// 递归的过程，首先因为岛屿只有一座，所以在遇到为1的点后，便开始判断其周围是否还存在陆地，
// 如果其上下左右任意一处为海或者超过来边栏，则return 1，因为此处会有栏杆，如果任意一处也为陆地，
// 则需要计算其上下左右，由于之前的点以及考虑过其上下左右，则需要给予一个标示来标示其以及被考察过了；
// 这与求最大面积不用，这里如果将其值赋为0，那么与其相连的陆地，在考察其周围时，就会将其当作海洋，栏杆则会加一。
// 所以我们要使用另外一个符号来标示，code中使用2来标示这样的已经被考察过的陆地，如果是考察过的陆地，则返回0。
//
// 有一处错误记录一下：判断当前点的上下左右是否是陆地还是海洋或者边框时，对于传入的(i,j)，直接判断即可，由于递归关系，
// 传入的就是当前点的上下左右位置坐标，其本质就是判断当前点是否为海洋、陆地还是边框...已经转换为对自身，而不是对周围。
// 这应该也就是递归思想的核心之处，每次是对自己判断。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int row = grid.size();
        int column = grid[0].size();
        int perimeter = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (grid[i][j] == 1) {
                    if (j - 1 < 0 || j - 1 >= 0 && grid[i][j - 1] == 0) {
                        ++perimeter;
                    }
                    if (j + 1 >= column || j + 1 < column && grid[i][j + 1] == 0) {
                        ++perimeter;
                    }
                    if (i - 1 < 0 || i - 1 >= 0 && grid[i - 1][j] == 0) {
                        ++perimeter;
                    }
                    if (i + 1 >= row || i + 1 < row && grid[i + 1][j] == 0) {
                        ++perimeter;
                    }
                }
            }
        }
        return perimeter;
    }

    int Recursive_process(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return 1;
        }
        if (grid[i][j] == 2) {
            return 0;
        }
        int result = 0;
        grid[i][j] = 2;
        result += Recursive_process(grid, i - 1, j) + Recursive_process(grid, i + 1, j) +
                  Recursive_process(grid, i, j - 1) + Recursive_process(grid, i, j + 1);
        return result;
    }

    int islandPerimeter_optimal(vector<vector<int>> &grid) {
        int row = grid.size();
        int column = grid[0].size();
        int perimeter = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (grid[i][j] == 1) {
                    perimeter = Recursive_process(grid, i, j);
                    return perimeter;
                }
            }
        }
        return perimeter;
    }
};

int main() {
    vector<vector<int>> grid(4, vector<int>(4));
    vector<int> a, b, c, d;
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    b.push_back(1);
    b.push_back(1);
    b.push_back(1);
    b.push_back(0);
    c.push_back(0);
    c.push_back(1);
    c.push_back(0);
    c.push_back(0);
    d.push_back(1);
    d.push_back(1);
    d.push_back(0);
    d.push_back(0);
    grid.push_back(a);
    grid.push_back(b);
    grid.push_back(c);
    grid.push_back(d);
    Solution solution;
//    int perimeter = solution.islandPerimeter(grid);
    int perimeter = solution.islandPerimeter_optimal(grid);
    cout << perimeter << endl;
    return 0;

}