//
// Created by Mr.Hu on 2018/12/12.
//
// leetcode 404 sum of left leaves
//
//

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode *root) {
        if (!root || !root->left && !root->right) {
            return 0;
        }
        int result = 0;
        queue<TreeNode *> cur_node;
        cur_node.push(root);
        TreeNode *front;
        while (!cur_node.empty()) {
            front = cur_node.front();
            if (front->left) {
                if (!front->left->left && !front->left->right) {
                    result += front->left->val;
                } else {
                    cur_node.push(front->left);
                }
            }
            if (front->right) {
                cur_node.push(front->right);
            }
            cur_node.pop();
        }
        return result;
    }

};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    a.left = &b;
    a.right = &c;
    c.left = &d;
    Solution solution;
    int left_leaves_sum = solution.sumOfLeftLeaves(&a);
    cout << "sum of left leaves: " << left_leaves_sum;
    return 0;
}