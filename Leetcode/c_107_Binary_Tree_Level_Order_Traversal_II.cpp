//
// Created by Mr.Hu on 2018/12/9.
//
// leetcode 107 binary tree level order traversal II
//
// 题目要求对二叉树进行逐层遍历，最终输出的结果为从底到顶每一层的节点，并且要求每一层的节点是从左往右进行输出；
//
// 从这个题目要求的逐层遍历来看，我们可以直接联想到BFS（广度优先搜索），借助数据结构queue（队列）来完成题目要求；
// 但是这里有一个限制要求，就是逐行有区分的输出，而BFS确实是一层一层的输出，却没有对每一行有哪些数据进行区分，
// 所以我们就需要保存每一行的结果，最后输出；而在queue中，每读取一个节点，会将其左右子节点加到队尾，这就导致一个问题，
// 我们如何区分该节点是当前层的节点，还是下一层的节点？
//
// 此时想到了两种方法：第一种，使用两个队列来分别维护当前层的节点和下一层的节点，这就涉及到什么时候用哪一个队列的问题，比较复杂；
// 第二种，用两个int变量分别表示当前层节点的个数和下一层节点的个数，如果在遍历过程中，当前层节点个数减少到0，则说明当前层已经遍历完毕；
// 接下来交换当前层和下一层节点个数，并将当前层节点遍历的集合保存在结果集合中，然后清零，继续上述的循环操作，直到队列中的节点全部遍历完毕。
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