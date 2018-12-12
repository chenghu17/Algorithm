//
// Created by Mr.Hu on 2018/12/12.
//
// leetcode 404 sum of left leaves
//
// 题目要求计算给定二叉树的所有左叶子节点的和。
//
// 在解答这个题目的时候，一直想怎么使用递归的方式进行解答，但是尝试了很久一直都没有accepted；
// 所以换了一种循环的方式：先考虑对所有叶子节点求和，如果使用DFS，则需要回溯到上一个父节点，而且还要避免这个节点重复计算其左右儿子...
// 如果使用BFS，逐层遍历，将每一层节点的儿子节点加入队列中，很容易判断节点是否为叶子节点。
// 那么如果判断节点是否为左叶子节点呢？有了上面的操作，我们只需要在每次加入节点的左儿子节点时，判断左儿子节点的左右儿子是否为空，
// 如果是，则表示其为左叶子节点。而对于右节点，无需这种的判断，但是也需要加入到队列中，因为可能其存在左儿子正好是叶子节点。
//

#include <iostream>
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
    int sumOfLeftLeaves(TreeNode *root) {
        if (!root || !root->left && !root->right) {
            return 0;
        }
        int result = 0;
        queue<TreeNode *> cur_node;
        cur_node.push(root);
        TreeNode *front;
        while (!cur_node.empty()) {
            front = cur_node.front();
            if (front->left) {
                if (!front->left->left && !front->left->right) {
                    result += front->left->val;
                } else {
                    cur_node.push(front->left);
                }
            }
            if (front->right) {
                cur_node.push(front->right);
            }
            cur_node.pop();
        }
        return result;
    }

};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    a.left = &b;
    a.right = &c;
    c.left = &d;
    Solution solution;
    int left_leaves_sum = solution.sumOfLeftLeaves(&a);
    cout << "sum of left leaves: " << left_leaves_sum;
    return 0;
}