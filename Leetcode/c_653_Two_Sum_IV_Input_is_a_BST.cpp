//
// Created by Mr.Hu on 2019/1/2.
//
// leetcode 653 two sum IV input is a BST
//
// 题目要求对于给定的二叉搜索树，判断树中是否存在两个节点值，其和等于给定的目标值
//
// 题目给定的是一棵二叉搜索树，完全可以使用中序遍历的方式，将树转换为排序好的数组，得到排序数组后，考虑数组中任意两个值是否等于目标值。
//
// 注：在对排序数组进行判断是否存在两个值等于目标值时，还可以进行优化
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool findTarget(TreeNode *root, int k) {
        vector<int> sorted_list;
        middle_order(root, sorted_list);
        // sorted_list为从小到大排序
        int size = sorted_list.size();
        if (size < 2) {
            return false;
        }
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (sorted_list[i] + sorted_list[j] == k) {
                    return true;
                }
            }
        }
        return false;
    }

    void middle_order(TreeNode *node, vector<int> &list) {
        if (!node->left && !node->right) {
            list.push_back(node->val);
            return;
        }
        if (node->left) middle_order(node->left, list);
        list.push_back(node->val);
        if (node->right) middle_order(node->right, list);
    }
};

int main() {
    TreeNode a(5);
    TreeNode b(3);
    TreeNode c(6);
    TreeNode d(2);
    TreeNode e(4);
    TreeNode f(7);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    Solution solution;
    bool exist = solution.findTarget(&a, 7);
    cout << exist;
    return 0;
}