//
// Created by Mr.Hu on 2018/3/31.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        vector<int> tmp;
        for (int i = 1; i <= rowIndex + 1; i++) {
            for (int j = 0; j < i; j++) {
                if (j == 0 || j == i - 1) {
                    tmp.push_back(1);
                } else {
                    int sum = result[j - 1] + result[j];
                    tmp.push_back(sum);
                }
            }
            result.swap(tmp);
            tmp.clear();
        }
        return result;
    }
};

int main() {
    int rowIndex = 3;
    Solution solution;
    vector<int> result = solution.getRow(rowIndex);
    vector<int>::iterator it;
    for (it = result.begin(); it < result.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}