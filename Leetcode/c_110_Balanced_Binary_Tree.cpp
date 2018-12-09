//
// Created by Mr.Hu on 2018/12/9.
//
// leetcode 110 balanced binary tree
//
// 平衡二叉树的理解：每个节点的左右子树高度相差不大于1，而每子树的高度为该树的最长路径
//
// 这个题目我在leetcode上提交了六七遍才顺利通过，而且最终通过的方法只打败了百分之五的方法，之所以前面错这么多次，是因为对于平衡二叉树的概念没有理解。
// 错误的理解和当时写的方法在code中已经给出了wrong method
//
// 下面讲一下另外一种已经通过，但是效率不高的方法。考虑到平衡二叉树判断的是每个节点左右子树的高度差，所以我们要取计算每个节点左右子树的高度，
// 然后进行比较。而以某个节点作为根节点的子树高度，是等于其左右子树中较大高度加一得到。
// 按照上面的思想，我们采用类似于DFS的方法，去遍历整棵树，从底向上计算每个节点作为根节点的子树高度，在计算高度之前，先判断其左右子树高度的差值，
// 如果差值大于1，则说明该子树不平衡，也就是整棵树不满足平衡的条件，结束判断。如果小于等于一，则取较大值加一作为以当前节点为根的子树高度。
// 具体的逻辑关系可以查看代码部分。
//
// 在上述方法中，我们需要取保存以某个节点作为根节点的子树高度，其实我们完全可以用递归的方法，递归的得到每个节点为根节点的高度；
// max(1+depth(root->left),1+depth(root->right))；
// 在树这类的题目中，熟练使用递归方法是一种必备技能，而且能够帮助我们减少代码量。
//

#include <iostream>
#include <stack>
#include <set>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        stack<TreeNode *> cur_node;
        map<TreeNode *, int> node_depth;
        if (root == nullptr || root->left == nullptr && root->right == nullptr) {
            return true;
        }
        int left_depth = 0, right_depth = 0;
        cur_node.push(root);
        while (!cur_node.empty()) {
            TreeNode *top = cur_node.top();
            //先考虑左子树
            if (top->left != nullptr && !node_depth.count(top->left)) {
                cur_node.push(top->left);
            }//再考虑右子树
            else if (top->right != nullptr && !node_depth.count(top->right)) {
                cur_node.push(top->right);
            }//节点是叶子节点的情况
            else if (top->left == nullptr && top->right == nullptr) {
                node_depth[top] = max(left_depth, right_depth);
                cur_node.pop();
            }//节点为内部节点，计算其左右子树的高度，并判断是否平衡，然后得到以该节点为根节点，树的高度
            else {
                if (top->left == nullptr) {
                    left_depth = 0;
                } else {
                    left_depth = node_depth[top->left] + 1;
                }
                if (top->right == nullptr) {
                    right_depth = 0;
                } else {
                    right_depth = node_depth[top->right] + 1;
                }
                if (abs(left_depth - right_depth) > 1) {
                    return false;
                } else {
                    node_depth[top] = max(left_depth, right_depth);
                    cur_node.pop();
                    left_depth = 0;
                    right_depth = 0;
                }
            }
        }
        return true;
    }

    // wrong method
    // 对于平衡二叉树理解错误时，写的一种方法，在leetcode上提交了五六次才发现理解错了
    bool isBalanced_wrong(TreeNode *root) {
        int max_depth = 0, cur_depth = 0;
        bool is_the_first = true;
        stack<TreeNode *> cur_node;
        set<TreeNode *> exist_left;
        set<TreeNode *> exist_right;
        if (root == nullptr) {
            return true;
        }
        cur_node.push(root);
        TreeNode *top = nullptr;
        while (!cur_node.empty()) {
            top = cur_node.top();
            if (top->left != nullptr && !exist_left.count(top->left)) {
                cur_node.push(top->left);
                exist_left.insert(top->left);
                cur_depth += 1;
            } else if (top->right != nullptr && !exist_right.count(top->right)) {
                cur_node.push(top->right);
                exist_right.insert(top->right);
                cur_depth += 1;
            } else if (top->left != nullptr && top->right != nullptr) {
                cur_node.pop();
                cur_depth -= 1;
            } else if (top->left == nullptr && top->right == nullptr) {
                if (is_the_first) {
                    max_depth = cur_depth;
                    is_the_first = false;
                } else {
                    if (abs(max_depth - cur_depth) > 1) {
                        return false;
                    } else {
                        max_depth = max(max_depth, cur_depth);
                    }
                }
                cur_node.pop();
                cur_depth -= 1;
            } else {
                if (abs(max_depth - cur_depth) > 1)
                    return false;
                else {
                    cur_node.pop();
                    cur_depth -= 1;
                }

            }
        }
        return true;
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(2);
    TreeNode f(3);
    TreeNode g(4);
    a.left = &b;
    a.right = &e;
    b.left = &c;
    c.left = &d;
    e.right = &f;
    f.right = &g;
    Solution solution;
    int result = (int) solution.isBalanced(&a);
    string res[] = {"False", "True"};
    cout << "is balanced binary tree: " << res[result];
    return 0;
}