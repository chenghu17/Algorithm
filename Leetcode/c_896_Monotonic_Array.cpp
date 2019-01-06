//
// Created by Mr.Hu on 2019/1/6.
//
// leetcode 896 monotonic array
//
// 题目要求判断数组是否为递增或者递减，相等也算。
//
// 刚开始分析居然没思路，主要卡在如果前面几个都是相等的数，则没办法判断该数组应该是递增还是递减；
// 最直接的方式就是写两个方法，分别判断数组是递增还是递减，只要其中一个为true，则return true；
// 但是这种方法太蛮力了，所以一直在思考其他方法（最终结果表面，这种"蛮力"更高效）
//
// 如果刚开始，数组连续相等，无法定数组是递增还是递减。所以先设定一个bool变量来表示是否已经确定递增还是递减；
// 因为如果相等，我们是可以直接继续循环的，因为不管在开头或者结尾，中间相等对判断没有什么影响。
//
// 设定了这样一个判断条件，然后再设定一个递增标示，如果是递增，则为true，否则为false；
// 每次两个数不相等，首先判断是否为第一个出现不相等的情况，如果是，将is_false更改为false，然后根据当前大小情况来定义递增标示；
// 如果不是第一次出现，则当前大小状态直接与递增标示判断，是否一致。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int> &A) {
        if (A.size() <= 2) {
            return true;
        }
        bool is_first = true;
        bool increase = true;
        for (int i = 0; i < A.size() - 1; i++) {
            if (A[i] == A[i + 1]) {
                continue;
            }
            if (A[i] < A[i + 1]) {
                // increase
                if (is_first) {
                    is_first = false;
                    increase = true;
                } else if (!increase) {
                    return false;
                }
            } else {
                // decrease
                if (is_first) {
                    is_first = false;
                    increase = false;
                } else if (increase) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<int> A;
    A.emplace_back(1);
    A.emplace_back(1);
    A.emplace_back(2);
    A.emplace_back(3);
    A.emplace_back(4);
    Solution solution;
    bool is_monotonic = solution.isMonotonic(A);
    cout << "is monotonic? " << is_monotonic << endl;
    return 0;
}