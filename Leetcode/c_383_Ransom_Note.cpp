//
// Created by Mr.Hu on 2018/6/20.
//
// leetcode 383 ransom note
//
// 题目要求判断ransomNote是否能从给定的字符串中magazine得到，字符种类和个数不能超过magazine中情况
//
// 对magazine中出现的字符进行统计，用vector进行存储，index即为字符的顺序。
// 然后对ransomNote进行遍历，对vector进行--操作，如果vector中存在负，则返回false，否则最后返回true。
//
// 注：刚开始用int数组来初始化所有字符出现的情况，但是初始化结果并不都是0，所以一直报错，改用vector后不再出现问题。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> magaz(26);
        int tmp;
        for (int i = 0; i < magazine.size(); ++i) {
            tmp = magazine[i] - 97;
            magaz[tmp]++;
        }
        for (int j = 0; j < ransomNote.size(); ++j) {
            tmp = ransomNote[j] - 97;
            magaz[tmp]--;
            if (magaz[tmp] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string ransomNote = "ab";
    string magazine = "ab";
    Solution solution;
    bool result = solution.canConstruct(ransomNote, magazine);
    cout << result << endl;
    return 0;
}