//
// Created by Mr.Hu on 2018/12/24.
//
// leetcode 590 n ary tree postorder traversal
//
// 题目要求对N叉树进行后序遍历
//
// 这里使用递归的方式进行遍历，类似于二叉树的后序遍历，只是在处理节点上，需要先循环访问节点的孩子节点，再访问当前节点。
// 使用循环的方式进行实现同样需要借助栈(stack)来进行，这里不再重复。
// 这里循环的方式和先序有一点不同，在于对节点进行访问后，每次访问孩子节点后，
// 需要将节点的孩子节点置为nullptr（具体操作应该是将vector<Node*> children进行pop清空操作）
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
    vector<int> postorder(Node *root) {
        vector<int> result;
        postorder_traversal(root, result);
        return result;
    }

    void postorder_traversal(Node *node, vector<int> &result) {
        if (!node) {
            return;
        }
        vector<Node *> children = node->children;
        for (auto child:children) {
            postorder_traversal(child, result);
        }
        result.push_back(node->val);
    }
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
    vector<int> result = solution.postorder(&a);

    for (auto i:result) {
        cout << i << " ";
    }
    return 0;
}