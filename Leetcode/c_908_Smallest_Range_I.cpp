//
// Created by Mr.Hu on 2019/1/31.
//
// leetcode 908 smallest range I
//
// 题目给定一个数组A，和一个数值K，要求选择x，从区间[-k,k]，加入到数组A[i]，得到数组B，使得数组B中的最大值和最小值距离最小。
//
// 由于加入到A[i]中的值不一定相等，所以可以灵活的加入，因为距离是两个值差值的绝对值，最小为0。
// 这就使得我们可以选择A中最大值和最小值，然后判断其差值和2k的大小关系，其他的值无所谓，因为加入到每个值上的结果不固定，保证
// 当前最大值最小值之前的距离最小后，其他的距离只会更小。
// 因此如果现在距离大于2k，那么最终B的最小距离为原距离-2k，如果小于2k，那么最小距离为0。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int> &A, int K) {
        auto max_idx = max_element(A.begin(), A.end());
        auto min_idx = min_element(A.begin(), A.end());
        if (*max_idx - *min_idx <= 2 * K) {
            return 0;
        } else {
            return *max_idx - *min_idx - 2 * K;
        }
    }
};

int main() {
    vector<int> A = {1, 2, 3, 6, 8};
    int K = 4;
    Solution solution;
    int max_dis = solution.smallestRangeI(A, K);
    cout << "array B max distance = " << max_dis << endl;
    return 0;
}