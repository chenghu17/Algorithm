//
// Created by Mr.Hu on 2018/7/29.
//
// leetcode 304 range sum query 2D
//
// 题目给定二维数组，和两个坐标分别矩形矩形的左上角和右下角位置，求矩形中所有值的和
//
// 1、brute force
// a、对围成的矩形从外向内以环的形式递归求和，如果内部不是环，则可能是一个点，一条垂线，一条横线，或者循环完毕
// b、对围城的矩形逐行求和，得到最终的结果
//
// 2、DP方法
// a、由于题目要求多次sumRegion，所以如果采用BF方法会导致runtime error，所以我们需要进行pre-processing
//  用一个新的二维数组，将每行中每个点到第一个点的和求出来并进行保存 data[r][c+1] = data[r][c]+matrix[r][c]
//  这种预处理的复杂度为O(m*n)，这样处理之后，每次计算矩行所围成的结果时，计算每行的和只需要data[r][col2+1]-data[r][col1]即可；
//  这样就不需要重复子操作，也就不会出现runtime error的情况。
//  b、第二种DP方法，我们可以将计算每个坐标点与(0,0)所围成的矩形中所有点的和，而任意两点围成的矩形和可以通过三个矩形和进行加减运算得到。
//  关键是找出递推公式：dp[r + 1][c + 1] = dp[r + 1][c] + dp[r][c + 1] + matrix[r][c] - dp[r][c];
//

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix_BF {
private:
    vector<vector<int>> data;
public:
    NumMatrix_BF(vector<vector<int>> matrix) {
        data = matrix;
    }

    // 以圆环的形式一层一层的内部计算
    int sumRegion_one(int row1, int col1, int row2, int col2) {
        int result = 0;
        if (row1 == row2 && col1 == col2) {
            return data[row1][col1];
        } else if (row1 > row2 && col1 > col2) {
            return 0;
        } else if (row1 == row2) {
            for (int i = col1; i <= col2; ++i) {
                result += data[row1][1];
            }
            return result;
        } else if (col1 == col2) {
            for (int i = row1; i <= row2; ++i) {
                result += data[1][col1];
            }
            return result;
        } else {
            // top-bottom
            for (int i = row1; i < row2; ++i) {
                result += data[i][col1];
            }
            // left-right
            for (int i = col1 + 1; i < col2; ++i) {
                result += data[row1][i];
            }
            // bottom-top
            for (int i = row2; i >= row1; --i) {
                result += data[i][col2];
            }
            // right-left
            for (int i = col2 - 1; i >= col1; --i) {
                result += data[row2][i];
            }
            result += sumRegion_one(row1 + 1, col1 + 1, row2 - 1, col2 - 1);
        }
        return result;
    }

    int sumRegion_two(int row1, int col1, int row2, int col2) {
        int result = 0;
        for (int i = row1; i <= row2; ++i) {
            for (int j = col1; j <= col2; ++j) {
                result += data[i][j];
            }
        }
        return result;
    }

};


class NumMatrix {
private:
    vector<vector<int>> data;
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty())
            return;
        int row = matrix.size();
        int col = matrix[0].size();
        data = vector<vector<int>>(row, vector<int>(col + 1));
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                data[r][c + 1] = data[r][c] + matrix[r][c];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = 0;
        for (int i = row1; i <= row2; ++i) {
            result += data[i][col2 + 1] - data[i][col1];
        }
        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */


int main() {
    vector<vector<int>> matrix;
    NumMatrix *obj = new NumMatrix(matrix);
    int param_1 = obj->sumRegion(1, 1, 5, 5);
    return 0;
}