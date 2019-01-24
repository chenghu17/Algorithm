//
// Created by Mr.Hu on 2019/1/24.
//
// leetcode 976 largest perimeter triangle
//
// 题目给出一个数组，每个值表示可选边长，要求从这个数组中找出三个值，使其能构成三角形三条边，且三角形周长最大。
//
// 首先，既然我们需要去寻找周长最大三角形，那么我们需要去找到合适的三条边，蛮力的解决方案就是遍历每一种情况，最后得到满足条件的最大周长。
// 但是，其中有些不能构成三角形的情况，我们没有很好的减少计算次数。
// 这里我采用的方法是先讲数组排序，从最后三个数依次往前，如果当前三个数不能构成三角形，那么可以直接丢弃掉最后一个数，因为不能构成三角形
// 肯定是某两边之和小于等于第三边，而最后一个数字为最大值，所以肯定最后一个数字肯定是第三边，一旦不能构成三角形，则其与比现在另外两个数
// 更小的数字就越发不能构成三角形。但是一旦可以构成三角形，则该三角形为最大周长三角形。
//
// 在这里构建三角形，因为我们知道了三角形三边的大小关系，我们只需要判断较小两边与第三边的大小关系，而不需要判断任意两条边和第三边的关系。
// 这很好理解，无效多解释。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int> &A) {
        int largest = 0;
        sort(A.begin(), A.end());
        int a, b, c;
        for (int i = A.size() - 1; i - 2 >= 0; i--) {
            a = A[i];
            b = A[i - 1];
            c = A[i - 2];
            if (b + c > a) {
                largest = a + b + c;
                break;
            }
        }
        return largest;
    }
};

int main() {
    vector<int> A = {1, 3, 5, 2, 6};
    Solution solution;
    int larget = solution.largestPerimeter(A);
    cout << "largest perimeter " << larget << endl;
    return 0;
}