//
// Created by Mr.Hu on 2018/5/23.
//
// leetcode 38 count and say
//
// 刚看这个题目，一脸懵逼...然后看了一下别人对这个题目的评价，三千多的down。内心得到了安慰。
// 观察这个题目，其实就是对给定数字进行朗读，朗读的内容包括数字的个数和数字本身，
// 连续相同的数字则统一读取：如1，则读为一个一，然后数字化后为11。
// 当前数字阅读的内容就是接下来的数字，即下一个数字为11。然后对这个数字进行读取，两个一，即
// 下一个数字为21...以此类推。
//
// 对这个问题进行抽象化就是给定一个初始值"1"，下一个数字即为当前数字的读取结果，且连续相同的数字
// 用其连续个数以及其本身来表示。
//
// 具体的实现的方法就是从n=1开始，此时say"one 1"；然后计算下一个，下一个的计算就是对数字从左到右
// 进行读取，判断连续情况，然后转换为string
//
// 在做这个题目的时候，几个地方出现来错误，第一个就是string中取某一位与数字进行比较，
// string中取一位得到的为char，需要先转换为int才能比较。需要使用int(init[j]-'0')
// 第二个地方就是对每个数循环完之后，由于循环完之后并没有对最后一段数字加当下一个数字中，所以
// 在循环结束后还要再加一次。
//
// 这个解法效率不够高...
// 活用string类是多么的重要...
//

#include<iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string init = "1";
        for (int i = 1; i < n; i++) {
            int count = 0;
            int number = 0;
            string tmp = "";
            int size = init.length();
            for (int j = 0; j < size; j++) {
                if (int(init[j] - '0') == (number)) {
                    count++;
                } else {
                    if (count != 0) {
                        tmp = tmp + to_string(count) + to_string(number);
                    }
                    number = int(init[j] - '0');
                    count = 1;
                }
            }
            tmp = tmp + to_string(count) + to_string(number);
            init = tmp;
        }
        return init;
    }
};

int main() {
    int n = 4;
    Solution solution;
    string result = solution.countAndSay(n);
    cout << result << endl;
    return 0;
}