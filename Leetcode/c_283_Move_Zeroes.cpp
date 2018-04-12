//
// Created by Mr.Hu on 2018/4/6.
//
// leetcode 283 Move Zeros
// 题目要求将给定数组中所有非零数移到数组前面，所有零元素移动到数组后面
// 由于题目要求的是in-place，所以不能用一个新的数组进行存储
// 想到之前leetcode 26中的方法，如果数字为0，则无需操作，继续判断下一个数字，
// 如果数字不为0，则需要与第一个不为0的数字进行交换，所以解题思路就是当前数字不为0时，找到第一个为0的位置，交换
// 执行完之后查看了submission detail，发现该方法的运行时间只击败了1.18%的方法，累...
//
// 于是观察想出了optimal的第二种方案：发现每次交换之后，第一个零元素一定出现在之前为零的下一个位置是，分析：
// 如果不存在连续的两个零，则每次交换即相邻交换，则零元素交换到下一位，即之前为零的下一个位置；
// 如果存在连续的两个零，则每次交换，第一个零元素会交换到第二个零元素的后面，那么交换后的第一个零元素即为之前的第二个零元素，即之前为零的下一个位置。
// 此时的submission detail击败了80%多，而且注意判断条件的顺序会很大程度上影响执行的时间效率
//
// 提出两种解法之后，又去网上看了一下别人的代码，贴在下面optional中，代码思想使用两层循环，第一层循环寻找第一个为零的数，
// 第二层循环寻找第一个非零数，然后进行交换，交换后break，再次进入第一层循环中，继续寻找第一个零元素，值得注意的是，
// 正如我自己的其他两种方法中的if (i > index)一样，交换的情况我们只需要管在零元素后面的非零元素即可，因为我们要求的是非零元素往前移，而不是往后移动。
// 但是这种时间复杂度还是比较高的，毕竟有两层循环。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                // get the first zero index
                int index = INT_MAX;
                for (int j = 0; j < size; j++) {
                    if (nums[j] == 0) {
                        index = j;
                        break;
                    }
                }
                // swap
                if (i > index) {
                    nums[index] = nums[i];
                    nums[i] = 0;
                }
            }
        }
    }
    void moveZeroes_optional(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                for(int j=i+1;j<nums.size();j++){
                    if(nums[j]!=0){
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
            }
        }
    }

    void moveZeroes_optimal(vector<int> &nums) {
        int size = nums.size();
        int index = INT_MAX;
        bool isZero = true;
        for (int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                // swap
                if (i > index) {
                    nums[index] = nums[i];
                    nums[i] = 0;
                    index = index + 1;
                }
            } else if (nums[i] == 0 && isZero) {
                index = i;
                isZero = false;
            }
        }
    }
};

int main() {
    vector<int> nums = {0, 1, 2, 0, 12, 3};
    Solution solution;
//    solution.moveZeroes(nums);
//    solution.moveZeroes_optional(nums);
    solution.moveZeroes_optimal(nums);
    auto it = nums.begin();
    for (it; it != nums.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}
