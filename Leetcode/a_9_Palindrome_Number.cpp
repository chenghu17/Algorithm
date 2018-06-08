//
// Created by Mr.Hu on 28/03/2018.
//
// leetcode 9 Palindrome Number (回文数)
// determine whether an integer is a palindrome, without extra space;
// Note negative integers are not palindromes
// 解这道回文数判断时，首先要明确负数不属于回文数
// 第一个解题思路是code中的第一种解法，使用vector来存储判定值，然后用最简单的比较方法进行判断，
// 当然这样做的话，算法的空间复杂度就达到来O(n)，不符合题目without extra space的要求，
// 在思考的过程中，题目有提示之前做过的reverse integer，翻转数字，int型翻转后，可能会overflow。
//
// 第二个解题思路是查了别人的思路之后再写的，主要是对without extra space的这个要求的理解不到位
// 第二个方法借助临时变量，考虑到回文数折中后左边剩下的部分，和右边翻转得到的数字相等则为palindrome，
// 并且这样折中后再翻转就不存在overflow的情况了，这是关键！
//
// 注：leetcode上的without extra space实际上的意思空间复杂度为O(1)；
// explanation from stackoverflow: “without extra space” usually means with O(1) space.
//                                  so if you use a temp variable you’e still using O(1) space and it is fine."
//
// 2018.6.8
// 做409题时，判断最长回文串，于是就想到之前似乎做了一道这样的题目，觉得可以用string来进行解决：
// 将int x用to_string()进行转换，然后再对字符串进行操作，首位依次比较，如果出现不相同，则说明不是回文数
// 如果循环结束都没有出现不相同，则说明是回文串。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> line;
        if (x < 0)
            return false;
        while (x != 0) {
            int tmp = x % 10;
            line.push_back(tmp);
            x /= 10;
        }
        int size = line.size() - 1;
        int tag = size / 2;
        for (int i = 0; i < tag; i++) {
            if (line[i] == line[size - i])
                continue;
            else
                return false;
        }
        return true;
    }

    bool isPalindrome_criterion(int x) {
        if (x < 0)
            return false;
        //without extra space
        int xx = x;
        int length = 0;
        while (x != 0) {
            x /= 10;
            length++;
        }
        int index = 0;
        int sum = 0;
        while (index < length / 2) {
            sum = sum * 10 + xx % 10;
            xx /= 10;
            index++;
        }
        if (length % 2 == 0 && xx == sum)
            return true;
        if (length % 2 == 1 && xx / 10 == sum)
            return true;
        return false;
    }

    bool isPalindrome_optional(int x) {
        if (x < 0) {
            return false;
        }
        string s = to_string(x);
        int size = s.length();
        for (int i = 0; i < size / 2; i++) {
            if (s[i] != s[size - i - 1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int number = 0;
    Solution solution;
    bool result = solution.isPalindrome(number);
    bool result_criterion = solution.isPalindrome_criterion(number);
    cout << result << endl;
    cout << result_criterion << endl;
    return 0;

}
