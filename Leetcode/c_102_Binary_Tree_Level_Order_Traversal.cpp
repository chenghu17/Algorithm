//
// Created by Mr.Hu on 2019/2/22.
//
// leetcode 102 binary tree level order traversal
//
// 题目要求对二叉树进行逐层遍历（即广度优先搜索）
//
// 在广度优先搜索中，我们用queue来表示待访问的节点，我们想要逐层遍历，一个关键点就是需要知道当前层节点的个数，因为最后结果要求：
// 按照不同层的结果进行区分，所以我们需要用两个变量来存储当前层节点的个数和下一层节点的个数，
// 当前层节点个数为0时，则表示接下来的节点是下一层的，需要对存储器进行更新。
//

#include <iostream>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        vector<vector<int>> res;
        int cur = 0, next = 0;
        if (root == nullptr) {
            return res;
        }
        q.push(root);
        cur = 1;
        vector<int> cur_layer;
        TreeNode *cur_node;
        while (!q.empty()) {
            if (cur != 0) {
                cur_node = q.front();
                q.pop();
                cur--;
                cur_layer.push_back(cur_node->val);
                if (cur_node->left) {
                    q.push(cur_node->left);
                    next++;
                }
                if (cur_node->right) {
                    q.push(cur_node->right);
                    next++;
                }
            } else {
                res.push_back(cur_layer);
                cur_layer.clear();
                swap(cur, next);
            }
        }
        res.push_back(cur_layer);
        return res;
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;
    d.right = &f;
    Solution solution;
    vector<vector<int>> res = solution.levelOrder(&a);
    for (auto layer:res) {
        for (auto node:layer) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}