//
// Created by Mr.Hu on 2018/8/15.
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

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        struct TreeNode *node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = nullptr;
        node->right = nullptr;
//        TreeNode node(val);
        if (root == nullptr) {
//            return &node;
            return node;
        }
        TreeNode *result = root;
        while (root != nullptr) {
            if (val > root->val) {
                if (root->right == nullptr) {
//                    root->right = node;
                    root->right = node;
                    break;
                }
                root = root->right;
            } else {
                if (root->left == nullptr) {
//                    root->left = node;
                    root->left = node;
                    break;
                }
                root = root->left;
            }
        }
        return result;
    }
};

int main() {
    TreeNode node1(4);
    TreeNode node2(2);
    TreeNode node3(7);
    TreeNode node4(1);
    TreeNode node5(3);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    Solution solution;
    int val = 5;
    TreeNode *root = solution.insertIntoBST(&node1, val);
}