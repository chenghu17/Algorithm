//
// Created by Mr.Hu on 2019/1/30.
//
// leetcode 970 powerful integers
//
// 题目给定两个基数x，y，一个上界bound，要求得到所有x^i+y^j值，该值小于等于bound，其中i,j>=0
//
// 这个题目最直接的解法就是对i和j进行迭代累加，两个while循环嵌套。
// 但是存在一个问题，上面这种方式会一直循环，直到i或j大于bound，一旦x或y有一个为1，那么就是死循环。
// 所以我们需要判断x和y的取值，如果两者都是1，则x^i+y^j的结果只可能为2，然后判断2和bound的大小关系；
// 如果只有一个为1，那么只有一层循环，对i或者j进行累乘，结果判断其与bound的大小关系。
// 这个数值类型的题目就得考虑清楚边缘条件。
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> power;
        set<int> res;
        int i = 1, j = 1;
        if (x == 1 && y == 1) {
            if (2 <= bound) {
                res.insert(2);
            }
        } else if (x == 1) {
            while (i + j <= bound) {
                res.insert(i + j);
                j *= y;
            }
        } else if (y == 1) {
            while (i + j <= bound) {
                res.insert(i + j);
                i *= x;
            }
        } else {
            while (true) {
                if (i > bound) {
                    break;
                }
                while (true) {
                    if (i + j > bound) {
                        break;
                    }
                    res.insert(i + j);
                    j *= y;
                }
                i *= x;
                j = 1;
            }
        }

        for (auto i:res) {
            power.push_back(i);
        }
        return power;
    }
};

int main() {
    Solution solution;
    vector<int> p = solution.powerfulIntegers(2, 3, 16);
    for (auto i :p) {
        cout << i << " ";
    }
    return 0;
}