//
// Created by Mr.Hu on 2018/4/21.
//
// leetcode 661 image smoother
//
// 题目要求对一个图片的灰度值求平均，每一个灰度值与其周围的八个灰度有关，如果是在边线上，相关的灰度值尽量多，
// 最后输出求平均后的灰度值
//
// 刚开始做这题，想的很复杂，想着先要分对角，边框，以及内部，然后分别进行计算，需要用到很多的if-else；
// 后来发现还会出现单行或者单列，觉得自己的方法不合适，允许来一下我的方法时间复杂度也太高了，
// 于是就去网上找了带技巧的方法，正如下面的code，虽然只beat了百分之八左右的人，但是这种方法在实现上还是很
// 简单的。其思想大概是这样：对于一个点，与其相关的点无非就是上下左右以及斜对角，那么在坐标上表示都是
// x与y进行[+1,-1,0]三种操作后可达，所以遍历原图像中的灰度值点，对其周围的坐标遍历取得，然后进行判断，
// 判断坐标x,y是否在数组范围内，如果在，则加入到current中，最后取平均，将平均值赋值给新数组相同的坐标位置。
// 这种策略值得学习，遇到那种一个正方形网格里面计算要求的，也可以用到，用坐标来判断该值是否存在，
// 而不是分多种情况再来分开求和，这样就想到复杂。
//
// 另外，vector初始化也值得学习！ vector<int> result(m,vector<int>(n))，初始二维数组。
//
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
        int m = M.size();
        int n = M[0].size();
        vector<vector<int>> result(m, vector<int>(n));
        int range[] = {-1, 0, 1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int current = 0;
                int count = 0;
                for (int a : range) {
                    for (int b : range) {
                        int row = i + a;
                        int col = j + b;
                        if (row >= 0 && row < m && col >= 0 && col < n) {
                            current += M[row][col];
                            count++;
                        }
                    }
                }
                result[i][j] = (int) floor((double) current / count);
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> M = {{1, 1, 1},
                             {1, 0, 1},
                             {1, 1, 1}};
    Solution solution;
    vector<vector<int>> result = solution.imageSmoother(M);
    return 0;

}