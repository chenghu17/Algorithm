//
// Created by Mr.Hu on 2019/1/8.
//
// leetcode 953 verifying an alien dictionary
//
// 看了一会儿题目没看懂...
// 刚开始以为是判断每个词内部的顺序，后来才了解到：给定一些words，以及字母顺序表，判断这些词之间是否按照字母表大小顺序排列，
// 即从每个词的第一位开始开始判断，相邻的words的对应位置，前者要小于后者。（注意：如果超过了某个词的长度，则为空格，其值小于字母）
//
// 理解了题目意思之后要开始想方法：很明显我们需要对每个词的对应位置进行对比，而这个大小是根据给定的顺序进行判断的。
// 先预处理给定的orders，用map<char,int>来保存顺序从左到右的遍历顺序，（最近总喜欢将map写成set）
// 得到顺序之后，再开始逐个位置进行判断，因为题目给定所有词的长度不超过20时，所以最外层的循环判断条件就是i<21，
// 然后就是遍历每个词，根据大小传递关系，每次判断当前和下一个的大小关系即可，A<=B,B<=C 得到 A<=C;
//
// 在对指定位置进行判断时，我们要弄清楚有多少中情况，
// 1、如果当前位置同时超过了当前词的长度和下一个词的长度，或者只超过当前词，则继续循环；
// 2、否则，如果只超过下一个词，则reutrn false；（空格比字母的"小"）
// 3、否则，如果都没查过，则可以开始取对应位置字符；如果相等，则需要判断下一个位置的情况，因此我们维护了一个has_same，
// 令has_same为true，说明需要进行下一个位置的判断
// 4、如果满足小于的情况，则进行循环，否则即是大于的情况，直接return false；
//
// 在当前循环结束后，判断has_same的情况，如果为false，即词列表呈现的是递增关系，后面的位置无需继续判断。
// 直接结束循环，返回true。否则，需要继续判断下一个对应位置。
//
// 注意：上面的判断顺序不能错位，特别是对于当前位置是否超过了字符大小，这个应该放在最前面，不然会导致索引不知道搜索到哪个空间。
// 我刚开始就交换了1和3，程序也accepted，花费了16ms，交换之后，只需要8ms，说明越界带来的搜索相当耗时。
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string> &words, string order) {
        map<char, int> alphabet_order;
        for (int i = 0; i < 26; i++) {
            alphabet_order[order[i]] = i + 1;
        }
        bool has_same;
        for (int i = 0; i < 21; i++) {
            has_same = false;
            for (int j = 0; j < words.size() - 1; j++) {
                if (i >= words[j].size() && i >= words[j + 1].size() || i >= words[j].size()) {
                    continue;
                } else if (i >= words[j + 1].size()) {
                    return false;
                } else if (alphabet_order[words[j][i]] == alphabet_order[words[j + 1][i]]) {
                    has_same = true;
                } else if (alphabet_order[words[j][i]] < alphabet_order[words[j + 1][i]]) {
                    continue;
                } else {
                    return false;
                }
            }
            if (!has_same) {
                break;
            }
        }
        return true;
    }
};

int main() {
    vector<string> words = {"hello", "leetcode"};
    string orders = "hlabcdefgijkmnopqrstuvwxyz";
    Solution solution;
    bool sorted = solution.isAlienSorted(words, orders);
    cout << "is sorted? " << sorted << endl;
    return 0;
}

