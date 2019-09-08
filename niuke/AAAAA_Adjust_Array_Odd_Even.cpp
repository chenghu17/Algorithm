//
// Created by Mr.Hu on 2019/9/7.
//
// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
// 所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
//
// 其实思路比较简单，从左往右遍历，一旦遇到奇数，则往前寻找偶数，遇到偶数则交换，直到遇到第一个奇数，则交换停止，即再往前都是奇数；、
// 交换完之后继续遍历，直到下一个奇数，再以同样的方式往前寻找偶数并交换，主循环遍历完，则奇数都排在偶数的前面，并且奇/偶数的相对位置没变
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int len = array.size();
        int k = -1;
        int tmp;
        for (int i = 0; i < len; ++i) {
            // 一旦遇到是奇数，则把前面的偶数后移，奇数插入第一个偶数的位置
            // k保存最近的一个奇数，为了后续不再对之前已经排过序的再次判断，初始值为-1
            if (array[i] % 2 == 1) {
                tmp = i;
                while (tmp > k) {
                    if (tmp == 0) {
                        break;
                    }
                    if (array[--tmp] % 2 == 0) {
                        swap(array[tmp], array[tmp + 1]);
                    } else {
                        k = tmp;
                        break;
                    }
                }
            }
        }
    }
};

int main() {
    vector<int> array = {3, 2, 5, 4, 6, 7, 9};
    Solution solution;
    solution.reOrderArray(array);
    for (auto it:array) {
        cout << it << " ";
    }
}