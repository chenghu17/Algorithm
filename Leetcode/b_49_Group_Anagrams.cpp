//
// Created by Mr.Hu on 2018/9/2.
//
// leetcode 49 group anagrams
//
// 题目要求对于给定的字符串组进行归类，对于字符串中字母种类和个数出现相同的，则认为为同构体，归为一类
//
// 说实话，刚开始看到这个题目的时候，看到有九百多个人点赞这个题目，我认为这个题目是一个很有技巧的题目，
// 所以想了好久，但是发现对于两个字符串，去判断是否为同构体，还是比较简单的，但是对于这么多类的同构体，
// 如果每个都去构建一个长度为26的字符数组存储各种字符出现的次数，实在是太麻烦了，所以想了好久的匹配方法。
// 刚开始想过对字符串内字符进行排序，然后再比较，但是由于排序是一个很麻烦的过程，所以把这个想法放弃了。
//
// 直到我看了leetcode上推荐的方法，我才发现我想多了。因为推荐的方法一中就是将字符串进行排序。
// 汗......
// 所以我就使用这种方法进行coding，不过这个题目又让我复习了map的定义方法，然后在使用sort对string进行排序，以及map的循环方法
// 其中，map的key为排序后的字符，value为vector<string>，用来保存为同构体的原字符串，最后对map进行遍历，将value中的所有vector
// 存入到vector<vector<string>>中，即最终分类的结果。
//
// 最后忍不住踩了一下这个题目
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 基本想法：对于每一个string，可以使用hash来存储它们中字符出现的次数
        // 然后比较每个字符串之间字符出现的情况，如果相同，则归属与一类，否则为另外一类
        // 但是这里可使用一个map来存储多个类别的字符串出现情况，当一个新字符串出现时，就可以逐个map中的value去比较

        vector<vector<string>> result;
        map<string,vector<string>> str_dict = map<string,vector<string>>();
        string tmp;
        for(int i=0;i<strs.size();++i){
            tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            str_dict[tmp].push_back(strs[i]);
        }
        for(auto it=str_dict.begin();it!=str_dict.end();++it){
            result.push_back(it->second);
        }
        return result;
    }
};

int main() {
    vector<string> strs;
    strs.emplace_back("eat");
    strs.emplace_back("tea");
    strs.emplace_back("tan");
    strs.emplace_back("ate");
    strs.emplace_back("nat");
    strs.emplace_back("bat");
    Solution solution;
    vector<vector<string>> result = solution.groupAnagrams(strs);
    for(int i=0;i<result.size();++i){
        for(int j=0;j<result[i].size();++j){
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}