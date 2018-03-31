//
// Created by Mr.Hu on 2018/3/31.
//
// leetcode 118 Pascal's Triangle


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=1;i<=numRows;i++){
            vector<int> tmp;
            for(int j=0;j<i;j++){
                if(j==0 || j==i-1){
                    tmp.push_back(1);
                }
                else{
                    int sum = result[i-2][j-1]+result[i-2][j];
                    cout<<sum<<endl;
                    tmp.push_back(sum);
                }
            }
            result.push_back(tmp);
            vector<int>().swap(tmp);
        }
        return result;
    }
};

int main(){
    int numRows = 5;
    Solution solution;
    vector<vector<int>> result = solution.generate(numRows);
    return 0;

}