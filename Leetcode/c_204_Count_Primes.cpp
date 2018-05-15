//
// Created by Mr.Hu on 2018/5/15.
//
// leetcode 204 count primes
//

#include <iostream>
#include <map>
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

int main(){
    int  n = 999983;
    Solution solution;
    int count = solution.countPrimes(n);
    cout<<count<<endl;
    return 0;
}