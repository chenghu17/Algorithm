//
// Created by Mr.Hu on 2018/4/22.
//
// leetcode 674 longest continuous increasing subsequence
//
// 
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        int max_subarray = 1;
        int tmp = 1;
        bool isNext = false;
        for (int i = 0; i < size - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                if (isNext) {
                    tmp++;
                } else {
                    isNext = true;
                    tmp++;
                }
            } else {
                if (tmp > max_subarray) {
                    max_subarray = tmp;
                }
                tmp = 1;
                isNext = false;
            }
        }
        if (tmp > max_subarray) {
            max_subarray = tmp;
        }
        return max_subarray;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5};
    Solution solution;
    int result = solution.findLengthOfLCIS(nums);
    cout<<result<<endl;
    return 0;
}