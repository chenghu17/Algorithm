//
// Created by Mr.Hu on 2019/9/7.
//
// 华为软件题模拟题2：对给定数组进行排序，且每个数字只能和0交换，题目给定对应数字与0交换的方法；
//
// 长度为n的数组乱序存放着0至n-1. 现在只能进行0与其他数的交换，完成以下函数
// swap_with_zero(...)是一个调用接口，直接使用。
//
// 相当于冒泡，只是每次需要先讲0移动到当前子数组的最后一个
//

#include <iostream>

using namespace std;

/**
 * 交换数组里n和0的位置
 * array: 存储[0-n)的数组
 * len: 数组长度
 * n: 数组里要和0交换的数
 */

extern void swap_with_zero(int *array, int len, int n);

class Solution {
public:
    /**
     * 调用方法swap_with_zero来对array进行排序
     */
    void sort(int *array, int len) {
        for (int i = len; i > 0; --i) {
            // 0与当前最后一个交换
            swap_with_zero(array, len, array[i - 1]);
            for (int j = 0; j < i; ++j) {
                if (array[j] == i - 1) {
                    swap_with_zero(array, len, array[j]);
                    break;
                }
            }
        }
    }
};