//
// Created by Mr.Hu on 2019/2/2.
//
// leetcode 860 lemonade change
//
// 题目给定一个交易场景，当前有很多顾客排队买单，每个顾客需要支付5元，而店家当前没有任何零钱在手中，当顾客给10块时，需要找回5块，
// 当顾客给20块时，需要找回15块。先提供每个用户给的钱数，要求判断店家在没有零钱的情况下，是否能将所有交易完成，顾客给定的钱为{5,10,20}。
//
// 利用两个变量分别保存店家手中的5块和10块数目，当顾客给20时，如果有10块的，则给其找回一个10块和一个5块，如果没有，则找回三个5块。
// 如果店家当前的零钱无法找给顾客，则返回false，如果都能找回，则返回true。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int> &bills) {
        int five = 0;
        int ten = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                five++;
            } else if (bills[i] == 10) {
                if (five == 0) {
                    return false;
                }
                five--;
                ten++;
            } else {
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (ten == 0 && five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    vector<int> bills = {5, 5, 5, 10, 20};
    Solution solution;
    bool change = solution.lemonadeChange(bills);
    cout << "can change ? " << change << endl;
    return 0;
}