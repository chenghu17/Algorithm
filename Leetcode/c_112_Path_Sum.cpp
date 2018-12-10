//
// Created by Mr.Hu on 2018/12/10.
//
// leetcode 112 path sum
//
// 题目
//
//

#include <iostream>
#include <stack>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) {
            return false;
        }
        stack<TreeNode *> cur_node;
        set<TreeNode *> joined_nodes;
        cur_node.push(root);
        int cur_sum = root->val;
        while (!cur_node.empty()) {
            TreeNode *top = cur_node.top();
            if (cur_sum == sum && !top->left && !top->right) {
                return true;
            } else if (!top->left && !top->right) {
                cur_sum -= top->val;
                joined_nodes.insert(top);
                cur_node.pop();
            } else if (top->left && !joined_nodes.count(top->left)) {
                cur_sum += top->left->val;
                cur_node.push(top->left);
            } else if (top->right && !joined_nodes.count(top->right)) {
                cur_sum += top->right->val;
                cur_node.push(top->right);
            } else {
                cur_sum -= top->val;
                joined_nodes.insert(top);
                cur_node.pop();
            }
        }
        return false;
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    a.left = &b;
    a.right = &c;
    Solution solution;
    bool result = solution.hasPathSum(&a,3);
    string res[] = {"False","True"};
    cout<<"is exist path? "<<res[int(result)];
    return 0;
}