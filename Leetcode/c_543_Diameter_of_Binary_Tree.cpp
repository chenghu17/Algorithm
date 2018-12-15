//
// Created by Mr.Hu on 2018/12/15.
//
// leetcode 543 diameter of binary tree
//
// 题目给定二叉树，要求得到该二叉树的直径（所谓直径，就是二叉树所有节点中，两个节点件距离最长的情况）
//
// 要想求每个经过每个节点的路径长度，其实就是求该节点左右子树的最长路径树，而求左右子树最长路径，可以利用DFS的思想，
// 遍历得到左子树中最长的情况，同时利用相同的方法，遍历得到右子树中最长的情况，两个相加即可得到经过该节点最长的路径；
// 对树中所有节点进行想用的操作，然后每次比较取当前做长路径，最后输出即可。
//
// 但是上述方法只超过了百分之十五的方案。不难发现，我们在计算每个节点路径时，从上到下进行计算，其实对于下面的节点来说，递归操作重复计算了很多次，
// 我们也可以使用额外的存储空间，从底向上来进行计算，保留每个节点的路径左右子树的路径长度，这样可以大大节省时间。
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