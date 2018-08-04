//
// Created by Mr.Hu on 2018/8/4.
//
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
    // 重构子树并返回重构后子树的根节点
    TreeNode *reConstruct(TreeNode *left, TreeNode *right) {
        if (left == nullptr || right == nullptr) {
            return left == nullptr ? right : left;
        }
        if (right->left == nullptr) {
            right->left = left;
            return right;
        }
        TreeNode *tmp = right->left;
        TreeNode *father = right;
        while (tmp != nullptr) {
            if (tmp->left != nullptr) {
                father = tmp;
                tmp = tmp->left;
            } else {
                father->left = tmp->right;
                tmp->left = left;
                tmp->right = right;
                break;
            }
        }
        return tmp;
    }

    bool isLeafNode(TreeNode *current) {
        if (current->left != nullptr || current->right != nullptr) {
            return false;
        }
        return true;
    }


    TreeNode *findKeyNode(TreeNode *root, int key) {
        TreeNode *fatherNode = nullptr;
        TreeNode *currentNode = root;
        bool flag = false;
        while (currentNode != nullptr) {
            if (currentNode->val == key) {
                flag = true;
                break;
            } else if (currentNode->val > key) {
                fatherNode = currentNode;
                currentNode = currentNode->left;
            } else {
                fatherNode = currentNode;
                currentNode = currentNode->right;
            }
        }
        if (!flag) {
            return nullptr;
        }
        if (!isLeafNode(currentNode)) {
            return fatherNode;
        } else if (fatherNode->left == currentNode) {
            fatherNode->left = nullptr;
            delete currentNode;
            return nullptr;
        } else {
            fatherNode->right = nullptr;
            delete currentNode;
            return nullptr;
        }
    }

    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr) {
            return root;
        }
        TreeNode *fatherNode;
        TreeNode *resultNode;
        if (root->val == key) {
            // keyNodeFather = nullptr;
            resultNode = reConstruct(root->left, root->right);
            return resultNode;
        } else {
            fatherNode = findKeyNode(root, key);
            // 没有等于key这样的节点 或者这样的节点为根节点
            if (fatherNode == nullptr) {
                return root;
            }
                // key这样的节点在左节点
            else if (fatherNode->left != nullptr && fatherNode->left->val == key) {
                resultNode = reConstruct(fatherNode->left->left, fatherNode->left->right);
                delete fatherNode->left;
                fatherNode->left = resultNode;
            }
                // key这样的节点在右节点
            else {
                resultNode = reConstruct(fatherNode->right->left, fatherNode->right->right);
                delete fatherNode->right;
                fatherNode->right = resultNode;
            }
            return root;
        }
    }
};

int main(){
    TreeNode a(5);
    TreeNode b(3);
    TreeNode c(6);
    TreeNode d(2);
    TreeNode e(4);
    TreeNode f(7);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    Solution solution;
    TreeNode* resultRoot = solution.deleteNode(&a,3);
    return 0;
}