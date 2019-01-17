//
// Created by Mr.Hu on 2019/1/17.
//
// leetcode 859 buddy strings
//
// 题目要求判断两个字符串是否为buddy string，即是否能够通过对字符串A交换两个字符串得到字符串B
//
// 这个题目思路其实不难，但是要仔细分析会出现的情况，特别是给定的case，我就是疏忽了题目给的case，错了好几次...心酸
//
// 对于"ab"和"ab"，结果为false，而对于"aa"和"aa"，结果为true；所以我们不能笼统的判断是否相等就给定最后的结果；
// 这里我们用两个int变量来表示可能存在的两个字符所在的位置，给予初始化-1；
// 在遍历字符串时，第一个不相同的位置赋值为dif1，第二个不相同的位置赋值给dif2，一旦出现第三个，则返回false；
// 用set<char>来统计其中一个字符串中每个字符出现的情况，一旦出现次数超过两次，则不需要继续记录，用一个bool变量has_duplication来记录，
// 这个变量在两个字符串相等时用，如果has_duplication为true，则可以交换两个字符得到另外一个；否则不可以。
// 如果两个字符串不想等，则判断两个int变量是否都不等于-1，存在等于-1的情况，则return -1；
// 如果两个int都不等于-1。则交叉判断两个字符dif1和dif2是否相同，存在不相同，则return false；
// 最后return true；
//

#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        set<char> alphabet;
        bool has_duplication = false;
        int dif1 = -1, dif2 = -1;
        for (int i = 0; i < A.length(); i++) {
            if (!has_duplication && alphabet.count(A[i])) {
                has_duplication = true;
            } else {
                alphabet.insert(A[i]);
            }
            if (A[i] != B[i]) {
                if (dif1 == -1) {
                    dif1 = i;
                } else if (dif2 == -1) {
                    dif2 = i;
                } else {
                    return false;
                }
            }
        }

        if (A == B) {
            return has_duplication;
        }

        if (dif1 == -1 || dif2 == -1) {
            return false;
        }
        return A[dif1] == B[dif2] && A[dif2] == B[dif1];
    }
};

int main() {
    string A1 = "ab", B1 = "ba", A2 = "aa", B2 = "aa", A3 = "ab", B3 = "ab";
    Solution solution;
    bool res1 = solution.buddyStrings(A1, B1);
    bool res2 = solution.buddyStrings(A2, B2);
    bool res3 = solution.buddyStrings(A3, B3);
    cout << "res1:" << res1 << endl;
    cout << "res2:" << res2 << endl;
    cout << "res3:" << res3 << endl;
    return 0;
}