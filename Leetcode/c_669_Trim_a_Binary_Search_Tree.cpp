//
// Created by Mr.Hu on 2019/1/2.
//
// leetcode 669 trim a binary search tree
//
// 题目给定一棵二叉搜索树，以及限定上界和下界[L,R]，要求对二叉树进行剪枝操作，即对于没有在要求范围内的节点进行丢弃。
// 最后返回修剪后的二叉排序树。
//
// 这个题目刚开始思考的时候没有什么思路，但是对于树的题目，还是努力想找到一种递归的方式进行解答，便寻找是否存在相同的处理结构。
//
// 假设对于某个节点，存在三种情况：
// 1、如果节点为nullptr，则返回nullptr；
// 2、如果节点值在[L,R]范围内，则需要继续考虑其左子节点、右节点是否在范围内，而这个过程和当前过程一样
// （因为我们前面针对的任意一个节点进行考虑；）
// 3、如果节点值不在[L,R]范围内，则同样需要考虑其左子节点、右子节点是否在范围内，但是这里有一个隐藏情况需要分析清楚，而且易错：
// 如果当前节点不在[L,R]范围内，根据二叉搜索树的定义，左子树上所有节点值小于父节点，右子树上所有节点值大于父节点。则当前节点的左儿子、
// 右儿子至多存在一个节点在[L,R]范围内，注意是至多。
//
// 分析完上述三种情况，我们需要开始考虑整个算法设计。
// 第一种情况很简单，直接返回nullptr即可；
// 第二种情况，当前节点已经满足情况，需要考虑其子节点的情况，则需要分别对左右节点进行判断，且判断返回的结果应该直接反映到其左右节点上，
// 所以利用 root->left = trimBST(root->left, L, R); 的方式，对子节点进行判断，如果在范围内，则子节点不变，如果不在，则进行剪枝，
// 返回其他满足条件的节点。
// 第三种情况，此时当前节点已经被剪去，需要考虑左子节点还是右子节点会替代当前节点的位置，或者是其他更底层的后代，因此此时需要判断，
// 且判断的结果不再是对节点的左右子节点进行更新，而是独立门户，充当当前子树的根节点，然后在递归中反馈给某一级祖先节点。
//
// ⚠️：第三步的操作是这个题目的关键，而且这个题目使用递归的方式写起来很简单，但是想要思考清楚还是有点难度，虽然这个题目是easy难度...
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
    TreeNode *trimBST(TreeNode *root, int L, int R) {
        if (!root) {
            return nullptr;
        } else if (root->val >= L && root->val <= R) {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            return root;
        } else {
            TreeNode *root_a = trimBST(root->left, L, R);
            TreeNode *root_b = trimBST(root->right, L, R);
            if (root_a) return root_a;
            if (root_b) return root_b;
            return nullptr;
        }
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(0);
    TreeNode c(2);
    a.left = &b;
    a.right = &c;
    Solution solution;
    int L = 0, R = 2;
    TreeNode *root = solution.trimBST(&a, L, R);
    return 0;
}