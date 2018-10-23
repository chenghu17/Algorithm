//
// Created by Mr.Hu on 2018/10/23.
//
// leetcode 94 binary tree inorder traserval
//
// 对二叉树进行中序遍历的 递归方法 和 循环方法
//
// 循环方法主要借助栈数据结构，每次先将节点右子节点放入栈中，并将当前节点右指针赋为nullptr，然后将当前节点放入栈中，
// 再将当前节点左子节点放入栈中并将其左指针赋值为nullptr。以此来防止一个节点的左右节点多次访问。
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void inorder(TreeNode *root, vector<int> &result) {
        if (root != nullptr) {
            if (root->left != nullptr) inorder(root->left, result);
            result.push_back(root->val);
            if (root->right != nullptr) inorder(root->right, result);
        }
    }

    // recusive solution
    vector<int> inorderTraversal_recursive(TreeNode *root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }

    // iterative solution
    vector<int> inorderTraversal_iterative(TreeNode *root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        stack<TreeNode *> cur_nodes;
        if (root->right != nullptr) {
            cur_nodes.push(root->right);
            root->right = nullptr;
        }
        cur_nodes.push(root);
        if (root->left != nullptr) {
            cur_nodes.push(root->left);
            root->left = nullptr;
        }
        while (!cur_nodes.empty()) {
            TreeNode *cur = cur_nodes.top();
            cur_nodes.pop();
            if (cur->left == nullptr && cur->right == nullptr) {
                result.push_back(cur->val);
                continue;
            }
            if (cur->right != nullptr) {
                cur_nodes.push(cur->right);
                cur->right = nullptr;
            }
            cur_nodes.push(cur);
            if (cur->left != nullptr) {
                cur_nodes.push(cur->left);
                cur->left = nullptr;
            }
        }
        return result;
    }
};

int main() {
    TreeNode root(1);
    TreeNode a(2);
    TreeNode b(3);
    root.right = &a;
    a.left = &b;
    Solution solution;
//    vector<int> result = solution.inorderTraversal_recursive(&root);
    vector<int> result = solution.inorderTraversal_iterative(&root);
    for (auto it:result) {
        cout << it << " ";
    }
    return 0;
}