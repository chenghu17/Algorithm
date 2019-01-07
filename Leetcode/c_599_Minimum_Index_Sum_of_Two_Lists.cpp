//
// Created by Mr.Hu on 2019/1/7.
//
// leetcode 599 minimum index sum of two lists
//
// 题目给定两个list，分别包含两个人喜欢的餐厅。要求选出一个列表，包含两个人都共同喜欢的餐厅，并且餐厅在各自列表中的索引和最小。
// 如果存在多个最小索引和，则全部输出。
//
// 首先遍历某一个list，记录不同餐厅的index，一一对应的关系；
// 然后遍历第二个list，如果餐厅在前面出现过，则是共同爱好，计算index sum，比较当前最小的index sum，小于则重置共同爱好列表，加入当前餐厅名，
// 并更新min_index_sum。等于则直接加入，大于则继续遍历list2。
//
// 其实有很多小trick，一是可以先遍历两个list中较短的一个，这样在下一次搜索map的keys时耗时就小；
// 在第二次遍历时，可以对当前index再做一个判断，即j<=min_sum。因为如果当前的index就超过了最小的index和，那么之后的餐厅肯定都不用考虑。
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
        int min_sum = INT_MAX;
        vector<string> common;
        map<string, int> index_sum;
        for (int i = 0; i < list1.size(); i++) {
            index_sum[list1[i]] = i;
        }
        // for(int j=0;j<list2.size();j++){
        for (int j = 0; j < list2.size() && j <= min_sum; j++) {
            auto it = index_sum.find(list2[j]);
            if (it != index_sum.end()) {
                if (index_sum[list2[j]] + j < min_sum) {
                    min_sum = index_sum[list2[j]] + j;
                    // common.clear();
                    // common.push_back(list2[j]);
                    common = {list2[j]};
                } else if (index_sum[list2[j]] + j == min_sum) {
                    common.push_back(list2[j]);
                }
            }
        }
        return common;
    }
};

int main() {
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    Solution solution;
    vector<string> res = solution.findRestaurant(list1, list2);
    for (auto str:res) {
        cout << str << " ";
    }
    return 0;
}