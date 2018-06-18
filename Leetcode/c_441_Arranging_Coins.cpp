//
// Created by Mr.Hu on 2018/6/18.
//
// leetcode 441 arranging coins
//
//
//



#include <iostream>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int k = 0;
        int result = 0;
        while (n - k >= 0) {
            n -= k;
            ++k;
        }
        return --k;
    }
};

int main() {
    int n = 111111111;
    Solution solution;
    int k = solution.arrangeCoins(n);
    cout << k << endl;
    return 0;
}