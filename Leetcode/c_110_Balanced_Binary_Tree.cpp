//
// Created by Mr.Hu on 2018/12/9.
//
// leetcode 110 balanced binary tree
//
// 平衡二叉树的理解：每个节点的左右子树高度相差不大于1，而每子树的高度为该树的最长路径
//
// 
//
//
//

#include <iostream>
#include <stack>
#include <set>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        stack<TreeNode *> cur_node;
        map < TreeNode * , int > node_depth;
        if (root == nullptr || root->left == nullptr && root->right == nullptr) {
            return true;
        }
        int left_depth = 0, right_depth = 0;
        cur_node.push(root);
        while (!cur_node.empty()) {
            TreeNode *top = cur_node.top();
            //
            if (top->left != nullptr && !node_depth.count(top->left)) {
                cur_node.push(top->left);
            }
                //
            else if (top->left == nullptr && top->right == nullptr) {
                node_depth[top] = max(left_depth, right_depth);
                cur_node.pop();
            }
                //
            else if (top->right != nullptr && !node_depth.count(top->right)) {
                cur_node.push(top->right);
            } else {
                if (top->left == nullptr) {
                    left_depth = 0;
                } else {
                    left_depth = node_depth[top->left] + 1;
                }
                if (top->right == nullptr) {
                    right_depth = 0;
                } else {
                    right_depth = node_depth[top->right] + 1;
                }
                if (abs(left_depth - right_depth) > 1) {
                    return false;
                } else {
                    node_depth[top] = max(left_depth, right_depth);
                    cur_node.pop();
                    left_depth = 0;
                    right_depth = 0;
                }
            }
        }
        return true;
    }

    // wrong method
    // 对于平衡二叉树理解错误时，写的一种方法，在leetcode上提交了五六次才发现理解错了
    bool isBalanced_wrong(TreeNode *root) {
        int max_depth = 0, cur_depth = 0;
        bool is_the_first = true;
        stack<TreeNode *> cur_node;
        set<TreeNode *> exist_left;
        set<TreeNode *> exist_right;
        if (root == nullptr) {
            return true;
        }
        cur_node.push(root);
        TreeNode *top = nullptr;
        while (!cur_node.empty()) {
            top = cur_node.top();
            if (top->left != nullptr && !exist_left.count(top->left)) {
                cur_node.push(top->left);
                exist_left.insert(top->left);
                cur_depth += 1;
            } else if (top->right != nullptr && !exist_right.count(top->right)) {
                cur_node.push(top->right);
                exist_right.insert(top->right);
                cur_depth += 1;
            } else if (top->left != nullptr && top->right != nullptr) {
                cur_node.pop();
                cur_depth -= 1;
            } else if (top->left == nullptr && top->right == nullptr) {
                if (is_the_first) {
                    max_depth = cur_depth;
                    is_the_first = false;
                } else {
                    if (abs(max_depth - cur_depth) > 1) {
                        return false;
                    } else {
                        max_depth = max(max_depth, cur_depth);
                    }
                }
                cur_node.pop();
                cur_depth -= 1;
            } else {
                if (abs(max_depth - cur_depth) > 1)
                    return false;
                else {
                    cur_node.pop();
                    cur_depth -= 1;
                }

            }
        }
        return true;
    }
};

int main(){
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(2);
    TreeNode f(3);
    TreeNode g(4);
    a.left = &b;
    a.right = &e;
    b.left = &c;
    c.left = &d;
    e.right = &f;
    f.right = &g;
    Solution solution;
    int result = (int)solution.isBalanced(&a);
    string res[] = {"False","True"};
    cout<<"is balanced binary tree: "<<res[result];
    return 0;
}