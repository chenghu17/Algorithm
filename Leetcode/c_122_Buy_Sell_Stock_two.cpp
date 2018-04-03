//
// Created by Mr.Hu on 2018/4/3.
// leetcode122 best tome to buy and sell stock two
// 拿到这个题目，发现并没有思路，刚开始认为是一个组合优化的问题，想到保证局部最优最后能达到全局最优

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        auto size = prices.size();
        if(size<2)
            return profit;
        int prior = 0;
        int current = 1;
        for(int i=2;i<size;i++){
            if(prices[current]>prices[prior]){
                if(prices[i]>prices[current]){
                    current = i;
                }
                else{
                    int local_profit = prices[current] - prices[prior];
                    profit += local_profit;
                    prior = i;
                    i++;
                    current = i;
                }
            }
            else{
                prior = current;
                current = i;
            }
        }
        if(current!=prior && current<size && prices[current]>prices[prior]){
            int local_profit = prices[current] - prices[prior];
            profit += local_profit;
        }
        return profit;
    }
};

int main(){
    vector<int> prices = {1,2,3,4,2,7};
    Solution solution;
    int max_profits = solution.maxProfit(prices);
    cout<<max_profits<<endl;
    return 0;


}