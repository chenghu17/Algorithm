//
// Created by Mr.Hu on 2018/12/8.
//
// leetcode 104 maximum depth of binary tree
//
// 题目要求求出给定二叉的树的深度，即二叉树所有路径中最长的路径。
//
// 可以使用DFS的思想，每次计算一条路径的长度，判断当前路径长度与当前最长路径的大小，取最大值保存在为最长路径，
// 直到最终遍历完所有路径，循环结束，输出此时最长路径即为二叉树深度
//
// DFS的思想需要记住stack来存储之前的节点
//

#include <iostream>
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
    int maxDepth(TreeNode *root) {
        int max_depth = 0;
        int tmp_depth;
        stack<TreeNode *> cur_node;
        if (root != nullptr) {
            cur_node.push(root);
            tmp_depth = 1;
        } else {
            return max_depth;
        }
        while (!cur_node.empty()) {
            TreeNode *top = cur_node.top();
            if (top->left != nullptr) {
                tmp_depth += 1;
                cur_node.push(top->left);
                top->left = nullptr;
            } else if (top->right != nullptr) {
                tmp_depth += 1;
                cur_node.push(top->right);
                top->right = nullptr;
            } else {
                max_depth = max(max_depth, tmp_depth);
                tmp_depth -= 1;
                cur_node.pop();
            }
        }
        return max_depth;
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
    b.right = &d;
    c.left = &e;
    e.left = &f;
    Solution solution;
    int max_depth = solution.maxDepth(&a);
    cout << "max depth = " << max_depth;
    return 0;
}