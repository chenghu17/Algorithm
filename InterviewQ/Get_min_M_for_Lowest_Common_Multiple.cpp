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
// 思路：由于题目要求求最小公倍数，可以联想到两个数求最小公倍数的方法：LCM(a,b)=(a*b)/GCD(a,b)
//      所以我们现在需要解决最大公约数的求解方法，最大公约数可以使用辗转相除法进行求解，即GCD(a,b)，a%b==c ... a=b,b=c,
//      重复操作，当a==b||c==0，此时的b就为最大公约数，当得到最大公约数后，我们就可以求解出最小公倍数。
//
//      题目让我们求LCM(1,2,3,...,m) = LCM(n+1,n+2,...,m)时m的取值，我们可以发现，要满足该等式，则需要满足：
//      LCM(n+1,n+2,...,m) % LCM(1,2,3,...,n) == 0 才可以，即在前者数组之前在加上后者数组，其LCM才不会变。
//      所以我们需要去分别求以上两个数字串的LCM，而求多个数字的LCM的方法：先求两个数的GCD从而得到这两个数字的LCM，
//      然后将该LCM与第三个数求GCD，三个数的乘积除以此时的GCD，则得到新的LCM，依次计算可以得到最终的LCM。
//      对于LCM(n+1,n+2,...,m)可以使用一个while循环，直到满足上面的整数，此时的m即为所求。
//
// 解题关键：求最大公约数，进而得到最小公倍数，辗转相除法求Greatest common divisor
// 多个数求LCM，即多个数的乘积除以多个数的GCD
//

#include <iostream>
using namespace std;

int GCD(int a, int b) {
    while (a != b) {
        int tmp = a % b;
        if(tmp==0){
            break;
        }
        a = b;
        b = tmp;
    }
    return b;
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


        int gcd_r;
        int m = n + 1;
        int lcm_r = n + 1;
        int product_r = n + 1;
        while (lcm_r % lcm_l != 0) {
            m++;
            product_r *= m;
            gcd_r = GCD(lcm_r, m);
            lcm_r = product_r / gcd_r;
        }
        cout << m;
    }
    return 0;
}
