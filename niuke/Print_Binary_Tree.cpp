//
// Created by Mr.Hu on 2019/9/18.
//
// 打印二叉树，从上到下，从左到右
//

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> res;
        queue<TreeNode *> cur;
        if (root == nullptr) {
            return res;
        }
        cur.push(root);
        TreeNode *front;
        while (!cur.empty()) {
            front = cur.front();
            cur.pop();
            res.push_back(front->val);
            if (front->left != nullptr) {
                cur.push(front->left);
            }
            if (front->right != nullptr) {
                cur.push(front->right);
            }
        }
        return res;
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    a.left = &b;
    a.right = &c;
    Solution solution;
    vector<int> res = solution.PrintFromTopToBottom(&a);
    for (auto it:res) {
        cout << it << endl;
    }
    return 0;
}