//
// Created by Mr.Hu on 2018/4/22.
//
// leetcode 674 longest continuous increasing subsequence
//
// 题目要求对给定的数组中，找出最长连续递增子序列
// 看到这个题目，就想到之前的一个题目，c_581（要求找出最短的非连续的序列，对这个序列进行排序后，整个序列即有序）
// 受之前那个题目的影响，第一反应以为也是前后两个指针查询，后来看了一下题目后，发现不要需要这么麻烦。
// 从第一个数开始往后遍历，如果满足递增，则tmp++，如果不满足，则比较当前最长子序列的长度与之前最长的情况，然后更新；
// 在做这题的时候出现来两个小错误，第一个就是没有考虑本身就是升序，所以循环结束后加上一个判断，其实在每次是升序加一后
// 就与之前max_subsequence进行对比，也是可以的。
// 另外一个没注意到的地方就是没有考虑到需序列长度为零的情况，之前别的题目都考虑了过这种情况，这次却忘记了...
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        }
        int max_subarray = 1;
        int tmp = 1;
        for (int i = 0; i < size - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                tmp++;
//                if (tmp > max_subarray) {
//                    max_subarray = tmp;
//                }
            } else {
                if (tmp > max_subarray) {
                    max_subarray = tmp;
                }
                tmp = 1;
            }
        }
        if (tmp > max_subarray) {
            max_subarray = tmp;
        }
        return max_subarray;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    Solution solution;
    int result = solution.findLengthOfLCIS(nums);
    cout << result << endl;
    return 0;
}