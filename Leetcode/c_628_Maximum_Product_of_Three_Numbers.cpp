//
// Created by Mr.Hu on 2018/4/19.
//
// leetcode 628 maximum product of three numbers
//
// 题目要求在给定的数组中，找出乘积结果最大的三个数。
// 第一想法就是要考虑两个负数相乘结果更大的情况，一想到这个我就忘记了去考虑别的陷阱。于是就采用了第一种wrong solution，
// 用一个set去存储最大的三个数，用另一个set去存储最小的两个数，
// 类似于c_414_Third_Maximum_Number中的方法，这又让我复习了一下set的用法。
// 同时我又发现之前的一个错误理解，*setname.end()并不是表示set的最后一个元素，而是最后一个元素的下一个元素，
// 被一篇错误的blog给误导了，但是*setname.rbegin()可以表示最后一个元素，其合理的解释是set点到反方向迭代器的第一个元素。
// 同时还学会了另一种用指针--的形式获取最后一个数字的方法，写在github中NOTES/set.txt中，
// 最后提交三次，总是在{1000,1000,1000}这个case中报错，一开始还没发现问题，输出比正确结果少三个0，
// 后来突然醒悟过来，原来是set的另外一个性质，自动去重...所以这种方法就完全错了
//
// 于是想另外的方法，想到还是要找最大的三个数和最小的两个数，那我何不对数组进行排序，然后直接按index值来获取值呢
// 用STL中封装的sort方法对vector进行排序，排序作用在原vector上，大小为从小达到，然后取最大的三个数相乘，最小的两个数和最大的三个数相乘，
// 然后判断两个结果，哪个大就输出哪个...原来这么简单...
//
// 做完这个题目，还是觉得不需要对整个数组进行排序，毕竟我只要最大三个数和最小两个数字，所以查了一下这个题目的官方解法，
// 第二种解法就是下面code中的optimal solution，有学到了这种策略：
// 用三个变量表示最大的三个数(设为max_one<max_two<max_three)，初始化INT_MIN，整数最小值，方便和数组第一次比较后替换
// 用两个变量表示最小的两个数(设min_one<min_two)，初始化为INT_MAX，同整数中最大值。原因同理。
// 然后遍历数组，每个数先和最大的max_three比较，如果比它大，则替换，同时要更新另外两个数字，将大数顺延给小点的数字；
// 和大数比较完，再和较小的数字比较，先和min_one比较，和上面同理，如果比min_one小，则min_one-->min_two，然后min_one被赋予更小的值。
// 这个顺延相当重要，因为涉及到必要的更新，只有这样才能得到真正的最大三个数和最小的两个数。
// 另外我还在一个每次比较判断处用<还是<=或者是>还是>=思考了一下，其实带不带都可以，因为数字会顺延。
// 这种方法的时间复杂度只有O(n)，而上面的算法复杂度为O(nlogn)
//
// 写了这么多，头晕，出去透透气...
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:

//        //the wrong solution
//    int maximumProduct(vector<int>& nums) {
//        // fine the max three number and the min two number
//        int size = nums.size();
//        set<int> maxThreeNumbers;
//        set<int> minTwoNumbers;
//        for (int i = 0; i < size; i++) {
//            maxThreeNumbers.insert(nums[i]);
//            minTwoNumbers.insert(nums[i]);
//            if (maxThreeNumbers.size() > 3) {
//                maxThreeNumbers.erase(maxThreeNumbers.begin());
//            }
//            if (minTwoNumbers.size() > 2) {
//                set<int>::iterator index = minTwoNumbers.end();
//                minTwoNumbers.erase(--index);
//            }
//        }
//        int result_one = 1, result_two = 1;
//        set<int>::iterator it_max;
//        for (it_max = maxThreeNumbers.begin(); it_max != maxThreeNumbers.end(); it_max++) {
//            result_one *= (*it_max);
//        }
//        for (auto it_min = minTwoNumbers.begin(); it_min != minTwoNumbers.end(); it_min++) {
//            result_two *= (*it_min);
//        }
//        result_two *= (*(--it_max));
//        return result_one > result_two ? result_one : result_two;
//    }

    int maximumProduct(vector<int> &nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int result_one = nums[size - 1] * nums[size - 2] * nums[size - 3];
        int result_two = nums[0] * nums[1] * nums[size - 1];
        return result_one > result_two ? result_one : result_two;
    }

    int maximumProduct_optimal(vector<int> &nums) {
        int size = nums.size();
        int max_one = INT_MIN, max_two = INT_MIN, max_three = INT_MIN;
        int min_one = INT_MAX, min_two = INT_MAX;
        for (int i = 0; i < size; i++) {
            if (nums[i] > max_three) {
                max_one = max_two;
                max_two = max_three;
                max_three = nums[i];
            } else if (nums[i] > max_two) {
                max_one = max_two;
                max_two = nums[i];
            } else if (nums[i] > max_one) {
                max_one = nums[i];
            }

            if (nums[i] < min_one) {
                min_two = min_one;
                min_one = nums[i];
            } else if (nums[i] < min_two) {
                min_two = nums[i];
            }
        }
        int result_one = max_one * max_two * max_three;
        int result_two = min_one * min_two * max_three;
        return result_one > result_two ? result_one : result_two;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, -8, -9, -10};
    Solution solution;
//    int max_product = solution.maximumProduct(nums);
    int max_product = solution.maximumProduct_optimal(nums);
    cout << max_product << endl;
    return 0;
}