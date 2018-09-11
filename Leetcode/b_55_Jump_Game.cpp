//
// Created by Mr.Hu on 2018/9/11.
//
// 根据题目的意思，要求在跳跃的路径中，不能达到step=0的位置
// 判断是否存在step=0的情况，不存在则一定可以达到the last index；
// 如果存在，则去判断是否能够跳过它们
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool jumpStep(vector<int> &nums, int index, int count) {
        int sum_count = count;
        if (nums[index] == 0) {
            return false;;
        }
        for (int i = 1; i <= nums[index]; ++i) {
            if ((sum_count + i) == (nums.size() - 1)) {
                return true;
            }
            if (!jumpStep(nums, i + index, sum_count + i)) {
                continue;
            } else {
                return true;
            }
        }
        return false;
    }

    bool canJump(vector<int> &nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return true;
        }
        int count = 0;
        return jumpStep(nums, 0, 0);
    }

    bool canJump_optimal(vector<int> &nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return true;
        }
        for (int i = nums.size() - 2; i >= 0; --i) {
            // 从后往前判断，如果某一位为0，则向前去遍历，是否存在一个位置可以将这个位置跳过
            // 只要能够跳过所有的0，则一定可以跳到最后一个step，因为每个位置的数字为其最大跳步，
            // 是可以灵活改变的
            if (nums[i] == 0) {
                int count = 1;
                bool can = false;
                for (int j = i - 1; j >= 0; --j) {
                    if (nums[j] > count) {
                        can = true;
                        break;
                    }
                    count++;
                }
                if (can) {
                    continue;
                }
                return false;
            }
        }
        return true;
    }

    bool canJump_elegant(vector<int> &nums) {
        int size = nums.size();
        int step = nums[0];
        for (int i = 1; i < size; ++i) {
            step--;
            if (step < 0)
                return false;
            if (nums[i] > step)
                step = nums[i];
        }
        return true;
    }

};

int main() {
    vector<int> nums;
    nums.emplace_back(2);
    nums.emplace_back(1);
    nums.emplace_back(2);
    nums.emplace_back(1);
    nums.emplace_back(0);
    nums.emplace_back(1);
    Solution solution;
//    bool canif = solution.canJump(nums);
//    bool canif = solution.canJump_optimal(nums);
    bool canif = solution.canJump_elegant(nums);
    cout << canif;
    return 0;
}