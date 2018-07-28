//
// Created by Mr.Hu on 2018/7/28.
//
// 题目要求在给定数组中，找出第一个未出现在 >=1的连续数列中的整数
//
// 由于题目求数组中第一个未在>=1连续数列中出现的整数，这里我们可以将每个整数与数组的索引值对应：
// 数组的第一个数，对应1，以此类推，即如果位置i的所对应的数存在，那么位置i的数应该为i；
//
// 由于数组的index值从0开始，即nums[i]==i+1才是代码中真正的条件。
// 具体思想就是对数组进行遍历，如果当前nums[i]<1或者>nums.size()，则将当前nums[i]与nums[size-1]进行交换，
// 并将数组的length--，即此时最后一位为nums[length-1]，这样做的原因是，如果当前数比1小，这个数我们不关心，
// 所以和最后一位交换之后，用length-1的方式来"丢掉"这个数；如果这个数比length大，则说明前面肯定存在比该数小的
// 整数没有出现，所以当前这个数我们也可以不考虑。
// 如果当前这个数nums[i]与i+1能够对应，则说明这个整数存在，此时i++；
// 如果不对应，则nums[i]与nums[nums[i]-1]进行交换，将nums[i]放到它本应该对应的位置当中；
// 重复上述操作，直到i==length，则说明index为i的数没有出现，且是1之后连续数列中第一个没出现的数，
// 由于index为i的数其实为i+1，所以最后return i+1。
//
// 这个题目使用的是循环不变式：如果某个命题初始为真，则每次更改后仍然保持该命题为真，则若干次更改后仍然为真。
// 思路：从开始位置将找到的元素放在正确位置上，如果最终发现某个元素一直没有找到，则还元素即为所求。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int FindTheFirstLackInteger(vector<int>& nums){
        int length = (int)nums.size();
        int i=0;
        while(i<length){
            if(nums[i]>length || nums[i]<1){
                swap(nums[i],nums[length-1]);
                --length;
            }
            else if(nums[i] == i+1){
                ++i;
            }
            else{
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        return i+1;
    }
};

int main(){
    vector<int> nums;
    nums.emplace_back(1);
    nums.emplace_back(3);
    nums.emplace_back(11);
    nums.emplace_back(19);
    nums.emplace_back(52);
    nums.emplace_back(6);
    Solution solution;
    int lack_integer = solution.FindTheFirstLackInteger(nums);
    cout<<lack_integer;
    return 0;
}