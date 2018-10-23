//
// Created by Mr.Hu on 2018/10/10.
//
// didi 2018 秋招笔试题
//
// 已知一把魔法权杖，上面有n颗能量石，现在可以对能量石进行合并，要求合并只能是相邻能量石之间合并。
// 求m次合并后，输出最小的能量石所拥有的能量。
//
// 思路：使用贪心的方法，每次找出能量石中最小的，然后与其两侧中较小的值合并，得到新的能量石，
// 依次方式合并m次，最后可以得到合并后的能量石排列。当前能量石集合中最小值即为所求。
//
// 问题：上述操作有一个问题，每次寻找能量石中最小的能量需要遍历整个集合，而当集合很大的时候，这种遍历的方法是相当耗时的，所以亟待改进。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void greedy_combine(vector<int> &power) {
    auto smallest = min_element(power.begin(), power.end());
    int index = (int) distance(power.begin(), smallest);
    if (index == 0) {
        power[index + 1] = power[index + 1] + power[index];
    } else if (index == power.size() - 1) {
        power[index - 1] = power[index - 1] + power[index];
    } else {
        power[index - 1] < power[index + 1] ? power[index - 1] += power[index] : power[index + 1] += power[index];
    }
    power.erase(smallest);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> power(n);
    for (int i = 0; i < n; ++i) {
        cin >> power[i];
    }
    if (m != 1) {
        for (int i = 0; i < m; ++i) {
            greedy_combine(power);
        }
    }
    auto smallest = min_element(power.begin(), power.end());
    cout << *smallest;
    return 0;
}