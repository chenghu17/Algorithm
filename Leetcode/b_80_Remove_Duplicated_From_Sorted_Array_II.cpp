//
// Created by Mr.Hu on 2018/7/29.
//


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int length = nums.size();
        if (length == 0) {
            return 0;
        }
        int count = 1;
        int tmp = nums[0];
        for (int i = 1; i < length; ++i) {
            if (nums[i] == tmp) {
                ++count;
                if (count > 2) {
                    for (int j = i + 1; j < length; ++j) {
                        nums[j - 1] = nums[j];
                    }
                    --length;
                    --i;
                    nums[length] = tmp; //optional
                }
            } else {
                count = 1;
                tmp = nums[i];
            }
        }
        return length;
    }

    int removeDuplicates_optimal(vector<int>& nums) {
        int i=0;
        for(auto n:nums){
            if(i<2 || n>nums[i-2]){
                nums[i++] = n;
            }
        }
        return i;
    }
};

int main() {
    vector<int> nums;
    nums.emplace_back(1);
    nums.emplace_back(2);
    nums.emplace_back(2);
    nums.emplace_back(2);
    nums.emplace_back(3);
    nums.emplace_back(4);
    Solution solution;
//    int length = solution.removeDuplicates(nums);
    int length = solution.removeDuplicates_optimal(nums);
    for (int i = 0; i < length; ++i) {
        cout << nums[i] << " ";
    }
    return 0;
}