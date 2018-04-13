//
// Created by Mr.Hu on 2018/4/13.
//
// leetcode 448 find all numbers disappeared
// 题目给定一个数组，size为n，数组中数字的范围为[1,n]，由于数组中存在重复出现的数字，
// 所以存在1-n中未出现的数字，求所有为出现的数字。要求不实用额外的空间，时间复杂度为O(n)。
//
// 这一题容易让人联想到268那一题，那一题是只有一个数字，且不存在重复数组，求和做差即可。
// 但是这一题有区别，不能用求和的方式进行解答。
// 思考一会后，想了使用蛮力法、使用set来存储已有数字，最后输出未出现的数字，但是这都不符合题目对时间和空间复杂度的要求。
// 于是去查了一下别人的做法，因为实在想不出这种策略...
//
// 符合要求的解题方法是对数组进行遍历，每个数-1即为索引值，将该索引值上的数字更新为其相反数；
// 一次遍历之后，再进行二次遍历，此时数组中不为负数的索引值+1即为数组中未出现的数字，因为如果该数字出现，
// 则该数字-1所在索引位置的数应该为负数。
//
// 注意，这个方法在第一次遍历时都要取绝对值，因为前面可能出现大数，导致后面索引位置的值为负数，那么
// 在遍历到后面位置时，其值-1就不是索引值来，应该是其值的绝对值-1。
//
// 这种方法妙在将数字与索引位置联系起来，由不改变索引位置上绝对值结果，这样就使得出现过的数字其对应的索引位置上的值为负数，
// 未出现过的数字其对应的索引位置上的值为非负数，为更改过，其实就是重复的数字。
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