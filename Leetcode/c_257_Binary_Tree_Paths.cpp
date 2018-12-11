//
// Created by Mr.Hu on 2018/12/11.
//
// leetcode 257 binary tree paths
//
//
//

#include <iostream>
#include <set>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> result;
        if (!root) return result;
        if (!root->left && !root->right) {
            result.push_back(to_string(root->val));
            return result;
        }
        stack<TreeNode *> cur_node;
        set<TreeNode *> internal_node;
        string path = to_string(root->val);
        cur_node.push(root);
        while (!cur_node.empty()) {
            // do something
            TreeNode *top = cur_node.top();
            if (!top->left && !top->right) {
                result.push_back(path);
                path = path.substr(0, path.size() - 2 - to_string(cur_node.top()->val).size());
                cur_node.pop();

            } else if (top->left && !internal_node.count(top->left)) {
                internal_node.insert(top->left);
                cur_node.push(top->left);
                path = path + "->" + to_string(top->left->val);
            } else if (top->right && !internal_node.count(top->right)) {
                internal_node.insert(top->right);
                cur_node.push(top->right);
                path = path + "->" + to_string(top->right->val);
            } else {
                if (path.size() == 1) {
                    break;
                }
                path = path.substr(0, path.size() - 2 - to_string(cur_node.top()->val).size());
                cur_node.pop();
            }
        }
        return result;
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(12);
    TreeNode c(13);
    TreeNode d(5);
    a.left = &b;
    a.right = &c;
    b.right = &d;
    Solution solution;
    vector<string> paths = solution.binaryTreePaths(&a);
    for (auto it:paths) {
        cout << it << endl;
    }
    return 0;
}