//
// Created by Mr.Hu on 2018/4/24.
//
// leetcode 697 degree of an array
//
//
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
        // there might be multi-numbers whiche appear the same max time
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