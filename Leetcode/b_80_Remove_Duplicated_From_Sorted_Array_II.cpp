//
// Created by Mr.Hu on 2018/7/29.
//
// 题目要求对已排序的数组进行去重处理，要求每个元素最多只能出现2此，最后返回满足要求的数组长度，要求在原数组上进行操作
//
// 第一种想法：循环遍历已排序数组，如果当前元素出现的次数超过2次，则将其之后的元素整体向前移，数组length--
//              循环结束条件为i<length，在这个过程中其实也在不断缩小 数组的长度，但是这个涉及到其后所有元素的移动，时间效率比较高。
//
// 第二种想法：使用两个指针分别指向重复元素起始位置和循环的当前位置，如果当前位置不满足重复情况，则和重复元素起始位交换，
//              但是这种想法的代码没有实现出来...在其实位置有点模糊。
//
// 他人的好方案啊：对于数组进行迭代，i表示数组中满足条件的位数。
//                  前两位是不用影响结果的，从第n位(n>2)开始，每次和n-2为比较，如果nums[n]>nums[n-2]，
//                  则可以将nums[i] = nums[n]，因为满足上述大小情况，一定存在nums[n]出现的次数小于等于2，
//                  这个地方很巧妙！同时i++，让我们一起欣赏下面optimal的优美代码。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int length = nums.size();
        if (length == 0) {
            return 0;
        }
        int count = 1;
        int tmp = nums[0];
        for (int i = 1; i < length; ++i) {
            if (nums[i] == tmp) {
                ++count;
                if (count > 2) {
                    for (int j = i + 1; j < length; ++j) {
                        nums[j - 1] = nums[j];
                    }
                    --length;
                    --i;
                    nums[length] = tmp; //optional
                }
            } else {
                count = 1;
                tmp = nums[i];
            }
        }
        return length;
    }

    int removeDuplicates_optimal(vector<int>& nums) {
        int i=0;
        for(auto n:nums){
            if(i<2 || n>nums[i-2]){
                nums[i++] = n;
            }
        }
        return i;
    }
};

int main() {
    vector<int> nums;
    nums.emplace_back(1);
    nums.emplace_back(2);
    nums.emplace_back(2);
    nums.emplace_back(2);
    nums.emplace_back(3);
    nums.emplace_back(4);
    Solution solution;
//    int length = solution.removeDuplicates(nums);
    int length = solution.removeDuplicates_optimal(nums);
    for (int i = 0; i < length; ++i) {
        cout << nums[i] << " ";
    }
    return 0;
}