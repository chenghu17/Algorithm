//
// Created by Mr.Hu on 2018/9/26.
//
// leetcode 872 leaf similar trees
//


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:

    vector<int> getLeaf(TreeNode *root) {
        vector<int> leaf1;
        stack<TreeNode *> tmp1;
        tmp1.push(root);
        while (!tmp1.empty()) {
            TreeNode *tmp = tmp1.top();
            tmp1.pop();
            if (tmp->left != nullptr || tmp->right != nullptr) {
                if (tmp->left != nullptr) {
                    tmp1.push(tmp->left);
                }
                if (tmp->right != nullptr) {
                    tmp1.push(tmp->right);
                }
            } else {
                leaf1.push_back(tmp->val);
            }
        }
        return leaf1;
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> leaf1, leaf2;
        leaf1 = getLeaf(root1);
        leaf2 = getLeaf(root2);
        // 比较leaf1和leaf2是否相同
        if (leaf1.size() != leaf2.size()) {
            return false;
        }
        for (int i = 0; i < leaf1.size(); ++i) {
            if (leaf1[i] != leaf2[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    TreeNode root1(1);
    TreeNode left1(2);
    TreeNode right1(3);

    TreeNode root2(1);
    TreeNode left2(3);
    TreeNode right2(2);

    root1.left = &left1;
    root1.right = &right1;

    root2.left = &left2;
    root2.right = &right2;

    Solution solution;
    bool isSimilar = solution.leafSimilar(&root1, &root2);
    cout << "Yes(1)/No(0):" << isSimilar;
    return 0;
}