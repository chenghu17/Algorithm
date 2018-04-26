//
// Created by Mr.Hu on 2018/4/26.
//
// leetcode 747 largest number at least twice of others
//
// 
//
//
//
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int> &nums) {
        int index = -1;
        bool isexist = true;
        auto biggest = max_element(nums.begin(), nums.end());
        int biggest_index = distance(nums.begin(), biggest);
        int biggest_num = *biggest;
        // if(biggest_num == 0){
        //     return index;
        // }
        int size = nums.size();
        int i = 0;
        for (; i < size; i++) {
            if (nums[i] == 0 || i == biggest_index) {
                continue;
            }
            if ((biggest_num / nums[i]) < 2) {
                isexist = false;
                break;
            }
        }
        if (isexist) {
            index = biggest_index;
        }
        return index;
    }
};

int main(){
    vector<int> nums = {1,2,3,12,4,4,0};
    Solution solution;
    int index = solution.dominantIndex(nums);
    cout<<index<<endl;
    return 0;
}