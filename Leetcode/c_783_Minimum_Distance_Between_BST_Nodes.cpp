//
// Created by Mr.Hu on 2018/9/13.
//


#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    vector<int> dfs(TreeNode *root) {
        vector<int> sortNums;
        stack<TreeNode *> listNode;
        listNode.push(root);
        while (!listNode.empty()) {
            TreeNode *cur = listNode.top();
            if (cur->left != nullptr) {
                listNode.push(cur->left);
                cur->left = nullptr;
            } else {
                sortNums.push_back(cur->val);
                if (cur->right != nullptr) {
                    listNode.pop();
                    listNode.push(cur->right);
                    cur->right = nullptr;
                } else {
                    listNode.pop();
                }
            }
        }
        return sortNums;
    }

    // 二叉搜索树进行中序遍历，直接得到排好序的树节点值，计算相邻树节点值的distance
    int minDiffInBST(TreeNode *root) {
        int min_dis = INT_MAX;
        vector<int> nums = dfs(root);
        for (int i = 1; i < nums.size(); ++i) {
            min_dis = min(abs(nums[i] - nums[i - 1]), min_dis);
        }
        return min_dis;
    }
};

int main() {
    TreeNode a(4);
    TreeNode b(2);
    TreeNode c(6);
    TreeNode d(1);
    TreeNode e(3);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    Solution solution;
    int min_distance = solution.minDiffInBST(&a);
    cout << "min_distance:" << min_distance;
    return 0;
}