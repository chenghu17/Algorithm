//
// Created by Mr.Hu on 2018/4/1.
// leetcode 121 Best Time to Buy and Sell Stock
// 这题的第一感觉就是蛮力法，嵌套循环，然后就出现了以下代码
// 第一次提交报错误，time limit exceeded，开始以为是出现了死循环，再次检查发现没有
// 于是坚持提交，通过...但是我看了一下执行时间 462ms，确实有点长哈，蛮力法的复杂度确实太高了。
// 今天状态不佳，先去写论文去了，明天做122题的时候顺便把这一题的第二种解法想出来并coding。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto size = prices.size();
        int max_profit = 0;
        for(int i=0;i<size;i++){
            for(int j=0;j<i;j++){
                int profit = prices[i]-prices[j];
                if(profit>max_profit){
                    max_profit = profit;
                }
            }
        }
        return max_profit;
    }
};

int main(){
    vector<int> prices = {7,6,2,5,8,9};
    Solution solution;
    int max_Profit = solution.maxProfit(prices);
    cout<<max_Profit<<endl;
    return 0;
}