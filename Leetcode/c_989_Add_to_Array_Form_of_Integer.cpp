//
// Created by Mr.Hu on 2019/2/16.
//
// leetcode 989 add to array form of integer
//
// 题目给定一个数字的数组形式，即按照数字的相对位置形成数组A，另外给定一个数字K，要求输出数组和该数字相加后的数组形式
//
// 首先这个题目不能将数组A转换为数字，然后加上给定数字K，因为A的位数最多可以达到1000位，int是无法存储的，
// 其实这里的计算方法和之前的大数加法很像，从A的最高位即该数字的个位，和K的个位对应开始判断，同时用一个数字表示进位情况。
// 每次相加后对K和A的对应位置进行更新，以及进位数字进行更新。
// 遍历完A的所有位置后，判断此时K和进位是否都为0，如果不为0说明需要继续向A的第一位增加新数字，这里就需要利用vector的insert方法。
// 具体代码如下
// 其实可以用一个新的vector来存储相加的关系，最后使用reverse方法翻转结果即可
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int> &A, int K) {
        // 类似于大数相加
        int exist = 0;
        for (int i = A.size() - 1; i >= 0; i--) {
            A[i] = A[i] + K % 10 + exist;
            K /= 10;
            exist = A[i] / 10;
            A[i] %= 10;
        }
        while (K || exist) {
            A.insert(A.begin(), (K % 10 + exist) % 10);
            exist = (K % 10 + exist) / 10;
            K /= 10;
        }
        return A;
    }
};


int main() {
    vector<int> A = {9, 9, 9, 9, 9, 9, 9, 9, 9};
    int K = 1;
    Solution solution;
    vector<int> res = solution.addToArrayForm(A, K);
    for (auto i:res) {
        cout << i << " ";
    }
    return 0;
}

