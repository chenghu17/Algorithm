//
// Created by Mr.Hu on 2018/4/27.
//
// lletcode 665 noe decreasing array
//
//
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        int size = nums.size();
        int count = 0;
        int index = 0;
        int num = 0;
        for (int i = 0; i < size - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (count == 0) {
                    count++;
                    index = i + 1;
                    num = i;
                } else {
                    return false;
                }
            }
        }
        if (count == 0 || index == 1 || num == size - 2) {
            return true;
        }
        if (nums[num + 2] >= nums[num]) {
            return true;
        }
        if (nums[num - 1] <= nums[num + 1]) {
            return true;
        }
        return false;
    }
};

int main(){
    vector<int> nums = {1,2,1,3,4,5,6};
    Solution solution;
    bool check = solution.checkPossibility(nums);
    cout<<check<<endl;
    return 0;
}