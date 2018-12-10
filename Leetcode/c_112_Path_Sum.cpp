//
// Created by Mr.Hu on 2018/12/10.
//
// leetcode 112 path sum
//
// 题目要求对于给定的二叉树，判断是否存在一条路径，使得该路径上所有节点值的和等于给定的目标结果
//
// 这个题目其实就是对于DFS（深度优先搜索）的应用，我在这里使用了循环的方式来遍历每一条路径，并判断该路径和是否等于目标值；
// 对于不在目标路径上的节点，为防止再次访问，我们使用set数据结构来保存，之后判断节点是否继续概率时也考虑是否已经被访问过，如果访问过，则跳过。
//
// 这个题目还可以使用递归的方式来求解，我们可以发现，对于每个节点而言，每次都是需要考虑左右路径，一旦接下来的节点为空，则说明到了根节点，
// 此时则可以判断累加和与目标结果的值，如果相等，则返回true，不相等则继续递归。
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
    bool result = solution.hasPathSum(&a, 3);
    string res[] = {"False", "True"};
    cout << "is exist path? " << res[int(result)];
    return 0;
}