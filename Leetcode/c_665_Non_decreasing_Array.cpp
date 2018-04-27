//
// Created by Mr.Hu on 2018/4/27.
//
// leetcode 665 noe decreasing array
//
// 题目要求对于给定的数组，判断是否能够最多更改一个值，使得数组成为非递减的数组，即nums[i]<=nums[i+1]
//
// 这个题目最开始做大概是三天前，当时做了三四十分钟，提交了三次都是wrong answer
// 所以就隔了几天再来做这个题目，上次做的时候想到了一种方法来观察规律，即用折线图来表示每个点，这样来判断
// 满足条件的数组所具备的特征，所以进行我又通过折线的方式来分析。
//
// 对于满足条件的数组，第一种就是原本就是非递减的数组，第二种就是存在一次nums[i]>nums[i+1]的情况，
// 如果出现两次那只改变一次是无法让数组变为非递减的，因为用折线表示则此时又两个"波谷"
// 所以我们现在需要判断的就是是否存在这样的位置，用count来表示位置个数，index来表示"波谷"的索引值，num表示"波谷"的前一个索引
// 如果count==0，则数组本身就是非递减数组，返回true；
// 如果count>1，则数组不可能通过替换一个值变为非递减数组；
// 如果count==1，通过观察简单的例子，如果nums[i]>nums[i+1]，满足i==0或者i==size-2，
// 即递减的位置在刚开始或者在最后，则一定可以替换较大或者较小的值，将数据转换为非递减数组。
// 除了以上的情况，则要考虑"波谷"在中间位置的情况，
// 如果"波谷"的下一位大于等于"波谷"的上一位，则可以替换"波谷"为其中间的数字，此时数组为非递减；
// 否则判断"波谷"与上上一位的大小，如果大于等于，则可以替换"波谷"的上一位来使数组为非递减，如例子：
// [-1,4,2,3]即替换i=1的4；[1,4,2,5]则替换i=2的2。
//
// 形式化的分析是理解这个题目，找准变换规律、判断条件的关键
// 另外，做完这个题目之后，其实可以发现，如果满足count==1，则要认真分析是替换掉"波谷"位置的数字，
// 还是替换掉"波谷"上一位比它大的数组，这样才能考虑所有的情况，我刚开始就只考虑替换"波谷"的情况，
// 而没有意识到有[-1,4,2,3]的情况出现。
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

int main() {
    vector<int> nums = {1, 2, 1, 3, 4, 5, 6};
    Solution solution;
    bool check = solution.checkPossibility(nums);
    cout << check << endl;
    return 0;
}