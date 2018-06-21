//
// Created by Mr.Hu on 2018/6/21.
//
// leetcode 58 length of last word
//
// 题目说明字符串由大小写字母以及空格组成，空格将每个word划分开，求最后一个word的长度
//
// 解这个题目的想法是：首先得到字符串的长度，从字符串的最后一位往前判读，当前位置会出现两种情况，如果当前位置不为空格，
// 则最后一个word的length++，如果当前位置为空格，则需要判断之前是否已经存在word，即是不是连续的空格，
// 所以判断当前result>0? 如果为true，则说明这个空格将最后一个word与前面的word分开，如果为false，则说明此时还是最后连续的多个word；
// 继续判断前一个位置的情况
// 最后返回result的累加结果即可。
//

#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.size();
        int result = 0;
        for (int i = length - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                if (result > 0) {
                    break;
                } else {
                    continue;
                }
            }
            ++result;
        }
        return result;
    }
};

int main() {
    string s = "helloworld";
    Solution solution;
    int result = solution.lengthOfLastWord(s);
    cout << result << endl;
    return 0;
}
