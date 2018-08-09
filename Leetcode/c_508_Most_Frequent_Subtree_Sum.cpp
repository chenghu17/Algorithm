//
// Created by Mr.Hu on 2018/8/9.
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
        // 访问过的节点，即已经将其左右节点加入到stack中，如果下次访问到这个节点，就是计算其左右节点和该节点值的和
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