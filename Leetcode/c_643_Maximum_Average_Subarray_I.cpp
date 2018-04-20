//
// Created by Mr.Hu on 2018/4/20.
//
// leetcode 643 maximum average subarray_I
//
// 题目要求从给定的数组中找出连续的k个数，使得其平均数最大。
//
// 这一题直接解答，还是比较直观的，想要求平均最大，则和要求最大。可以说是最大子序列问题。
// 每次向后移动一位，如果后一位比之前k位中的第一位大，则说明接下的四位数的和可能比之前最大的结果大，
// 直到遍历完，则可以得到最大连续k个数的和。最后求平均数即可得到所求。
// 要注意 for (int i = 0; i < size - k; i++) 这个循环的终止条件，刚开始我写的size-k+1，但是输出
// 一直特别大，我想是哪里越界了，但是一直没有找到位置，原来vector越界后是不报错的...
// 因为我们在后面的判断是nums[i + k] > nums[i]，那么i的值就只能是i<size-k，如果i<size-k+1，
// 那么i最大可以取size-k，那么i+k就为size，很明显这里就越界了...我刚开始只考虑了i，没有想到i+k越界的情况。
// vector越界不会报错！再次强调！
//
// 因为代码值beat掉百分之六左右的人，所以想去改改：
// 我就想到其实只要比较每个连续子序列的第一个值和子序列下一个值就可以判断是否会增大，于是就改了代码，去掉了
// 那些繁琐的求和，但是执行了三次都报错了，我看了结果例子，这种方法确实存在局限性，因为每次判断后，如果没有比第一个数字大，
// 则就跳过这个数，这个数在后面的累加中是可以被用到的，但是仅仅靠其与第一个值的大小就跳过这个值，
// 这样就出现这个数比原来子序列中其他数大的情况，而这种情况被跳过了，
// 但是这个数可能与后面积累起来大于最开始那个最大的子序列，所以这样改就不行了。
//
// 写完上面这段话之后我开始怀疑为的做法，证明了一下才接受其合理性，中午做题就是不知道自己想的和做的到底是啥。
// 已知数组[a,b,c,d,e,f,g]，现最大值假设为A = a+b+c+d，判断a和e的大小，若a<e，A>B,则最大值不变；否则最大值为B = b+c+d+f；
// 现在假设a<e，此时第一索引值指向了b，接下俩就需要判断b与f的大小，如果f>b，C>B，则需要判断C = c+d+e+f与A = a+b+c+d的大小；
// 对！合理性就在这里，我不是每次都拿与当前index相距k与a比较，而是与当前index进行比较，然后与当前最大和进行比较。
// 每次都又一个中间和，即A>B,C>B，那么需呀判断A与C的大小，如果A>B,B>C，则最大值还是A，
// 到下一次判断时，中间和就变成了C，如果A>C，D>C，则需要判断A与D的大小，同时。
// 即每次都使用当前最大值，和当前的中间和，且最大值和中间和的大小关系已经由上一次确定。
//
// 感觉这段话写的好乱，之后自己读可能都会骂自己...
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        int size = nums.size();
        int max_result = 0;
        for (int j = 0; j < k; j++) {
            max_result += nums[j];
        }
        for (int i = 0; i < size - k; i++) {
            if (nums[i + k] > nums[i]) {
                int tmp = 0;
                for (int j = 1; j <= k; j++) {
                    tmp += nums[i + j];
                }
                if (tmp > max_result) {
                    max_result = tmp;
                }
            }
        }
        double result = max_result * 1.0 / k;
        return result;
    }
};

int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    Solution solution;
    double average = solution.findMaxAverage(nums, k);
    cout << average << endl;
    return 0;
}