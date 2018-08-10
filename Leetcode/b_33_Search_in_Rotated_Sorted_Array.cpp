//
// Created by Mr.Hu on 2018/8/10.
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