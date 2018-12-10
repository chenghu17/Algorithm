//
// Created by Mr.Hu on 2018/12/10.
//
// leetcode 226 invert binary tree
//
// 题目给定二叉树，要求将该二叉树进行颠倒。即对于每一层的元素，从左到右的顺序变成从右向左；
//
// 刚开始对这个题目理解错了，想的很麻烦，又是将当前父节点放在queue（队列）中，将子节点放在stack（栈）中，同时考虑nullptr；
//
// 其实从BFS（广度优先搜索）的角度出发，我们如果交换了根节点的左右儿子，则就把第二层颠倒了，
// 同理，我们把第二层所有节点各自的儿子节点分别颠倒，最终的结果就是第三层完全颠倒，以此类推，所有内部节点的左右儿子都交换完毕，整棵树都颠倒。
//
// 所以我们采用BFS的方式，逐层对每个内部节点的左右儿子进行交换，用queue来存储待交换的内部节点，在循环的过程中，一个节点如果不是叶子节点，
// 将其左右儿子进行交换，然后将其左右儿子放置queue中（放置顺序无所谓），直到queue为空，则整棵树都颠倒完毕。其实每个内部节点的交换是独立的，
// 而就是这所有的独立操作，执行完后，整棵树也就颠倒咯。
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
    TreeNode *invertTree(TreeNode *root) {
        if (!root || !root->left && !root->right) {
            return root;
        }
        queue<TreeNode *> cur_node;
        cur_node.push(root);
        TreeNode *tmp;
        TreeNode *cur;
        while (!cur_node.empty()) {
            cur = cur_node.front();
            cur_node.pop();
            if (cur->left) {
                cur_node.push(cur->left);
            }
            if (cur->right) {
                cur_node.push(cur->right);
            }
            tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;
        }
        return root;
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    Solution solution;
    TreeNode *root = solution.invertTree(&a);
    // BFS
    queue<TreeNode *> cur;
    cur.push(root);
    while (!cur.empty()) {
        TreeNode *node = cur.front();
        cout << node->val << " ";
        cur.pop();
        if (node->left) {
            cur.push(node->left);
        }
        if (node->right) {
            cur.push(node->right);
        }
    }
    return 0;
}