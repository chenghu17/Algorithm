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