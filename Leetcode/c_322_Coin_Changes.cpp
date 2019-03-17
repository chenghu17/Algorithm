//
// Created by Mr.Hu on 2019/3/17.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int coinChange(vector<int> &coins, int amount) {
        int coins_type = coins.size();
        // 表示当前硬币种类和需要找零的钱数
        vector<vector<int>> optimal_change_num(coins_type + 1, vector<int>(amount + 1));

        // 当前硬币面值为0时，所有需要找零的钱都没办法得到满足，定义为无穷多个
        for (int i = 0; i <= amount; i++) {
            optimal_change_num[0][i] = 1000000000;  // 设定没有方案时的上限
        }

        // 当前需要找零的钱为0时，所有币种需要0个
        for (int i = 0; i <= coins_type; i++) {
            optimal_change_num[i][0] = 0;
        }

        // 开始逐层遍历填充二维状态空间
        for (int coin_idx = 1; coin_idx <= coins_type; coin_idx++) {
            for (int money = 1; money <= amount; money++) {
                // 当前硬币面值大于需要找零数，即需要调整硬币面值
                // 注意这里需要使用 coins[coin_idx-1]，因为coins数组还是从0开始编号的
                if (coins[coin_idx - 1] > money) {
                    optimal_change_num[coin_idx][money] = optimal_change_num[coin_idx - 1][money];
                    continue;
                }

                // 否则，问题变为选与不选当前面值硬币，取两者最小
                optimal_change_num[coin_idx][money] =
                        min(optimal_change_num[coin_idx][money - coins[coin_idx - 1]] + 1,
                            optimal_change_num[coin_idx - 1][money]);

            }
        }

        return optimal_change_num[coins_type][amount] != 1000000000 ? optimal_change_num[coins_type][amount] : -1;

    }
};

int main() {
    Solution solution;
//    vector<int> coins = {1, 2, 5};
    vector<int> coins = {2};
    int amount = 3;
    int min_num = solution.coinChange(coins, amount);
    cout << "the min coin number = " << min_num << endl;
    return 0;
}