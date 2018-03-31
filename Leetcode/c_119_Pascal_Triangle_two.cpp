//
// Created by Mr.Hu on 2018/3/31.
//
// leetcode 119 Pascal's Triangle 2
// 做完 leetcode 118 然后再做这个题目，思路基本差不堵，只是输出不一样。
// 根据题目要求，O(K)的空间复杂度，于是想到题目要求的输出内容，只是最后一行的内容
// 而最后一行的值，只与上一行有关，所以只需要用一个vector tmp记录当前行，一个vector result记录上一行就行了。
// 在实际过程中，每一次循环的结果是下一次循环的上一行，这就需要把此时的tmp与上一次的result进行交换，然后继续进行循环。
// 所以就想到了vector所具有的一个方法，直接 result.swap(tmp)就可以交换，然后tmp.clear()释放内存，tmp继续保存继续循环的结果。
// 最后result与当前行的结果tmp进行交换，循环结束，返回result即可。
//
// 写完之后编译遇到了一个问题，就是我还没有从上一题的想法中出来，在int sum = result[j - 1] + result[j]中我继续沿用了result[i-2][j-1]...
// 此时就报错了，result哪里是二维向量哟，罪过罪过、糊涂糊涂...
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        vector<int> tmp;
        for (int i = 1; i <= rowIndex + 1; i++) {
            for (int j = 0; j < i; j++) {
                if (j == 0 || j == i - 1) {
                    tmp.push_back(1);
                } else {
                    int sum = result[j - 1] + result[j];
                    tmp.push_back(sum);
                }
            }
            result.swap(tmp);
            tmp.clear();
        }
        return result;
    }
};

int main() {
    int rowIndex = 3;
    Solution solution;
    vector<int> result = solution.getRow(rowIndex);
    vector<int>::iterator it;
    for (it = result.begin(); it < result.end(); it++)
        cout << *it << " ";
    return 0;
}