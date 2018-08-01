//
// Created by Mr.Hu on 2018/8/1.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sum = 0;

    int sumBST(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        sum += root->val;
        sumBST(root->left);
        sumBST(root->right);
        return sum;
    }

    int greatTree(TreeNode *root, int result) {
        int tmp_one = 0;
        int tmp_two = 0;
        if (root->left == nullptr && root->right == nullptr) {
            tmp_one = result - root->val;
            root->val = result;
            return tmp_one;
        } else {
            // 如果不是叶子节点，则继续向下，且先左节点，再父节点，最后右节点
            if (root->left == nullptr) {
                tmp_one = result - root->val;
                root->val = result;
                return greatTree(root->right, tmp_one);
            } else if (root->right == nullptr) {
                tmp_one = greatTree(root->left, result);
                tmp_two = tmp_one - root->val;
                root->val = tmp_one;
                return tmp_two;
            } else {
                tmp_one = greatTree(root->left, result);
                tmp_two = tmp_one - root->val;
                root->val = tmp_one;
                return greatTree(root->right, tmp_two);
            }
        }
    }

    TreeNode *convertBST(TreeNode *root) {
        if (root == nullptr || root->left == nullptr && root->right == nullptr) {
            return root;
        }
        int result = sumBST(root);
        int tmp = greatTree(root, result);
        return root;

    }
};

int main() {
    TreeNode a(5);
    TreeNode b(2);
    TreeNode c(13);
    a.left = &b;
    a.right = &c;
    Solution solution;
    TreeNode *root = solution.convertBST(&a);
    cout << root->val << endl;
    cout << root->left->val << endl;
    cout << root->right->val << endl;
    return 0;
}