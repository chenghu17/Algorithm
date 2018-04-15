//
// Created by Mr.Hu on 2018/4/15.
//
// leetcode 561 array partition I
// 题目给出2n大小的数组，要求形成n个pair，使得所有pair中最小的数字的和最大。
//
// 拿到这个题目后，分析来一下，要想所有pair中最小的数字加起来和最大，则说明每个pair中较大的数字不能大于下一个pair，
// 因为如果大于下一个pair，则说明下一个pair中较小的数字被削弱了，那么和一定不是最大的，局部最优最终可达到全局最优。
// 因此只需要将连续大小的数组成数对，则所有较小的值就不会存在被削弱的情况，最终的和也是组合最大的情况。
// 于是就先使用sort函数对vector进行排序，然后遍历一次，每次取下下一位加入到和中，最终可得到所有pair中最小的数字的和最大。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum_max = 0;
        auto size = nums.size();
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