//
// Created by Mr.Hu on 2019/1/29.
//
// leetcode 868 binary gap
//
// 题目要求对于给定的十进制数字，计算其二进制表示中，连续1之间最长距离。
//
// 这里我们可以直接将十进制转换成二进制，每次除2取余数，得到的值压入栈中，知道十进制数字变成0。
// 然后对栈进行操作，用两个变量分别表示连续的两个1的位置，然后每次计算其距离，并保存当前最大距离。
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int binaryGap(int N) {
        // 转换为2进制
        // 计算连续1之间最长的距离
        stack<int> binary_stack;
        while (N) {
            binary_stack.push(N % 2);
            N /= 2;
        }
        int first = -1, second = -1, i = 1, max_dis = 0;
        while (!binary_stack.empty()) {

            if (binary_stack.top() == 1) {
                // 判断first和second哪个更小
                if (first <= second) {
                    first = i;
                } else {
                    second = i;
                }
                // 计算距离
                if (first != -1 && second != -1) {
                    max_dis = max(max_dis, abs(second - first));
                }
            }
            binary_stack.pop();
            i++;
        }
        return max_dis;
    }
};

int main() {
    Solution solution;
    int max_dis = solution.binaryGap(8);
    cout << "binary gap = " << max_dis << endl;
    return 0;
}