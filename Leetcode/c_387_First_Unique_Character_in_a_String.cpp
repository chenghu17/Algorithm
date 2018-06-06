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
// 代码已经accpted，但是执行时间上只超过来百分之二十多的结果。原因就在于使用map的key来查询value值是一个很慢的过程。
// 所以想到能否用list来作为存储对象，但是list的index必须为int型，所以遇到了难题...
//
// 查了一下别人的solution，发现是可以用list来存储对象的，因为字符串中都是小写字母，而小写字母的个数是有限的，
// 即26个，所以我们可以将小写字母的ASCII码值映射到0-25，即小写字母的ASCII码值减去a的ASCII码值97即可。
// 这种方式的执行效率就超过了百分之八十多的结果。
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

    int firstUniqChar_optimal(string s) {
        int result[26] = {};
        int c;
        for (auto m:s) {
            c = m - 97;
            result[c]++;
        }
        for (int i = 0; i < s.length(); i++) {
            c = s[i] - 97;
            if (result[c] == 1) {
                return i;
            }
        }
        return -1;
    }

};

int main() {
    string s = "loveyouloveyou";
    string q = "aabbccd";
    Solution solution;
    int index_s = solution.firstUniqChar(s);
    int index_q = solution.firstUniqChar_optimal(q);
    cout << index_s << endl;
    cout << index_q << endl;
    return 0;
}