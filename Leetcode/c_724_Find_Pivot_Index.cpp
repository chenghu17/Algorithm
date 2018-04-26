//
// Created by Mr.Hu on 2018/4/26.
//
// leetcode 724 fine pivot index
//
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int index = -1;
        int size = nums.size();
        int sum = 0;
        int left_result = 0;
        int right_result = 0;
        for (int i = 0; i < size; i++) {
            sum += nums[i];
        }
        for (int i = 0; i < size; i++) {
            left_result += nums[i];
            right_result = sum + nums[i] - left_result;
            if (left_result == right_result) {
                index = i;
                break;
            }
        }
        return index;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 5, 6, 5, 3, 2, 1};
    Solution solution;
    int pivotIndex = solution.pivotIndex(nums);
    cout << pivotIndex << endl;
    return 0;
}