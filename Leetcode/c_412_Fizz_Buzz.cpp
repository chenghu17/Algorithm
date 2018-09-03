//
// Created by Mr.Hu on 2018/9/3.
//
// leetcode 412 fizz buzz
//
// 题目定义，给定数组，输出满足要求的字符串数组：被3整除的位置用"Fizz"表示，被5整除的位置用"Buzz"表示，
// 被3和5共同整除的位置用"FizzBuzz表示"，其他位置用数组的字符串形式表示。
//
// 这个题目随机pick，用于练手
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) {
                result.push_back("FizzBuzz");
                continue;
            }
            if (i % 3 == 0) {
                result.push_back("Fizz");
                continue;
            }
            if (i % 5 == 0) {
                result.push_back("Buzz");
                continue;
            }
            result.push_back(to_string(i));
        }
        return result;
    }
};

int main() {
    int n = 10;
    Solution solution;
    vector<string> result = solution.fizzBuzz(n);
    for (auto it = result.begin(); it != result.end(); ++it) {
        cout << *it << " ";
    }
    return 0;
}