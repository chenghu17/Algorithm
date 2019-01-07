//
// Created by Mr.Hu on 2019/1/7.
//
// leetcode 645 set mismatch
//
// 题目给定一个数组，从1到n，n为数组大小，其中存在一个重复的数字，因此也就缺少一个数字。数组为乱序。要求找出重复数字和缺少数字。
//
// 这个题目之前遇到过类似的，有这样一个思路可以复用：从第一个数字开始，如果数字与索引值不能对应，则将数字与到其本身应该在位置的值进行交换。
// 中间存在一个判断，如果其本身位置上的数字和其相等，则该数字就是重复数组。
//
// 得到重复数字后，如何得到缺少数字呢？有一个trick：已知理想数组是1-n，现在有一个重复一个丢失，重复已经找到，丢失的可以用和的差值求得。
// 这就是本题的整个思路。
//
// leetcode上最好的方法是给定一个大容量数组，遍历nums，数组的值为每个数字出现的次数，出现两次的数为重复的数字，没出现过的数字为缺失数字。
// 这种可以说是空间换时间的操作。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        int repeat_num = 0;
        int size = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == i + 1) {
                continue;
            } else if (nums[nums[i] - 1] == nums[i]) {
                repeat_num = nums[i];
                break;
            } else {
                swap(nums[i], nums[nums[i] - 1]);
                i--;
            }
        }
        int target_sum = (1 + size) * size / 2;
        int actual_sum = 0;
        for (auto i:nums) {
            actual_sum += i;
        }
        int loss_num = target_sum - actual_sum + repeat_num;
        vector<int> result;
        result.push_back(repeat_num);
        result.push_back(loss_num);
        return result;

    }
};

int main() {
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    Solution solution;
    vector<int> result = solution.findErrorNums(nums);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}