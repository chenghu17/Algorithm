//
// Created by Mr.Hu on 21/03/2018.
// leetcode : Two_Sum
// 相邻两个值的和为目标结果，则输出该数对

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main(){
    vector<int> nums = {3,2,4};
    int target = 6;
    vector<int> result = twoSum(nums,target);
    cout<<result[0]<<result[1]<<endl;

}

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    long number = nums.size();
    bool isRight = false;
    for(int i=0;i<number;i++){
        for(int j=i+1;j<number;j++){
            if(nums[i]+nums[j]==target){
                result.push_back(i);
                result.push_back(j);
                isRight=true;
                break;
            }
        if(isRight)
            break;
        }
    }
    return result;
}

// 学会使用c++容器vector
// 该算法的时间效率还不是最高的