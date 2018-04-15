//
// Created by Mr.Hu on 2018/4/15.
//
// leetcode 561 array partition I
// 题目给出2n大小的数组，要求形成n个pair，使得所有pair中最小的数字的和最大。
//


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum_max = 0;
        int size = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<size;i=i+2){
            sum_max += nums[i];
        }
        return sum_max;

    }
};

int main(){
    vector<int> nums = {-1,3,5,2};
    Solution solution;
    int result = solution.arrayPairSum(nums);
    cout<<result;
    return 0;
}