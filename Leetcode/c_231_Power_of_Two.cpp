//
// Created by Mr.Hu on 2018/6/4.
//
// leetcode 231 power of two
//
//


#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        while (n != 1) {
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n = 32;
    Solution solution;
    bool isornot = solution.isPowerOfTwo(n);
    cout << isornot << endl;
    return 0;
}