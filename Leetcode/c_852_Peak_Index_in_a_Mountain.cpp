//
// Created by Mr.Hu on 2018/6/25.
//
// leetcode 852 peak index in a mountain
//
// 题目要求从类似于山的数组中找出山顶的index值，当前数组满足山的属性，只存在一个山峰
//
// 这个题目比较简单，使用最简单的遍历方法也可以求解，直接判断第一次出现A[i] > A[i + 1]的i即为所求index；
//
// 当然这个题目也可以使用binary search的方法来做
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int> &A) {
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] > A[i + 1]) {
                return i;
            }
        }
    }
};

int main() {
    vector<int> A;
    A.push_back(0);
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);
    A.push_back(6);
    A.push_back(3);
    A.push_back(2);
    A.push_back(1);
    A.push_back(1);
    A.push_back(0);
    Solution solution;
    int index = solution.peakIndexInMountainArray(A);
    cout << index << endl;
    return 0;
}