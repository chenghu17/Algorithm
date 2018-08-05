//
// Created by Mr.Hu on 2018/8/5.
//
// Tencent 2018 机试题
//
// 题目描述：已知一个正整数对(x,y)，其中x，y都不大于n，并且x除以y的余数大于等于k，求满足该条件共有多少数对。
// 输入两个整数n，k（1<=n<=10^5，0<=k<=n-1）
//

#include <iostream>
using namespace std;

int number_of_integer_pair(int n,int k){
    // 要求x除以y的余数大于等于k，则x一定要大于k
    int result = 0;
    for(int i=k;i<=n;++i){
//        int time = i/k;
        for(int j=k+1;j<=i-k;++j){
            if(i%j>=k){
                ++result;
            }
        }
        if(n-i>0){
            result += n-i;
        }
    }
    return result;
}



int main(){
    int n,k;
    cin>>n>>k;
    int result = number_of_integer_pair(n,k);
    cout<<result<<endl;
    return 0;
}

