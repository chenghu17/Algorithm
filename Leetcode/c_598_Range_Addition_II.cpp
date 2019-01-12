//
// Created by Mr.Hu on 2019/1/12.
//
// leetcode 598 range addition II
//
// 题目给定一个全零的m*n矩阵，以及一些操作，如(2,2)，即表示对于矩阵0<=i<2，0<=j<2的部分，全部加一，
// 当经过所有ops后，求矩阵中值最大的点（范围）为多少。
//
// 这个题目其实就是考察所有操作中，重叠部分的大小，因为重叠部分相当于进行了|ops|次加一操作。
// 而每次操作都是左上部分矩阵，因此每次判断操作所对应的长宽大小，每次保存最小的长宽，最后的乘积即为最小范围。
//
// 注：由于操作可能会为空，所有最大值即为0，范围即为整个矩阵的大小
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>> &ops) {
        // 即求重叠部分的面积
        int weight = m;
        int height = n;
        for (int i = 0; i < ops.size(); i++) {
            weight = min(weight, ops[i][0]);
            height = min(height, ops[i][1]);
        }
        return weight * height;
    }
};

int main() {
    int m = 3, n = 3;
    vector<vector<int>> ops = {{2, 2},
                               {3, 3}};
    Solution solution;
    int max_count = solution.maxCount(m, n, ops);
    cout << max_count << endl;
    return 0;
}