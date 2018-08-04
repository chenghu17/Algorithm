//
// Created by Mr.Hu on 2018/8/4.
//
// leetcode 450 delete node in a BST
//
// 题目要求在BST（二叉搜索树）中删除val==key的节点，并返回删除节点后新的BST的root node
//
// 要想实现这样一个操作，需要进行两步，首先需要遍历BST判断是否存在这样的节点，根据BST的特点，
// 实际使用的是二分搜索方法去定位这样一个节点。
// 首先，如果这个不存在，则直接返回原树的根节点root；
// 如果节点存在，且节点是叶子节点，则直接删除这个节点即可；
// 如果节点存在，但是不是叶子节点，当我们删除这个节点后，此时BST的结构被破坏，我们需要更新这个
// BST，而更新的方法就是找到删除节点右边子数中最左叶子节点，将这个节点移动到当前删除的节点的位置，
// 并将该节点的右子树分配给其父节点当作左子树，这就能够保证BST的特性。
//
//
// 这个题目的代码我写的很多，分了几个函数来实现，我在解答完这个题目之后，想到了无需如此复杂的代码实现，
// 其实对于节点的交换和删除，我们没有必要去将节点真正重新连接，有时候我们只需要交换两个node的val值就可以了。
// 在以后类似的题目中进行实现。
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