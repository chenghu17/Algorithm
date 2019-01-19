//
// Created by Mr.Hu on 2019/1/19.
//
// leetcode 475 heaters
//
// 题目给定一些房子位置和加热器的位置，要求对加热器设定一个固定的温度，使得所有的房子都能够暖和。
//
// 这个题目基本思想就是对于每个房子，找出其左右加热器的位置，算出各自的距离，并取较小值作为需要设定的温度，
// 每个房子都进行同样的操作，而对于每个房子需要设定的最小温度而言，需要取所有房子需要温度的最大值，才能满足所有的条件。
//
// 解答思想比较简单，但是编码上还是有一些技巧，最终的编码还是参考了题目中discussion部分别人的思路。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int distance = 0;
        int i = 0;
        for (const int house : houses) {
            //找到当前house右边第一个heater
            while ((i < heaters.size()) && (heaters[i] <= house)) {
                i++;
            }
            int minDistance = numeric_limits<int>::max();
            if (i > 0) {
                minDistance = min(minDistance, abs(house - heaters[i - 1]));
            }
            if (i < heaters.size()) {
                minDistance = min(minDistance, abs(house - heaters[i]));
            }
            distance = max(distance, minDistance);
        }
        return distance;
    }
};

int main() {
    vector<int> houses = {1, 2, 3};
    vector<int> heaters = {1};
    Solution solution;
    int distance = solution.findRadius(houses, heaters);
    cout << distance << endl;
    return 0;
}