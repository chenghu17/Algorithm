//
// Created by Mr.Hu on 2018/12/17.
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