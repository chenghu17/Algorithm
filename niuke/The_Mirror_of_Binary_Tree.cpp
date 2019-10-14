//
// Created by Mr.Hu on 2019/10/14.
//
// 题目要求对给定的二叉树求其镜像
// 即画一个中轴线，相对位置上的值交换
// 第一种思想，对应位置交换值，可能有的对应的是空；
// 其实我们从上到下逐层的交换某节点的左右子树，等价于上面交换值的思想，
// 所以我们可以使用递归的方式，逐层进行交换节点的左右子树，知道当前节点为叶子节点为止
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot == nullptr || (pRoot->left == nullptr && pRoot->right == nullptr)) {
            return;
        }
        // 每次交换当前节点的左右子树即可
        TreeNode *tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};

int main() {
    Solution solution;
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    a.left = &b;
    b.right = &c;
    solution.Mirror(&a);
    cout << "a.right = " << a.right->val << endl;
    cout << "b.left = " << b.left->val << endl;
    return 0;
}