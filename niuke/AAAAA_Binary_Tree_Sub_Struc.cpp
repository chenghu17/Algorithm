//
// Created by Mr.Hu on 2019/9/9.
//
// 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
//
// 可以使用递归的方式来解决这题
// 值得注意的是，当子结构的节点为叶子节点后，比较完相等则返回true，而当子结构本身为空是，则返回false，这两个结果是不一样的，所以在递归中状态要分开；
// 前者在递归中实现，后者在递归之外实现。
//
// 另外当判断两个节点值相等时，则继续判断其左右子树是否相同，同时也不能丢失当前节点左右子树与待判断树的判断关系：即下面代码40行
//

#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};


class Solution {
public:
    bool JudgeHasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
        if (pRoot2 == nullptr) {
            return true;
        }
        if (pRoot1 == nullptr) {
            return false;
        }
        if (pRoot1->val == pRoot2->val) {
            if (pRoot2->left == nullptr && pRoot2->right == nullptr) {
                return true;
            }
            return JudgeHasSubtree(pRoot1->left, pRoot2->left) &&
                   JudgeHasSubtree(pRoot1->right, pRoot2->right) ||
                   JudgeHasSubtree(pRoot1->left, pRoot2) ||
                   JudgeHasSubtree(pRoot1->right, pRoot2);
        } else {
            return JudgeHasSubtree(pRoot1->left, pRoot2) || JudgeHasSubtree(pRoot1->right, pRoot2);
        }
    }

    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
        if (pRoot1 == nullptr || pRoot2 == nullptr) {
            return false;
        }
        return JudgeHasSubtree(pRoot1, pRoot2);

    }
};


int main() {

    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    TreeNode g(7);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    c.right = &e;
    e.left = &f;
    e.right = &g;

    TreeNode h(5);
    TreeNode i(6);
    TreeNode j(7);
    h.left = &i;
    h.right = &j;

    Solution solution;
    bool hasSubtree = solution.HasSubtree(&a, &h);
    cout << hasSubtree << endl;

    return 0;
}
