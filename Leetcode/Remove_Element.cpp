//
// Created by Mr.Hu on 25/03/2018.
//
// leetcode27 Remove Element
// 在原vector上进行update，设置一个位置变量来记录当前多少位与给定数不相同
// 一旦出现不相同，则与记录位进行交换，最终记录位的大小即位与给定数字不相同的上界
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int count = 0;
        int tmp = 0;
        auto size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] != val) {
                tmp = nums[count];
                nums[count] = nums[i];
                nums[i] = tmp;
                count++;
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    Solution sol;
    int result = sol.removeElement(nums, val);
    for (int i = 0; i < result; i++)
        cout << nums[i] << endl;
    return 0;

}


