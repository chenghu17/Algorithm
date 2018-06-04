//
// Created by Mr.Hu on 2018/4/14.
//
// leetcode 485 max consecutive ones
//
// 题目要求找到给定数组中最大的连续1的个数，数组中只包含0和1；
// 刚拿到这一题想到可以设置一个bool变量来作为辅助判断，是否为连续，但是着手去coding，
// 发现并需要这个辅助变量，设置一个结果记录变量result就可以了，遇到0则把记录变量变为0，遇到1则++，但是此时就有一个问题，之前出现的最大连续数怎么办，
// 于是需要另一个变量max，初始化为INT_MIN，方便第一次比较，其实赋值为0最好，最后的判断也就不需要了。
// 每次对result进行++操作后，判断result与max的大小，如果result比max大，则对max进行更新。
// 如果遇到0，则把result变为0，用于接下来可能的连续1记录。
// 直到遍历完成后，输出max即可。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int size = nums.size();
        int max = INT_MIN;
        int result = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] == 1) {
                result++;
                if (result > max) {
                    max = result;
                }
            } else {
                result = 0;
            }
        }
        return max > result ? max : result;
//        return max;
    }
};

int main() {
    vector<int> nums = {0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0};
    Solution solution;
    int maxNumber = solution.findMaxConsecutiveOnes(nums);
    cout << maxNumber << endl;
    return 0;
}