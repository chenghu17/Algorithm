//
// Created by Mr.Hu on 2018/8/10.
//
// leetcode 33 search in rotated sorted array
//
// 题目要求对于有序的数组按照某个支点进行翻转后，查询target是否存在与这个数组中。
//
// 对于有序数组，我们可以二分查找的方式去查找target是否存在。但是当前的数组是经过一个有序数组按照
// 某个支点将数组进行翻转。（此处数组中无重复值）
// 但是我们还是可以采用二分查找来查询target值：
// 同样的middle计算方法和while(left<=right)判定条件，如果nums[middle]==target，则可以直接输出，
// 如果不相等，则判断nums[middle]<=nums[right]，则说明middle->right之间为连续递增，如果target在
// 其中，则left = middle+1，否则target只可能存在与左边部分，即left->middle，因此right = middle-1;
//
// 同理，如果nums[left]<=nums[middle]，target如果在其中，则right = middle-1；否则target只可能在数组的右边部分，即
// middle->right，因此left = middle+1
//
// 以这种二分查找算法的变体，可以高效的进行查找。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int index = -1;
        if (nums.size() == 0) {
            return index;
        }
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        while (left <= right) {
            middle = left + (right - left) / 2;
            if (nums[middle] == target) {
                index = middle;
                break;
            }
                // 右侧有序
            else if (nums[middle] <= nums[right]) {
                // 判断target是否在右侧
                if (target > nums[middle] && target <= nums[right]) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
                // 左侧有序
            else {
                // 判断target是否在左侧
                if (target >= nums[left] && target < nums[middle]) {
                    right = middle - 1;
                }
                    //
                else {
                    left = middle + 1;
                }
            }
        }
        return index;
    }
};

int main(){
    Solution solution;
    vector<int> nums;
    nums.emplace_back(4);
    nums.emplace_back(5);
    nums.emplace_back(6);
    nums.emplace_back(7);
    nums.emplace_back(0);
    nums.emplace_back(1);
    nums.emplace_back(2);
    int index = solution.search(nums,7);
    cout<<index<<endl;
    return 0;
}