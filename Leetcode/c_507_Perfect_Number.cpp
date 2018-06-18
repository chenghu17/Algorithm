//
// Created by Mr.Hu on 2018/6/18.
//
// leetcode 507 perfect number
//
//
//

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) {
            return false;
        }
        int middle = int(sqrt(num));
        int result = 0;
        for (int i = 1; i <= middle; ++i) {
            if (num % i == 0) {
                result = result + i + num / i;
            }
        }
        return result == num * 2;
    }
};

int main() {
    int num = 1020103;
    Solution solution;
    bool isPerfect = solution.checkPerfectNumber(num);
    cout << isPerfect << endl;
    return 0;
}