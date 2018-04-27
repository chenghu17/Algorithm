//
// Created by Mr.Hu on 2018/4/27.
//
// leetcode 746 min cost climbing stairs
//
//
//
//


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> mincost = vector<int>(cost.size()+1);
        mincost[0]= cost[0];
        mincost[1]=cost[1];
        for(int i=2;i<=cost.size();i++){
            int costV = (i==cost.size())? 0:cost[i];
            mincost[i] = (min(mincost[i-1]+costV,mincost[i-2]+costV));
        }
        return mincost[cost.size()];
    }
};

int main(){
    vector<int> cost = {1,2,100,1,1,1,100,1};
    Solution solution;
    int mincost = solution.minCostClimbingStairs(cost);
    cout<<mincost<<endl;
    return 0;
}