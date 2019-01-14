//
// Created by Mr.Hu on 2019/1/14.
//
// 题目给定两个字符串，其中#表示一个回退键，即删除上一个字符，若#处于第一个位置，表示没有什么影响，要求判断两个字符串最后是否相同。
//
// 这个题目可以相当于多项式判断括号是否完整一样。
// 我们可以维护两个stack结构，分别来存储两个字符串中的字符。遍历两个字符串，如果遇到#，则删除栈顶元素，
// 遍历完两个字符串，则判断最终的两个栈中元素是否对应相同。
// 如果相同，则返回true，否则返回false。
//
// 题目要求时间复杂度为O(N)，空间复杂度为O(1)；
// 所以重新想了一个方法，即从两个字符串的尾部开始判断，且使用两个变量来保存当前位置之后已经出现过的#，
// 一旦当前位置不为#且之前已经出现#，则跳过；
// 有一点需要注意，可能当某一字符串已经遍历完后，另外一个字符串还未遍历完，是因为字符串被#全部删除了，
// 所以需要在上述判断之后，继续判断哪个字符串还未遍历完，如果没有遍历完，且存在某一位置不为#，其后又没有#累计，则return false；
// 最后return true；
// 注：两个名字相近的变量，很容易写重复😢
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:

    void get_final_stack(string S, stack<int> &s_stack) {
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '#') {
                if (!s_stack.empty()) {
                    s_stack.pop();
                }
            } else {
                s_stack.push(S[i]);
            }
        }
    }

    bool backspaceCompare(string S, string T) {
        stack<int> s_stack, t_stack;

        get_final_stack(S, s_stack);
        get_final_stack(T, t_stack);

        while (!t_stack.empty() && !s_stack.empty()) {
            if (s_stack.top() == t_stack.top()) {
                s_stack.pop();
                t_stack.pop();
            } else {
                return false;
            }
        }
        return t_stack.empty() && s_stack.empty();
    }

    bool backspaceCompare_option(string S, string T) {
        int s_length = S.length() - 1;
        int t_length = T.length() - 1;
        int s_sharpe = 0, t_sharpe = 0;
        while (s_length >= 0 && t_length >= 0) {
            if (S[s_length] != '#' && T[t_length] != '#' && !s_sharpe && !t_sharpe) {
                if (S[s_length] == T[t_length]) {
                    s_length--;
                    t_length--;
                    continue;
                } else {
                    return false;
                }
            }

            if (S[s_length] == '#') {
                s_sharpe++;
                s_length--;
            } else if (S[s_length] != '#' && s_sharpe) {
                s_sharpe--;
                s_length--;
            }

            if (T[t_length] == '#') {
                t_sharpe++;
                t_length--;
            } else if (T[t_length] != '#' && t_sharpe) {
                t_sharpe--;
                t_length--;
            }
        }

        while (s_length >= 0) {
            if (S[s_length] != '#' && !s_sharpe) {
                return false;
            } else if (S[s_length] == '#') {
                s_length--;
                s_sharpe++;
            } else {
                s_length--;
                s_sharpe--;
            }
        }
        while (t_length >= 0) {
            if (T[t_length] != '#' && !t_sharpe) {
                return false;
            } else if (T[t_length] == '#') {
                t_length--;
                t_sharpe++;
            } else {
                t_length--;
                t_sharpe--;
            }
        }
        return true;
    }
};

int main() {
    string S = "ab#cd", T = "ac#cd";
    Solution solution;
//    bool is_same = solution.backspaceCompare(S, T);
    bool is_same = solution.backspaceCompare_option(S, T);
    cout << is_same << endl;
    return 0;
}