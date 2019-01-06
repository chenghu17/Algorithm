//
// Created by Mr.Hu on 2019/1/6.
//
// leetcode 914 X of a kind in a deck of cards
//
// 题目给定一些卡片，要求选择一个数字X，可以将卡片分成多组，每组卡片的个数为X，且每组卡片上的数字都相同。
//
// 首先，我们需要统计每种数组的卡片有多少个。所以这里使用map<int,int>来保存；
// 得到每个卡片的个数之后，便设计到划分的问题了。刚开始对题目没有理解透，以为只有每种卡片的个数相等才满足条件。
// 一顿操作之后，提示[1,1,2,2,2,2]也可以...然后发现如果某一种卡片的个数能被其他卡片个数都整除，也是可以的...
// 又是一顿操作之后，提示[1,1,1,1,2,2,2,2,2,2]也可以...然后才发现问题真正存在的地方：
// 如果每种卡片的个数集合，存在大于等于2的公共约数，则说明可以划分，否则不可以！
//
// 原来是酱紫！所以得到每个数字出现的个数之后，首先遍历得到所有数字中出现次数的最小的值min_time，如果小于2，直接return false；
// 然后从2到最小值min_time进行遍历，如果每个卡片出现的次数能够整除其中的任何一个值，则说明X可以取该值然后进行划分。
// 如果不存在，则X没有满足情况的时候。
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int> &deck) {
        int min_time = INT_MAX;
        map<int, int> card_map;
        for (auto i:deck) {
            card_map[i]++;
        }
        for (auto it = card_map.begin(); it != card_map.end(); it++) {
            min_time = min(min_time, it->second);
        }
        if (min_time < 2) {
            return false;
        }
        for (int i = 2; i <= min_time; i++) {
            bool hasX = true;
            for (auto it = card_map.begin(); it != card_map.end(); it++) {
                if (it->second % i != 0) {
                    hasX = false;
                    break;
                }
            }
            if (hasX) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> deck;
    deck.push_back(1);
    deck.push_back(2);
    deck.push_back(3);
    deck.push_back(1);
    deck.push_back(1);
    deck.push_back(1);
    deck.push_back(2);
    deck.push_back(3);
    Solution solution;
    bool hasX = solution.hasGroupsSizeX(deck);
    cout << "has X？" << hasX << endl;
    return 0;
}