//
// Created by Mr.Hu on 2018/11/12.
//
// leetcode 101 symmetric tree
//
// 题目要求判断给定的二叉树是否为对称树，即根节点的左右儿子相等，
// 内部节点的左儿子节点值等于其兄弟节点的右节点值，
// 内部节点的右儿子节点值等于其兄弟节点的左节点值。如果为空节点，也是对称位置为空
//
// solution1：使用先序遍历，深度优先搜索实现，利用两个栈来存储待访问节点的信息，
// 要求第一个栈在存储当前待访问节点的左右子节点时，先存储左节点，再存储右节点；
// 第二个栈在存储当前待访问节点的左右子节点时，先存储右节点，再存储左节点；空节点也存储。
// 这样做的原因就是首先将该树考虑称满二叉树，然后当分别取两个栈的栈顶元素时，来自于对称位置的节点
//

#include <iostream>
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
    bool isSymmetric(TreeNode *root) {
        stack<TreeNode *> stack1, stack2;
        if (root != nullptr) {
            stack1.push(root);
            stack2.push(root);
        } else {
            return true;
        }
        while (!stack1.empty() && !stack2.empty()) {
            TreeNode *top_node1 = stack1.top();
            TreeNode *top_node2 = stack2.top();
            stack1.pop();
            stack2.pop();
            if (top_node1 != nullptr && top_node2 != nullptr) {
                if (top_node1->val == top_node2->val) {
                    stack1.push(top_node1->left);
                    stack1.push(top_node1->right);
                    stack2.push(top_node2->right);
                    stack2.push(top_node2->left);
                } else {
                    return false;
                }
            } else if (top_node1 == nullptr && top_node2 == nullptr) {
                continue;
            } else {
                return false;
            }
        }
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    TreeNode root(10);
    TreeNode left1(2);
    TreeNode right1(2);
    TreeNode left11(3);
    TreeNode left12(4);
    TreeNode right11(4);
    TreeNode right12(3);
    root.left = &left1;
    root.right = &right1;
    left1.left = &left11;
    left1.right = &left12;
    right1.left = &right11;
    right1.right = &right12;
    Solution solution;
    bool result = solution.isSymmetric(&root);
    cout << "is symmetric tree?: " << result;
    return 0;
}