//
// Created by Mr.Hu on 2018/10/24.
//
// leetcode 145 binary tree postorder traversal
//
// 二叉树后序遍历 递归方法 和 循环实现
//
// 循环实现中有一部分比中序遍历简洁，和前序遍历差不多，即第一个节点压入栈中，
// 无需其他操作，直接进入循环中判断栈顶元素其右儿子是否存在，左儿子是否存在
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
    void postorder(TreeNode *root, vector<int> &result) {
        if (root->left != nullptr) postorder(root->left, result);
        if (root->right != nullptr) postorder(root->right, result);
        result.push_back(root->val);
    }

    // recursive solution
    vector<int> postorderTraversal_recursive(TreeNode *root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        postorder(root, result);
        return result;
    }

    // iterative solution
    vector<int> postorderTraversal_iterative(TreeNode *root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        stack<TreeNode *> cur_nodes;
        cur_nodes.push(root);
        while (!cur_nodes.empty()) {
            TreeNode *cur = cur_nodes.top();
            if (cur->left == nullptr && cur->right == nullptr) {
                result.push_back(cur->val);
                cur_nodes.pop();
            } else {
                if (cur->right != nullptr) {
                    cur_nodes.push(cur->right);
                    cur->right = nullptr;
                }
                if (cur->left != nullptr) {
                    cur_nodes.push(cur->left);
                    cur->left = nullptr;
                }
            }
        }
        return result;
    }
};

int main() {
    TreeNode root(1);
    TreeNode left(2);
    TreeNode right(3);
    root.left = &left;
    root.right = &right;
    Solution solution;
//    vector<int> result = solution.postorderTraversal_recursive(&root);
    vector<int> result = solution.postorderTraversal_iterative(&root);
    for (auto it:result) {
        cout << it << " ";
    }
    return 0;
}