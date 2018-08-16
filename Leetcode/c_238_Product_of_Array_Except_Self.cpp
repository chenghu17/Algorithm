//
// Created by Mr.Hu on 2018/8/16.
//
// leetcode 238 Product_of_Array_Except_Self
//
// 题目要求对于给定的数组进行转换，转换后的结果为原数组nums[i]的值等于除该值以外其他值的乘积
//
// solution 1: 使用division
// 考虑到如果原数组中存储0，则可以简化整个操作过程。
// 如果原数组中存在一个0，则除0位置的值等于其他位置数的乘积以外，其他位置的值最终都是0；
// 如果原数组中存在两个0，则所有位置的值最终都是0；
// 如果原数组中不存在0，则每个位置的值为其他位置的值的乘积。
// 所以需要保存0出现的位置，以及所有值的乘积结果，最终求某一位的值，即为所有值的乘积除以该值即可得到。
//
// solution 2: without division
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        // 记录0的位置
        // 如果0出现的次数大于1个，则最终结果全为0，如果0的个数为1个，则除了0对应位置上的数不为0其他都为0
        // 如果0没有出现，则结果中每一位上的值为其他位置上值的乘积
        vector<int> zero_index;
        vector<int> result;
        long product = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                zero_index.push_back(i);
                if (zero_index.size() > 1) {
                    break;
                }
            } else {
                product *= nums[i];
            }
        }
        if (zero_index.size() >= 1) {
            for (int i = 0; i < nums.size(); ++i) {
                result.emplace_back(0);
            }
            if (zero_index.size() == 1) {
                result[zero_index[0]] = product;
            }
        } else {
            for (int i = 0; i < nums.size(); ++i) {
                result.push_back(product / nums[i]);
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums;
    nums.emplace_back(1);
    nums.emplace_back(2);
    nums.emplace_back(3);
    nums.emplace_back(4);
    Solution solution;
    vector<int> result = solution.productExceptSelf(nums);
    for (auto it:result) {
        cout << it << " ";
    }
    return 0;
}