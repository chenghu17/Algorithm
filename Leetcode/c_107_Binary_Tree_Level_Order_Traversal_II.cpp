//
// Created by Mr.Hu on 2018/12/9.
//
// leetcode 107 binary tree level order traversal II
//
//
//

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        int cur = 1, next = 0;
        queue<TreeNode *> cur_node;
        vector<int> tmp_result;
        cur_node.push(root);
        stack<vector<int>> middle;

        while (!cur_node.empty()) {
            TreeNode *front = cur_node.front();
            cur_node.pop();
            tmp_result.push_back(front->val);
            if (front->left != nullptr) {
                cur_node.push(front->left);
                next++;
            }
            if (front->right != nullptr) {
                cur_node.push(front->right);
                next++;
            }
            cur--;
            if (cur == 0) {
                middle.push(tmp_result);
                tmp_result.clear();
                swap(cur, next);
            }
        }
        while (!middle.empty()) {
            result.push_back(middle.top());
            middle.pop();
        }
        return result;
    }
};

int main() {
    TreeNode a(3);
    TreeNode b(9);
    TreeNode c(20);
    TreeNode d(15);
    TreeNode e(7);
    TreeNode f(13);
    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;
    e.right = &f;
    Solution solution;
    vector<vector<int>> result = solution.levelOrderBottom(&a);
    for (auto it:result) {
        for (auto i:it) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}