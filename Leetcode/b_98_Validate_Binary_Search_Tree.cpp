//
// Created by Mr.Hu on 2019/2/27.
//
// leetcode 98 validate binary search
//
// 给定一棵二叉树，判断是否为搜索树
//
// 最开始的想法，利用递归的方式，自底向上判断子树的情况；
// 但是存在一个问题：每次需要返回该树的左右结果，而且还需要判断当前子树是不是搜索树，这就导致了两个返回结果。
//
// 后来发现：既然是搜索树，那么按照中序遍历得到的结果应该是有序的。
// 而中序列遍历完全可以用dfs的方式进行，所以问题结局。
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

    void validation(TreeNode *cur, vector<int> &seq) {
        if (cur->left) {
            validation(cur->left, seq);
        }
        seq.push_back(cur->val);
        if (cur->right) {
            validation(cur->right, seq);
        }
    }

    bool isValidBST(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        vector<int> seq;
        validation(root, seq);
        for (int i = 1; i < seq.size(); i++) {
            if (seq[i - 1] >= seq[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    TreeNode a(3);
    TreeNode b(1);
    TreeNode c(4);
    a.left = &b;
    a.right = &c;
    bool valid = solution.isValidBST(&a);
    cout << "is binary search tree ? " << valid << endl;
    return 0;
}