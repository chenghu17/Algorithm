//
// Created by Mr.Hu on 2018/4/4.
//
// leetcode 167 Two Sum two
// 题目给出升序数列，以及目标值，要求输出两个数的索引值，这两个数的和即为目标值，
// 且第一个值的索引值比第二个值的索引值小，并且要求数列中的每个数只能使用一次。且不考虑无解情况。
//
// 第一想法是蛮力，得改掉这种坏习惯。当我看到每个element can't be used twice，就知道蛮力法肯定不行
// 既然数组是有序的，而且一定有解，而且肯定是一个小点的数加大点的数字，何不从数组中最小数和最大数的匹配开始，
// 如果结果比target要大，说明大数偏大，把大数字的指针往后移动(变小的方向)，
// 反之则说明小点的数偏小，则把小数字的指针往前移动(变大的方向)。直到存在结果等于target即结束且输出。
// 这个题目在输出的时候要谨慎，因为题目给的例子index是从1开始的，如果按照常规的想法，index从0开始，那么结果中的两个数字都比实际的值小1。
//
// 在写这个方案的时候突然产生了一个疑惑，题目中要求的每个数字不能被用两次，那我现在已经accepted的方案中，一旦结果和target不相等，
// 那么一个数字移动另一个数字不移动，则不移动的数字在下一次判断的过程中有重新使用，这算不算使用多次呢？
// 如果这都算，那我只能加一个tmp变量去临时保存那个值了...但是这可能只是形式上的没有使用第二次...去找找别人的方案。
//
// 好吧，大家都是这么写的，Greedy Algorithm 解法。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> index;
        int size = numbers.size();
        int index1 = 0, index2 = size - 1;
        for (; index1 < index2;) {
            int result = numbers[index1] + numbers[index2];
            if (result == target) {
                index.push_back(index1 + 1);
                index.push_back(index2 + 1);
                break;
            }
            if (result < target) {
                index1++;
            } else {
                index2--;
            }
        }
        return index;
    }
};

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 17;
    Solution solution;
    vector<int> index = solution.twoSum(numbers, target);
    vector<int>::iterator it;
    for (it = index.begin(); it != index.end(); it++) {
        cout << *it << endl;
    }
}