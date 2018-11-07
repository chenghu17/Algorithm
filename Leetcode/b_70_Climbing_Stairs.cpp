//
// Created by Mr.Hu on 2018/11/7.
//
// leetcode 70 climbing stairs
//
// 题目要求对于给定的台阶数，求出所有可能的走法，要求每次只能走一个台阶或者两个台阶。
//
// 这个题目在我之前的面试中遇到过，属于动态规划的范畴。可以用递归的方式进行解决，当然也可以用递归的方式解决，
// 其递推式：f(n) = f(n-1) + f(n-2)，但是使用递归的方式会相当耗时而且占用资源。
//
// 当然我们可以用动态规划的方式，采用备忘录法来记录子问题的结果，在后面的运算中直接使用。
//
// 这个问题需要注意的是，一旦n的取值比较大时，结果会成指数级增长，所以在用备忘录法来求解问题时，我们需要考虑大数加法的情况
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs_Recursion(int n) {
        vector<int> result;
        result.push_back(0);
        result.push_back(1);
        result.push_back(2);
        if (n < 3) {
            return result[n];
        }
        return climbStairs_Recursion(n - 1) + climbStairs_Recursion(n - 2);
    }

    string addNumber(string num1, string num2) {
        int carry = 0;
        int first = 0, second = 0;
        string summary = "";
        for (int i = (int) num1.length(), j = (int) num2.length(); i > 0 || j > 0;) {
            first = i > 0 ? num1[--i] - '0' : 0;
            second = j > 0 ? num2[--j] - '0' : 0;
            summary = to_string((first + second + carry) % 10) + summary;
            carry = (first + second + carry) / 10;
        }
        return summary;
    }

    int climbStairs_DP(int n) {
        vector<string> result;
        result.emplace_back("0");
        result.emplace_back("1");
        result.emplace_back("2");
        if (n < 3) {
            return stoi(result[n]);
        }
        for (int i = 3; i <= n; i++) {
            result.push_back(addNumber(result[i - 1], result[i - 2]));
        }
        return stoi(result[n]);
    }
};

int main() {
    int n;
    cin >> n;
    Solution solution;
    cout << "summary = " << solution.climbStairs_DP(n);
//    cout << "summary = " << solution.climbStairs_Recursion(n);
    return 0;
}