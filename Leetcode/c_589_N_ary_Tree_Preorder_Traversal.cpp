//
// Created by Mr.Hu on 2018/12/24.
//
// leetcode 589 n ary tree preorder traversal
//
// 题目要求对N叉树进行先序遍历
//
// 这里使用递归的方式进行遍历，类似于二叉树的先序遍历，只是在处理节点上，需要循环访问节点的孩子节点。
// 使用循环的方式进行实现同样需要借助栈(stack)来进行，这里不再重复。
//

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    // recursive
    vector<int> preorder(Node *root) {
        vector<int> result;
        preorder_traversal(root, result);
        return result;
    }

    void preorder_traversal(Node *node, vector<int> &result) {
        if (!node) {
            return;
        }
        result.push_back(node->val);
        vector<Node *> children = node->children;
        for (auto child:children) {
            preorder_traversal(child, result);
        }
    }

    // iteratively
};

int main() {
    vector<Node *> children1;
    Node e, f;
    e.val = 5;
    f.val = 6;
    children1.push_back(&e);
    children1.push_back(&f);

    vector<Node *> children2;
    Node b, c, d;
    b.val = 3;
    c.val = 2;
    d.val = 4;
    b.children = children1;
    children2.push_back(&b);
    children2.push_back(&c);
    children2.push_back(&d);

    Node a;
    a.val = 1;
    a.children = children2;

    Solution solution;
    vector<int> result = solution.preorder(&a);

    for (auto i:result) {
        cout << i << " ";
    }
    return 0;
}