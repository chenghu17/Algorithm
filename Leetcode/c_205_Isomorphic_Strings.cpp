//
// Created by Mr.Hu on 2018/5/20.
//
// leetcode 205 isomorphic strings
//
//
//

#include <iostream>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> tmp;
        set<char> tmp_s, tmp_t;
        int size_s = s.length();
        int size_t = t.length();
        if (size_s != size_t) {
            return false;
        }
        for (int i = 0; i < size_s; i++) {
            tmp_s.insert(s[i]);
            tmp_t.insert(t[i]);
            if (tmp[s[i]] == NULL) {
                tmp[s[i]] = t[i];
            } else if (tmp[s[i]] != t[i]) {
                return false;
            }
        }
        return tmp_s.size() == tmp_t.size();
    }
};

int main(){
    string s = "title";
    string t = "paper";
    Solution solution;
    bool result = solution.isIsomorphic(s,t);
    cout<<result<<endl;
}