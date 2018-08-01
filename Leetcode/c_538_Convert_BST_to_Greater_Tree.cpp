//
// Created by Mr.Hu on 2018/8/1.
//
// leetcode 538 convert BST to greater tree
//
// 题目要求将一颗二叉搜索树转换为greater树，即将当前节点加上所有大于该节点的值，得到该节点的新值
//
// 我们知道，二叉搜索树满足任意树(子树)的根节点值大于其左子树上所有节点的值，小于右子数上所有节点的值
// 因此要实现题目要求，可以先求得二叉树所有节点的和，然后对树采用中序遍历，用result保存比当前节点大的所有节点值的和。
// 每访问一个节点，就将当前result赋值给当前节点的val，然后返回剩下的result(由result减去原来节点的val即可)
// 中序遍历采用深度优先搜索的递归方式进行，遍历完整棵树，所有节点的值也便更新完毕。
//
// 写完上述方法，突然想到另外一种方法，不需要预先计算所有节点的和，可以采用递归的方式，先访问右节点，然后将右节点的值加到
// 父节点中，再将所有和加到左节点中...
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
    int sum = 0;

    int sumBST(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        sum += root->val;
        sumBST(root->left);
        sumBST(root->right);
        return sum;
    }

    int greatTree(TreeNode *root, int result) {
        int tmp_one = 0;
        int tmp_two = 0;
        if (root->left == nullptr && root->right == nullptr) {
            tmp_one = result - root->val;
            root->val = result;
            return tmp_one;
        } else {
            // 如果不是叶子节点，则继续向下，且先左节点，再父节点，最后右节点
            if (root->left == nullptr) {
                tmp_one = result - root->val;
                root->val = result;
                return greatTree(root->right, tmp_one);
            } else if (root->right == nullptr) {
                tmp_one = greatTree(root->left, result);
                tmp_two = tmp_one - root->val;
                root->val = tmp_one;
                return tmp_two;
            } else {
                tmp_one = greatTree(root->left, result);
                tmp_two = tmp_one - root->val;
                root->val = tmp_one;
                return greatTree(root->right, tmp_two);
            }
        }
    }

    TreeNode *convertBST(TreeNode *root) {
        if (root == nullptr || root->left == nullptr && root->right == nullptr) {
            return root;
        }
        int result = sumBST(root);
        int tmp = greatTree(root, result);
        return root;

    }
};

int main() {
    TreeNode a(5);
    TreeNode b(2);
    TreeNode c(13);
    a.left = &b;
    a.right = &c;
    Solution solution;
    TreeNode *root = solution.convertBST(&a);
    cout << root->val << endl;
    cout << root->left->val << endl;
    cout << root->right->val << endl;
    return 0;
}