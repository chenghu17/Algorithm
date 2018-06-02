//
// Created by Mr.Hu on 2018/6/2.
//
// leetcode 171 excel sheet column number
//

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int length = s.size();
        int result = 0;
        for(int i=0;i<length;i++){
            int tmp = int(s[i]-'\0')-64;
            result += tmp * pow(26,(length-i-1));
        }
        return result;
    }
};

int main(){
    string s = "ABCD";
    Solution solution;
    int result = solution.titleToNumber(s);
    cout<<result<<endl;
    return 0;
}