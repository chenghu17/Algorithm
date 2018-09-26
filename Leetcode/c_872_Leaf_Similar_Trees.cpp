//
// Created by Mr.Hu on 2018/9/26.
//
// leetcode 872 leaf similar trees
//
// 题目要求判断两棵二叉树的叶子节点是否相同且顺序一致。
//
// 这个题目目标就是找出二叉树的叶子结点集合，然后比较。由于只需要得到叶子节点，所以我们不需要使用DFS或者BFS去访问每一个节点。
// 用一个stack保留节点，每次取出栈顶节点，并pop()掉栈顶元素，然后判断取出的节点是否存在左右子节点，如果存在，则将左右子节点放入栈中，
// 如果不存在，则说明该节点是一个叶子节点，将该节点的值存入vector中，继续判断栈是否为空，直到栈为空，则树中所有节点已经被遍历完。
//
// 对两棵树分别执行上述操作，得到两个vector，比较两个vector是否相同，相同则返回true，不相同则返回false。
//
// 注：在遍历树的过程中，如果一个节点存在左右节点，则分别将左右节点压入栈中，
// 这个压栈的顺序则决定了最后得到的vector是从左到右记录叶子节点，还是从右到左记录叶子节点。所有我们对不同的树在记录叶子节点的值时，
// 使用同一个方法才能保证是同一方向，这个顺序是影响最后的结果的。因此不要为了炫技，第一棵树先放左节点再放右节点，第二棵树反过来，
//

#include <iostream>
#include <vector>
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

    vector<int> getLeaf(TreeNode *root) {
        vector<int> leaf1;
        stack<TreeNode *> tmp1;
        tmp1.push(root);
        while (!tmp1.empty()) {
            TreeNode *tmp = tmp1.top();
            tmp1.pop();
            if (tmp->left != nullptr || tmp->right != nullptr) {
                if (tmp->left != nullptr) {
                    tmp1.push(tmp->left);
                }
                if (tmp->right != nullptr) {
                    tmp1.push(tmp->right);
                }
            } else {
                leaf1.push_back(tmp->val);
            }
        }
        return leaf1;
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> leaf1, leaf2;
        leaf1 = getLeaf(root1);
        leaf2 = getLeaf(root2);
        // 比较leaf1和leaf2是否相同
        if (leaf1.size() != leaf2.size()) {
            return false;
        }
        for (int i = 0; i < leaf1.size(); ++i) {
            if (leaf1[i] != leaf2[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    TreeNode root1(1);
    TreeNode left1(2);
    TreeNode right1(3);

    TreeNode root2(1);
    TreeNode left2(3);
    TreeNode right2(2);

    root1.left = &left1;
    root1.right = &right1;

    root2.left = &left2;
    root2.right = &right2;

    Solution solution;
    bool isSimilar = solution.leafSimilar(&root1, &root2);
    cout << "Yes(1)/No(0):" << isSimilar;
    return 0;
}