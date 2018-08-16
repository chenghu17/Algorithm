//
// Created by Mr.Hu on 2018/8/16.
//
// leetcode 238 Product_of_Array_Except_Self
//
//
//
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