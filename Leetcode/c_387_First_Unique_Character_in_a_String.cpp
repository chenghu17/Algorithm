//
// Created by Mr.Hu on 2018/6/6.
//
// leetcode 387 first unique character in a string
//
// 这个题目要求对于给定的字符串，寻找第一个只出现一次的字符，返回其index，如果不存在，则返回-1
//
// 刚来是想这个题目的时候，想用双层循环去每个字符判断，但是复杂度会达到O(n*n)，
// 因为每个字符必须与其他所有字符进行比较，所以果断放弃这种方法。
//
// 然后回归到hash table中，对字符串遍历一次，使用map<char,int>记录每个字符出现的次数，
// 然后再重新遍历一次，每次在hash table中去查询当前字符出现的次数，如果次数等于1，
// 则将index值赋值为当前的位置，break，结束循环，return index;
//

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int index = -1;
        map<char, int> result;
        for (auto m:s) {
            result[m]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (result[s[i]] == 1) {
                index = i;
                break;
            }
        }
        return index;
    }
};

int main() {
    string s = "loveyouloveyou";
    Solution solution;
    int index = solution.firstUniqChar(s);
    cout << index << endl;
    return 0;
}