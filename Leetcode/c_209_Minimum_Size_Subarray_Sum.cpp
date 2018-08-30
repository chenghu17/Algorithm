//
// Created by Mr.Hu on 2018/8/29.
//
// 题目要求找出最小长度连续子数组，使得子数组的和大于等于给定的s值，返回子数组的长度
//
// 方法一、（BF方法）使用双层循环，第一层表示子数组开始的位置，第二层表示连续子数组累加过程，直到累加和大于等于s，
// 则比较当前长度与之前最小长度，取最小情况。
//
// 方法二：（使用数组中常用的先求从index=0开始，所有子集的和，最后比较子集之间的差值，即中间子序列的和）
// 先求出length个从index=0开始的子集的和，然后从index=0开始，sub_sum[index]+s，找出第一个sub_sum[i]大于等于该值的i，
// i-index即为之间数字的个数；然后将index++，继续上述操作，每次找到第一个大于等于该结果的i后，计算中间数字的个数，
// 取最小的情况，最后输出最小结果。
// 在求解零数组，数组中连续结果最小和时都可以思考这种方法。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int length = nums.size();
        if (length == 0) {
            return 0;
        }
        int min_length = length;
        int tmp, sum_num;
        for (int i = 0; i < length; ++i) {
            tmp = 1;
            sum_num = nums[i];
            if (sum_num >= s) {
                return 1;
            }
            for (int j = i + 1; j < length; ++j) {
                sum_num += nums[j];
                tmp += 1;
                if (sum_num >= s) {
                    break;
                }
            }
            if (sum_num >= s) {
                min_length = tmp < min_length ? tmp : min_length;
            } else if (i == 0) {
                return 0;
            }
        }
        return min_length;
    }

    int minSubArrayLen_option(int s, vector<int>& nums) {
        int length = nums.size();
        if(length==0){
            return 0;
        }
        vector<int> sub_sum(length+1,0);
        for(int i=1;i<length+1;++i){
            sub_sum[i] = sub_sum[i-1] + nums[i-1];
        }
        if(sub_sum[length]<s){
            return 0;
        }
        int tmp = 0;
        int result = INT_MAX;
        for(int i=0;i<length;++i){
            tmp = s + sub_sum[i];
            for(int j=i+1;j<length+1;++j){
                // 这里使用binary search更高效
                if(sub_sum[j]>=tmp){
                    result = min(result,j-i);
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums;
    nums.emplace_back(2);
    nums.emplace_back(1);
    nums.emplace_back(3);
    nums.emplace_back(5);
    nums.emplace_back(2);
    nums.emplace_back(3);
    nums.emplace_back(1);
    int s = 7;
    Solution solution;
//    int min_length = solution.minSubArrayLen(s, nums);
    int min_length = solution.minSubArrayLen_option(s, nums);
    cout << min_length << endl;
    return 0;
}