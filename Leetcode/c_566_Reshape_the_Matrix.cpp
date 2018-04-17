//
// Created by Mr.Hu on 2018/4/17.
//
// leetcode 566 reshape the matrix
//
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