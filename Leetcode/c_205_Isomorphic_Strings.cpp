//
// Created by Mr.Hu on 2018/5/20.
//
// leetcode 205 isomorphic strings
//
// 题目要求判断两个字符串是否为同构字符串，即字符串s中的属于同一个字符被替换为另外一个，
// 不同的字符所映射的字符要求不一样，字符可以映射为其自身
//
// 这一个题目我的做法和c_242比较像，对于字符串s中的字符先存储在map的keys中，字符串t中的字符则对应与
// 相同位置上map[key]的value 值，如果s中相同的字符对应于t中字符不相同，则return false；
// 在coding完之后，有一个case报错，s="ab",t="aa"，通过上面的逻辑 map[a] = a,map[b] = a,
// 这样就出现了两个不同的字符映射到同一个字符中；其实这就是我们code中的bug：
// 我们的思想是对于s中相同的字符，所对应的t中字符必须相同，即tmp[s[i]]不为NULL时，tmp[s[i]]==t[i];
// 但是疏忽了t中相同字符对应于s中字符也相同的情况，tmp[s[i]] != NULL时的判断只能是判断同构的必要条件，而不是充分必要条件。
// 所以我又加了一个set来分别存储s和t中出现的字符，要满足同构，s和t中出现的字符种类数还必须相等。
// 但是使用了这么多数据结构，程序最终的执行效率比较低，只超过了百分之十五的accepted结果。
//
// 在官网上查看了别人提交的代码，行数少，而且执行效率高；
// 那个256应该是ASCII的范围
// 对于s和t上同一位置的字符分别计数，他们各自的出现个数应该是相同的，所以这样就能保证对应
// 而不是前者作为后者的判断或者后者作为前者的判断。
// 这种方法值得多思考。
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

    bool isIsomorphic_optimal(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};

int main() {
    string s = "title";
    string t = "paper";
    Solution solution;
    bool result = solution.isIsomorphic_optimal(s, t);
    cout << result << endl;
}