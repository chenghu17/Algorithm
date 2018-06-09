//
// Created by Mr.Hu on 2018/6/9.
//
// leetcode find all anagrams in a string
//
// 题目要求给定一个字符串s和一个非空字符串p，找出s中所有子串为字符串p的同字母异构体的索引（index）值列表。
//
// 这个题目刚开始的思想就是使用substr获得子串sub，然后把子串sub和字符串p用sort排序，最后判断两个排序后的字符串是否相等。
// 但是这个方法自己测试没问题，提交后有一个case，s和p的长度都非常长，这就导致每次sort的耗时累积起来相当大，这就导致了time limited error。
//
// 所以就想了另外一种方法：将p中字母映射到0-25，然后记录每个字母出现的个数，对于字符串s的子串，也采用这样的方式；
// 每次对子串中所有字母出现的次数与p中出现的次数进行对比，这个遍历就只需要对26个索引值进行，
// 如果26个字母出现的个数都相同，则说明这两个字符串属于anagram，记录当前的索引值。
// 最后accepted，但是看了一下runtime，只超过了百分之八的结果...
//
// 其实这个题目引申出来就会一个海量数据中数据匹配的问题
//
// 查看了别人的方法，发现我有一个地方是可以改进的，就是每次取substr的地方，我在记录第一个substr中所有字母出现的次数之后，
// 当我的首字母指针往前移动一个时，其实我只是低调了第一个字母，然后加进行来原子串的下一位，所以我只需要更新这两个元素就行。
// 由于第一个字串需要全部计算，我们可以将其单独进行计算，后面的子串依赖前面的结果简单更新就行。
// 于是做来改动，发现最终的结果超过来百分之五十多的结果。
//
// 因为第一次和接下来的n次都需要进行字母数组是否相同的判断，所以我将其提取出一个函数，然后再执行，发现超过了百分之九十八的结果...
// 逻辑没有变，只是抽象出一个函数，说明避免重复代码块还是很有用的，
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> tmp;
        int p_voca[26] = {};
        int p_size = p.length();
        int s_size = s.length();
        for (int i = 0; i < p_size; i++) {
            p_voca[p[i] - 97] += 1;
        }
        for (int i = 0; i <= s_size - p_size; i++) {
            int s_voca[26] = {};
            string sub = s.substr(i, p_size);
            for (int j = 0; j < p_size; j++) {
                s_voca[sub[j] - 97] += 1;
            }
            bool same = true;
            for (int q = 0; q < 26; q++) {
                if (p_voca[q] != s_voca[q]) {
                    same = false;
                    break;
                }
            }
            if (same) {
                tmp.push_back(i);
            }
        }
        return tmp;
    }
};


class Solution_optimal {
public:
    void push_right_index(int p_voca[], int s_voca[], vector<int> &tmp, int index) {
        bool same = true;
        for (int q = 0; q < 26; q++) {
            if (p_voca[q] != s_voca[q]) {
                same = false;
                break;
            }
        }
        if (same) {
            tmp.push_back(index);
        }
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> tmp;
        int p_voca[26] = {};
        int s_voca[26] = {};
        int p_size = p.length();
        int s_size = s.length();
        if (s_size < p_size)
            return tmp;
        for (int i = 0; i < p_size; i++) {
            p_voca[p[i] - 97] += 1;
            s_voca[s[i] - 97] += 1;
        }
        push_right_index(p_voca, s_voca, tmp, 0);

        for (int i = p_size; i < s_size; i++) {
            s_voca[s[i] - 97] += 1;
            s_voca[s[i - p_size] - 97] -= 1;
            push_right_index(p_voca, s_voca, tmp, i - p_size + 1);
        }
        return tmp;
    }
};

int main() {
    string s = "aaaabbvfbbbbbbvgewdf";
    string p = "bbv";
    Solution_optimal solution;
//    Solution solution;
//    vector<int> result = solution.findAnagrams(s, p);
    vector<int> result = solution.findAnagrams(s, p);
    for (auto it = result.begin(); it != result.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}