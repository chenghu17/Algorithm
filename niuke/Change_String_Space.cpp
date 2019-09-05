//
// Created by Mr.Hu on 2019/9/5.
//
// 请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
//
// 这个题目给的函数的返回类型为void，且给定的字符串为char*类型，不能直接按照string类型来使用；
// 对于char*，可以理解是char[]的指针，而且char[]即字符数组，对于其中的空格替换，意味着数组实际大小会增加。
// 解题思路：先统计所有空格的个数，然后从字符串最后开始移动字符串，因为字符串最后增加的大小即空格数的两倍，从最后开始移动时间复杂度会比较小；
// 一旦遇到空格，则降空格转换为题目要求的'%20'，注意，不能直接赋值，因为是字符数组，所以需要每一位单独赋值。
// 当然也可以从前向后移动，但是后面的字符串会移动多次，时间复杂度会增加很多。
//

#include <iostream>

using namespace std;

class Solution {
public:
    void replaceSpace(char *str, int length) {
        int space_count = 0;
        for (int i = 0; i < length; ++i) {
            if (str[i] == ' ') {
                space_count += 1;
            }
        }
        for (int i = length - 1; i >= 0 && space_count > 0; --i) {
            if (str[i] == ' ') {
                str[i + space_count * 2] = '0';
                str[i + space_count * 2 - 1] = '2';
                str[i + space_count * 2 - 2] = '%';
                --space_count;
            } else {
                str[i + space_count * 2] = str[i];
            }
        }
    }
};

int main() {
    char str[] = " ";

    Solution solution;
    solution.replaceSpace(str, 11);

    cout << str << endl;
}