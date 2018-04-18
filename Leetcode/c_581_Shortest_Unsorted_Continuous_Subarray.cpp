//
// Created by Mr.Hu on 2018/4/18.
//
// leetcode 581 shortest unsorted continuous subarray
//
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int size = nums.size();
        int l_index = 0;
        int r_index = size - 1;
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (nums[i] > nums[j]) {
                    l_index = i;
                    for (int m = size - 1; m > l_index; m--) {
                        for (int n = m - 1; n >= l_index; n--) {
                            if (nums[m] < nums[n]) {
                                r_index = m;
                                return r_index - l_index + 1;
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 2, 1};
    Solution solution;
    int result = solution.findUnsortedSubarray(nums);
    cout << result << endl;
    return 0;
}