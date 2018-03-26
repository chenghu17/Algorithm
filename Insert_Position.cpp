//
// Created by Mr.Hu on 26/03/2018.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if(nums[0]>target)
            return 0;
        if(nums[size-1]<target)
            return size;
        for(int i=0;i<size;i++){
            if(nums[i]==target)
                return i;
            else if(nums[i]>target){
                return i;
            }
        }
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int target = 1;
    Solution solution;
    int position = solution.searchInsert(nums,target);
    cout<<position<<endl;
    return 0;

}