//
// Created by Mr.Hu on 2018/4/14.
//
// leetcode 485 max consecutive ones
// 题目要求找到给定数组中最大的连续1的个数，数组中只包含0和1；
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size = nums.size();
        int max = INT_MIN;
        int result = 0;
        // bool isConsecutive = true;
        for(int i=0;i<size;i++){
            if(nums[i]==1){
                result++;
                if(result>max){
                    max = result;
                }
            }
            else{
                result = 0;
            }
        }
        return max>result?max:result;
    }
};

int main(){
    vector<int> nums = {0,1,1,1,0,0,1,1,1,1,1,0};
    Solution solution;
    int maxNumber = solution.findMaxConsecutiveOnes(nums);
    cout<<maxNumber<<endl;
    return 0;
}