//
// Created by Mr.Hu on 2018/5/17.
//
//
//



#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int size_s = s.size();
        int size_t = t.size();
        // if(size_s!=size_t){
        //     return false;
        // }
        map<char, int> tmp_s;
        // map<char,int> tmp_t;
        for (int i = 0; i < size_s; i++) {
            tmp_s[s.at(i)]++;
        }
        for (int i = 0; i < size_t; i++) {
            if (tmp_s[t.at(i)] == 0) {
                return false;
            }
            tmp_s[t.at(i)]--;
        }
        for (int i = 0; i < size_s; i++) {
            if (tmp_s[s.at(i)] != 0) {
                return false;
            }
        }
        return true;
    }
};

int main(){
    string s = "anagram";
    string t = "nagaram";
    Solution solution;
    bool isAnagram = solution.isAnagram(s,t);
    cout<<isAnagram<<endl;
}