//
// Created by Mr.Hu on 2018/8/3.
//
// leetcode 392 is subsequence
//
// 
//
//
//
//
//
//


#include <iostream>

using namespace std;


class Solution {
public:


    bool isSubsequence_optimal(string s, string t) {
        bool result = false;
        int t_length = t.size();
        int loc = 0;
        for (auto c:s) {
            result = false;
            for (int i = loc; i < t_length; ++i) {
                if (c == t[i]) {
                    result = true;
                    loc = i + 1;
                    break;
                }
            }
            if (!result) {
                return false;
            }
        }
        return true;
    }

    bool isSubsequence(string s, string t) {
        bool result;
        int s_length = s.size();
        int t_length = t.size();
        if (s_length == 0) {
            return true;
        }
        if (s_length > t_length) {
            return false;
        }
        if (s[s_length - 1] == t[t_length - 1]) {
            result = isSubsequence(s.substr(0, s_length - 1), t.substr(0, t_length - 1));
            // 此处无需再判断结果，之前认识存在误区
            // if(!result){
            //     result = isSubsequence(s,t.substr(0,t_length-1));
            // }
        } else {
            result = isSubsequence(s, t.substr(0, t_length - 1));
        }
        return result;
    }
};

int main(){
    string s = "abcdefg";
    string t = "aabbccddeeffgg";
    Solution solution;
//    bool result = solution.isSubsequence(s,t);
    bool result = solution.isSubsequence_optimal(s,t);
    cout<<result<<endl;
    return 0;
}