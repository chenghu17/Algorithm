//
// Created by Mr.Hu on 2019/1/3.
//
// leetcode 965 univalued binary tree
//
// 使用类似于DFS/BFS遍历的思想
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
    bool isUnival = true;

    bool isUnivalTree(TreeNode *root) {
        dfs(root, root->val);
        return isUnival;
    }

    bool dfs(TreeNode *root, int target) {
        if (isUnival) {
            if (root->val != target) {
                isUnival = false;
            } else {
                if (root->left) dfs(root->left, target);
                if (root->right) dfs(root->right, target);
            }
        }
        return isUnival;
    }


    bool isUnivalTree_optimal(TreeNode *root) {
        return dfs_optimal(root, root->val);
    }

    bool dfs_optimal(TreeNode *node, int target) {
        if (!node) return true;
        if (node->val != target) return false;
        return dfs(node->left, target) && dfs(node->right, target);
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(1);
    TreeNode c(1);
    a.left = &b;
    a.right = &c;
    Solution solution;
//    bool result = solution.isUnivalTree(&a);
    bool result = solution.isUnivalTree_optimal(&a);
    cout << result << endl;
    return 0;
}