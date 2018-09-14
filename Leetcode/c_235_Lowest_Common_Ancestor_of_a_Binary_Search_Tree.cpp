//
// Created by Mr.Hu on 2018/9/14.
//
// leetcode 235 lowest common ancestor of a binary search tree
//
// 题目给定一颗二叉搜索树（BST），以及其中的两个节点，要求找出这两个节点的最低公共祖先。
//
// 所谓最低公共祖先（LCA），其实就是两个节点的所有节点中，离节点最近且公共的祖先节点。
// 这个题目的解题突破口主要是利用BST的性质：节点的值大于其左子数上所有节点的值，小于其右子数上所有节点的值，
// 我们可以利用这个性质，采用二分搜索的思想，取寻找给定的节点，并记录从根节点到该节点所走过的路径。
// 这里路径用队列(queue)来存，这点在后面解释。当拿到两条路径之后，我们可以比较两条路径中的节点。
// 因为都是从根节点出发，依此向下。LCA其实就是路径中最后一个相同的节点。
// 这就好比两个人走走路，刚开始都是走A->B->C->D，到了D之后，两个人目标点不一样，一个走向了E，一个走向了F。
// 因此两个人最后一个相同的点就是D，这也就是我们上面说的路径中最后一个相同的节点。
//
// 基于上面的这样一个分析，再来看为什么要用queue来存储这样一个路径呢？
// 两条路径的开始节点都是根节点，我们的目标是找到最后一个不相同的节点，
// 基于queue的FIFO的性质，我们在存储路径是从根节点开始存储的，所以我们从最开始的节点开始比较，
// 每次保留当前最新的相同的节点，直到两个节点不同。
//

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    queue<TreeNode *> getpath(TreeNode *root, TreeNode *target) {
        queue<TreeNode *> path;
        while (true) {
            if (root->val == target->val) {
                path.push(root);
                break;
            } else if (root->val > target->val) {
                path.push(root);
                root = root->left;
            } else {
                path.push(root);
                root = root->right;
            }
        }
        return path;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *tmp1 = root;
        TreeNode *tmp2 = root;
        queue<TreeNode *> path1 = getpath(tmp1, p);
        queue<TreeNode *> path2 = getpath(tmp2, q);
        TreeNode *LCA;
        while (!path1.empty() && !path2.empty()) {
            if (path1.front() == path2.front()) {
                LCA = path1.front();
                path1.pop();
                path2.pop();
                continue;
            }
            break;
        }
        return LCA;
    }
};

int main(){
    TreeNode root(6);
    TreeNode a(2);
    TreeNode b(8);
    TreeNode c(0);
    TreeNode d(4);
    TreeNode e(7);
    TreeNode f(9);
    TreeNode g(3);
    TreeNode h(5);
    root.left = &a;
    root.right = &b;
    a.left = &c;
    a.right = &d;
    b.left = &e;
    b.right = &f;
    d.left = &g;
    d.right = &h;
    Solution solution;
    TreeNode* LCA = solution.lowestCommonAncestor(&root,&a,&d);
    cout<<"LAC->val = "<<LCA->val;
    return 0;
}