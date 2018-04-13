//
// Created by Mr.Hu on 2018/4/13.
//
// leetcode 448 find all numbers disappeared
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int index = abs(nums[i])-1;
            nums[index] = abs(nums[index])*(-1);
        }
        for(int j=0;j<n;j++){
            if(nums[j]>0){
                res.push_back(j+1);
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,4,6,7,7};
    Solution solution;
    vector<int> result = solution.findDisappearedNumbers(nums);
    auto it = result.begin();
    for(it;it!=result.end();it++)
        cout<<*it<<' ';
}