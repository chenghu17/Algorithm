//
// Created by Mr.Hu on 2019/1/9.
//
// leetcode 13 roman to integer
//
// 题目给定一个场景：罗马字符与阿拉伯数字计数之间的联系，要求根据关系，将给出的罗马字符转换为阿拉伯数字。
//
// 根据题意，主要需要关注的就是4、9、40、90、400、900这六种情况。
// 罗马计数方式不存在进位关系，所以我们只需要把给定的字符串以正确的方式划分，然后累加即可。
// 但是这里存在一个问题，就是IIIV这种情况，它转换得到的数字为6。如果我们按从左向右遍历，则需要相当负责的判断，因为还存在其他情况。
// 没思路...
//
// 看了讨论区里面的一个解法，很妙！
// 从尾部开始遍历，如果当前位置所对应的数字比上一个数字小，说明应该为组合数字，而差值正好就是当前位置对应的数字，
// 所以我们先加上上一个数字，如果下一位比其小，则直接减去即可，如果比其大，则继续加上。向前继续遍历。
//

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> r2i = {{'I', 1},
                              {'V', 5},
                              {'X', 10},
                              {'L', 50},
                              {'C', 100},
                              {'D', 500},
                              {'M', 1000}};

        int length = s.length();
        int sum = r2i[s[length - 1]];
        for (int i = length - 2; i >= 0; --i) {
            if (r2i[s[i]] < r2i[s[i + 1]]) {
                sum -= r2i[s[i]];
            } else {
                sum += r2i[s[i]];
            }
        }
        return sum;
    }
};

int main() {
    string s = "MCMXCIV";
    Solution solution;
    int sum = solution.romanToInt(s);
    cout << "roman 2 integer: " << sum;
    return 0;
}