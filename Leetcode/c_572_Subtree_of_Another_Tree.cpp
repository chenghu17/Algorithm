//
// Created by Mr.Hu on 2018/12/20.
//
// leetcode 572 subtree of another tree
//
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
    // s>t
    bool isSubtree(TreeNode *s, TreeNode *t) {
        queue<TreeNode *> cur_queue;
        cur_queue.push(s);
        TreeNode *front;
        while (!cur_queue.empty()) {
            front = cur_queue.front();
            cur_queue.pop();
            if (front && front->left) cur_queue.push(front->left);
            if (front && front->right) cur_queue.push(front->right);
            if (compare(front, t)) {
                return true;
            }
        }
        return false;
    }


    bool compare(TreeNode *s, TreeNode *t) {
        if (!s && !t) {
            return true;
        }
        if (!s && t || s && !t) {
            return false;
        }
        if (s->val == t->val) {
            return compare(s->left, t->left) && compare(s->right, t->right);
        }
        return false;
    }
};

int main() {
    TreeNode s(5);
    TreeNode s1(4);
    TreeNode s2(3);
    TreeNode s3(1);
    TreeNode s4(2);
    TreeNode s5(3);

    TreeNode t(1);
    TreeNode t1(2);
    TreeNode t2(3);

    s.left = &s1;
    s.right = &s2;
    s1.left = &s3;
    s3.left = &s4;
    s3.right = &s5;

    t.left = &t1;
    t.right = &t2;

    Solution solution;
    bool isSub = solution.isSubtree(&s, &t);
    cout << "is subtree? " << isSub << endl;
    return 0;
}