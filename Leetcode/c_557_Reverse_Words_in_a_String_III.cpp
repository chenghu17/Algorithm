//
// Created by Mr.Hu on 2019/1/15.
//
// leetcode 557 reverse words in a string
//
// 题目要求对一个字符串进行翻转，要求不改变空格的位置，对字符串中的每个word进行翻转
//
// 刚开始想的是之前见到过的一个题型，即先整体翻转，然后再对位替换，发现无法实现题目所求。
// 所以想到two pointers的方法，即定义两个变量，分别表示当前word的起始，然后进行reverse；
// 这里我使用了这种方式，先复制一个字符串，然后用left和right分别表示字符串中某个word的起始位置，
// 然后从s的right复制给tmp的left，直到left增加到当前位置i；需要注意的就是最后一个word需要单独执行，因为最后没有空格作为判定结束条件。
//
// 其实这里存在一些重复操作，即对于每个word的reverse，我们可以直接在字符串s本身上进行操作，而且只需要执行word.length()/2次操作即可。
// 无需复制s然后进行重新赋值，累赘。
//

#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res = s;
        int left = 0, right = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i == s.length() - 1) {
                right = i;
                while (left <= i) {
                    res[left] = s[right];
                    right--;
                    left++;
                }
            }
            if (s[i] == ' ') {
                right = i - 1;
                while (left < i) {
                    res[left] = s[right];
                    right--;
                    left++;
                }
                left++;
            }

        }
        return res;
    }
};

int main() {
    string s = "let's do it";
    Solution solution;
    string reverse_s = solution.reverseWords(s);
    cout << reverse_s << endl;
    return 0;
}