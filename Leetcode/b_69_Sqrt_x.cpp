//
// Created by Mr.Hu on 2018/6/25.
//
// leetcode 69 sqrt x
//
// 
//

#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) {
            return 1;
        }
        long left = 0;
        long right = x / 2;
        long mid;
        while (left <= right) {
            mid = (left + right) / 2;
            long result = mid * mid;
            if (result == x) {
                return mid;
            } else if (result < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left - 1;
    }
};

int main() {
    int x = 100;
    Solution solution;
    int result = solution.mySqrt(x);
    cout << result << endl;
    return 0;
}