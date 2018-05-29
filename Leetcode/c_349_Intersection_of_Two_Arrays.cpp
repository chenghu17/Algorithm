//
// Created by Mr.Hu on 2018/5/21.
//
// leetcode 349 intersection of two arrays
//
// 题目要求对给定的两个字符串（列表）求其相同的元素
//
// 看到这个题目就想到最近做实验写的对recommended list与原结果做交集求precision的方法了
// 所以就想到使用python来实现，因为python中可以对两个set做&操作，即求交集，
// 最后返回结果的list形式。执行之后顺利通过，而且还超过来百分之九十六的accepted answer
//
// 稍后再同c++实现一下；
//
// 今天做到350时，想到了一种方法，其实不需要将两个vector转换为set后求交集，
// 因为在python中求set的交集时一个比较简单的事情，但是在c++中就没有那么容易了。
// 所以想到对两个vector先从小到大排序，然后依次进行比较，即三种情况，相等则存储在set中；
// 最后将set循环输出到vector中，return即可。
// 代码执行效率超过百分之九十八的accpted
//

// python
//class Solution:
//        def intersection(self, nums1, nums2):
//        """
//        :type nums1: List[int]
//        :type nums2: List[int]
//        :rtype: List[int]
//        """
//            num_1 = set(nums1)
//            num_2 = set(nums2)
//            result = num_1&num_2
//            return list(result)

#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int size1 = nums1.size();
        int size2 = nums2.size();
        int index1 = 0, index2 = 0;
        while (index1 < size1 & index2 < size2) {
            if (nums1[index1] == nums2[index2]) {
                result.insert(nums1[index1]);
                index1++;
                index2++;
            } else if (nums1[index1] < nums2[index2]) {
                index1++;
            } else {
                index2++;
            }
        }
        vector<int> tmp;
        for(auto it=result.begin();it!=result.end();it++){
            tmp.push_back(*it);
        }
        return tmp;
    }
};

int main(){
    vector<int> nums1 = {1, 2, 2, 3, 3, 4};
    vector<int> nums2 = {1, 2, 3};
    Solution solution;
    vector<int> result = solution.intersection(nums1, nums2);
    for(auto it = result.begin();it!=result.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}