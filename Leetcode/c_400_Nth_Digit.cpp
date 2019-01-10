//
// Created by Mr.Hu on 2019/1/10.
//
//
//
//
//
//
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int num_length = 1; // 表示每个数字的长度
        int num_size = 9;   // 表示这个长度的数字总共有多少个

        while (n / (num_size + 1) >= num_length) {
            n -= num_length * num_size;
            num_length++;
            num_size *= 10;
        }

        int next = n % num_length;
        int num = n / num_length;
        if (next == 0) {
            num = num - 1;
            next = num_length;
        }

        int begin = num_size / 9;
        string cur_number = to_string(begin + num);

        return cur_number[next - 1] - 48;
    }
};

int main() {
    int n = 2147483647;
    Solution solution;
    int digit = solution.findNthDigit(n);
    cout << "the digit is " << digit << endl;
    return 0;
}