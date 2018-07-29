//
// Created by Mr.Hu on 2018/7/29.
//
//
//
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