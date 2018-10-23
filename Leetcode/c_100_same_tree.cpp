//
// Created by Mr.Hu on 2018/10/23.
//
// leetcode 100 is same tree
//
// 题目要求判断两棵二叉树是否相同，即结构和每个节点值是否相同
//
// 思路：判断两颗树是否相同，首先判断其根节点是否相同，如果相同，则判断其左子树是否相同，右子树是否相同。
// 判断左右子树是否相同使用的方法和前面的方法一样。所以这里我们可以使用递归的方法来实现。
// 递归结束的条件就是达到叶子节点，如果遇到两个节点都是叶子节点的子节点，即nullptr，则return true；
// 如果遇到两个节点中其中一个为nullptr，另一个不是，则return false。
// 如果两个节点都不为空，则判断其val是否相等，相等则继续判断两个节点的左右节点是否对应相同，即递归调用。
//
// 递归方法需要明确递归结束条件和递归的模式
//

#include <iostream>
using namespace std;

struct node {
    int val;
    node *left;
    node *right;

    node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool is_Same_Tree(node *a, node *b) {
        if (a == nullptr && b == nullptr) {
            return true;
        }
        if (a == nullptr || b == nullptr) {
            return false;
        }
        return a->val == b->val && is_Same_Tree(a->left, b->left) && is_Same_Tree(a->right, b->right);
    }
};

int main() {
    node a1(1);
    node b1(2);
    node c1(3);
    node d1(4);
    a1.left = &b1;
    a1.right = &c1;
    b1.right = &d1;

    node a2(1);
    node b2(2);
    node c2(3);
    node d2(4);
    a2.left = &b2;
    a2.right = &c2;
    b2.right = &d2;

    Solution solution;
    bool isSame = solution.is_Same_Tree(&a1,&a2);
    cout<<"is same? "<<isSame<<endl;
    return 0;
}