//
// Created by Mr.Hu on 2018/6/13.
//
// leetcode 575 distribute candies
//
// 题目给出一个数组，数组中的数字表示糖果的种类，每种糖果有多个，需要分给一个哥哥和一个妹妹，求最多能分给妹妹多少种糖果。
//
// 第一种想法就是对所有种类的糖果进行统计，再进行分配，这种方法我觉得太繁琐，就没有写；
// 第二种方法就是code中实现的思想，使用set<int> 数据结构来对vector<int> 进行去重复，set的size就是糖果的种类；
// 如果糖果的种类要比糖果总数的一半还要多，说明妹妹不能得到所有种类的糖果，只能得到总数一般的糖果；
// 如果糖果的种类要比糖果总数的一般要少，则说明妹妹可以分的所有种类的糖果，并且还会得到多个同一类的糖果。
// 这样思考代码量就简单多了，但是由于set对于vector去重操作是一个相当耗时的操作，所以代码的执行效率只查过了百分之三十多的accepted solution
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int> &candies) {
        int number = candies.size();
        set<int> kind(candies.begin(), candies.end());
        if (kind.size() > number / 2) {
            return number / 2;
        }
        return kind.size();
    }
};

int main() {
    vector<int> candies;
    candies.push_back(1);
    candies.push_back(1);
    candies.push_back(2);
    candies.push_back(2);
    candies.push_back(3);
    candies.push_back(4);
    Solution solution;
    int result = solution.distributeCandies(candies);
    cout << result << endl;
    return 0;
}