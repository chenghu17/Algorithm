//
// Created by Mr.Hu on 2018/9/3.
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
};

int main(){
    vector<int> temperatures;
    temperatures.push_back(73);
    temperatures.push_back(74);
    temperatures.push_back(75);
    temperatures.push_back(71);
    temperatures.push_back(69);
    temperatures.push_back(72);
    temperatures.push_back(76);
    Solution solution;
    vector<int> min_wait = solution.dailyTemperatures(temperatures);
    for(auto it=min_wait.begin();it!=min_wait.end();++it){
        cout<<*it<<" ";
    }
    return 0;
}