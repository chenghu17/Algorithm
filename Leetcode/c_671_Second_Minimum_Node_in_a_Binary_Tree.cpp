//
// Created by Mr.Hu on 2019/1/3.
//
// leetcode 671 second minimum node in a binary tree
//
//
//
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
    int root_val, result;

    int findSecondMinimumValue(TreeNode *root) {
        root_val = root->val;
        result = INT_MAX;
        dfs(root);
        return result != INT_MAX ? result : -1;
    }

    void dfs(TreeNode *node) {
        if (node->val < result && node->val != root_val) {
            result = node->val;
        }
        if (node->left) dfs(node->left);
        if (node->right) dfs(node->right);
    }
};

int main() {
    TreeNode a(2);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(5);
    TreeNode e(7);
    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;
    Solution solution;
    int second_minimum = solution.findSecondMinimumValue(&a);
    cout << second_minimum;
    return 0;
}