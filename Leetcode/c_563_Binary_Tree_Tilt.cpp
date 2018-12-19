//
// Created by Mr.Hu on 2018/12/19.
//
// leetcode 563 binary tree tilt
//
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 每个节点左右子树和的差值，然后进行累加

class Solution {
public:
    int tilt = 0;

    int findTilt(TreeNode *root) {
        traverse(root);
        return tilt;
    }

    int traverse(TreeNode *node) {
        if (!node) {
            return 0;
        }
        int left = traverse(node->left);
        int right = traverse(node->right);
        tilt += abs(left - right);
        return left + right + node->val;
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    a.left = &b;
    a.right = &c;
    Solution solution;
    int tilt = solution.findTilt(&a);
    cout << "the tree's tilt is " << tilt << endl;
    return 0;
}