//
// Created by Mr.Hu on 2018/4/12.
//
// leetcode 414 third maximum number
//
// 题目要求在给定的数组中找出第三大的数字，且重复的数字只算一遍，如果数组中不同的数字没有三个，则输出最大值
// 一开始想这题目的时候觉得没有什么简便方法，想着就用三个变量来存储top-3，但是总觉得把问题搞复杂了，于是去查别人是怎么做的，
// 看了两个解答都是这种，那就自己写一下这种方法吧，刚开始想着给top-3初始INT_MIN，然后与给定的数字进行比较，
// 但是第一次提交发现实例中也会给INT_MIN的值，于是就会导致错误，因为我用的是大于INT_MIN才加入到top-3中，
// 所以就用LONG_MIN，另外我定义了一个count来记录给定数组中有多少个不同的数字，最后循环结束后，若count小于3，
// 则输出最大的数result[0]，否则输出result[2]；
//
// 去找来一下其他解法，发现还有一种代码看来起更少的方法，用set来存储top-3，set数据结构会自动排序，
// 而且set会自动去重，代码如下optional，执行速度上会稍微快一点，在我的IDE上会出现问题，查了一下是因为c++11中initializer_list与int冲突的问题
// 当然还有一种经常用在海量数据挖掘中的，用最大堆来进行解决，后面学习这种数据结构继续练习
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int> &nums) {
        vector<long> result;
        result.push_back(LONG_MIN);
        result.push_back(LONG_MIN);
        result.push_back(LONG_MIN);
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > result[0]) {
                result[2] = result[1];
                result[1] = result[0];
                result[0] = nums[i];
                count++;
            } else if (nums[i] > result[1] && nums[i] != result[0]) {
                result[2] = result[1];
                result[1] = nums[i];
                count++;
            } else if (nums[i] > result[2] && nums[i] != result[1] && nums[i] != result[0]) {
                result[2] = nums[i];
                count++;
            }
        }
        if (count < 3)
            return (int) result[0];
        else
            return (int) result[2];
    }

    int thirdMax_optional(vector<int> &nums) {
        set<int> result;
        for (int i = 0; i < nums.size(); i++) {
            result.insert(nums[i]);
            if (result.size() > 3) {
                result.erase(result.begin());
            }
        }
        if (result.size() >= 3)
            return *result.begin();
        else
            return *result.rbegin();
    }

};

int main() {
    vector<int> nums = {2, 1};
    Solution solution;
    int result = solution.thirdMax(nums);
    cout << result << endl;
    int result_optional = solution.thirdMax_optional(nums);
    cout << result_optional << endl;

    return 0;
}