//
// Created by Mr.Hu on 2018/6/22.
//
// leetcode 459 repeated substring pattern
//
// 题目要求对给定的字符串s，判断其是否存在子串模式，使得模型重复拼接可以得到该字符串s
//
// 看到这个题目，首先想到的是，如果存在这样的子串模式，则至少需要重复2此，最多重复s.size()次（即字符串为同一个字母组成）
// 所以目前有两种方法：第一种从2增加到s.size()；第二种从s.size()减小到2。
// 我选择了第一种，因为从2增加到s.size()，比较次数是从小到大，比较次数的期望小。
//
// 假设pattern重复i次可以得到字符串s，那么必有s.size()%i==0成立，而此时的pattern_size = s.size()/i；
// 有了重复次数和pattern_size，我们就可以得到循环提取子串，从第0个位置，第pattern_size*1个位置，
// 第pattern_size*2个位置...每次提取长度即为pattern_size，比较当前子串与第一个模式子串是否相同，相同则
// 将定义好的标示bool变量赋值为true，直到所有子串比较完，则判断bool变量的值，若为true，则return true；
// 如果在子串比较中存在不相等情况，则将bool变量赋值为false，并结束当前循环，继续下一种长度的模式字串判断...
//
// 如果所有长度的模式子串循环完，都没有return true，则在循环结束后return false。
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int length = s.size();
        int pattern_size;
        string pattern, next_pattern;
        bool isPattern = false;
        for (int i = 2; i <= length; ++i) {
            if (length % i == 0) {
                pattern_size = length / i;
            } else {
                continue;
            }
            pattern = s.substr(0, pattern_size);
            for (int j = 1; j < i; ++j) {
                next_pattern = s.substr(j * pattern_size, pattern_size);
                if (pattern == next_pattern) {
                    isPattern = true;
                } else {
                    isPattern = false;
                    break;
                }
            }
            if (isPattern) {
                return true;
            }
        }
        return false;
    }
};

int main(){
    string s = "abc";
    Solution solution;
    bool result = solution.repeatedSubstringPattern(s);
    cout<<result<<endl;
    return 0;
}