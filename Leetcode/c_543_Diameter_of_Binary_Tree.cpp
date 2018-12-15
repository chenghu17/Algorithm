//
// Created by Mr.Hu on 2018/12/15.
//
// leetcode 543 diameter of binary tree
//
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
    int diameterOfBinaryTree(TreeNode *root) {
        int result = 0;
        if (!root) {
            return result;
        }
        queue<TreeNode *> cur_node;
        cur_node.push(root);
        TreeNode *front;
        int tmp_path;
        while (!cur_node.empty()) {
            front = cur_node.front();
            if (front->left) cur_node.push(front->left);
            if (front->right) cur_node.push(front->right);
            tmp_path = dfs_path(front->left) + dfs_path(front->right);
            result = max(result, tmp_path);
            cur_node.pop();
        }
        return result;
    }

    int dfs_path(TreeNode *node) {
        if (!node) return 0;
        if (!node->left && !node->right) return 1;
        int L = 0, R = 0;
        if (node->left) L = dfs_path(node->left) + 1;
        if (node->right) R = dfs_path(node->right) + 1;
        return max(L, R);
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    d.left = &e;
    d.right = &f;
    Solution solution;
    int diameter = solution.diameterOfBinaryTree(&a);
    cout << "diameter = " << diameter;
    return 0;
}