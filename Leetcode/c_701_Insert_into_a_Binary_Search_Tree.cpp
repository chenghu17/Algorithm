//
// Created by Mr.Hu on 2018/8/15.
//
// 题目要求在一棵二叉搜索树中插入一个节点，给定该节点的value。
//
// 这个题目在leetcode中的难度系数为medium，但是这个题目中加入了一个提交，
// 即插入的值在树中未出现过，树中的值都是唯一的。
// 所以这个题目在代码上就简化了，无需移动子树，节点插入之后充当的角色都是叶子节点。
//
// 因为给定的树为二叉搜索树，即节点的值小于左子树上的所有节点值，大于右子树上所有节点的值。
// 所以我们在插入节点时，判断当前值与节点之前的大小关系，大于该节点则继续搜索其右子树，
// 如果小于该节点，则继续搜索其左子树。如果节点的右(左)子树为nullptr，则当前值就找到了插入位置，
// 创建一个节点，将新节点作为当前的右(左)节点，最后返回树的根节点。
//
// 另注：leetcode的遍历环境中无法直接使用TreeNode node(val)来创建新的节点，
// 只能使用(struct TreeNode* )malloc(sizeof(struct TreeNode))的方式来生成一个struct TreeNode* node;
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
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        struct TreeNode *node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = nullptr;
        node->right = nullptr;
//        TreeNode node(val);
        if (root == nullptr) {
//            return &node;
            return node;
        }
        TreeNode *result = root;
        while (root != nullptr) {
            if (val > root->val) {
                if (root->right == nullptr) {
//                    root->right = node;
                    root->right = node;
                    break;
                }
                root = root->right;
            } else {
                if (root->left == nullptr) {
//                    root->left = node;
                    root->left = node;
                    break;
                }
                root = root->left;
            }
        }
        return result;
    }
};

int main() {
    TreeNode node1(4);
    TreeNode node2(2);
    TreeNode node3(7);
    TreeNode node4(1);
    TreeNode node5(3);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    Solution solution;
    int val = 5;
    TreeNode *root = solution.insertIntoBST(&node1, val);
}