//
// Created by Mr.Hu on 2018/4/27.
//
// leetcode 766 toeplitz matrix （常对角矩阵、特普利茨矩阵）
//
// 题目要求对给定的矩阵，判断是否为常对角矩阵，即nums[i][j]==nums[i+1][j+1]==....
//
// 这个题目思想很简单，遍历的过程中判断是否和最开始的值相等，不相等则return false；
// 最主要的就是细心，特别是在对行列index值做加法的时候，我刚开始提交错误就是在循环里面对
// ++i，然后循环的时候还要i++，这就跳过了一行，应该是用一个tmp来保存i，然后后面对tmp++；
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        for (int i = 0; i < row; i++) {
            int tmp = i;
            int j = 0;
            int num = matrix[i][j];
            while (++tmp < row && ++j < column) {
                if (matrix[tmp][j] != num) {
                    return false;
                }
            }
        }
        for (int j = 1; j < column; j++) {
            int tmp = j;
            int i = 0;
            int num = matrix[i][j];
            while (++i < row && ++tmp < column) {
                if (matrix[i][tmp] != num) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<int>> nums = {{1, 2, 3},
                                {4, 0, 2}};
    Solution solution;
    bool result = solution.isToeplitzMatrix(nums);
    cout << result << endl;
    return 0;
}