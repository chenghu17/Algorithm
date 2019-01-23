//
// Created by Mr.Hu on 2019/1/23.
//
// leetcode 530 minimum absolute difference in BST
//
// 题目给定一棵平衡二叉树，要求找出树中所有任意两点节点值之差的相对最小值（即绝对值）。
//
// 由于给定的是一棵平衡二叉树，所以我们可以很容易的转换为有序的数组，使用中序遍历即可，递归操作。
// 得到顺序数组之后，想要得到最小的任意两点之间差的绝对值，我们只需要考虑数组所有前后值所有的差值的绝对值即可。
// 在所有差值绝对值中，最小值即为所求。
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    vector<int> order;

    void inorder(TreeNode *node) {
        if (!node) {
            return;
        }
        if (node->left) inorder(node->left);
        order.push_back(node->val);
        if (node->right) inorder(node->right);
    }

    int getMinimumDifference(TreeNode *root) {
        // 中序遍历，得到排序后的树
        inorder(root);
        int min_dif = INT_MAX;
        for (int i = 1; i < order.size(); i++) {
            min_dif = min(min_dif, order[i] - order[i - 1]);
        }
        return min_dif;
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(3);
    TreeNode c(2);
    a.right = &b;
    b.left = &c;
    Solution solution;
    int min_diff = solution.getMinimumDifference(&a);
    cout << min_diff << endl;
    return 0;
}