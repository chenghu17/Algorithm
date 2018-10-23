//
// Created by Mr.Hu on 2018/10/23.
//
// leetcode 144 binary tree preorder traversal
//
// 二叉树先序遍历
//
// 递归方法 & 循环实现
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
    void preorder(TreeNode *root, vector<int> &result) {
        if (root != nullptr) {
            result.push_back(root->val);
            if (root->left != nullptr) preorder(root->left, result);
            if (root->right != nullptr) preorder(root->right, result);
        }
    }

    // recursive solution
    vector<int> preorderTraversal_recursive(TreeNode *root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }

    // iterative solution
    vector<int> preorderTraversal_iterative(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> cur_nodes;
        if(root==nullptr){
            return result;
        }
        cur_nodes.push(root);
        while(!cur_nodes.empty()){
            TreeNode* cur = cur_nodes.top();
            cur_nodes.pop();
            result.push_back(cur->val);
            if(cur->right!=nullptr) cur_nodes.push(cur->right);
            if(cur->left!=nullptr) cur_nodes.push(cur->left);
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
//    vector<int> result = solution.preorderTraversal_recursive(&root);
    vector<int> result = solution.preorderTraversal_iterative(&root);
    for (auto it:result) {
        cout << it << " ";
    }
    return 0;
}