//
// Created by Mr.Hu on 2019/1/14.
//
// leetcode 926 long pressed name
//
// 题目给定一个场景：在键盘上敲某个人的名字时，可能会有一些字符重复输入，要求判断键盘输入的字符去掉重复后是否和实际的名字相同。
//
// 具体思路：给定name和typed，name相当于一个模板，而计算重复输入，即typed当前位置与name当前位置不同，
// 那么一定有typed当前位置与name前一个位置相同，这才是正常的重复输出，如果两种情况都不满足，则说明是输入错误。
// 有了上述方法，我们定义一个idx表示当前name字符位置，对typed进行循环，首先判断对应位置是否相同，相同则继续，且idx++；
// 不相同则判断是否与name的上一位置相同，相同则继续；否则return false；
// 循环结束后，判断idx的值是否与name的长度一致，一致则为true；为了防止name="alex"，typed="aall"情况
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (!name.length() && !typed.length()) {
            return true;
        } else if (!name.length() || !typed.length()) {
            return false;
        }
        int idx = 0;
        for (int i = 0; i < typed.length(); i++) {
            if (typed[i] == name[idx]) {
                idx++;
            } else if (idx != 0 && typed[i] == name[idx - 1]) {
                continue;
            } else {
                return false;
            }
        }
        return idx == name.length();
    }
};

int main() {
    string name = "alex", typed = "aallexx";
    Solution solution;
    bool is_pressed = solution.isLongPressedName(name, typed);
    cout << is_pressed << endl;
    return 0;
}