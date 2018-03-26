//
// Created by Mr.Hu on 26/03/2018.
//
// leedcode plus one
// 题目刚开始没看懂，查了一些别人的讲解才理解！
// 题目是一个非负数的各位数用vector表示，高位在前，个位在后
// 给这个数字个位加一，需要判断进位，以及一直进位下去需要在开头添加一个新数字的情况
// 先考虑不进位的情况，加了之后直接返回结果
// 对于进位的情况，

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            auto size = digits.size();
            int i;
            for(i=size-1;i>=0;i--){
                if(digits[i]+1!=10){
                    digits[i] += 1;
                    return digits;
                }
                else{
                    digits[i] = 0;
                    //digits[i-1] += 1
                }
            }
            if(i==-1){
                digits.insert(digits.begin(),1);
            }
            return digits;
        }
};

int main(){
    vector<int> digits = {9,9,9,9,9,9,9,1};
    Solution solution;
    digits = solution.plusOne(digits);
    vector<int>::iterator it;
    for(it=digits.begin();it!=digits.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}