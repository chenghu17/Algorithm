//
// Created by Mr.Hu on 2018/11/6.
//
// leetcode 931 minimum falling path sum
//
// 题目给定一个方阵，从方阵中的每一行选出一个树进行累加，要求最后的结构最小。而每次选择的列，与上一行选择的列最多相差一个单位。
//
// 本题是一道动态规划（dynamic programming）的题目，不难发现，每次选择下一行的某一列是一个重复子问题，
// 即确定了当前所选择的列，即可确定接下来的三列，保留所有的中间结果，直到所有行都被选择。然后比较每种情况结果值，得到最终最小的和。
//
// 下面给出了一种递归方法，能够成功的解答该问题。但是递归调用相当耗时，所以当给定的方阵比较大时，会出现time limit exceeded情况。
//
// 看了一下题目给定的solution，原来可以直接在给定的方阵上进行操作，即用这样一个二维矩阵来保留状态，因此可以减少执行时间。
// 即下面的DP方法
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

    // 在原方阵的基础上保存过程中的结果，即备忘录法，以此来减少执行时间
    int minFallingPathSum_DP(vector<vector<int>> &A) {
        for (int i = 1; i < A[0].size(); ++i) {
            for (int j = 0; j < A[0].size(); ++j) {
                // 对当前行中每一个数，选择上一行中可选择的数字进行累加，得到当前行每一列最小的累加结果
                A[i][j] += min(A[i - 1][j], min(A[i - 1][max(0, j - 1)], A[i - 1][min(j + 1, (int) A[0].size() - 1)]));
            }
        }
        return *min_element(A[A.size() - 1].begin(), A[A.size() - 1].end());
    }


    int addPath(vector<vector<int>> &A, int row, int col) {
        int result1 = 0, result2 = 0, result3 = 0;
        if (row >= A[0].size()) {
            return 0;
        }
        result1 += A[row][col];
        result1 += addPath(A, row + 1, col);
        int min_sum = result1;
        if (col - 1 >= 0) {
            result2 += A[row][col - 1];
            result2 += addPath(A, row + 1, col - 1);
            min_sum = min(min_sum, result2);
        }
        if (col + 1 < A[0].size()) {
            result3 += A[row][col + 1];
            result3 += addPath(A, row + 1, col + 1);
            min_sum = min(min_sum, result3);
        }
        // 返回result1，result2，result3中最小的值;
        return min_sum;
    }

    // Recursion Solution
    // 该方法使用递归调用来寻找最小的结果，但是由于每次递归调用都会在栈空间中创建一个函数副本，且会重复调用，
    // 所以当输入数据规模比较大的时候，相当耗时而且占用内存比较大。
    // 在leetcode中，出现time limit exceeded情况
    int minFallingPathSum_Recursion(vector<vector<int>> &A) {
        int min_sum = INT_MAX;
        for (int i = 0; i < A[0].size(); ++i) {
            int tmp_sum = 0;
            tmp_sum += A[0][i];
            tmp_sum += addPath(A, 1, i);
            min_sum = min(min_sum, tmp_sum);
        }
        return min_sum;
    }
};

int main() {
    vector<vector<int>> A(3, vector<int>(3));
    int m = 1;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            A[i][j] = m;
            ++m;
        }
    }
    Solution solution;
    int min_result = solution.minFallingPathSum_DP(A);
//    int min_result = solution.minFallingPathSum_Recursion(A);
    cout << "min result : " << min_result << endl;
    return 0;
}
