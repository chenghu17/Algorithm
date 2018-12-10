//
// Created by Mr.Hu on 2018/12/10.
//
// leetcode 111 minimum depth of binary tree
//
// 题目要求计算出二叉树的最小深度，即包含节点最少的路径，其中深度的大小等于路径上节点的个数。
//
// 这个题目与104，求二叉树的最大深度刚好相反，由于当时使用的循环的方法，所以这里尝试使用递归的方式来求解。
// 在递归求解的过程中，刚开始考虑的比较简单，就是min(1+depth(root->left),1+depth(root->right))，
// 但是这里就存在一个问题，如果一个节点是内部节点，并且该节点只有左儿子或者右儿子，那么从这棵树的最小深度就固定在了从根节点到这个节点的深度，
// 因为上面这个迭代关系在root->left为nullptr就结束了，但是我们知道，这并不是一条合理的路径，只是路径的一部分。
// 所以我们在进行递归的时候，需要判断当前节点的属性，如果是叶子节点，则直接return 1，如果是内部节点并且左右儿子都存在，则使用上面的取左右子树最小的情况。
// 如果只存在左儿子或者右儿子，则只需要继续递归计算存在的那个儿子节点。这样就可以避免将内部节点只包含一个儿子的情况当作终止条件。
//
// ⚠️另外值得注意的是，这段代码的运行时间只超过了百分之四的正确提交答案，于是开始思考是否哪里可以提升一下：
// 1、return min(1 + depth(root->left), 1 + depth(root->right)); 这里的+1操作可以提到外面来，这样可以减少一次加法操作，在递归的过程中可以减少多次加法操作；
// 2、if (root->left == nullptr && root->right == nullptr) 这里的if判断，完全可以直接用if (!root->left && !root->right)，无需nullptr指定；
// root->left如果为nullptr，则返回0，否则返回1
// 通过上面的修改，重新执行代码，此时的效率超过了百分之百的正确提交。
//
// 当然，这个题目也可以用BFS（广度优先搜索）的方式进行，这样在搜索每一层的过程中，哪一层最先出现叶子节点，则最小深度就是这一层的层数。
// 这种方法似乎更加清晰。
//

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return depth(root);
    }

    int depth(TreeNode *root) {
//        if (root->left == nullptr && root->right == nullptr) {
        if (!root->left && !root->right) {
            return 1;
        } else if (root->left && root->right) {
//            return min(1 + depth(root->left), 1 + depth(root->right));
            return min(depth(root->left), depth(root->right))+1;
        } else {
            return root->left ? 1 + depth(root->left) : 1 + depth(root->right);
        }
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    c.right = &e;
    e.right = &f;
    Solution solution;
    int min_depth = solution.minDepth(&a);
    cout << "min depth = " << min_depth;
    return 0;
}