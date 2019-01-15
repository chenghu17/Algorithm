//
// Created by Mr.Hu on 2019/1/15.
//
// leetcode 520 detect capital
//
// 题目要求检测字符串中的大写字母，只有满足下面三种情况的一种，字符串才合规：
// 1、字符串全是大写；2、除开头是大写字母，其他都是小写；3、字符串全是小写。
//
// 根据三个要求可以发现，对于一个字符串是否合规，最主要的是看第一个字符和第二个字符给该字符串定义三种情况的哪一种；
// 所以我们设定两个变量来表示第一个字符和第二个字符的大小写情况，然后判断其他字符的两种情况：当前字符为小写，当前字符为大写。
// 刚开始没有考虑当前字符为小写的情况，没有思考完整，导致case "FFFFFf"判断错误。
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        // ascii
        // capital (65-90), letter(97-122)
        if (word.length() == 1) {
            return true;
        }
        int first_capital = false, second_capital = false;
        for (int i = 0; i < word.length(); i++) {
            if (i == 0 && word[i] >= 65 && word[i] <= 90) {
                first_capital = true;
            } else if (i == 1 && word[i] >= 65 && word[i] <= 90) {
                if (first_capital) {
                    second_capital = true;
                } else {
                    return false;
                }
            } else if (word[i] >= 65 && word[i] <= 90) {
                // 全是大写，当前字符也是大写
                if (first_capital && second_capital) {
                    continue;
                } else {
                    return false;
                }
            } else {
                // 当前字符是小写，但目标字符串前面都是大写
                if (first_capital && second_capital) {
                    return false;
                } else {
                    continue;
                }
            }
        }
        return true;
    }
};

int main() {
    string test1 = "FFFFFf";
    string test2 = "leetcode";
    string test3 = "CHINA";
    string test4 = "falsE";
    Solution solution;
    bool result1 = solution.detectCapitalUse(test1);
    bool result2 = solution.detectCapitalUse(test2);
    bool result3 = solution.detectCapitalUse(test3);
    bool result4 = solution.detectCapitalUse(test4);
    cout << "result1 " << result1 << endl;
    cout << "result2 " << result2 << endl;
    cout << "result3 " << result3 << endl;
    cout << "result4 " << result4 << endl;
    return 0;
}