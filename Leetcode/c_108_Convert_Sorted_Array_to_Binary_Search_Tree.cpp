//
// Created by Mr.Hu on 2018/12/9.
//
// leetcode 108 convert sorted array to binary search tree
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    TreeNode* ArrayToBST(vector<int>& nums,int begin,int end){
        if(begin>end){
            return nullptr;
        }
        int middle = (begin + end)/2;
        TreeNode* root = new TreeNode(nums[middle]);
        root->left = ArrayToBST(nums,begin,middle-1);
        root->right = ArrayToBST(nums,middle+1,end);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int nums_size = nums.size();
        TreeNode* root =  ArrayToBST(nums,0,nums_size-1);
        return root;
    }
};

int main(){
    vector<int> nums;
    nums.push_back(-10);
    nums.push_back(-8);
    nums.push_back(-1);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(13);
    Solution solution;
    TreeNode* root = solution.sortedArrayToBST(nums);
    // 输出该平衡二叉搜索树
    return 0;
}