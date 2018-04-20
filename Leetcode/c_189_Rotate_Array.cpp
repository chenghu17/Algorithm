//
// Created by Mr.Hu on 2018/4/20.
//
// leetcode 189 rotate array
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int size = nums.size();
        int m = k % size;
        vector<int> rotateArray;
        for (int i = size - m; i < size; i++) {
            rotateArray.push_back(nums[i]);
        }
        for (int j = size - m - 1; j >= 0; j--) {
            nums[j + m] = nums[j];
        }
        for (int n = 0; n < m; n++) {
            nums[n] = rotateArray[n];
        }

        // Time Limit Exceeded
        // int size = nums.size();
        // for(int i=1;i<=k;i++){
        //     int tmp = nums[size-1];
        //     for(int j=size-1;j>0;j--){
        //         nums[j] = nums[j-1];
        //     }
        //     nums[0] = tmp;
        // }
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 4;
    Solution solution;
    solution.rotate(nums,k);
    auto it = nums.begin();
    while(it!=nums.end()){
        cout<<*it<<' ';
        it++;
    }
    return 0;
}