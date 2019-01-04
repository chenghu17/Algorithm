//
// Created by Mr.Hu on 2019/1/4.
//
// leetcode 832 flipping an image
//
// 对于一个二值矩阵（图片二值化），将每一行翻转，然后取反。
// 其实就是遍历该矩阵，翻转可以依靠vector的reverse方法，取反可以使用位运算方法。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
        int row = A.size();
        int column = A[0].size();
        bool is_single = column % 2 == 0 ? false : true;
        for (int i = 0; i < row; i++) {
            int j = 0;
            for (; j < column / 2; j++) {
                int tmp_a = A[i][j];
                int tmp_b = A[i][column - 1 - j];
                A[i][j] = tmp_b ? 0 : 1;
                A[i][column - 1 - j] = tmp_a ? 0 : 1;
            }
            if (is_single) {
                A[i][j] = A[i][j] ? 0 : 1;
            }
        }
        return A;
    }
};

int main() {
    vector<vector<int>> A;
    vector<int> B;
    vector<int> C;
    vector<int> D;
    B.emplace_back(1);
    B.emplace_back(0);
    B.emplace_back(1);
    C.emplace_back(0);
    C.emplace_back(1);
    C.emplace_back(1);
    D.emplace_back(1);
    D.emplace_back(0);
    D.emplace_back(1);
    A.push_back(B);
    A.push_back(C);
    A.push_back(D);
    Solution solution;
    solution.flipAndInvertImage(A);
    for (auto i:A) {
        for (auto j:i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}