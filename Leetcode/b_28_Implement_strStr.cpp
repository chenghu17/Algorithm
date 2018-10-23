//
// Created by Mr.Hu on 2018/10/22.
//
// leetcode 28 implement strStr()
//
// 题目要求实现strStr()方法，即判断字符串a是否为字符串b的子串，如果是则返回第一次出现a的头索引值，如果不是，则返回-1，
// 注：如果字符串a为空串，则返回0。这在面试时相当重要，提前考虑这种情况。
//
// 方法1，直接使用string::find()方法，返回的值为string::size_type类型，如果存在，则返回头索引，如果不存在，则返回string::npos
// 方法2：循环判断是否存在b的子串与字符串a相同，有则返回该字符串在b中的头索引值，不存在则返回-1，
// 获取字符串b中的子串使用sunstr(index,length)的方法。具体实现如下。
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public :
    int strStr(const string haystack, const string needle) {
        string::size_type position = haystack.find(needle);
        if (position == string::npos) {
            return -1;
        }
        return position;
    };

    int strStr_optional(const string haystack, const string needle) {
        int h_size = (int) haystack.size();
        int n_size = (int) needle.size();
        if (h_size < n_size) {
            return -1;
        }
        if (n_size == 0) {
            return 0;
        }
        for (int i = 0; i <= h_size - n_size; ++i) {
            if (haystack.substr(i, n_size) == needle) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
//    cout<<solution.strStr("abcde","bc")<<endl;
    cout << solution.strStr_optional("abcde", "bc") << endl;
}