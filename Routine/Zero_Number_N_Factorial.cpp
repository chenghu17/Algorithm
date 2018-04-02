//
// Created by Mr.Hu on 2018/4/2.
//
// 给定数字n，计算其n！的结果末尾有多少个0
// 阶乘的结果一般都特别大，所以如果直接算，n稍微大一点就会overflow
// 所以观察发现，n！结果中尾数0的个数，来源于2x5
// 所以只需要

#include <iostream>
using namespace std;

int zeroNumber(int n);

int main(){
    int n = 20;
    int zero_Number = zeroNumber(n);
    cout<<zero_Number<<endl;
    return 0;
}

int zeroNumber(int n){
    int result = 0;
    if(n<=0)
        return result;
    for(int i=1;i<=n;i++){
        int m = i;
        while(m%5==0){
            result++;
            m /= 5;
        }
    }
    return result;
}