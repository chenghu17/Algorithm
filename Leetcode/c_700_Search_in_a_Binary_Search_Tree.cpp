//
// Created by Mr.Hu on 2018/12/8.
//
// leetcode 700 search in a binary search tree
//
// 题目要求判断给定的数值是否存在与二叉搜索树中，如果存在，则返回以该节点为根的子树，如果不存在，则返回nullptr
//
// 由于在leetcode上，系统已经将最终的输出程序给定，我们只需要找出该节点即可得到最终需要的子树的结果。
// 该题目相当于回顾一下对树的遍历，二叉搜索树的遍历方法和一般化的树不一样，由于其左右子节点大小的性质，我们可以使用
// while循环进行二分查找，以可以使用递归的方法进行查找。下面给出了递归的实现的方法。
//
// 由于leetcode最后输出子树的方法是一个黑盒，所以我在最终的输出部分也将该方法进行实现，其实就是一个BFS（广度优先搜素）的实现，
// 需要用到队列(queque)这个数据结构。具体方法代码中已给出。
//

#include <iostream>
#include <vector>
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
    TreeNode *searchBST(TreeNode *root, int val) {
        if (root == nullptr || root->val == val) {
            return root;
        } else if (root->val < val) {
            return searchBST(root->right, val);
        } else {
            return searchBST(root->left, val);
        }
    }
};

int main() {
    TreeNode a(4);
    TreeNode b(2);
    TreeNode c(7);
    TreeNode d(1);
    TreeNode f(3);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &f;
    Solution solution;
    TreeNode* result_root = solution.searchBST(&a, 0);
    vector<int> result;
    queue<TreeNode*> cur_queue;
    // BFS
    if(result_root!=nullptr){
        cur_queue.push(result_root);
        while(!cur_queue.empty()){
            TreeNode* cur = cur_queue.front();
            cur_queue.pop();
            result.push_back(cur->val);
            if(cur->left!=nullptr){
                cur_queue.push(cur->left);
            }
            if(cur->right!=nullptr){
                cur_queue.push(cur->right);
            }
        }
    }
    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}