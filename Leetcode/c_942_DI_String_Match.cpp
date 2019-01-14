//
// Created by Mr.Hu on 2019/1/14.
//
// leetcode 942 DI string match
//
// 题目给定一个只包含"D"和"I"的字符串，其中I表示A[i]<A[i+1]，D表示A[i]>A[i+1]，求根据字符串S得到的数组
//
// 通过例子我们可以观察对，对于length长度的字符串S，其对应的数组长度为length+1，
// 可以先初始化一个长度为length+1的数组，然后定义两个变量，一个表示数组的最小值，初始值为0，
// 另一个表示数组的最大值，初始值为length。遍历字符串，当遇到I时，则拿当前最小值，最小值++，
// 当遇到D时，拿当前最大值，最大值--，循环结束后，此时数组最后的一个数还未更新，而此时的begin和end是相等的，只存在这样一个值，
// 于是数组的值可以等于end或者begin即可。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string S) {
        int length = S.length();
        vector<int> result(length + 1);
        int begin = 0, end = length;
        for (int i = 0; i < length; i++) {
            if (S[i] == 'I') {
                result[i] = begin;
                begin++;
            } else {
                result[i] = end;
                end--;
            }
        }
        result[length] = begin;
        return result;
    }
};

int main() {
    string S = "DIIDD";
    Solution solution;
    vector<int> result = solution.diStringMatch(S);
    for (auto i : result) {
        cout << i << " ";
    }
    return 0;
}