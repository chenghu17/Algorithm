//
// Created by Mr.Hu on 2019/1/2.
//
// leetcode 637 average of levels in binary tree
//
// 题目要去对于给定的二叉树，计算每一层的平均值。
//
// 这题属于BFS（广度优先搜索）的拓展，我们需要遍历每一层，得到每层节点值的和。
// 可以使用BFS的循环方式，利用queue来保存待访问节点，然后使用两个int变量分别保存当前节点的剩余数量和下一层的节点数。
//
// 我这里使用两个vector来交替保存当前节点和下一层节点，直到最后两个vector都为空，则表示二叉树的每一层的平均值都计算完毕。
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
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> result;
        if (!root) {
            return result;
        }
        vector<TreeNode *> v1, v2;
        v1.push_back(root);
        double sum_level;
        while (true) {
            sum_level = 0;
            if (v1.empty() && v2.empty()) {
                break;
            }
            if (!v1.empty()) {
                for (auto node:v1) {
                    sum_level += node->val;
                    if (node->left) v2.push_back(node->left);
                    if (node->right) v2.push_back(node->right);
                }
                result.push_back(sum_level / v1.size());
                v1.clear();
                continue;
            }
            if (!v2.empty()) {
                for (auto node:v2) {
                    sum_level += node->val;
                    if (node->left) v1.push_back(node->left);
                    if (node->right) v1.push_back(node->right);
                }
                result.push_back(sum_level / v2.size());
                v2.clear();
            }
        }
        return result;
    }
};

int main() {
    TreeNode a(3);
    TreeNode b(4);
    TreeNode c(9);
    TreeNode d(4);
    TreeNode e(8);
    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;
    Solution solution;
    vector<double> result = solution.averageOfLevels(&a);
    for (auto i:result) {
        cout << i << " ";
    }
    return 0;

}