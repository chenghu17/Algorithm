//
// Created by Mr.Hu on 2019/1/3.
//
// leetcode 897 increasing order search tree
//
// 题目要求对给定的BST（二叉搜索树）重新排列，得到一棵新的树，新树所有节点都没有左节点，且按照递增顺序依次向下。
//
// 这个题目其实就是需要将BST进行中序遍历，然后对遍历的节点从前向后连接起来。
// 注意：如果使用原始节点，需要将原来的节点左右子节点赋值为nullptr，不然会导致最终得到的结果很乱，存在之前树的残余。
//

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *increasingBST(TreeNode *root) {
        queue<TreeNode *> nodes;
        middle_order(root, nodes);
        TreeNode *rsl = nodes.front();
        TreeNode *tmp = nodes.front();
        tmp->left = nullptr;
        tmp->right = nullptr;
        TreeNode *next;
        nodes.pop();
        while (!nodes.empty()) {
            next = nodes.front();
            next->left = nullptr;
            next->right = nullptr;
            nodes.pop();
            tmp->right = next;
            tmp = next;
        }
        return rsl;
    }

    void middle_order(TreeNode *node, queue<TreeNode *> &nodes) {
        if (!node) {
            return;
        }
        if (node->left) middle_order(node->left, nodes);
        nodes.push(node);
        if (node->right) middle_order(node->right, nodes);
    }
};

int main() {
    TreeNode a(5);
    TreeNode b(2);
    TreeNode c(6);
    a.left = &b;
    a.right = &c;
    Solution solution;
    TreeNode *new_root = solution.increasingBST(&a);
    while (new_root) {
        cout << new_root->val << " ";
        new_root = new_root->right;
    }
    return 0;
}