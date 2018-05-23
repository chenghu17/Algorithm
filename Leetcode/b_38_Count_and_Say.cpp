//
// Created by Mr.Hu on 2018/5/23.
//
// leetcode 38 count and say
//

#include<iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string init = "1";
        for(int i=1;i<n;i++){
            int count = 0;
            int number = 0;
            string tmp = "";
            int size = init.length();
            for(int j=0;j<size;j++){
                if(int(init[j]-'0') == (number)){
                    count ++;
                }
                else{
                    if(count!=0){
                        tmp = tmp + to_string(count) + to_string(number);
                    }
                    number = int(init[j]-'0');
                    count = 1;
                }
            }
            tmp = tmp + to_string(count) + to_string(number);
            init = tmp;
        }
        return init;
    }
};

int main(){
    int n = 4;
    Solution solution;
    string result = solution.countAndSay(n);
    cout<<result<<endl;
    return 0;
}