//
// Created by Mr.Hu on 2018/4/17.
//
// leetcode 566 reshape the matrix
//
// 题目要求对矩阵进行行列变换，根据给定的行数和列数，将原矩阵转换为目标矩阵，如果无法变换，则返回原矩阵
// 分析：如果无法变换，则说明前后两个矩阵的元素个数不相同，即行列乘积结果不等，于是输出原矩阵；
// 若行列数乘积相等，则可以进行变换，考虑到要取值，同时又要加入到新矩阵中，混在一起很难判断，
// 所以先将原矩阵的数字按先行后列的顺序取出，得到一个数组，然后再按顺序，加入到目标矩阵的行列中，
// 加入完毕即得到变换后的目标矩阵，返回即可。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        int row = nums.size();
        int column = nums[0].size();
        if (row * column != r * c)
            return nums;
        vector<vector<int>> result;
        vector<int> tmp;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                tmp.push_back(nums[i][j]);
            }
        }
        vector<int> row_number;
        for (int i = 0; i < r; i++) {
            int numbers = i * c;
            int index = 0;
            for (int j = 0; j < c; j++) {
                index = numbers + j;
                row_number.push_back(tmp[index]);
            }
            result.push_back(row_number);
            row_number.clear();
        }
        return result;
    }
};

int main() {
    vector<vector<int>> nums = {{1, 2},
                                {3, 4}};
    Solution solution;
    int r = 1, c = 4;
    vector<vector<int>> result = solution.matrixReshape(nums, r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}