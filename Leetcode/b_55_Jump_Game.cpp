//
// Created by Mr.Hu on 2018/9/11.
//
// 题目给定一个阶梯场景，每一阶梯上的数字表示最大可跳台阶数，要求判断从最开始的阶梯开始跳，是否能够跳到最后一个台阶。
//
// 分析：根据题目的意思，要求在跳跃的路径中，不能达到step=0的位置，所以我们需要判断否存在step=0的情况。
//
// Solution1：canJump；该方法是我解这个题目的一个递归操作，思想就是从第一个位置开始，从1开始，直到最大可跳步数，进行循环，
// 在循环中递归的调用该方法，只是位置从原来的index到现在的index+i，总共已经跳的步数为count+i，如果所跳的位置值为0，则返回false，
// 循环中对这个这个结果进行判断，如果结果为false，则continue，即i++操作，
// 如果为true，则说明可以到达最后一个台阶位置，此时可以直接返回true。
//
// Solution2：canJump_optimal；从后往前判断，如果某一位为0，则用一个count变量来保存从其前面跳到该位置所需要的步长，
// 然后向前去遍历，判断当前点的最大跳步数目是否大于count，大于则说明存在路径能够不经过此处为0的台阶；如果不能，则count需要加一，
// 并继续向前遍历，直到遍历完整个数组。重复上面的操作直到判断完第一阶台阶。这种方法的复杂度最坏情况O(N*N)，最好情况O(N)。
//
// Solution3：canJump_elegant；这个方法是在上一个方法accpted之后，在Discuss中学习的一种巧妙的解决方法。
// 该方法通过初始值step为第一阶台阶，然后[--step]是否小于0，即当前位置是否为0，如果为0，则说明没法跳跃到最后一个台阶，return false；
// 否则，判断下一阶台阶i允许的最大跳跃数是否大于[--step]，如果大于，则说明从下一阶台阶i能到达的台阶可以包含当前台阶所能到达的位置，
// 因此我们可以将step更新为nums[i]，然后继续上述判断，如果遍历完都没有出现return false的情况，则return true。
// 这种方法巧妙在一次遍历可以判断是否能到达最后一个台阶，复杂度为O(N)。通过找出一个台阶数目大于前面台阶能走的范围这种情况，
// 来替换掉前面的台阶判断的情况，这种思想就是贪心法，每次保留还能走最远台阶数的位置。
// 其实这个方法也可以理解为方法二的正向判断。
//
//
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool jumpStep(vector<int> &nums, int index, int count) {
        int sum_count = count;
        if (nums[index] == 0) {
            return false;;
        }
        for (int i = 1; i <= nums[index]; ++i) {
            if ((sum_count + i) == (nums.size() - 1)) {
                return true;
            }
            if (!jumpStep(nums, i + index, sum_count + i)) {
                continue;
            } else {
                return true;
            }
        }
        return false;
    }

    bool canJump(vector<int> &nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return true;
        }
        int count = 0;
        return jumpStep(nums, 0, 0);
    }

    bool canJump_optimal(vector<int> &nums) {
        if (nums.size() == 0 || nums.size() == 1) {
            return true;
        }
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] == 0) {
                int count = 1;
                bool can = false;
                for (int j = i - 1; j >= 0; --j) {
                    if (nums[j] > count) {
                        can = true;
                        break;
                    }
                    count++;
                }
                if (can) {
                    continue;
                }
                return false;
            }
        }
        return true;
    }

    bool canJump_elegant(vector<int> &nums) {
        int size = nums.size();
        int step = nums[0];
        for (int i = 1; i < size; ++i) {
            step--;
            if (step < 0)
                return false;
            if (nums[i] > step)
                step = nums[i];
        }
        return true;
    }

};

int main() {
    vector<int> nums;
    nums.emplace_back(2);
    nums.emplace_back(1);
    nums.emplace_back(2);
    nums.emplace_back(1);
    nums.emplace_back(0);
    nums.emplace_back(1);
    Solution solution;
//    bool canif = solution.canJump(nums);
//    bool canif = solution.canJump_optimal(nums);
    bool canif = solution.canJump_elegant(nums);
    cout << canif;
    return 0;
}