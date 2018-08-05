//
// Created by Mr.Hu on 2018/8/5.
//
// Tencent 2018 机试题
//
// 题目描述：已知一个正整数对(x,y)，其中x，y都不大于n，并且x除以y的余数大于等于k，求满足该条件共有多少数对。
// 输入两个整数n，k（1<=n<=10^5，0<=k<=n-1）
//
// 分析：1、题目要求x%y>=k，那么x一定满足x>=k，因为余数是一定小于等于被除数，要想余数>=k，则被除数一定>=k，
// x的边界为x<=n；2、对于y，因为余数是一定小于除数，要想余数>=k，则除数一定>=k；3、当除数取x-k之后的数时，
// 余数一定小于k，所以除数的边界为y<=x-k。在上述三个条件下的双循环中进行遍历，求得x>=y时满足条件pairs个数.
// 值得注意的是，由于k是可以取0，而n是从1开始，所以我们在循环之前先判断k的值，如果k==0，则用tmp来代替k，且tmp最小为1。
//
// 讨论完x>=y（k=0时存在x==y的情况），还需要考虑x<y的情况（）此时y的取值情况存在与闭区间[x+1,n]，其中包含n-x个数，
// 且在x>=k的情况下，y取这n-x个数个数，余数都是x，即都满足题目要求。
// 因此判断n-x>0?，是则将result+=n-x。
//
// 重复上述循环，最终返回result的结果。
//
// 题目的主要思考点是判断x与y的取值情况，我们可以根据被除数、除数、余数三者之间的关系来缩小判定范围，从而降低时间复杂度。
//

#include <iostream>
using namespace std;

int number_of_integer_pair(int n, int k) {
    int result = 0;
    int tmp = k == 0 ? 1 : k;
    for (int x = tmp; x <= n; ++x) {
        for (int y = tmp; y <= x - k; ++y) {
            if (x % y >= k) {
                ++result;
            }
        }
        if (n - x > 0) {
            result += n - x;
        }
    }
    return result;
}


int main() {
    int n, k;
    cin >> n >> k;
    int result = number_of_integer_pair(n, k);
    cout << result << endl;
    return 0;
}

