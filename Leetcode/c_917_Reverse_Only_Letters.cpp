//
// Created by Mr.Hu on 2019/1/18.
//
// leetcode 917 reverse only letters
//
// 给定一个字符串，要求只将字母翻转，其他字符位置保持不变。
//
// 定义两个变量分别保存前后匹配位置，left初始值为0，right初始值为S.length()-1。
// 如果两个位置的字符都是字母，则交换，left++，right--；
// 否则判断哪个位置不是字符，如果是left，则left++，如果是right，则right--
// 上述操作为循环体，判定条件即left>right。
//

#include <iostream>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int left = 0, right = S.length() - 1;
        while (left < right) {
            if (isalpha(S[left]) && isalpha(S[right])) {
                swap(S[left], S[right]);
                left++;
                right--;
            } else {
                if (!isalpha(S[left])) {
                    left++;
                }
                if (!isalpha(S[right])) {
                    right--;
                }
            }
        }
        return S;
    }
};

int main() {
    string S = "Test1ng-Leet=code-Q!";
    cout << "origin string : " << S << endl;
    Solution solution;
    string res = solution.reverseOnlyLetters(S);
    cout << "reverse result : " << res << endl;
    return 0;
}