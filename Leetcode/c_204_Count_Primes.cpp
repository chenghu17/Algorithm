//
// Created by Mr.Hu on 2018/5/15.
//
// leetcode 204 count primes
//
// 这个题目要求求出小于n的素数的个数
//
// 当拿到这个题目，我刚开始想的是素数的计算方法。根据概念，因数只有1和其本身的数称为素数。
// 没有一个公式能够很好的描述素数，因为它在数学表达上无法刻画。经过了一天，我觉得去学习一下别人是怎么做的。
//
// 基本方法就是从2开始判断，因为0,1都不是素数。如果该数a是素数，则a*2,a*3,,,a*m都为合数；
// 如果该数为合数，则跳过，如合数4，不用计算4*2,4*3，因为在前一个数固定为2的时候，2*4,2*5,2*6已经将基数为4的合数更新过了。
//
// 更一般的，以一个数a为底，则a*2,a*3,a*4...都是合数。而且在计算合数时，以a为底，我们直接从a*a,a*(a+1)开始计算即可，
// 因为a*(a-1),a*(a-2)已经在底为a-1合底为a-2的时候计算过了。当a为合数的时候，我们不用重复计算，因为它一定由其之前的合数组成，
// 并且它的倍数一定被前面合数计算过。
//
// 在对以上思想进行coding的过程中，使用map<int,bool>来进行存储，当n比较大时，执行时间特别长，
// 所以去找了一下别人的方法，发现别人使用的是bool *allnumber数组来进行存储。更改了我的存储方法后，
// 执行时间从原来的1603ms变为了6ms...
//
// 对于map、array、list、vector，set之间存储效率和更新效率对比需要了解一下。
//



#include <iostream>
//#include <map>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
//        map<int, bool> allnumber;
        bool *allnumber = new bool[n];
        for (int i = 0; i < n; i++) {
            allnumber[i] = true;
        }
        allnumber[0] = false;
        allnumber[1] = false;
        isPrime(n, allnumber);
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (allnumber[i])
                count++;
        }
        return count;

    }

//    void isPrime(int n, map<int, bool> &allnumber) {
    void isPrime(int n, bool *allnumber) {
        for (int i = 2; i * i < n; i++) {
            if (allnumber[i]) {
                int tmp = i * i;
                while (tmp < n) {
                    allnumber[tmp] = false;
                    tmp += i;
                }
            }
        }
    }
};

int main() {
    int n = 999983;
    Solution solution;
    int count = solution.countPrimes(n);
    cout << count << endl;
    return 0;
}