//
// Created by Mr.Hu on 2018/4/20.
//
// leetcode 643 maximum average subarray_I
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        int size = nums.size();
        int max_result = 0;
        for (int j = 0; j < k; j++) {
            max_result += nums[j];
        }
        for (int i = 0; i < size - k; i++) {
            if (nums[i + k] > nums[i]) {
                int tmp = 0;
                for (int j = 1; j <= k; j++) {
                    tmp += nums[i + j];
                }
                if (tmp > max_result) {
                    max_result = tmp;
                }
            }
        }
        double result = max_result * 1.0 / k;
        return result;
    }
};

int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    Solution solution;
    double average = solution.findMaxAverage(nums, k);
    cout << average << endl;
    return 0;
}