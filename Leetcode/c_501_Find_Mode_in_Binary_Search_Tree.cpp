//
// Created by Mr.Hu on 2018/12/13.
//
// leetcode 501 find mode in binary search tree
//
// 题目要求对给定的二叉搜索树，找出所有出现次数最多的元素；
// 二叉搜索树的定义，节点的值大于等于左子树上所有节点的值，小于等于右子树所有节点的值。
//
// 我先使用蛮力法进行解决，对该树使用BFS（广度优先搜索）的方式，逐层遍历每个节点，使用map数据结构存储每个节点值的出现次数，
// 同时更新当前最多出现次数。遍历完整棵树后，在map中找出出现次数等于最多出现次数的key值，即为题目要求的mode(s)集合
// 这种方式借助了大量的外部存储空间，这不满足题目所期望的不使用额外存储空间。
//
// 关于不使用额外存储空间的思考：上面的方法对整棵树进行遍历，最终得到每个节点值出现的次数。我们并没有用到这棵树是二叉搜索树这样一个条件，
// 上面的方法对任意一颗二叉树都可以使用。所以这一点是我们可以思考的地方。。。
//
// recursion solution
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> findMode(TreeNode *root) {
        vector<int> modes;
        if (!root) {
            return modes;
        }
        // BFS
        int max_count = 1;
        queue<TreeNode *> cur_nodes;
        map<int, int> nodes_num;
        cur_nodes.push(root);
        TreeNode *front;
        while (!cur_nodes.empty()) {
            front = cur_nodes.front();
            if (nodes_num.count(front->val)) {
                nodes_num[front->val]++;
                max_count = max(max_count, nodes_num[front->val]);
            } else {
                nodes_num[front->val] = 1;
            }
            if (front->left) {
                cur_nodes.push(front->left);
            }
            if (front->right) {
                cur_nodes.push(front->right);
            }
            cur_nodes.pop();
        }
        for (auto it:nodes_num) {
            if (it.second == max_count) {
                modes.push_back(it.first);
            }
        }
        return modes;
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(1);
    TreeNode c(2);
    TreeNode d(2);
    a.left = &b;
    a.right = &c;
    c.right = &d;
    Solution solution;
    vector<int> result = solution.findMode(&a);
    for (auto it:result) {
        cout << it << " ";
    }
    return 0;
}