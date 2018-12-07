//
// Created by Mr.Hu on 2018/12/7.
//
// leetcode 230 kth smallest element in a BST
//
// 题目要求在给定的BST(平衡二叉树)中，找出第k小的数字
//
// 根据BST的性质，根节点左子树上的所有节点值都小于根节点，根节点右子树上的所有节点值大于根节点，在所有子树上同样成立
// 所以要判断第k小的节点值，需要从该树的最左叶子节点开始判断，直到第k个，即为所求。
//
// 我们这里采用深度优先搜索中使用的数据结构，用栈(stack)来存储待访问的节点，循环判断当前栈顶节点是否存在左节点，即比当前节点小的值，
// 如果存在，则将该节点左儿子节点放入stack中，如果不存在，则判断当前k是否等于1，如果等于1，则说明当前栈顶元素即第k小的元素，
// 如果不等于1，则判断当前节点右子树是否为nullptr，如果不为null，则k--，并将栈顶元素出栈，将原栈顶元素的右节点压入栈中。
// 这样做的目的即删除掉前m小的点，第k小的节点一定存在于剩下的节点中。
// 如当前节点右子树为nullptr，则说明该节点为叶子节点，k--，同时将该节点出栈，继续上述循环。
//
// 这个题目的主要逻辑在于先要判断最左叶节点（即最小值），然后判断该叶节点的父节点，再判断父节点的右子树。
// 按照这个逻辑不断进行循环，这样的顺序保证了从小到大的去遍历树中的所有值。
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
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> cur_stack;
        cur_stack.push(root);
        while (!cur_stack.empty()) {
            TreeNode *top = cur_stack.top();
            if (top->left != nullptr) {
                cur_stack.push(top->left);
                top->left = nullptr;
            } else if (k == 1) {
                return top->val;
            } else if (top->right != nullptr) {
                k--;
                cur_stack.pop();
                cur_stack.push(top->right);
            } else {
                cur_stack.pop();
                k--;
            }
        }
    }
};

int main() {
    TreeNode a(3);
    TreeNode b(1);
    TreeNode c(4);
    TreeNode d(2);
    a.left = &b;
    a.right = &c;
    b.right = &d;
    Solution solution;
    int kth = solution.kthSmallest(&a, 3);
    cout << kth << endl;
    return 0;
}