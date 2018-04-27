//
// Created by Mr.Hu on 2018/4/27.
//
// leetcode 766 toeplitz matrix （常对角矩阵、特普利茨矩阵）
//
//
//
//
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