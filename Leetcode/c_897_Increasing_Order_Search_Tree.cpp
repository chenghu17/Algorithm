//
// Created by Mr.Hu on 2019/1/3.
//
// leetcode 897 increasing order search tree
//

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *increasingBST(TreeNode *root) {
        queue<TreeNode *> nodes;
        middle_order(root, nodes);
        TreeNode *rsl = nodes.front();
        TreeNode *tmp = nodes.front();
        tmp->left = nullptr;
        tmp->right = nullptr;
        TreeNode *next;
        nodes.pop();
        while (!nodes.empty()) {
            next = nodes.front();
            next->left = nullptr;
            next->right = nullptr;
            nodes.pop();
            tmp->right = next;
            tmp = next;
        }
        return rsl;
    }

    void middle_order(TreeNode *node, queue<TreeNode *> &nodes) {
        if (!node) {
            return;
        }
        if (node->left) middle_order(node->left, nodes);
        nodes.push(node);
        if (node->right) middle_order(node->right, nodes);
    }
};

int main() {
    TreeNode a(5);
    TreeNode b(2);
    TreeNode c(6);
    a.left = &b;
    a.right = &c;
    Solution solution;
    TreeNode *new_root = solution.increasingBST(&a);
    while (new_root) {
        cout << new_root->val << " ";
        new_root = new_root->right;
    }
    return 0;
}