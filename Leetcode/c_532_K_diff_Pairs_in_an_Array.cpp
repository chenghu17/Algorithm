//
// Created by Mr.Hu on 2018/4/14.
//
// leetcode 532 k diff pairs in an array
// 题目给定一个数组，一个目标数字，求出由数组中数字组成的数对，数对中两个数差的绝对值与目标数字相等，
// 且不考虑数对中两个数字的顺序，同一个数对只记录一次，数组中的每个数字只能使用一次。
//
// 刚拿到这一题目，没什么思路，准备用map的key-value形式来存储所有可能的数对，但是无法存储，因为key值有重复的情况；
// 于是就去找每一对数对存在的特殊性，发现每一对不同的数对，其和是不相同的！这就是问题的突破口了
// 我们可以遍历每两个数的diff，等于给定的目标值，则记录它们的和，如果和与之前的数对相同，则说明这两个数对相同
// 为了说服自我我还特地证明了一下上面的这个结论：
// a-b=c; d-e=c; 一定有a-b=d-e，则一定有a-d=b-e(1).
// 如果两个数对的和相同，则a+b=d+e ---> a-d=e-b(2)
// (1)与(2)联合，则说明b=e & a=d，于是可以得到：差相同并且和也相同的两个数对，一定有这两个数对相同
// 因此这道题目的解法突破点就在这个定理当中!
//
// 但是时间复杂度好像有点高...才超过了5%左右的方法
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        set<int> result;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (abs(nums[i] - nums[j]) == k) {
                    int diff = nums[i] + nums[j];
                    result.insert(diff);
                }
            }
        }
        return result.size();
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1, 4, 6, 2};
    int k = 2;
    Solution solution;
    int pairs = solution.findPairs(nums, k);
    cout<<pairs<<endl;
    return 0;
}