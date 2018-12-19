//
// Created by Mr.Hu on 2018/12/19.
//
// leetcode 563 binary tree tilt
//
// 题目给定一颗二叉树，定义每个节点的偏差为该节点左子树所有节点和 与 右子树所有节点和 差的绝对值。
// 先要求二叉树的整体偏差：即每个节点的偏差累加的结果
//
// 最直观的方法：我们需要对每个节点的左右子树计算结果，然后得到偏差值，最后累加。
// 如果我们采用循环的方法，对每个节点的左右子树分别求和，这里可以使用递归的方式得到左右和，但是如果从上到下计算的话，会需要许多重复的结果。
//
// 所以这里我们使用递归的方式，从底向上进行计算，每次得到节点的左子树所有节点的和，右子树所有节点的和，然后计算tilt，并将该tilt累加到一个全局的变量中，
// 计算完后，将return left+right+node->val，递归返回到上一层，这里的结果将传递给上一层父节点，作为该父节点的左/右子树的结果。
// 按照上述递归的方式，即可将所有节点的"偏差"累加到tilt中，最后返回该tilt即可。
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 每个节点左右子树和的差值，然后进行累加

class Solution {
public:
    int tilt = 0;

    int findTilt(TreeNode *root) {
        traverse(root);
        return tilt;
    }

    int traverse(TreeNode *node) {
        if (!node) {
            return 0;
        }
        int left = traverse(node->left);
        int right = traverse(node->right);
        tilt += abs(left - right);
        return left + right + node->val;
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    a.left = &b;
    a.right = &c;
    Solution solution;
    int tilt = solution.findTilt(&a);
    cout << "the tree's tilt is " << tilt << endl;
    return 0;
}