//
// Created by Mr.Hu on 2018/9/13.
//
// 题目给定一个二叉搜索树，要求寻找树节点中两个节点差最小的值（都取绝对值）。
//
// 刚开始理解这个题目以为是找相邻两个节点，即父子节点，之间的距离最小值，使用一个递归的方法可以找出该值，
// 但是在提交之后，出现了没有通过的case，发现是树中所有节点两两差值最小。
//
// 所以想到BST的特点，即节点的值大于其左子树所有节点的值，小于其右子树所有节点的值。
// 因此我们对BST采用中序遍历，并将每个节点的值存储在vector中，由于是中序遍历，最后vector是按照从小到大的顺序排列，
// 这也是BST的一种性质。此时我们可以计算vector中相邻两个数的差值并取其中的最小值进行返回。
//
// 这个题目我主要用到了中序遍历，用stack来存储访问过的节点，由于深度优先搜索会回溯到之前的节点，
// 所以我们在将节点的左孩子节点压入栈中后，将该节点的left定义为nullptr，而将节点的右孩子节点压入栈中之前，我们将该节点pop()，
// 这是为了不重复方法该节点。如果是后序遍历就不需要。这也是中序遍历的一个注意点。
// 另外：深度优先搜索用stack保留访问过的节点，广度优先搜索用queue保留访问过的节点。并且在访问节点后，需要根据实际情况定义一些操作来防止重复访问。
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