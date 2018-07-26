//
// Created by Mr.Hu on 2018/7/26.
//
// leetcode 594 longest harmonious subsequence
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findLHS(vector<int> &nums) {
        map<int, int> n;
        int longest = 0;
        for (auto d:nums) {
            ++n[d];
        }
        for (auto m:n) {
            if (n.count(m.first + 1)) {
                longest = max(longest, m.second + n[m.first + 1]);
            }
        }
        return longest;
    }
};

int main() {
    vector<int> nums;
    int range = 80;
    for (int i = 0; i < range; ++i) {
        int number = rand() % (20 - 5 + 1) + 5;
        nums.emplace_back(number);
    }
    Solution solution;
    int longest = solution.findLHS(nums);
    cout << longest << " ";
    return 0;
}