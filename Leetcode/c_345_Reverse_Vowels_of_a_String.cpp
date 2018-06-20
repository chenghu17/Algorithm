//
// Created by Mr.Hu on 2018/6/20.
//
// leetcode reverse vowels of a string
//
// 题目要求将字符串中的元音字母进行翻转，其他不变。
//
// 元音字母有（a，e，i，o，u）五种，算上大小写就是十种。第一种方法使用set存储十种元音字母，
// 然后对字符串进行遍历，将所有元音字母按照顺序使用vector存储起来，
// 然后再将这个vector进行reserve，接着对原字符串进行遍历，遇到第n个元音字母，就用翻转后的vector中的第n个进行替换。
// 最后输出string s即可。但是这种方式只beat掉来百分之十二的accepted solution。
//
// 于是想了第二种方法，即不需要将字符串s中的元音字母存储起来，只需要将其index值存储起来，然后首尾对称的index值
// 在string s中的字母进行swap交换就可以了。这种方法的code即为下面的optional，最终的结果beat掉了百分之三十多的accpetd solution。
//
// 这个题目让我复习了一下set的用法，set使用count来判断某个元素是否存在只针对于int型，其他type无法使用这种方法。
//
// 然后就是用STL中自带的reverse方法，其参数是vector的begin()和end()地址
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        set<int> voewls = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<int> tmp;
        for (int i = 0; i < s.size(); ++i) {
            if (voewls.count(s[i])) {
                tmp.push_back(s[i]);
            }
        }
        if (tmp.size() == 0) {
            return s;
        }
        reverse(tmp.begin(), tmp.end());
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (voewls.count(s[i])) {
                s[i] = tmp[count];
                ++count;
            }
        }
        return s;
    }

    string reverseVowels_optional(string s) {
        set<int> voewls = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<int> index;
        for (int i = 0; i < s.size(); ++i) {
            if (voewls.count(s[i])) {
                index.push_back(i);
            }
        }
        int length = index.size();
        if (length == 0) {
            return s;
        }
        int change;
        for (int j = 0; j < length / 2; ++j) {
            change = s[index[j]];
            s[index[j]] = s[index[length - 1 - j]];
            s[index[length - 1 - j]] = change;
            // swap(s[index[j]], s[index[length-1-j]]);
        }
        return s;
    }


};

int main() {
    string s = "leetcode";
    Solution solution;
    string result = solution.reverseVowels(s);
    cout << result << endl;
    return 0;
}