//
// Created by Mr.Hu on 2018/4/3.
// leetcode122 best tome to buy and sell stock two
//
// 题目要求求最大利益，可以买卖多次，但是当天只能买或者卖。
// 拿到这个题目，发现并没有思路，刚开始认为是一个组合优化的问题，想到保证局部最优最后能达到全局最优，
// 还想着能不能用图解决，但是这个是一个序列问题，所以果断放弃这种思路。
// 后来想着多用几组测试数据看能不能找到规律：
// 发现对于这个最大利益满足：若当前时间(a)的价格比之前时间(b)的价格高，且相邻的下一个时间(a+1)的价格比当前时间低，
// 则当前时间(a)卖掉在之前时间(b)买的stock是最大利益的一部分。若相邻的下一个时间(a+1)的价格比当前时间高，则stock在下一个时间进行出售可能比较好。
// 举个例子[7,3,8,5,6,4,9]
// 利益最大的情况是3买入，8卖出，然后5买入，6卖出，然后4买入，9卖出；
// 在leetcode121中，要求只能一次买卖，则3买入，9卖出，得到的利益最大。
//
// 上面的这个规律是观察出来的，当然我用代码实现发现结果正是这样，我一直在思考为什么？
// 例如[4,6,5,9]，(1)4买入6卖出，5买入9卖出 得到的利益要比 (2)4买入9卖出 多！无法说服我的内心...
// 所以想到了一种形式化的方法，将每个时间点的价格放在坐标轴中，然后用纵坐标投影距离来将利益形式化为距离，从而加深理解。
// 即如果在6处未卖出，此时价格就降到5，然后再涨到9，此时有一个单位(6-5)的利润就没有赚到。
// 只要中间转手一次，不不考虑最开始和最后，只要转手的价格比再买入的价格高，则就赚了。股票里面的做空就是这个道理哈。
// 比如我先借1股，今天价格为6钱，我认为这支股票接下来会跌，所以我卖了，获得6钱，然后第二天我再买1股，此时只花了5钱，然后把这1股还给别人，那我从中间就套利1钱。
//
// 具体的coding，是设定三个指针，一个为当前最低价格的prior;一个是当前的价格current；以及下一个时间的价格i；
// 通过prior与current，current与i之间的比较，来更新指针，并更新利润。
//
// 突然相处了一个优化方案！！！
// 通过思考股票做空，想到如果想要通过多次转手买卖获得最大利润，则在每个相邻时间把握住赚钱机会！
// 所以计算相邻时间的差值，如果为正，则这次买卖为赚钱，所以值得进行
// 对于这个题目，可以先脱离题目数据进行思考，考虑实际的股票市场情况，然后与这题联系起来，就可以得到最优解答

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        auto size = prices.size();
        if (size < 2)
            return profit;
        int prior = 0;
        int current = 1;
        for (int i = 2; i < size; i++) {
            if (prices[current] > prices[prior]) {
                if (prices[i] > prices[current]) {
                    current = i;
                } else {
                    int local_profit = prices[current] - prices[prior];
                    profit += local_profit;
                    prior = i;
                    i++;
                    current = i;
                }
            } else {
                prior = current;
                current = i;
            }
        }
        if (current != prior && current < size && prices[current] > prices[prior]) {
            int local_profit = prices[current] - prices[prior];
            profit += local_profit;
        }
        return profit;
    }


    int maxProfit_optimal(vector<int> &prices) {
        int profit = 0;
        auto size = prices.size();
        if (size < 2)
            return profit;
        for (int i = 0; i < size - 1; i++) {
            int difference = prices[i + 1] - prices[i];
            if (difference > 0)
                profit += difference;
        }
        return profit;
    }
};

int main() {
    vector<int> prices = {1, 2, 3, 4, 2, 7};
    Solution solution;
    int max_profits = solution.maxProfit(prices);
    int max_profits_optimal = solution.maxProfit_optimal(prices);
    cout << "max_profits = " << max_profits << endl;
    cout << "max_profits_optimal = " << max_profits_optimal << endl;
    return 0;


}