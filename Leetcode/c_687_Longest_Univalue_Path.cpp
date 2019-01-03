//
// Created by Mr.Hu on 2019/1/3.
//
// leetcode 687 longest univalue path
//
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

    int max_path = 0;

    int longestUnivaluePath(TreeNode *root) {
        if (!root) {
            return max_path;
        }
        getPath(root, root->val);
        return max_path;
    }

    int getPath(TreeNode *node, int target) {
        if (node->val != target) {
            getPath(node, node->val);
            return 0;
        }
        if (!node->left && !node->right) {
            return 1;
        }

        int left_length = 0, right_length = 0;
        if (node->left) left_length = getPath(node->left, target) + 1;
        if (node->right) right_length = getPath(node->right, target) + 1;

        if (left_length != 0 && right_length != 0) {
            max_path = max(max_path, left_length + right_length - 2);
        } else if (left_length != 0 || right_length != 0) {
            max_path = max(max_path, left_length + right_length - 1);
        }

        return max(left_length, right_length);
    }
};

int main() {
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(5);
    TreeNode d(1);
    TreeNode e(1);
    TreeNode f(5);
    TreeNode g(5);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;

    Solution solution;
    int longest_path = solution.longestUnivaluePath(&a);
    cout << longest_path << endl;
    return 0;
}