//
// Created by Mr.Hu on 2018/4/12.
//
// leetcode 414 third maximum number
//



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int> &nums) {
        vector<long> result;
        result.push_back(LONG_MIN);
        result.push_back(LONG_MIN);
        result.push_back(LONG_MIN);
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > result[0]) {
                result[2] = result[1];
                result[1] = result[0];
                result[0] = nums[i];
                count++;
            } else if (nums[i] > result[1] && nums[i] != result[0]) {
                result[2] = result[1];
                result[1] = nums[i];
                count++;
            } else if (nums[i] > result[2] && nums[i] != result[1] && nums[i] != result[0]) {
                result[2] = nums[i];
                count++;
            }
        }
        if (count < 3)
            return (int) result[0];
        else
            return (int) result[2];
    }

};

int main() {
    vector<int> nums = {2, 1};
    Solution solution;
    int result = solution.thirdMax(nums);
    cout << result << endl;
    return 0;
}