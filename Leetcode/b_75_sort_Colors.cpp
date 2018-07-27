//
// Created by Mr.Hu on 2018/7/27.
//
// leetcode 75 sort colors
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // using quick-sort
    void quicksort(vector<int> &nums, int begin, int end, int mark) {
        int tmp;
        for (int i = begin; i < end; ++i) {
            if (nums[i] > mark) {
                tmp = nums[i];
                for (int j = end; j > i; --j) {
                    if (nums[j] == mark) {
                        nums[i] = mark;
                        nums[j] = tmp;
                        break;
                    }
                }
                if (nums[i] != mark) {
                    tmp = i;
                    break;
                }
            }
        }
        ++mark;
        if (mark < 2) {
            quicksort(nums, tmp, end, mark);
        }
    }

    void sortColors(vector<int> &nums) {
        quicksort(nums, 0, nums.size() - 1, 0);
    }
};

int main(){
    vector<int> nums;
    nums.emplace_back(2);
    nums.emplace_back(1);
    nums.emplace_back(0);
    nums.emplace_back(1);
    nums.emplace_back(1);
    nums.emplace_back(0);
    nums.emplace_back(2);
    Solution solution;
    solution.sortColors(nums);
    for(auto n:nums){
        cout<<n<<" ";
    }
    return 0;
}