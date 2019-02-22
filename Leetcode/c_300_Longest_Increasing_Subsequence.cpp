//
// Created by Mr.Hu on 2019/2/22.
//
// leetcode 300 longest increasing subsequence
//
// 该题目是一个很常考的面试题，给定一个数组，要求数组中最长递增子序列（注意是子序列，不是子数组）的长度。
//
// 这里其实隐含着一个条件，即子序列不一定连续，所以求解的时候，要注意。
//
// 一开始想着直接两层循环，每次判断当前值与序列中最后一个值的大小关系，来更新序列长度，但是存在这样一个问题：
// [2,5,3,4]，如果按照上面的双层循环，则以2开头的最长递增序列长度为2，而不是3。
// 所以我们现在需要想别的办法，来避免这种因为前面的决定而影响后面的情况：
//
// 用nums.size()长的数组来保存以每个位置结尾的最长递增子序列的长度，
// 第一个值初始化为1，从第二个值开始，判断其与前面所有值的大小，如果比前面的值大，则临时最长递增子序列即前面位置对应的最长值+1；
// 所有临时最长递归子序列的最大值，即为当前值达到最大的选择，并记录该最大值+1为当前位置结尾的最长子序列的长度。
// 每次记录完后，与当前全局的最长递增子序列的长度比较，保留最大值，重复上述循环。
// 最后的全局最长递增子序列长度即为所求。
//
// 时间复杂度为 O(N*N)
// 如何将其提升到 O(N*logN) 需要另外思考，但是根据logN，可以联想到二分搜索的时间复杂度。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return 1;
        }
        vector<int> max_length(nums.size()); //表示以当前值结尾时，递增序列的长度
        max_length[0] = 1; // 初始化第一个值
        int cur = 0; // 临时存储当前值结尾的当前最长长度
        int cur_max_length = 0; // 全局最长递增子序列的长度
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                // 此处不需要加等号
                if (nums[i] > nums[j]) {
                    cur = max(cur, max_length[j]);
                }
            }
            max_length[i] = 1 + cur;
            cur_max_length = max(cur_max_length, max_length[i]);
            cur = 0;
        }
        return cur_max_length;
    }
};

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution solution;
    int max_length = solution.lengthOfLIS(nums);
    cout << "longest increasing subsequence = " << max_length << endl;
    return 0;
}