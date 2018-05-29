//
// Created by Mr.Hu on 2018/5/29.
//
// leetcode 350 intersection of two arrays 2
//
// 题目要求求两个数组中相同的元素，不是349中的集合。
//
// 刚开始想的很复杂，想着要将两个vector中出现的数字以及其个数用map<int,int>
// 存储起来，然后分别比较map中相同key值所对应的value值，再循环输出到vector结果中。
// 觉得太麻烦，于是想到另外一种方法：要想求所有共同存在的元素，只需要比较nums1和nums2，
// 判断元素是否相同。但是如果每个数分别比较，一方面复杂度高，另一方面会出现重复比较的情况。
// 所以为了解决这个问题，想到可以先对两个vector进行排序，排序之后依次进行比较，
// 两个vector分别维护自己的索引值index1和index2，从0开始，如果两个数相等，则将该数字加入到result中，同时index1和index2都加1
// 如果vector<index1> < vector<index2>，则index1++，index2不变，因为当前index2所指向的数字更大，index1++后可能出现相等。
// 如果vector<index1> > vector<index2>，则index1不变，index2++，道理同上。
// 一旦任何一个vector迭代完，循环结束，return result。
//


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int size1 = nums1.size();
        int size2 = nums2.size();
        int index1 = 0, index2 = 0;
        while (index1 < size1 & index2 < size2) {
            if (nums1[index1] == nums2[index2]) {
                result.push_back(nums1[index1]);
                index1++;
                index2++;
            } else if (nums1[index1] < nums2[index2]) {
                index1++;
            } else {
                index2++;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 2, 3, 3, 4};
    vector<int> nums2 = {1, 2, 3, 4};
    Solution solution;
    vector<int> result = solution.intersect(nums1, nums2);
    for(auto it = result.begin();it!=result.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}