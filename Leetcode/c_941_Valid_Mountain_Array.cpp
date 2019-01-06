//
// Created by Mr.Hu on 2019/1/6.
//
// leetcode 941 valid mountain array
//
// 题目给定一个数组，判断是否成山形，即山顶数字最大，然后左右向两边递减。
//
// 首先得到该顶点，然后再判断右边部分。
// 注意不能存在相等的值，且只存在一个山峰（题目并没有定义清楚）
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int> &A) {
        int length = A.size();
        if (length < 3) {
            return false;
        }
        int middle = 0;
        for (int i = 1; i < length; i++) {
            if (A[i - 1] < A[i]) {
                middle = i;
            } else if (A[i - 1] == A[i]) {
                return false;
            } else {
                break;
            }
        }
        if (middle == 0 || middle == length - 1) return false;
        for (int i = middle + 1; i < length; i++) {
            if (A[i - 1] <= A[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(1);
    Solution solution;
    bool valid_mountain = solution.validMountainArray(A);
    cout << "valid mountain: " << valid_mountain << endl;
    return 0;
}