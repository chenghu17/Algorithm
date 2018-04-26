//
// Created by Mr.Hu on 2018/4/26.
//
// leetcode 724 fine pivot index
//
// 题目要求对给定出的数组，找出其折点(pivot index)，要求折点左边子数组的和等于折点右边数组的和，都包含该点。
// 看到这个题目既然要求左右和相等，那比较条件就是左右两边的和，如果每次都计算两边的和，那复杂度就提高了，
// 那么就先把数组的和求出来，然后每次得到左边的数组和之后，则可以直接用整个数组的和加上当前折点再减去左边的和即可。
// 注意这里一定给整个数组和加上当前的节点。
// 另外值得注意的地方就是对左边数组求和，我一看写的是双循环，对left_result每次都重新算，但是最后又没有将
// 这个值重置为0，后来发现其实不用写双循环，直接对letf_result加上当前折点的值，即可以得到此时左边子数组的和。
// 然后比较left_result和right_result，相等则终止循环，并返回当前折点的index值。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int index = -1;
        int size = nums.size();
        int sum = 0;
        int left_result = 0;
        int right_result = 0;
        for (int i = 0; i < size; i++) {
            sum += nums[i];
        }
        for (int i = 0; i < size; i++) {
            left_result += nums[i];
            right_result = sum + nums[i] - left_result;
            if (left_result == right_result) {
                index = i;
                break;
            }
        }
        return index;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 5, 6, 5, 3, 2, 1};
    Solution solution;
    int pivotIndex = solution.pivotIndex(nums);
    cout << pivotIndex << endl;
    return 0;
}