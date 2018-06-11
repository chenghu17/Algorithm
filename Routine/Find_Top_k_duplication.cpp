//
// Created by Mr.Hu on 2018/6/11.
//
// 题目给定只包含正整数的数组，求前K个重复次数最多的数组，按照重复数字从小到大的顺序进行排列输出
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> find_Top_n_duplication(vector<int> arr, int n) {
        vector<int> result(n);
        map<int, int> tmp;
        auto size = arr.size();
        for (int i = 0; i < size; ++i) {
            int index = arr[i];
            tmp[index]++;
        }
        // 对map按照value值排序
        vector<pair<int, int>> vtMap;
        for (auto it = tmp.begin(); it != tmp.end(); it++)
            vtMap.push_back(make_pair(it->first, it->second));

        sort(vtMap.begin(), vtMap.end(),
             [](const pair<int, int> &x, const pair<int, int> &y) -> int {
                 return x.second > y.second;
             });
        int i=0;
        for (auto it = vtMap.begin(); it != vtMap.end(); it++) {
            if(i<n){
                result[i] = it->first;
                i++;
            }
            else {
                break;
            }
        }
        return result;
    }
};

int main() {
    vector<int> arr;
    int n = 5;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    Solution solution;
    vector<int> res = solution.find_Top_n_duplication(arr, n);
    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
};