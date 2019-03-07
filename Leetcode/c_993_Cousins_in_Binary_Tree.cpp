//
// Created by Mr.Hu on 2019/3/7.
//
// leetcode 993 cousins in binary tree
//
// 给定一棵二叉树，所有节点值都不同，规定根节点depth=0，而其他节点的depth为从根节点到该节点路径上所有节点的个数。
// 现在给定两个值x，y，要求判断这两个值所对应的节点是否为cousins，即属于同一层，但是父节点不同。
//
// 思路：使用dfs递归的思想找到x，y所在节点的depth，同时用两个TreeNode节点分别保存其父节点信息，最后判断depth是否相等，且父节点是否不同。
// 另外，值得注意的是，我们没有考虑x或者y为根节点的情况，所以在dfs之前，先判断x或y是否为root，如果是，则先将其对应的depth和父节点赋值。
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
    TreeNode *first_father = nullptr;
    TreeNode *second_father = nullptr;
    int first_path = 0, second_path = 0;
    int cur_path = 0;

    void dfs(TreeNode *node, int x, int y) {
        if (first_father && second_father) {
            return;
        }
        cur_path++;
        if (node->left) {
            if (node->left->val == x) {
                first_father = node;
                first_path = cur_path + 1;
            } else if (node->left->val == y) {
                second_father = node;
                second_path = cur_path + 1;
            } else {
                dfs(node->left, x, y);
                cur_path--;
            }
        }
        if (node->right) {
            if (node->right->val == x) {
                first_father = node;
                first_path = cur_path + 1;
            } else if (node->right->val == y) {
                second_father = node;
                second_path = cur_path + 1;
            } else {
                dfs(node->right, x, y);
                cur_path--;
            }
        }
    }


    bool isCousins(TreeNode *root, int x, int y) {
        // 两个节点处于同一层
        // 但是两个节点的父亲节点不相同
        if (!root) {
            return false;
        }
        if (root->val == x) {
            first_path = 0;
        }
        if (root->val == y) {
            second_path = 0;
        }
        dfs(root, x, y);
        return first_path == second_path && first_father != second_father;

    }
};

int main() {
    Solution solution;
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    a.left = &b;
    a.right = &c;
    b.right = &d;
    c.right = &e;
    bool res = solution.isCousins(&a, 4, 5);
    cout << res << endl;
    return 0;

}