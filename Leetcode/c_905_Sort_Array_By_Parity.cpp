//
// Created by Mr.Hu on 2019/1/6.
//
// leetcode 905 sort array by parity
//
// 题目给定一个非负数组，要求返回一个数组，数组中的前部分全为偶数，后半部分全是奇数。
//
// 这个题目思路可以采用快速排序中的方法，两个指针，一个从头，一个从尾，找到的第一个奇数和找到的第一个偶数交换，直到两个指针遇到为止。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &A) {
        int left = 0, right = A.size() - 1;
        while (left < right) {
            if (A[left] % 2 != 0) {
                if (A[right] % 2 == 0) {
                    swap(A[left], A[right]);
                    left++;
                    right--;
                } else {
                    right--;
                }
            } else {
                left++;
            }
        }
        return A;
    }
};

int main() {
    vector<int> A;
    A.push_back(1);
    A.push_back(3);
    A.push_back(2);
    A.push_back(5);
    A.push_back(6);
    Solution solution;
    vector<int> B = solution.sortArrayByParity(A);
    for (auto i:B) {
        cout << i << " ";
    }
    return 0;
}