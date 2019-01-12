//
// Created by Mr.Hu on 2019/1/12.
//
// leetcode 728 self dividing numbers
//
// 题目给定闭区间的左右边界，要求判断区间内的数哪些能被其自身所包含的所有数字整除，注如果该数中包含0，则肯定不满足条件。
//
// 定义一个判断数是否满足条件的方法，取数字的每一位，如果所有位均不等于1，且能够整除原来的数字，则原数满足条件。
// 具体取每一位数，第一种方法是转换为string的方法，这会增加内存，且每次取一位比较耗时；
// 第二种方法，利用每次取最后一位，满足条件则把当前数字更新为n/=10，这种方法的执行效率更少。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    bool isSelf(int number) {
        string num = to_string(number);
        for (int i = 0; i < num.length(); i++) {
            if (num[i] == 48 || number % (num[i] - 48) != 0) {
                return false;
            }
        }
        return true;
    }

    bool isSelf_optimal(int number) {
        int n = number;
        while (n) {
            int tmp = n % 10;
            if (tmp == 0 || number % tmp != 0) {
                return false;
            }
            n /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for (int i = left; i <= right; i++) {
//            if (isSelf(i)) {
            if (isSelf_optimal(i)) {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main() {
    int left = 1, right = 22;
    Solution solution;
    vector<int> result = solution.selfDividingNumbers(left, right);
    for (auto i:result) {
        cout << i << " ";
    }
    return 0;
}