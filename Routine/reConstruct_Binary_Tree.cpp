//
// Created by Mr.Hu on 2019/2/28.
//
// 给定二叉树的前序和中序遍历，重建该树，或者是求该树的后序遍历。
//
// 根据前序和中序遍历，重新建立树，基本步骤是从前序遍历第一个节点开始，即二叉树的根节点，在中序遍历中找到该节点，
// 该节点左边的所有值即位其左子树，而其右边所有值即为该节点的右子树。
// 左边子树节点的个数知道后，我们便可以顺推得到左子树的前序遍历，也可以得到右子树的前序遍历。
// 经过上面的操作，我们得到了根节点，左子树的前序和中序遍历，右子树的前序和中序遍历。
// 这就和原来的问题一样，相同的解答，所以我们这里可以利用递归的方式，层层建立，最后返回根节点即可。
//
// 值得注意的是：从前序遍历找到中序遍历中根节点位置，然后反推左边子树的前序遍历范围 和 右边子树的前序遍历范围这是一个关键点。
//


#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *build(vector<int> &pre, int p_l, int p_r, vector<int> &vin, int v_l, int v_r) {
        // 找到pre[p_l]在vim中的位置
        TreeNode *cur = new TreeNode(pre[p_l]);
        if (p_l == p_r) {
            return cur;
        }
        int count = 0;
        for (int i = v_l; i <= v_r; i++) {
            if (vin[i] == pre[p_l]) {
                count = i - v_l;
            }
        }
        //
        if (count == 0) {
            cur->right = build(pre, p_l + 1, p_r, vin, v_l + 1, v_r);
        } else if (v_l + count == v_r) {
            cur->left = build(pre, p_l + 1, p_r, vin, v_l, v_r - 1);
        } else {
            cur->left = build(pre, p_l + 1, p_l + count, vin, v_l, v_l + count - 1);
            cur->right = build(pre, p_l + count + 1, p_r, vin, v_l + count + 1, v_r);
        }
        return cur;
    }

    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        TreeNode *root = build(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
        return root;
    }
};

int main() {
    vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> vin = {4, 7, 2, 1, 5, 3, 8, 6};
    Solution solution;
    TreeNode *root = solution.reConstructBinaryTree(pre, vin);
    return 0;
}