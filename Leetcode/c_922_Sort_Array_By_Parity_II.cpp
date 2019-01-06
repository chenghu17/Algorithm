//
// Created by Mr.Hu on 2019/1/6.
//
// leetcode 922 sort array by parity II
//
// 题目要求对给定的数组进行排序，其中index值为偶数的位置，其对应的值也是偶数；index值为奇数的位置，其对应的值也为奇数。
//
// 该题目是905的变形版本。同样使用两个变量来表示当前已经到达的奇数位和偶数位置；
// 遍历给定的数组A，创建新的数组B，以A的大小进行初始化。
// 遍历A，如果为偶数，则加到当前的偶数位置，否则，加入到奇数位置，然后更新下一个目标位置
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int> &A) {
        vector<int> B(A.size(), 0);
        int odd = 1, even = 0;
        for (auto i:A) {
            if (i % 2 == 0) {
                B[even] = i;
                even += 2;
            } else {
                B[odd] = i;
                odd += 2;
            }
        }
        return B;
    }
};

int main() {
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    Solution solution;
    vector<int> B = solution.sortArrayByParityII(A);
    for (auto i:B) {
        cout << i << " ";
    }
    return 0;
}