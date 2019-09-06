//
// Created by Mr.Hu on 2019/9/6.
//

#include <iostream>
#include <time.h>

using namespace std;

class Solution {
public:
    int Fibonacci_(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }

    int Fibonacci(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        int first = 0, second = 1, cur = 0;
        n -= 2;
        while (n >= 0) {
            cur = first + second;
            first = second;
            second = cur;
            n -= 1;
        }
        return cur;
    }

};

int main() {
    auto start = time(nullptr);
    Solution solution;
    cout << solution.Fibonacci(7) << endl;
    auto end = time(nullptr);
    cout << end - start << endl;
    return 0;
}