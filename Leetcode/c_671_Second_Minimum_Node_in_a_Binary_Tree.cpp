//
// Created by Mr.Hu on 2019/1/3.
//
// leetcode 671 second minimum node in a binary tree
//
// 题目给定一棵二叉树，该树满足以下特点：每个节点要么没有子节点，要么有两个子节点；父节点的值小于等于子节点的值；
// 要求找出这棵树中第二小的值，如果不存在，则返回-1
//
// 刚开始思考这个题目想的很简单，只需呀判断根节点，根节点左儿子，根节点右儿子即可。然后报错了...
// 因为我没有考虑到，当其中一个子节点a等于根节点时，另一个子节点b大于根节点时，此时第二小的值可能出现在以a为根节点的子树上。
// 太斯拜了!
//
// 重新换一种想法，这个题目从根本上出发，还是要遍历整棵树，找出第二小的值；但是有一个值我们是知道的：最小的值，即根节点的值；
// 所以我们可以用两个全局变量，一个保存根节点的值，一个保存第二小的值（初始化为INT_MAX）；
// 然后使用dfs对整棵树进行遍历，如果当前访问的节点值小于second，并且不等于root_val，则说明可能是第二小的值；
// 继续遍历...直到遍历结束。最后判断second的值是否为初始值，如果不是，则return second，否则return -1；
//

#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int root_val, result;

    int findSecondMinimumValue(TreeNode *root) {
        root_val = root->val;
        result = INT_MAX;
        dfs(root);
        return result != INT_MAX ? result : -1;
    }

    void dfs(TreeNode *node) {
        if (node->val < result && node->val != root_val) {
            result = node->val;
        }
        if (node->left) dfs(node->left);
        if (node->right) dfs(node->right);
    }
};

int main() {
    TreeNode a(2);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(5);
    TreeNode e(7);
    a.left = &b;
    a.right = &c;
    c.left = &d;
    c.right = &e;
    Solution solution;
    int second_minimum = solution.findSecondMinimumValue(&a);
    cout << second_minimum;
    return 0;
}