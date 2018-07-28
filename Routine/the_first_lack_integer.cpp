//
// Created by Mr.Hu on 2018/7/28.
//
// 题目要求在给定数组中，找出第一个未出现在 >=1的连续数列中的整数
//
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int FindTheFirstLackInteger(vector<int>& nums){
        int length = (int)nums.size();
        int i=0;
        while(i<length){
            if(nums[i]>length || nums[i]<1){
                swap(nums[i],nums[length-1]);
                --length;
            }
            else if(nums[i] == i+1){
                ++i;
            }
            else{
                swap(nums[i],nums[nums[i]]);
            }
        }
        return i+1;
    }
};

int main(){
    vector<int> nums;
    nums.emplace_back(1);
    nums.emplace_back(3);
    nums.emplace_back(11);
    nums.emplace_back(19);
    nums.emplace_back(52);
    nums.emplace_back(6);
    Solution solution;
    int lack_integer = solution.FindTheFirstLackInteger(nums);
    cout<<lack_integer;
    return 0;
}