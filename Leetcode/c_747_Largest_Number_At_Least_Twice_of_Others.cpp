//
// Created by Mr.Hu on 2018/4/26.
//
// leetcode 747 largest number at least twice of others
//
// 题目要求对给定的数组输出最大值的索引，该最大值要满足为数组中其他数字的两倍以上
// 第一步使用vector的max_element方法求出最大值的索引，这个索引其实是地址，然后使用distance方法
// 求出该值在数组的位置。接着对数组进行遍历，判断该值与其他值的倍数关系，如果都大于2，则输出
// 最大值在数组中的位置，否则输出-1。
//
// 这个题目简单，当作练手。但是在code中有一个地方我刚开始疏忽了，就是判断当前循环的位置与
// 最大值的索引是否相同，一看是写在了for循环的判断条件里面，没有意识到for循环的判断条件一旦
// 不满足则会结束for循环，所以这里要注意到，没有实际的编码真的不会意识到自己在这里的理解有时候有偏差。
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

int main() {
    vector<int> nums = {1, 2, 3, 12, 4, 4, 0};
    Solution solution;
    int index = solution.dominantIndex(nums);
    cout << index << endl;
    return 0;
}