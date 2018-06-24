//
// Created by Mr.Hu on 2018/6/24.
//
// leetcode 744 find smallest letter greater than target
//
// 题目要求从给定的字符列表（已排序）中，搜素第一个比target字符大的字符并输出，如果不存在，则返回letters中的第一个，此处可以当成一个环。
//
// 这个题目做的很晕，但是理解了binary_search中的一些特点，二分搜索从第0为到第length-1位，
// 如果存在相等情况，则有两种情况：1、相等的位置是否为最后一位；2、下一位是否也相等，即该字符重复出现。
// 如果不存在相等情况，则while循环会在left==right的情况时终止，此时也存在三种情况：1、left(right)在第0处；
// 2、left(right)在第length-1处；3、left(right)在中间位置；
// 1、在第0处，需要判断0出的char与target的大小，如果<=target,则返回letters[1]，否则返回letters[0]；
// 2、在length-1处，如果>target，则返回letters[length-1]，否则返回letters[0]；
// 3、在中间位置，如果>target，则返回letters[left]，否则返回letters[left+1];
//
// 以上方法超过了百分之九十九的accepted solution
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        int length = letters.size();
        int left = 0;
        int right = length - 1;
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (letters[mid] == target) {
                if (mid == length - 1) {
                    return letters[0];
                }
                if (letters[mid + 1] != target) {
                    return letters[mid + 1];
                } else {
                    left = mid + 1;
                }
            }
            if (letters[mid] > target) {
                right = mid - 1;
            } else if (letters[mid] < target) {
                left = mid + 1;
            }
        }
        if (left == length - 1) {
            if (letters[left] > target) {
                return letters[left];
            }
            return letters[0];
        }
        if (left == 0) {
            if (letters[left] <= target) {
                return letters[1];
            }
            return letters[0];
        }
        if (letters[left] > target) {
            return letters[left];
        }
        return letters[left + 1];
    }
};

int main() {
    vector<char> letters;
    letters.push_back('a');
    letters.push_back('a');
    letters.push_back('a');
    letters.push_back('d');
    letters.push_back('e');
    letters.push_back('f');
    letters.push_back('f');
    letters.push_back('f');
    letters.push_back('q');
    Solution solution;
    char nextGreatestChar = solution.nextGreatestLetter(letters, 'f');
    cout << nextGreatestChar << endl;
    return 0;
}