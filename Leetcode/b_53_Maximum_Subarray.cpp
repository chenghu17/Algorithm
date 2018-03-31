//
// Created by Mr.Hu on 27/03/2018.
//
// leetcode 53 Maximum Subarray
// 刚午休起来，做这一题有点蒙，刚开始想到的是用回溯法，但是题目只要求输出最大结果，觉得应该只需要设置一个存储最大值的项就行了。
// 在进行思考的过程中，发现这个求最大子数组最大值有这样两个规律：
// 1、如果下一个数字比加上之前已有子集后的结果还要大，则说明可以舍弃已有子集,因为子集对于下一个数带来的是更多的消耗；
// 2、如果如果下一个数字不大于加上之前已有子集后的结果，则说明将这个数字加入到已有子集中，进行下一个数字的判断。
// 按照上面的规则，在测试例[-2,1,-3,4,-1,2,1,-5,4]上执行后，发现最后的结果是5，则说明在[-5,4]都被加入进行，但是实际上的结果并不是最大的
// 所以又设置了当前最大和maximum这个变量，在每次更新subarray之后，将当前sum与maximum进行对比，来得到当前子数组的最大和
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int size = nums.size();
        vector<int> subarray;
        int sum = 0;
        int maximum = INT_MIN;
        vector<int>::iterator it;
        for (it = nums.begin(); it != nums.end(); it++) {
            if (*it > (sum + *it)) {
                subarray.empty();
                subarray.push_back(*it);
                sum = *it;
            } else {
                subarray.push_back(*it);
                sum += *it;
            }
            if (sum > maximum)
                maximum = sum;
        }
        return maximum;
    }
};

int main() {
    vector<int> nums = {-2, 1};
    Solution solution;
    int maximum = solution.maxSubArray(nums);
    cout << "maximum=" << maximum << endl;
    return 0;
}