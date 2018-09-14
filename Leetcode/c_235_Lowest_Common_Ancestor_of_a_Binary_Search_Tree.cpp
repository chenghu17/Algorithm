//
// Created by Mr.Hu on 2018/9/14.
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