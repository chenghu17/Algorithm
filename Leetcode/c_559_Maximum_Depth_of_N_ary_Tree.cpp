//
// Created by Mr.Hu on 2018/12/17.
//
// leetcode 559 maximum depth of n ary tree
//
// 题目要求对于给定的n叉树，查找其最大的深度。
//
// 这个题目的思路可以用二叉树求最大深度的方式进行求解。基本思想也就是对与从根节点出发的每一条路径进行遍历，然后返回最长的路径。
// 这里使用递归的方式，进行DFS（深度优先搜索），每次对当前节点的儿子节点进行遍历，取其儿子节点中最长的路径进行返，利用递归的方式，
// 返回至根节点即可，根节点得到的结果即为这颗多叉树的最长深度。
// 递归的方式实现起来比较简答，但是执行效率并不到，下面的solution只超过了百分之十一的accpted solution。
//
// 另外，我们也可以使用非递归的方式进行求解。因为DFS本身就可以有递归方式和非递归方式（循环方式）
// 循环方式可以模仿429，对多叉树进行广度优先搜索的方式，只是这里我们使用深度优先所有，即用stack（栈）来存储待访问元素。
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
    int maxDepth(Node *root) {
        if (!root) {
            return 0;
        }
        return depth(root->children) + 1;
    }

    int depth(vector<Node *> child) {
        int max_depth = 0;
        if (child.size() == 0) {
            return 0;
        }
        for (auto i:child) {
            max_depth = max(max_depth, depth(i->children) + 1);
        }
        return max_depth;
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
    int max_depth = solution.maxDepth(&a);
    cout << "max depth = " << max_depth;
    return 0;
}