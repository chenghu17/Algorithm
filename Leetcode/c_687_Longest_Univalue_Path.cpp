//
// Created by Mr.Hu on 2019/1/3.
//
// leetcode 687 longest univalue path
//
// 题目给定一棵二叉树，要求找出二叉树中，连续节点值相同的最长路径；
//
// 这个题目似曾相识，但是具体是之前的哪一题忘记了...
// 利用递归的方式进行解答，需要注意的是：对于题目要求的路径，要理解清楚，因为该路径可能是从某一个节点出发，自定向下，
// 也有可能是某个节点的左右子树连接而成，这在递归操作中是相当重要的部分。
//
// 由于我们需要得到最终的最长路径，就某个节点考虑，我们需要考虑其左边相同值所构成的路径长度，右边也需要考虑，
// 所以在递归的返回值应该是左右最大值，同时也要考虑以节点为中心，左右部分路径连接而成的路径长度，
// 这个长度就需要提前计算，并与当前最大路径比较。因此我们需要设定一个全局值来保存当前最长路径。
//
// 递归结束的条件：当前节点值与上一个节点值不同，则开始新的递归，接下来return 0，从而结束上一段递归。当前节点为叶子节点，
//
// 每次需要计算左右子路径的情况，
// 然后得到左右子路径构成的路径长度，注意这个长度有一个特点，如果路径只有左边或者右边，则需要在原始值上-1，因为我们记录的是节点数；
// 如果由左右两边拼接而成，则需要-2，因为我们重复计算的根节点的个数。
// 计算出来后与当前max_path比较取最大值。
//
// 最后返回left_length和right_length的最大值，用于上一层相同值节点的最长路径计算。
//
// 这个题目的递归思想还蛮有意思的，值得回味。
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

    int max_path = 0;

    int longestUnivaluePath(TreeNode *root) {
        if (!root) {
            return max_path;
        }
        getPath(root, root->val);
        return max_path;
    }

    int getPath(TreeNode *node, int target) {
        if (node->val != target) {
            getPath(node, node->val);
            return 0;
        }
        if (!node->left && !node->right) {
            return 1;
        }

        int left_length = 0, right_length = 0;
        if (node->left) left_length = getPath(node->left, target) + 1;
        if (node->right) right_length = getPath(node->right, target) + 1;

        if (left_length != 0 && right_length != 0) {
            max_path = max(max_path, left_length + right_length - 2);
        } else if (left_length != 0 || right_length != 0) {
            max_path = max(max_path, left_length + right_length - 1);
        }

        return max(left_length, right_length);
    }
};

int main() {
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(5);
    TreeNode d(1);
    TreeNode e(1);
    TreeNode f(5);
    TreeNode g(5);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;

    Solution solution;
    int longest_path = solution.longestUnivaluePath(&a);
    cout << longest_path << endl;
    return 0;
}