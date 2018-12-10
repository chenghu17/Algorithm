//
// Created by Mr.Hu on 2018/12/10.
//
// leetcode 226 invert binary tree
//
//

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (!root || !root->left && !root->right) {
            return root;
        }
        queue<TreeNode *> cur_node;
        cur_node.push(root);
        TreeNode *tmp;
        TreeNode *cur;
        while (!cur_node.empty()) {
            cur = cur_node.front();
            cur_node.pop();
            if (cur->left) {
                cur_node.push(cur->left);
            }
            if (cur->right) {
                cur_node.push(cur->right);
            }
            tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;
        }
        return root;
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
    b.right = &e;
    Solution solution;
    TreeNode *root = solution.invertTree(&a);
    // BFS
    queue<TreeNode *> cur;
    cur.push(root);
    while (!cur.empty()) {
        TreeNode *node = cur.front();
        cout << node->val << " ";
        cur.pop();
        if (node->left) {
            cur.push(node->left);
        }
        if (node->right) {
            cur.push(node->right);
        }
    }
    return 0;
}