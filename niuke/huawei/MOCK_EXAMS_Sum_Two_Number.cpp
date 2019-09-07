//
// Created by Mr.Hu on 2019/9/7.
//
// 华为软件题模拟题1：计算a+b的和
// 每行包含两个整数a和b
// 对于每行输入对应输出一行a和b的和
//
// 输入
// 1 5
// 输出
// 6
//
// 注意：题目没有给出多少组数，所以不能存在数组中，只能每次输入都计算，直到没有输入位置
//

#include <iostream>

using namespace std;

int main() {

    int a, b;
    while (cin >> a >> b) {
        cout << a + b << endl;
    }
    return 0;
}