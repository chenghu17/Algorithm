//
// Created by Mr.Hu on 2018/12/9.
//
// leetcode 108 convert sorted array to binary search tree
//
// 题目要求对于给定已排序的数组，转换为平衡的二叉搜索树
//
// 这个题目的思想有点像二分搜索，每次找出中间的值当作子树的根节点，使用递归的方法自顶向下构建该树。
// 每次选择中位数当作二叉树的跟节点，以此来保证二叉搜索树是平衡的。
// 这个题目的做法和树的深度优先搜索的递归方法比较像
//
// 在这个题目的coding中，发现了一个问题，就是我在创建TreeNode时，最后返回的TreeNode每次都是空值，
// 最开始，我在ArrayToBST()方法中使用的TreeNode root = TreeNode(val)来创建，在最后的返回语句中使用return &root，
// 但是最终的主函数中拿到的总是nullptr。
// 这里就隐含着一个变量存储位置的情况：
// 1、不使用new得到的变量，作用域限制在定义类对象的方法中，当方法结束时，类对象也被系统释放了，这种方法安全，不会造成内存系统泄漏。存放在栈中
// 2、使用new得到的变量，创建的是指向类对象的指针，作用域变成了全局，当程序结束时，必须使用delete删除，系统不会自动释放。存放在堆中
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