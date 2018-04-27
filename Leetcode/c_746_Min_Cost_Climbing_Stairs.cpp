//
// Created by Mr.Hu on 2018/4/27.
//
// leetcode 746 min cost climbing stairs
//
// 题目要求对于给定的数组，即为楼梯，每一阶楼梯都有其cost，可以从第0阶，或者第1阶开始，
// 每次可以向上前进1阶或者2阶，求达到最顶端，即走过最后一阶楼梯的最小花费。
//
// 刚开始看这个题目让我想到了c_695，觉得又是一个回溯法，然后我用图的形式进行可视化之后，发现是一个动态规划的
// 题目，想了一段时间发现不会做这个类型的题目，就去网上找了解题方法。
//
// 动态规划的题目还要多练习，这种思想要理解内化。
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