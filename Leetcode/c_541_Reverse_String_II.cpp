//
// Created by Mr.Hu on 2018/6/23.
//
// leetcode 541 reverse string II
//
// 题目要求对于给定的字符串s，将字符串中每2k个字符中前k的翻转，剩下的k个不翻转，如果字符串长度小于2k，大于k，
// 则将前k个翻转，剩下的不翻转；如果字符串长度小于等于k，则将字符串全部翻转。
//
// 题目的解法就是依次取2k长度的字串，如果不足2k就将剩下的子串全部提取，然后每次将子串的前k个翻转，剩下k个继续保留；
// 依次将翻转后的结果连接，最后的结果字符串就是满足要求翻转的结果。
//
// 觉得自己的这种写法比较复杂，就去看了discuss中别人的解答：
// 原来对string是可以使用自带的reverse的，看了reverse的源码，是每次将前后两个数字进行swap，
// 确实比我一个一个去累加快的多，reverse里面需要传递string的首尾地址信息，这里是我之前这么做出错的地方，
// 而且reverse是在原字符串上进行翻转，都不需要额外的空间进行存储。
// 所以以后需要注意：1、可以使用reverse进行翻转的地方就用reverse
//                 2、如果不能使用reverse进行翻转，可以使用对应位置swap的方式，而不是从后往前一个一个读取来达到目标
//

#include <iostream>
using namespace std;

class Solution {
public:
    string reverse_module(string s, int k) {
        string result;
        int m = s.size();
        if (m <= k) {
            for (int i = m - 1; i >= 0; --i) {
                result += s[i];
            }
        } else {
            for (int i = k - 1; i >= 0; --i) {
                result += s[i];
            }
            result += s.substr(k, m - k + 1);
        }
        return result;
    }

    string reverseStr(string s, int k) {
        int length = s.size();
        int count = 0;
        string result;
        while (length > 0) {
            if (length / 2 * k > 0) {
                result += reverse_module(s.substr(count * 2 * k, 2 * k), k);
                length -= 2 * k;
                ++count;
            } else if (length / k > 0) {
                result += reverse_module(s.substr(count * 2 * k, length), k);
                length = 0;
            } else {
                result += reverse_module(s.substr(count * 2 * k, length), k);
                length = 0;
            }
        }
        return result;
    }

    string reverseStr_optimal(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            reverse(&s[i], &s[min(int(s.size()), i + k)]);
        }
        return s;
    }
};

int main() {
    string s = "abcdefghijk";
    Solution solution;
//    string result = solution.reverseStr(s,2);
    string result = solution.reverseStr_optimal(s, 2);
    cout << result << endl;
    return 0;
}