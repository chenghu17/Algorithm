//
// Created by Mr.Hu on 2018/4/18.
//
// leetcode 581 shortest unsorted continuous subarray
//
// 昨天做这一题快一个小时，提交了九次，但是始终没有通过，心累➕心酸...
// 没提交一次就会出现一个新的case通不过，而正是我没有想到的，然后我又基于这个case去改，
// 改完之后发现新的case还是通不过，这可能就是一个bug解决了，还有千千万万个bug等着我...
// 其实我大概明白，我昨天的想法可能有问题，对问题理解的过于特殊化，用机器学习中的词来说就是不具备泛化能力。
// 但是我还是坚持改改改，一直提交了九次...还是没过，这个故事告诉我们，悬崖前要勒马。
//
// 删掉了昨天的代码，今天重新理解这个题目，有了新的想法：其实要找最小的未排序的子序列，其实就是从左到右
// 找第一个值，要求其后面存在数字比它还小，则说明这个数字没有在它应该在的位置上；
// 找到左边的界以后，则开始找右边的界，同理从右边开始进行比较，找到第一个数，要求其前面的数字存在比它大，
// 说明这个数字不应该在这个位置，而且是最右边的一个，即右边界；
// 得到左边界和右边界，则可以得到最短未排序连续子序列的长度了；
// 如果一直未找到左边界，则右边界也就不需要找了，循环结束后，则说明原数组为满足要求的有序数组，输出0即可。
//
// 因为我的执行时间只超过了个位数人，所以去查了一下别人的解答，大部分都是另外建立一个数组，进行深拷贝
// 然后对数组进行排序，将排序后的数组与原数组进行比较，找到左边第一个和右边第一个与排序数组不相等的位置
// 这样就可以计算最短未排序连续子序列的长度
//
// 另外看到一个时间复杂度为O(n)，空间复杂度为O(1)的解法，时间有限，我还没有去理解这个解法，
// 下次理解了再更新这个思路，先把代码copy过来，以备之后理解。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int size = nums.size();
        int l_index = 0;
        int r_index = size - 1;
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (nums[i] > nums[j]) {
                    l_index = i;
                    for (int m = size - 1; m > l_index; m--) {
                        for (int n = m - 1; n >= l_index; n--) {
                            if (nums[m] < nums[n]) {
                                r_index = m;
                                return r_index - l_index + 1;
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }

    int findUnsortedSubarray_optimal(vector<int> &nums) {
        int n = nums.size(), start = -1, end = -2;
        int mn = nums[n - 1], mx = nums[0];
        for (int i = 1; i < n; ++i) {
            mx = max(mx, nums[i]);
            mn = min(mn, nums[n - 1 - i]);
            if (mx > nums[i]) end = i;
            if (mn < nums[n - 1 - i]) start = n - 1 - i;
        }
        return end - start + 1;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 2, 1};
    Solution solution;
//    int result = solution.findUnsortedSubarray(nums);
    int result = solution.findUnsortedSubarray_optimal(nums);
    cout << result << endl;
    return 0;
}