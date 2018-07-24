//
// Created by Mr.Hu on 2018/7/24.
//
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec2[2]<=rec1[0] || rec2[0]>=rec1[2] || rec2[1]>=rec1[3] || rec2[3]<=rec1[1]){
            return false;
        }
        return true;
    }
};

int main(){
    vector<int> rec1,rec2;
    rec1.emplace_back(0);
    rec1.emplace_back(0);
    rec1.emplace_back(1);
    rec1.emplace_back(1);
    rec2.emplace_back(1);
    rec2.emplace_back(0);
    rec2.emplace_back(2);
    rec2.emplace_back(1);
    Solution solution;
    bool isoverlap = solution.isRectangleOverlap(rec1,rec2);
    cout<<isoverlap<<endl;
    return 0;
}