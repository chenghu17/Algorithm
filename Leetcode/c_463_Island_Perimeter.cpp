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
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        int perimeter = 0;
        for(int i=0;i<row;++i){
            for(int j=0;j<column;++j){
                if(grid[i][j]==1){
                    if(j-1<0||j-1>=0 && grid[i][j-1] == 0){
                        ++perimeter;
                    }
                    if(j+1>=column || j+1<column && grid[i][j+1] == 0){
                        ++perimeter;
                    }
                    if(i-1<0 || i-1>=0 && grid[i-1][j] == 0){
                        ++perimeter;
                    }
                    if(i+1>=row || i+1<row && grid[i+1][j] == 0){
                        ++perimeter;
                    }
                }
            }
        }
        return perimeter;
    }
};

int main(){
    vector<vector<int>> grid(4,vector<int>(4));
    vector<int> a,b,c,d;
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
    int perimeter = solution.islandPerimeter(grid);
    cout<<perimeter<<endl;
    return 0;

}