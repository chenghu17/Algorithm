//
// Created by Mr.Hu on 2019/1/7.
//
// leetcode 290 word pattern
//
// 题目给定两个字符串，第一个为模式串，第二个为匹配串，要求匹配串符合模式串的模式。
//
// 这个题目主要是考察对hash的运用。我提交了三次才accepted。
// 因为我没有完整考虑到各种case。最开始我只使用了pattern2word这样一个map来保存一一对应的关系，但是当case为（pattern，str2）时，无法判断准确。
// 于是我将key-value值替换，变成word2pattern的map来保存一一对应的关系，但是当case为（pattern，str1）时，则无法判断准确
// 因此，我们需要维护两个map，来保证一一对应的关系。每次对得到的word和pattern进行双向验证。
//
// 其实如果使用python来写，一个map就可以搞定，因为python是可以直接得到key和value的数组列表的，只要判断二者都在或者都不在，则可继续，否则为false
//

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        // 保证双向关系
        map<char, string> pattern2word;
        map<string, char> word2pattern;
        //对于string的截取，可以使用find方法，也可以进行遍历然后利用string的substr
        int pattern_size = pattern.length();
        int substr_size = 0;
        int left = 0;
        for (int i = 0; i < str.length(); i++) {
            // 此处返回的是char，也可以说是ASCII码
            if (str[i] == ' ' || i == str.length() - 1) {
                substr_size;
                if (substr_size + 1 > pattern_size) {
                    return false;
                }
                string substr = i == str.length() - 1 ? str.substr(left, i + 1 - left) : str.substr(left, i - left);
                char pattern_key = pattern[substr_size];

                auto it_pattern = word2pattern.find(substr);
                auto it_word = pattern2word.find(pattern_key);

                if (it_pattern != word2pattern.end()) {
                    if (it_pattern->second != pattern_key) {
                        return false;
                    }
                } else if (it_word != pattern2word.end()) {
                    if (it_word->second != substr) {
                        return false;
                    }
                } else {
                    word2pattern[substr] = pattern_key;
                    pattern2word[pattern_key] = substr;
                }
                left = i + 1;
                substr_size++;
            }
        }
        return substr_size == pattern_size;
    }
};

int main(){
    string pattern = "abba";
    string str1 = "dog cat cat fish";
    string str2 = "dog dog dog dog";
    string str3 = "dog cat cat dog";

    Solution solution;

    bool exist_pattern1 = solution.wordPattern(pattern,str1);
    bool exist_pattern2 = solution.wordPattern(pattern,str2);
    bool exist_pattern3 = solution.wordPattern(pattern,str3);

    cout<<"pattern1 exist?"<<exist_pattern1<<endl;
    cout<<"pattern2 exist?"<<exist_pattern2<<endl;
    cout<<"pattern3 exist?"<<exist_pattern3<<endl;

    return 0;
}