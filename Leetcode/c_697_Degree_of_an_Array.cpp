//
// Created by Mr.Hu on 2018/4/24.
//
// leetcode 697 degree of an array
//
// 题目要求对给定的数组，求出数组的度所在子序列的最小长度。数组的度用出现次数最多的数的个数表示。
//
// 早上做这个题目，头很清醒，先分析了一下：要想得到题目所求，则要求得到出现最多的数在数组中的索引值，
// 然后将最大索引和最小索引做差就可以得到子序列的长度，如果存在多个出现相同次数的数，则比较它们的
// 子序列长度，取最小值即可。
// 于是就开始coding，首先要把数组中出现的所有数，以及它们出现的索引值给提取出来，所以就想到了使用
// map<int,vector<int>>这个数据结构，遍历一次数组即可得到，然后对这个map进行遍历，注意是遍历其value，
// 在这里要使用iterator(迭代器)，对value.size()最大的进行保留，由于可能出现相同大小的，所以这里使用
// vector<vector<int>>来进行保存，这样我们就得到了数组度的所有的索引集合，然后对这个vector进行遍历，
// 求其中vector<int>中的最大最小值，即度的最大和最小索引值，然后计算子序列的长度；由于可能
// 出现相同度的情况，所以子序列的最小长度即这些度中子序列长度的最小值。
// 值得注意的是：minSubarray的初始值设定为大于size；
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int> &nums) {
        int size = nums.size();
        // tmp is uesd to contain every number and its index-set
        map<int, vector<int>> tmp;
        for (int i = 0; i < size; i++) {
            (tmp[nums[i]]).push_back(i);
        }
        map<int, vector<int >>::const_iterator it = tmp.begin();
        // maxNumber is the max appear time
        // degree contains the index_array which appear the max time
        // there might be multi-numbers which appear the same max time
        int maxNumber = 0;
        vector<vector<int>> degree;
        for (; it != tmp.end(); it++) {
            vector<int> index = it->second;
            int num = index.size();
            if (num > maxNumber) {
                maxNumber = num;
                degree.clear();
                degree.push_back(index);
            } else if (num == maxNumber) {
                degree.push_back(index);
            }
        }
        // calculate the shortest subarray degree
        int minSubarray = size + 1;
        for(int j = 0; j < degree.size(); j++) {
            auto biggest = max_element(degree[j].begin(), degree[j].end());
            auto smallest = min_element(degree[j].begin(), degree[j].end());
            int subarrayLength = *biggest - *smallest + 1;
            if (subarrayLength < minSubarray) {
                minSubarray = subarrayLength;
            }
        }
        return minSubarray;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 2, 4, 5, 2, 1, 7, 1};
    Solution solution;
    int result = solution.findShortestSubArray(nums);
    cout << result << endl;
    return 0;
}