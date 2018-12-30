//
// Created by Mr.Hu on 2018/12/30.
//
// leetcode 617 merge two binary trees
//
// 题目要求对两棵二叉树进行合并，从根节点开始，如果节点存在重叠，则将重叠节点的值累加，形成新的节点
//
// 这个题目也是在深度优先搜索的基础上增加一些条件。我们同样使用递归的方式，如果两棵树存在重叠，则创建新的节点，其值为两个节点值的和。
// 如果不存在重叠，即有一棵树的子树为空，此时可以直接将另外一棵存在的子树连接到合并树中，而不需要增加新的节点来保存。
// 以下使用递归的方式进行coding
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
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (t1 && t2) {
            TreeNode *root = new TreeNode(t1->val + t2->val);
            merge(root, t1, t2);
            return root;
        }
        if (t1 && !t2 || !t1 && t2) {
            return t1 ? t1 : t2;
        }
        return nullptr;
    }

    void merge(TreeNode *root, TreeNode *t1, TreeNode *t2) {
        if (t1->left && t2->left) {
            TreeNode *tmp = new TreeNode(t1->left->val + t2->left->val);
            root->left = tmp;
            merge(root->left, t1->left, t2->left);
        } else if (t1->left && !t2->left || !t1->left && t2->left) {
            root->left = t1->left ? t1->left : t2->left;
        }

        if (t1->right && t2->right) {
            TreeNode *tmp = new TreeNode(t1->right->val + t2->right->val);
            root->right = tmp;
            merge(root->right, t1->right, t2->right);
        } else if (t1->right && !t2->right || !t1->right && t2->right) {
            root->right = t1->right ? t1->right : t2->right;
        }
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
    d.left = &e;
    d.right = &f;
    Solution solution;
    TreeNode *root = solution.mergeTrees(&a, &d);
    cout << root->val << endl;
    cout << root->left->val << endl;
    cout << root->right->val << endl;
    return 0;
}