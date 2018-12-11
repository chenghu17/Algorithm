//
// Created by Mr.Hu on 2018/12/11.
//
// leetcode 257 binary tree paths
//
// 题目要求对于给定的二叉树，返回所有的路径（根节点到叶子节点）
//
// 这个题目的思路和之前112、113关于path sum差不多，都是去遍历树的所有路径。这里还需要保存每条路径，得到相应的string数组。
// 首先，还是可以将这个问题理解为DFS（深度优先搜索）、先序遍历的问题。使用非递归的方法，将访问的节点压栈，并且将
// 形如"->x"的字符串加入到path上，直到栈顶元素为叶子节点，则将当前的path记录到路径数组中。
// 然后将栈顶元素出栈，使用字符串取子串的方法，将后面2+top.size()个字符进行删除，这就保证了当前节点离开此时的路径时，路径的结果表示也去除了该部分。
// 由于我们回溯到上一个节点时，并没法判断其左儿子和右儿子是否已经访问过，为了避免重复访问，我们使用一个set（集合）来保存访问过的节点。
//

#include <iostream>
#include <set>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> result;
        if (!root) return result;
        if (!root->left && !root->right) {
            result.push_back(to_string(root->val));
            return result;
        }
        stack<TreeNode *> cur_node;
        set<TreeNode *> visited_node;
        string path = to_string(root->val);
        cur_node.push(root);
        while (!cur_node.empty()) {
            // do something
            TreeNode *top = cur_node.top();
            if (!top->left && !top->right) {
                result.push_back(path);
                path = path.substr(0, path.size() - 2 - to_string(cur_node.top()->val).size());
                cur_node.pop();

            } else if (top->left && !visited_node.count(top->left)) {
                visited_node.insert(top->left);
                cur_node.push(top->left);
                path = path + "->" + to_string(top->left->val);
            } else if (top->right && !visited_node.count(top->right)) {
                visited_node.insert(top->right);
                cur_node.push(top->right);
                path = path + "->" + to_string(top->right->val);
            } else {
                if (path.size() == 1) {
                    break;
                }
                path = path.substr(0, path.size() - 2 - to_string(cur_node.top()->val).size());
                cur_node.pop();
            }
        }
        return result;
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(12);
    TreeNode c(13);
    TreeNode d(5);
    a.left = &b;
    a.right = &c;
    b.right = &d;
    Solution solution;
    vector<string> paths = solution.binaryTreePaths(&a);
    for (auto it:paths) {
        cout << it << endl;
    }
    return 0;
}