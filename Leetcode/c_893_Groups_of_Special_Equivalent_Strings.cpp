//
// Created by Mr.Hu on 2019/1/17.
//
// leetcode 893 groups of special equivalent strings
//
// 题目给定一些字符串，要求判断存在多少类"特殊等价"的字符串。规定"特殊等价"是对一个字符串进行多次moves操作，能够转换成两外一个字符产，
// 那么这两个字符串"特殊等价"，而这些moves操作需要满足：i%2==j%2，即i和j为需要移动字符的索引值。
//
// 分析：这里主要要弄明白moves操作的含义：i%2==j%2，即i和j要么为偶数，要么为奇数，
// 也就是说对于两个字符串，它们的奇数位上出现字符情况相同，偶数位也相同，则这两个字符串可以通过多次moves变换，从而"特殊等价"。
//
// 所以我们接下来的任务就是要分别统计每个字符串的奇数位置和偶数位置的字符出现情况；
// 我这里使用map来分别存储，即每个字符串会得到两个map<char,int>，然后来比较每个词的这两个map；
// 这样操作思路完全没问题，实现方式最后的结果只超过了百分之零点九的答案。
//
// 写一种accepted solution中高效的方式，用一个pair<string,tring>来保存奇数位和偶数位的字符，保存之前先排序
// 最后将所有的pair放入set中，set的大小就是最终的种类数目。
//

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    // 分别得到词的奇数位和偶数位的字母出现情况
    vector<map<char, int>> get_word_odd_even(string S) {
        vector<map<char, int>> result;
        map<char, int> even, odd;
        for (int i = 0; i < S.length(); i += 2) {
            if (even.find(S[i]) != even.end()) {
                even[S[i]] += 1;
            } else {
                even[S[i]] = 1;
            }
        }
        for (int i = 1; i < S.length(); i += 2) {
            if (odd.find(S[i]) != odd.end()) {
                odd[S[i]] += 1;
            } else {
                odd[S[i]] = 1;
            }
        }
        result.push_back(even);
        result.push_back(odd);
        return result;
    }

    // 判断两个map是否相同
    bool is_same(map<char, int> &res1, map<char, int> &res2) {
        if (res1.size() != res2.size()) {
            return false;
        }
        for (auto it = res1.begin(); it != res1.end(); it++) {
            if (res2.find(it->first) == res2.end()) {
                return false;
            } else if (res2[it->first] != it->second) {
                return false;
            }
        }
        return true;
    }

    int numSpecialEquivGroups(vector<string> &A) {
        // 奇数位才能相互交换，偶数位相互交换
        int count = 0;
        string cur;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == "") {
                continue;
            }
            count++;
            cur = A[i];
            A[i] = "";
            for (int j = i + 1; j < A.size(); j++) {
                if (A[j] == "") {
                    continue;
                }
                vector<map<char, int>> res1 = get_word_odd_even(cur);
                vector<map<char, int>> res2 = get_word_odd_even(A[j]);
                if (is_same(res1[0], res2[0]) && is_same(res1[1], res2[1])) {
                    A[j] = "";
                }
            }
        }
        return count;
    }

    int numSpecialEquivGroups_optimal(vector<string>& A) {
        // 奇数位才能相互交换，偶数位相互交换
        set<pair<string,string>> res;
        for(int i=0;i<A.size();i++){
            string even="",odd="";
            for(int j=0;j<A[i].length();j+=2){
                even += A[i][j];
            }
            for(int k=1;k<A[i].length();k+=2){
                odd += A[i][k];
            }
            sort(even.begin(),even.end());
            sort(odd.begin(),odd.end());
            res.insert(make_pair(even,odd));
        }
        return res.size();
    }
};

int main() {
    vector<string> A = {"abc", "acb", "bac", "bca", "cab", "cba"};
    Solution solution;
    int count_optimal = solution.numSpecialEquivGroups_optimal(A);
    int count = solution.numSpecialEquivGroups(A);
    cout << "special equivalent number = " << count << endl;
    cout << "special equivalent number = " << count_optimal << endl;
    return 0;
}