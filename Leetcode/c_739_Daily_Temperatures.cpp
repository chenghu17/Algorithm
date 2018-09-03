//
// Created by Mr.Hu on 2018/9/3.
//
// leetcode 739 daily temperature
//
// 题目要去对于给定的天气情况，计算每一天需要等待多少天可以升温，如果其后所有天都没有比当天温度高，则记为0
//
// 方法1：蛮力法，可以从头开始进行遍历，找到第一个比当天温度高值，则计算两个时间点中间的时间间隔；如果遍历完数组没有找到，则记为0，
//          （其实我们在初始化时就以及赋值为0，因此在没有找到比当天温度高的某一天时，则继续第一层循环）
//
// 方法2：由于蛮力法的执行时间相当长，在leetcode中只击败了百分之三的accepted cpp，所以又去思考了一下是否能够改进。
//          我们可以从最后一天开始考虑，最后一天的min_wait(最小等待天数)肯定为0，然后倒数第二天，如果其比最后一天小，
//          则其min_wait的值就为1，否则也为0，然后继续推进。如果第n天的值比第n+1天的值要小，则min_wait为1，否则按照方法1
//          蛮力操作，得继续判断n+2的情况。但是我们知道：在计算n+1时，是已经与n+2进行比较的，所以如果第n个数比第n+1个数字要大，
//          我们可以借助之前比较第n+1个数的结果，记min_wait，如果min_wait(n+1)==0，则说明其后没有比它大的数字，因此min_wait(n)=0，
//          否则，则直接定位到第一个比n+1大的数字的位置。记n+1+min_wait(n+1)，进行比较，依此类推。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int size = temperatures.size();
        vector<int> min_wait = vector<int>(size, 0);
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (temperatures[i] < temperatures[j]) {
                    min_wait[i] = j - i;
                    break;
                }
            }
        }
        return min_wait;
    }

    vector<int> dailyTemperatures_optimal(vector<int> &temperatures) {
        int size = temperatures.size();
        vector<int> min_wait = vector<int>(size, 0);
        for (int i = size - 2; i >= 0; --i) {
            if (temperatures[i] < temperatures[i + 1]) {
                min_wait[i] = 1;
                continue;
            }
            int tmp = i + 1;
            while (min_wait[tmp] != 0 && tmp < size) {
                if (temperatures[i] < temperatures[tmp + min_wait[tmp]]) {
                    min_wait[i] = tmp + min_wait[tmp] - i;
                    break;
                } else {
                    tmp = tmp + min_wait[tmp];
                }
            }
        }
        return min_wait;
    }
};

int main() {
    vector<int> temperatures;
    temperatures.push_back(73);
    temperatures.push_back(74);
    temperatures.push_back(75);
    temperatures.push_back(71);
    temperatures.push_back(69);
    temperatures.push_back(72);
    temperatures.push_back(76);
    Solution solution;
//    vector<int> min_wait = solution.dailyTemperatures(temperatures);
    vector<int> min_wait = solution.dailyTemperatures_optimal(temperatures);
    for (auto it = min_wait.begin(); it != min_wait.end(); ++it) {
        cout << *it << " ";
    }
    return 0;
}