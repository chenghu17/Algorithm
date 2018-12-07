//
// Created by Mr.Hu on 2018/12/7.
//
// leetcode 230 kth smallest element in a BST
//
// 题目要求在
//
//
//

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> cur_stack;
        cur_stack.push(root);
        while (!cur_stack.empty()) {
            TreeNode *top = cur_stack.top();
            if (top->left != nullptr) {
                cur_stack.push(top->left);
                top->left = nullptr;
            } else if (k == 1) {
                return top->val;
            } else if (top->right != nullptr) {
                k--;
                cur_stack.pop();
                cur_stack.push(top->right);
                // top->right = nullptr;
            } else {
                cur_stack.pop();
                k--;
            }
        }
    }
};

int main() {
    TreeNode a(3);
    TreeNode b(1);
    TreeNode c(4);
    TreeNode d(2);
    a.left = &b;
    a.right = &c;
    b.right = &d;
    Solution solution;
    int kth = solution.kthSmallest(&a, 3);
    cout << kth << endl;
    return 0;
}