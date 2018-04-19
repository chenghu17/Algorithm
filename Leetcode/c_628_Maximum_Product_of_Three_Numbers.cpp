//
// Created by Mr.Hu on 2018/4/19.
//
// leetcode 628 maximum product of three numbers
//
// 题目要求在给定的数组中，找出乘积结果最大的三个数。
//
//
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:

//        //the wrong solution
//    int maximumProduct(vector<int>& nums) {
//        // fine the max three number and the min two number
//        int size = nums.size();
//        set<int> maxThreeNumbers;
//        set<int> minTwoNumbers;
//        for (int i = 0; i < size; i++) {
//            maxThreeNumbers.insert(nums[i]);
//            minTwoNumbers.insert(nums[i]);
//            if (maxThreeNumbers.size() > 3) {
//                maxThreeNumbers.erase(maxThreeNumbers.begin());
//            }
//            if (minTwoNumbers.size() > 2) {
//                set<int>::iterator index = minTwoNumbers.end();
//                minTwoNumbers.erase(--index);
//            }
//        }
//        int result_one = 1, result_two = 1;
//        set<int>::iterator it_max;
//        for (it_max = maxThreeNumbers.begin(); it_max != maxThreeNumbers.end(); it_max++) {
//            result_one *= (*it_max);
//        }
//        for (auto it_min = minTwoNumbers.begin(); it_min != minTwoNumbers.end(); it_min++) {
//            result_two *= (*it_min);
//        }
//        result_two *= (*(--it_max));
//        return result_one > result_two ? result_one : result_two;
//    }

    int maximumProduct(vector<int> &nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int result_one = nums[size - 1] * nums[size - 2] * nums[size - 3];
        int result_two = nums[0] * nums[1] * nums[size - 1];
        return result_one > result_two ? result_one : result_two;
    }

    int maximumProduct_optimal(vector<int> &nums) {
        int size = nums.size();
        int max_one = INT_MIN, max_two = INT_MIN, max_three = INT_MIN;
        int min_one = INT_MAX, min_two = INT_MAX;
        for (int i = 0; i < size; i++) {
            if (nums[i] > max_three) {
                max_one = max_two;
                max_two = max_three;
                max_three = nums[i];
            } else if (nums[i] > max_two) {
                max_one = max_two;
                max_two = nums[i];
            } else if (nums[i] > max_one) {
                max_one = nums[i];
            }

            if (nums[i] < min_one) {
                min_two = min_one;
                min_one = nums[i];
            } else if (nums[i] < min_two) {
                min_two = nums[i];
            }
        }
        int result_one = max_one * max_two * max_three;
        int result_two = min_one * min_two * max_three;
        return result_one > result_two ? result_one : result_two;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, -8, -9, -10};
    Solution solution;
//    int max_product = solution.maximumProduct(nums);
    int max_product = solution.maximumProduct_optimal(nums);
    cout << max_product << endl;
    return 0;
}