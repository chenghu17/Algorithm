//
// Created by Mr.Hu on 2018/12/12.
//
// leetcode 437 path sum III
//
// 题目要求对于给定的二叉树，找出所有可能的路径，路径上所有节点的和等于给定的值，路径都是自订向下
//
// 这个题目我的思路是先确定路径的起点，然后往下遍历，如果路径和为指定值，count++；
// 所以是先BFS（广度优先搜索），确定当前的起点，然后在其中嵌入DFS（深度优先搜索），查找以当前节点为起点，往下的所有路径。
// 逐层遍历并进行深度优先搜索，直到所有层都遍历完，此时可得到所有满足条件的路径总数。
//
// 但是这种方法有点蛮力法，没有充分利用中间结果，所以时间复杂度很高。
// 需要寻找一种更加高效的方法...如使用递归的方式
//

#include <iostream>
#include <set>
#include <queue>
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
    int pathSum(TreeNode *root, int sum) {
        if (!root) {
            return 0;
        }
        int count = 0;
        // BFS
        queue<TreeNode *> cur_queue;
        cur_queue.push(root);
        TreeNode *front;
        while (!cur_queue.empty()) {
            int cur_sum = 0;
            front = cur_queue.front();
            stack<TreeNode *> cur_stack;
            set<TreeNode *> visited_node;
            cur_stack.push(front);
            cur_sum += front->val;
            TreeNode *top;
            // DFS
            while (!cur_stack.empty()) {
                top = cur_stack.top();
                if (cur_sum == sum && !visited_node.count(top)) {
                    count++;
                    visited_node.insert(top);
                }
                if (top->left && !visited_node.count(top->left)) {
                    cur_stack.push(top->left);
                    cur_sum += top->left->val;
                } else if (top->right && !visited_node.count(top->right)) {
                    cur_stack.push(top->right);
                    cur_sum += top->right->val;
                } else {
                    cur_stack.pop();
                    cur_sum -= top->val;
                    visited_node.insert(top);
                }
            }
            if (front->left) {
                cur_queue.push(front->left);
            }
            if (front->right) {
                cur_queue.push(front->right);
            }
            cur_queue.pop();
        }
        return count;
    }
};

int main() {
    TreeNode a(10);
    TreeNode b(5);
    TreeNode c(-3);
    TreeNode d(3);
    TreeNode e(2);
    TreeNode f(11);
    TreeNode g(3);
    TreeNode h(-2);
    TreeNode i(1);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    d.left = &g;
    d.right = &h;
    e.right = &i;
    Solution solution;
    int path_count = solution.pathSum(&a, 8);
    cout << "path count: " << path_count;
    return 0;
}