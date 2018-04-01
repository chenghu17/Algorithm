//
// Created by Mr.Hu on 2018/4/1.


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