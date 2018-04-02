//
// Created by Mr.Hu on 2018/4/2.
//
// Q：给定数字n，计算其n！的结果末尾有多少个0？
// 阶乘的结果一般都特别大，所以如果直接算，n稍微大一点就会overflow
// 所以观察发现，n！结果中尾数0的个数，来源于2x5
// 所以只需要观察有多少个n！中有多少个2x5即可
// 但是判断2x5也不是一件容易的事情，对于2和5而言，将数字分解为因数包含2，和将数字分解为因数包含5；
// 很明显含2的多，所以我们只需要判断，n！中，可以提取出多少个5就可以了，因为一定存在相对数量的2，来与5相乘。
// 所以我就对每个数进行判断，判断其模5后余数为不为0，为0则结果+1，然后判断剩下的因数是否还包含；
// 不包含则对下一个乘数进行上述判断。
//

#include <iostream>

using namespace std;

int zeroNumber(int n);

int main() {
    int n = 20;
    int zero_Number = zeroNumber(n);
    cout << zero_Number << endl;
    return 0;
}

int zeroNumber(int n) {
    int result = 0;
    if (n <= 0)
        return result;
    for (int i = 1; i <= n; i++) {
        int m = i;
        while (m % 5 == 0) {
            result++;
            m /= 5;
        }
    }
    return result;
}