//
// Created by Mr.Hu on 2019/1/25.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int> &A) {
        // int num = A.size();
        set<int> s;
        for (auto i:A) {
            if (s.count(i)) {
                return i;
            }
            s.insert(i);
        }
        return 0;
    }
};

int main() {
    vector<int> A = {1, 3, 2, 2};
    Solution solution;
    int repeat = solution.repeatedNTimes(A);
    cout << "repeat N times : " << repeat << endl;
    return 0;
}