//
// Created by Mr.Hu on 2019/1/23.
//
// leetcode 977 squares of a sorted array
//
// 题目给定一个非降序排列的数组，要求对每个数取平方，最后的结果也是一个非降序的数组
//
// 这个题目主要需要关注的地方就是负值平方后可能比正数大。而题目给定的数组已经排序好的，
// 所以这里可以使用两个指针的方法，对起始点进行判断，哪个的绝对值大，则平方后加入到结果集合中，
// 如果是left大，则left++，否则，right--，直到left>right则循环结束。
// 但是上述操作得到的结果是非递增的数组，我们这里要求的结果是非递减，所以这里使用reverse函数对vector<int> res进行翻转，得到结果。
//
// 注：当要求从小到大比较难操作时，可以逆向思维，先得到从大到小，然后再翻转结果，即为题目所求。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int> &A) {
        int left = 0, right = A.size() - 1;
        vector<int> res;
        if (A[0] >= 0) {
            for (auto i:A) {
                res.push_back(i * i);
            }
        } else if (A[right] <= 0) {
            for (int i = right; i >= 0; i--) {
                res.push_back(A[i] * A[i]);
            }
        } else {
            while (left <= right) {
                if (abs(A[left]) > abs(A[right])) {
                    res.push_back(A[left] * A[left]);
                    left++;
                } else {
                    res.push_back(A[right] * A[right]);
                    right--;
                }
            }
            reverse(res.begin(), res.end());
        }
        return res;
    }
};

int main() {
    vector<int> A = {-4, -2, 1, 4, 6};
    Solution solution;
    vector<int> res = solution.sortedSquares(A);
    for (auto i:res) {
        cout << i << " ";
    }
    return 0;
}