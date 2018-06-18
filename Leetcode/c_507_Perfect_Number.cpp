//
// Created by Mr.Hu on 2018/6/18.
//
// leetcode 507 perfect number
//
// 题目定义了perfect number的概念，即对于非负数，除其自身外，所有因数的和等于其本身的数，即为perfect number
//
// 所以我们得找出其所有的因数，并将所有的因数累加然后判断其与num是否相等。
// 而找出所有的因数，我们直到只需要循环判断num%i==0的情况，并且i的取值范围只需要是[1,sqrt(num)]
// 所以只要num%i==0成立，则result = result + i + num / i;
// 由于题目要求求和部分不能包含num本身，而result是包含了num自身的，所以我们在最后判断的过程中需要对num*2。
//
// 题目还有一个坑，就是非负数判断，以及1的判断，1并不属于perfect number！
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