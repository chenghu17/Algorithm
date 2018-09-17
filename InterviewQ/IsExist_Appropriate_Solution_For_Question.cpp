//
// Created by Mr.Hu on 2018/9/16.
//
// 腾讯2019秋招开发岗 在线编程第三题
//
// 题目描述：给定三个数字A,B,C，现在可以选择若干个数字（至少一个），这些数字要求是A的倍数，
// 判断是否存在一种选择方法使得这些数字的和对B取余的结果为C，如果存在则输出"YES"，否则输出"NO"
//
// 输入描述：第一行为整数t（1<=t<=20）,表示测试情况数，接下来t行每行三个数字分别为A,B,C，以空格分割
//
// 思路：根据题目的要求我们可以得到，如果存在这样的若干的数字，那么数字的和等于 A*n，n表示正整数，
//          所以我们现在要判断的是 （A*n）% B == C是否成立，此时就需要去遍历n，那么n的取值范围是多少呢？
//          我们可以分析得到，只需要计算到n=B即可，因为n=B+1等价于n=1，即n的取值为[1,B]
//

#include <iostream>
#include <vector>

using namespace std;

bool isExist(int A, int B, int C) {
    for (int i = 1; i <= B; ++i) {
        if (A * i % B == C) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    vector<vector<int>> data(t, vector<int>(3));
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> data[i][j];
        }
    }
    for (int i = 0; i < t-1; ++i) {
        cout << (isExist(data[i][0], data[i][1], data[i][2]) ? "YES" : "NO") << endl;
    }
    cout << (isExist(data[t-1][0], data[t-1][1], data[t-1][2]) ? "YES" : "NO");
    return 0;
}