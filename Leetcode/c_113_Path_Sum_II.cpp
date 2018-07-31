//
// Created by Mr.Hu on 2018/7/31.
//
// leetcode 113 path sum II
//
// 题目给定
//
//
//

#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void graph(TreeNode *root, map<TreeNode *, bool> &leaf_node) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            leaf_node[root] = true;
        } else {
            leaf_node[root] = false;
            graph(root->left, leaf_node);
            graph(root->right, leaf_node);
        }
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        map<TreeNode *, bool> leaf_node;
        graph(root, leaf_node);
        stack<TreeNode *> nodes;
        vector<int> path;
        int tmp_sum = 0;
        nodes.push(root);
        path.push_back(root->val);
        tmp_sum += root->val;
        TreeNode *current_node;

        while (!nodes.empty()) {
            current_node = nodes.top();
            if (current_node->left == nullptr && current_node->right == nullptr) {
                cout << 0 << endl;
                //当前节点是叶子节点，是则进行下面几步
                if (current_node->left == nullptr && current_node->right == nullptr) {
                    //当前节点是叶子节点，是则进行下面几步
                    if (leaf_node[current_node] && tmp_sum == sum) {
                        result.push_back(path);
                    }
                    tmp_sum -= path.back();
                    path.pop_back();
                    nodes.pop();
                    if(nodes.empty()){
                        break;
                    }
                    if (nodes.top()->left != nullptr) {
                        nodes.top()->left = nullptr;
                    } else {
                        nodes.top()->right = nullptr;
                    }
                }
            } else if (current_node->left != nullptr) {
                nodes.push(current_node->left);
                tmp_sum += current_node->left->val;
                path.push_back(current_node->left->val);
            } else if (current_node->right != nullptr) {
                nodes.push(current_node->right);
                tmp_sum += current_node->right->val;
                path.push_back(current_node->right->val);
            }
        }
        return result;
    }
};

int main() {
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(11);
    TreeNode d(7);
    TreeNode e(2);
    TreeNode f(8);
    TreeNode g(13);
    TreeNode h(4);
    TreeNode i(5);
    TreeNode j(1);
    a.left = &b;
    b.left = &c;
    c.left = &d;
    c.right = &e;
    a.right = &f;
    f.left = &g;
    f.right = &h;
    h.left = &i;
    h.right = &j;
    Solution solution;
    vector<vector<int>> result = solution.pathSum(&a, 22);
    return 0;
}