//
// Created by Mr.Hu on 2018/12/29.
//
// leetcode 606 construct string from binary tree
//
// 题目要求根据规则，将二叉树转换为字符串。中间使用括号进行区分
//
// 这个题目是在深度优先搜索的基础上增加了一些条件，即使用括号来分割各个子树。
// 以下使用递归的方式进行coding
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    string tree2str(TreeNode *t) {
        string s = "";
        if (!t) {
            return s;
        }
        return treeTostr(t, s);
    }

    string treeTostr(TreeNode *t, string s) {

        s = s + to_string(t->val);

        if (!t->left && !t->right) {
            return s;
        }

        if (t->left && t->right) {
            s = s + "(";
            s = treeTostr(t->left, s);
            s = s + ")";
            s = s + "(";
            s = treeTostr(t->right, s);
            s = s + ")";
        }

        if (t->left && !t->right) {
            s = s + "(";
            s = treeTostr(t->left, s);
            s = s + ")";
        }

        if (!t->left && t->right) {
            s = s + "()";
            s = s + "(";
            s = treeTostr(t->right, s);
            s = s + ")";
        }

        return s;
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    d.left = &e;
    Solution solution;
    string s = solution.tree2str(&a);
    cout << s << endl;
    return 0;
}