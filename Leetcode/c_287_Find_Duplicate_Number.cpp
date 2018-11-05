//
// Created by Mr.Hu on 2018/11/5.
//
// leetcode 287 find duplicate number
//
// 题目要求给定长度为n+1的数组，其中所有的数字在1-n之间，该数组中一定存在重复数字，且满足重复数字只有一个
// 要求返回该重复数字。
//
// 这个题目要求，数组为只读，即不能修改数组的值。并且只能空间复杂度为O(1)，
// 时间复杂读不能高于O(n*n)，对于重复出现的数字，可能不止重复出现一次。
//
// in-place solution：我能想到的第一种方法是不考虑题目要求的数组为只读，即改变原来数组的值。
// 基本思想：由于题目要求数组中所有数字的值区间位于1-n之间，所以我们可以这样理解：如果不存在重复数字，
// 那么每一个数字与数组的index之间存在的明显的对应关系。即num=array[num+1]。根据这个基本思想，我们可以对数组进行遍历，
// 每当我们访问一个数组，我们比较当前数组的index与该位置上的值是否存在着这样的对应关系，如果存在，则继续下一个，如果不存在，
// 则将当前index对应的值num，与index为num-1所对应的值进行交换，并且继续判断当前index的值情况。
// 如果在交换之前，index对应的num，与index为num-1所对应的值相等，则说明num-1所对应的值已经存在，即当前的num值即为重复值。
// 通过这样的方法，我们最多只需要遍历完整个数组就可以找到该重复的数字。
//
// 上述方法并不满足题目要求的数组为只读的情况，但是在时间复杂度上进行了优化，比蛮力法要好。
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // in=place solution
        int length = nums.size();
        int tmp=0;
        for(int i=0;i<length;++i){
            if(nums[i]!=i+1){
                if(nums[i]==nums[nums[i]-1]){
                    return nums[i];
                }
                else{
                    tmp = nums[i];
                    nums[i] = nums[tmp-1];
                    nums[tmp-1] = tmp;
                    --i;
                }
            }
        }
    }
};

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(2);
    Solution solution;
    int dup_num = solution.findDuplicate(nums);
    cout<<"duplicate num: "<<dup_num;
    return 0;
}