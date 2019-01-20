//
// Created by Mr.Hu on 2019/1/20.
//
// leetcode 303 range sum query immutable
//
// 题目要求对于给定的数组，实现给定索引值i,j(i<=j)，求[i,j]区间内所有元素的和
//
// 可以对输入的数组进行预处理，用相同大小的数组存储每个位置及之前所有值的和，
// 那么对于[i,j]区间所有元素的和，sum[j]-sum[i-1]，其中i>0，
// 如果i==0，则结果为sum[j]
//

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> sum_num;

    NumArray(vector<int> nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            sum_num.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return sum_num[j];
        }
        return sum_num[j] - sum_num[i - 1];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray *na = new NumArray(nums);
    cout << na->sumRange(0, 2) << endl;
    cout << na->sumRange(1, 6) << endl;
    return 0;
}