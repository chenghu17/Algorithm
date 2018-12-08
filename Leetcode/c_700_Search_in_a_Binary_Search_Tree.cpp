//
// Created by Mr.Hu on 2018/12/8.
//
// leetcode 700 search in a binary search tree
//
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