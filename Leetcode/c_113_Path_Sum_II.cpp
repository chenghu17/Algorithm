//
// Created by Mr.Hu on 2018/7/31.
//
// leetcode 113 path sum II
//
// 题目给定一个二叉树，和一个值sum，要求找出所有root->leaf的路径，路径上所有节点val的和为sum
//
// 这是一道关于二叉树遍历的题目，可以采用先序遍历的方式，以DFS算法来实现。
// 将路径中的值依此保存在vector<int>中，将之前走过的节点以stack<TreeNode*>来存储。
// 这个题目我的解法是先对二叉树中所有节点进行遍历，即graph函数，使用map来存储，value用bool型值：
// 如果节点为叶子结点，则value=true，否则为false；
//
// 拿到了每个节点的性质，我们开始使用DFS来遍历二叉树，如果当前节点存在左子树，则继续搜索其左子树，
// 如果只有右子树，则继续搜索右子树。直到节点没有左右子树为止，此时判断tmp_sum与sum的结果，如果相等，
// 则将path加入到result中，此时从stack中将top出栈，如果当前top()节点存在leaf_node，则将其赋值为nullptr，
// 否则将right_node赋值为nullptr，这是为了防止对同一个叶子结点访问多次，但是这里就会出现一个问题，当一个节点的
// 左右叶子节点都赋值为nullptr，此时这个节点也退化为leaf_node，这就需要用到我们之前map存储的各个节点状态。
// 如果当前节点不是leaf_node，且其左右子节点为nullptr，说明经过这个节点的路径已经遍历完了，这个节点也要出栈，
// 同理这个节点的父节点也要进行剪枝操作，直到最后只存在一个根节点，且其左右节点都已经被剪枝。
//
// 这种思想其实就是DFS的循环实现方法，需要借助辅助节点状态这个辅助信息来完成。
// 当然还有递归实现方法，递归实现在以后的学习中进行训练。
//

#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void graph(TreeNode *root, map<TreeNode *, bool> &leaf_node) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            leaf_node[root] = true;
        } else {
            leaf_node[root] = false;
            graph(root->left, leaf_node);
            graph(root->right, leaf_node);
        }
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        map<TreeNode *, bool> leaf_node;
        graph(root, leaf_node);
        stack<TreeNode *> nodes;
        vector<int> path;
        int tmp_sum = 0;
        nodes.push(root);
        path.push_back(root->val);
        tmp_sum += root->val;
        TreeNode *current_node;
        while (!nodes.empty()) {
            current_node = nodes.top();
            if (current_node->left == nullptr && current_node->right == nullptr) {
                //当前节点是叶子节点，是则进行下面几步
                if (current_node->left == nullptr && current_node->right == nullptr) {
                    //当前节点是叶子节点，是则进行下面几步
                    if (leaf_node[current_node] && tmp_sum == sum) {
                        result.push_back(path);
                    }
                    tmp_sum -= path.back();
                    path.pop_back();
                    nodes.pop();
                    if(nodes.empty()){
                        break;
                    }
                    if (nodes.top()->left != nullptr) {
                        nodes.top()->left = nullptr;
                    } else {
                        nodes.top()->right = nullptr;
                    }
                }
            } else if (current_node->left != nullptr) {
                nodes.push(current_node->left);
                tmp_sum += current_node->left->val;
                path.push_back(current_node->left->val);
            } else if (current_node->right != nullptr) {
                nodes.push(current_node->right);
                tmp_sum += current_node->right->val;
                path.push_back(current_node->right->val);
            }
        }
        return result;
    }
};

int main() {
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(11);
    TreeNode d(7);
    TreeNode e(2);
    TreeNode f(8);
    TreeNode g(13);
    TreeNode h(4);
    TreeNode i(5);
    TreeNode j(1);
    a.left = &b;
    b.left = &c;
    c.left = &d;
    c.right = &e;
    a.right = &f;
    f.left = &g;
    f.right = &h;
    h.left = &i;
    h.right = &j;
    Solution solution;
    vector<vector<int>> result = solution.pathSum(&a, 22);
    return 0;
}