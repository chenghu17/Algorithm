//
// Created by Mr.Hu on 2018/7/27.
//
// leetcode 875 koko eating banana
//
// 这个题目和面试中遇到的题型很类似，以故事的形式来呈现。
// 题目已知有n堆香蕉，每堆中香蕉数目为piles[i]，现在管理员要出去H个小时，
// 问koko最少每小时吃多少个香蕉，才能保证在管理员回来之前吃完所有香蕉。
// （每堆香蕉吃完后如果一个小时还没结束，koko不能吃其他堆香蕉）
//
// 这个题目的思路主要在于如何去寻找这个最小的k，使得koko吃完所有香蕉的时间在H小时内；
// 因为 piles.length <= H ，我们可以得到，如果两者相等，则最小的k即为piles中最大数
// 接下来我们就需要在1～piles.max中去寻找最小的k，使得吃完所有香蕉时间<=H,
// 我们可以发现待搜索的列表为有序列表，所以我们可以使用二分搜索去找到这样一个k值；
// 一旦当前所花时间大于H，则说明当前k值不够，左边界l=middle+1，继续查找
// 如果小于等于H，则说明当前k值满足条件，求min_k = min(middle,min_k)；且此时可以继续搜索是否存在更小的k值，
// 即右边界r=middle-1。整个迭代过程的判断条件是while(l<=r)
// 最后输出min_k即为所求。
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int H) {
        int size = piles.size();
        auto max_elemt = max_element(piles.begin(), piles.end());
        int max_piles = *max_elemt;
        int l = 1, r = max_piles, middle, min_k = max_piles, count_k = 0;
        if (size == H) {
            return min_k;
        }
        while (l <= r) {
            middle = l + (r - l) / 2;
            for (auto i:piles) {
                if (i <= middle) {
                    ++count_k;
                } else {
                    count_k += ceil(i * 1.0 / middle);
                }
            }
            if (count_k > H) {
                l = middle + 1;
            } else {
                min_k = min(middle, min_k);
                r = middle - 1;
            }
            count_k = 0;
        }
        return min_k;
    }
};

int main() {
    vector<int> piles;
    piles.emplace_back(30);
    piles.emplace_back(11);
    piles.emplace_back(23);
    piles.emplace_back(4);
    piles.emplace_back(20);
    int H = 6;
    Solution solution;
    int min_k = solution.minEatingSpeed(piles, H);
    cout << min_k << endl;
    return 0;
}