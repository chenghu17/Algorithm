//
// Created by Mr.Hu on 2018/7/22.
//
// leetcode 324 wiggle sort II
//
// 题目要求对于给定的数组按照要求进行排序，满足nums[0]<nums[1]>nums[2]<nums[3]>nums[4]...
// 这个题目在leetcode属于medium级别，之前做这个题目没有什么思路，然后最近学习了stack的知识，结合这个题目来做一下。
// 首先对nums进行排序，从小到大，然后将nums从0到size-1都压栈，即当前top为最大元素，
// 要想满足当前排序条件，可以发现，nums[1],nums[3],nums[5]...要求是数组中较大元素，而nums[0],nums[2],nums[4]...
// 是数组中较小元素，所以我们可以把当前数组分为较大数和较小数，一旦我们能够做到nums[1]>nums[3]>nums[5]，
// 同时nums[0]>nums[2]>nums[4]，则最终的结果一定满足排序条件，因为较大数中最大值和较小数中的最大值进行比较，
// 且给定的数组一定能进行wiggle sort。
//
//
// solution2：在写上述方法的时候我想出了第二种方法，对数组进行排序，找出数组的中位数和最大值，判断整个数组的位数，为奇数，则中位数将中位数与数组第一位进行swap，
// 最大值与数组第二位进行swap，然后将数组从第三位到最后一位采用上述同样的方式，直到最后结束。为偶数，则每次取第一个中间较小index的那一位进行操作。
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        stack<int> numbers;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            numbers.push(nums[i]);
        }
        int index = 1, i = 1;
        while (index < size) {
            nums[index] = numbers.top();
            numbers.pop();
            ++i;
            index = 2 * i - 1;
        }
        index = 0, i = 1;
        while (index < size) {
            nums[index] = numbers.top();
            numbers.pop();
            ++i;
            index = 2 * i - 2;
        }
    }
};

int main(){
    vector<int> nums;
    nums.emplace_back(1);
    nums.emplace_back(3);
    nums.emplace_back(2);
    nums.emplace_back(1);
    nums.emplace_back(9);
    nums.emplace_back(8);
    nums.emplace_back(5);
    Solution solution;
    solution.wiggleSort(nums);
    for(auto it = nums.begin();it!=nums.end();++it){
        cout<<*it<<" ";
    }
    return 0;
}