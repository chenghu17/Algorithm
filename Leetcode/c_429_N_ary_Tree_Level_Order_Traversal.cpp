//
// Created by Mr.Hu on 2018/12/12.
//
// leetcode 429 n ary tree level order traversal
//
// 题目给定一个n叉树，要求对其进行逐层遍历，从左到右，从上到下。
//
// n叉树每个节点的孩子节点为一个vector<Node*>，所以我们在使用类似于二叉树的BFS时，要注意队列中保存的是节点列表
// 这里同样使用队列来存储接下来需要访问的节点，用两个int来保存当前层的列表数和下一层的列表数。
// 当当前层所有的节点列表都被访问完后，则交换当前层树和下一层树，继续上述循环。
// 每一层结束后将该层所有节点值列表加入到结果集中，然后清除当前层的结果用来存储接下来一层的结果值。
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// definition for a node
class Node {
public:
    int val = NULL;
    vector<Node *> children;

    Node() {}

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> result;
        vector<int> every_layer;
        if (!root) {
            return result;
        }
        every_layer.push_back(root->val);
        result.push_back(every_layer);
        if ((root->children).size() == 0) {
            return result;
        }
        queue<vector<Node *>> nodes;
        int cur_layer = 1, next_layer = 0;
        nodes.push(root->children);
        every_layer.clear();
        vector<Node *> cur;
        while (cur_layer || next_layer) {
            if (cur_layer != 0) {
                cur = nodes.front();
                nodes.pop();
                cur_layer--;
                for (auto node:cur) {
                    every_layer.push_back(node->val);
                    if ((node->children).size() != 0) {
                        nodes.push(node->children);
                        next_layer++;
                    }
                }
            }
            if (cur_layer == 0) {
                swap(cur_layer, next_layer);
                result.push_back(every_layer);
                every_layer.clear();
            }
        }
        return result;
    }
};

int main() {
    Node b, c, d, e, f;
    b.val = 1;
    c.val = 2;
    d.val = 3;
    e.val = 4;
    f.val = 5;
    vector<Node *> children;
    children.push_back(&b);
    children.push_back(&c);
    children.push_back(&d);
    children.push_back(&e);
    children.push_back(&f);
    Node a(12, children);
    Solution solution;
    vector<vector<int>> result = solution.levelOrder(&a);
    for (auto layer:result) {
        for (auto i:layer) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}