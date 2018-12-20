//
// Created by Mr.Hu on 2018/12/20.
//
// leetcode 572 subtree of another tree
//
// 题目给定两棵二叉树s和t，要求判断二叉树s中，是否存在子树，与二叉树t完全相同（树的结构以及每个节点的值都相同）。
// 对于s的子树，要求是子树根节点下所有的后代节点，不能只是子树的一部分。
//
// 这个题目刚开始看没有什么思路，因为存在这样一个问题：对于s与t，哪个是模式树呢？其实题目已经说明了，二叉树t为模式树，是去寻找s中的子树。
// 所以这里我们就需要去判断，究竟s中哪一部分可能和t相同。首先应该判断两颗树的根节点是否相等，如果相等才有机会去进行后续的操作。
// 首先对s树采用广度优先搜索的方式，自顶向下判断每个节点是否与t的根节点是否相同，如果相同，则开始判断后代是否相同。
// 在对树进行模式匹配的过程中，很明显的可以使用递归的方式进行判断，最后输出结果，如果存在子树与t完全相同，则返回true，
// 如果遍历完s中的所有节点，都没有找到与t相同的子树，则返回false。
//
// 这里递归的方法可以很大程度上减少树比较的空间复杂度和时间复杂度，如果用循环的方式也可以，但是需要维护两个queue，然后进行比较。
// 循环的方式读者也可以试试，这里还是比较清晰的。
//

#include <iostream>
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
    // s>t
    bool isSubtree(TreeNode *s, TreeNode *t) {
        queue<TreeNode *> cur_queue;
        cur_queue.push(s);
        TreeNode *front;
        while (!cur_queue.empty()) {
            front = cur_queue.front();
            cur_queue.pop();
            if (front && front->left) cur_queue.push(front->left);
            if (front && front->right) cur_queue.push(front->right);
            if (compare(front, t)) {
                return true;
            }
        }
        return false;
    }


    bool compare(TreeNode *s, TreeNode *t) {
        if (!s && !t) {
            return true;
        }
        if (!s && t || s && !t) {
            return false;
        }
        if (s->val == t->val) {
            return compare(s->left, t->left) && compare(s->right, t->right);
        }
        return false;
    }
};

int main() {
    TreeNode s(5);
    TreeNode s1(4);
    TreeNode s2(3);
    TreeNode s3(1);
    TreeNode s4(2);
    TreeNode s5(3);

    TreeNode t(1);
    TreeNode t1(2);
    TreeNode t2(3);

    s.left = &s1;
    s.right = &s2;
    s1.left = &s3;
    s3.left = &s4;
    s3.right = &s5;

    t.left = &t1;
    t.right = &t2;

    Solution solution;
    bool isSub = solution.isSubtree(&s, &t);
    cout << "is subtree? " << isSub << endl;
    return 0;
}