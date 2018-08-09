//
// Created by Mr.Hu on 2018/8/9.
//
// leetcode 508 most frequent substree sum
//
// 题目要求，对于给定的二叉树结构，计算所有子树和中出现最多的那个数或那几个数
//
// 这个题目相当于到对每个子树求节点值的和，其中也包含根节点。
// 而想要求这个结构，需要使用depth-first-search的方法来遍历这一棵树。
// 1、使用循环的方法，先将当前节点放入stack中，如果当前节点存在子节点，则将其子节点放入栈中，
//  并将该节点标记为以及访问过的节点；如果不存在，则说明该节点为叶子节点，将叶子结点的值存入map中，并将其出现的次数加一。
//  如果当前节点已经被访问，则说明其左右子节点已经入过栈，此时再访问到这个节点时，就需要将其节点值和左右节点值加起来，
//  作为子树的和，并存储到map中，而且当前节点的val也要更新为此时的和，这样操作后，其父节点在计算子树和时，只需要加上
//  左右节点的值即可，因为此时左右节点的值各自代表了其子数的节点和。
//
// 2、这里可以明显看出有一种递归结构，即以当前节点为根的子树的节点和等于当前节点的值加上以左右节点为根的两棵子树的节点和。
// sum = dfs(root->left)+root->val+dfs(root->right)为递归式子
// 而且这里不存在重复计算，每个子树之前无交叉，所以递归的效率也很高
//

#include <iostream>
#include <stack>
#include <set>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        int max_sum = 1;
        map<int, int> count;
        // 使用DFS，因为是求子树上所有节点的和，不是只有左右子节点
        // 存储当前节点
        stack < TreeNode * > stack_nodes;
        // 访问过的节点，即已经将其左右节点加入到stack中，
        // 如果下次访问到这个节点，就是计算其左右节点和该节点值的和
        set < TreeNode * > set_nodes;
        stack_nodes.push(root);
        TreeNode *tmp;
        int sum = 0;
        while (!stack_nodes.empty()) {
            tmp = stack_nodes.top();
            if (!set_nodes.count(tmp)) {
                // 如果为非叶子节点，则将左右子节点加入stack_nodes中
                if (tmp->left != nullptr) {
                    stack_nodes.push(tmp->left);
                }
                if (tmp->right != nullptr) {
                    stack_nodes.push(tmp->right);
                }
                set_nodes.insert(tmp);
            } else {
                sum = tmp->val;
                if (tmp->left != nullptr) {
                    sum += tmp->left->val;
                }
                if (tmp->right != nullptr) {
                    sum += tmp->right->val;
                }
                count[sum] += 1;
                tmp->val = sum;
                sum = 0;
                stack_nodes.pop();
            }
        }

        for (auto it = count.begin(); it != count.end(); ++it) {
            if (it->second == max_sum) {
                result.emplace_back(it->first);
            } else if (it->second > max_sum) {
                max_sum = it->second;
                result.clear();
                result.emplace_back(it->first);
            }
        }
        return result;
    }
};

int main(){
    TreeNode a(5);
    TreeNode b(1);
    TreeNode c(-5);
    a.left = &b;
    a.right = &c;
    Solution solution;
    vector<int> result = solution.findFrequentTreeSum(&a);
    for(auto it:result){
        cout<<it<<" ";
    }
    return 0;
}