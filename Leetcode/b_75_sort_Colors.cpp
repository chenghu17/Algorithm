//
// Created by Mr.Hu on 2018/7/27.
//
// leetcode 75 sort colors
//
// 题目要求对于数组中的数字进行排序，数组中只存在三种数字0,1,2
// 要求不能先遍历数组记录0，1，2出现的次数之后再重写，并且排序要求in-place，空间复杂度为O(1)
//
// 这个题目其实就是一个快速排序的题目，我们可以完全按照快速排序的思想进行解答；
// 但是由于题目已经告诉了我们可能出现的数，所以我们可以把这个当作辅助条件来使用。
//
// 首先使用快排的思想，两个指针分别指向数组的头尾，从头开始判断，找出第一个!=mark的数，
// 然后从尾部开始，找出第一个等于mark的数，并将这个两个数进行swap交换；
// 接着继续从前面当前位置向后进行上述搜索，循环结束的条件是：
// 1、从头开始到尾部都搜索完，无!mark的数
// 2、找到!=mark的数之后，从尾部开始未找==mark的数
// 上述两个条件都可以结束当前循环，当循环结束后，我们这里的思想其实只是将等于mark的数字都放在了前面，
// 当mark==0，即0都排在了前面，没有管后面的排列顺序，所以此时我们要从当前循环结束的位置到end，对mark==1
// 进行上述循环，由于只有三种数字，所以将1排序完之后，我们就可以结束循环，此时的vector即为排序好的结果。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // using quick-sort
    void quicksort(vector<int> &nums, int begin, int end, int mark) {
        int tmp;
        for (int i = begin; i < end; ++i) {
            if (nums[i] > mark) {
                tmp = nums[i];
                for (int j = end; j > i; --j) {
                    if (nums[j] == mark) {
                        nums[i] = mark;
                        nums[j] = tmp;
                        break;
                    }
                }
                if (nums[i] != mark) {
                    tmp = i;
                    break;
                }
            }
        }
        ++mark;
        if (mark < 2) {
            quicksort(nums, tmp, end, mark);
        }
    }

    void sortColors(vector<int> &nums) {
        quicksort(nums, 0, nums.size() - 1, 0);
    }
};

int main(){
    vector<int> nums;
    nums.emplace_back(2);
    nums.emplace_back(1);
    nums.emplace_back(0);
    nums.emplace_back(1);
    nums.emplace_back(1);
    nums.emplace_back(0);
    nums.emplace_back(2);
    Solution solution;
    solution.sortColors(nums);
    for(auto n:nums){
        cout<<n<<" ";
    }
    return 0;
}