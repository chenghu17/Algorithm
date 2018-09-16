//
// Created by Mr.Hu on 2018/9/16.
//
// 腾讯2019秋招开发岗 在线编程第一题
//
// 题目描述：输入一个正整数n，要求找出最小的大于n的正整数，使得满足 LCM(1,2,3,...,m) = LCM(n+1,n+2,...,m)。
// 其中LCM表示 lowest common multiple，最小公倍数
//
// 输入描述：一个正整数n (1<=n<=10^6)
// 输出描述：一个正整数m，即题目中所求
//
//


#include <iostream>

using namespace std;


// 求最大公约数，进而得到最小公倍数
// 转转相除法求 Greatest common divisor

int GCD(int a, int b) {
    // Greatest common divisor
    while (a != b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 2;
    } else {
        int gcd_l = 1;
        int product_l = 1;
        int lcm_l;
        for (int i = 2; i <= n; ++i) {
            lcm_l = product_l / gcd_l;
            gcd_l = GCD(lcm_l, i);
            product_l *= i;
        }
        lcm_l = product_l / gcd_l;

        int gcd_r = n + 1;
        int m = n + 1;
        int lcm_r = n + 1;
        int product_r = n + 1;
        while (lcm_r % lcm_l != 0) {
            m++;
            product_r *= m;
            lcm_r = product_r / gcd_r;
            gcd_r = GCD(lcm_r, m);

        }
        cout << m;
    }

    return 0;
}
