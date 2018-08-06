//
// Created by Mr.Hu on 2018/8/6.
//
// leetcode 867 transpose matrix
//
//


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        vector<vector<int>> ts(col,vector<int>(row));
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                ts[j][i] = A[i][j];
            }
        }
        return ts;
    }
};

int main(){
    vector<vector<int>> A;
    vector<int> x;
    x.emplace_back(1);
    x.emplace_back(2);
    x.emplace_back(3);
    A.emplace_back(x);
    x.clear();
    x.emplace_back(4);
    x.emplace_back(5);
    x.emplace_back(6);
    A.emplace_back(x);
    Solution solution;
    vector<vector<int>> result = solution.transpose(A);
    for(auto n:result){
        for(auto m:n){
            cout<<m<<" ";
        }
        cout<<endl;
    }
}