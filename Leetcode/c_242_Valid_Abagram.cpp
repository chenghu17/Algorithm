//
// Created by Mr.Hu on 2018/5/17.
//
// leetcode 242 valid anagram
//
// 题目要求判断两个两个字符串是否为同字母异序词
//
// 刚开始理解以为只要两个字符串中出现的字母种类一样就可以了，经过两次提交，发现在部分case上通不过
// 发现原来不仅仅是要求字母种类一样，字母出现的次数也要一样多能返回为true
//
// 所以重新对代码进行了更新，基本思想是先使用map<char,int> tmp来表示字符串s中出现的字符种类和每个字符出现的次数
// 然后对字符串t进行迭代，如果字符串t中存在字符在tmp中不存在，则返回false；
// 如果字符串t中存在字符出现的次数比在tmp中出现的次数要多，则返回false；
// 对字符串t迭代结束后，判断tmp中的字符是否存在不等于0的情况，存在字符的value值不等于0说明字符串t中该字符出现的次数比s中少，则返回false；
// 最后返回true
// 这种方法的执行效率只超过了百分之三十多的accepted result
//
// 在写上面一段话的时候，突然想到可以先对字符串t和s的长度进行判断，如果两个字符串长度不一样，说明每个字符出现的次数不可能完全相同。
// 有了这样一个判断，上述方法中最后一步判断tmp中每个字符的value值是否为0就不需要了。因为长度的判断其实就是对这个判断的另一种方法。
// 重新提交了一下代码，方法是正确的，但是在时间消耗上并没有太大的提升，需要再想想别的好方法。
//
// 既然已经判断两个字符串长度一样，那么在对字符串s进行迭代的同时，也可以对字符串t进行迭代
// 对字符串s出现的字符在map中的keys中，则对其value进行++操作，对字符串t则进行--操作；
// 最后对map进行迭代，判断所有value值是否存在不等于1的情况，存在在返回false；
// 这样做的效果比上面的方法提高了10%左右。
//
// 在网上查了一下，有一种代码量极少，但是效率却很低的方法
// 即使用c++标准库中的sort()，该方法使用的排序算法类似于快排
// sort()函数在头文件#include <algorithm>中
// 其包含三个参数，第一个为数组起始位置，第二个为结束位置，第三个为排序方法，可以从小到大或者从大到小，默认从小到大
//



#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int size_s = s.size();
        int size_t = t.size();
         if(size_s!=size_t){
             return false;
         }
        map<char, int> tmp_s;
        for (int i = 0; i < size_s; i++) {
            tmp_s[s.at(i)]++;
        }
        for (int i = 0; i < size_t; i++) {
            if (tmp_s[t.at(i)] == 0) {
                return false;
            }
            tmp_s[t.at(i)]--;
        }
//        for (int i = 0; i < size_s; i++) {
//            if (tmp_s[s.at(i)] != 0) {
//                return false;
//            }
//        }
        return true;
    }

    bool isAnagram_second(string s, string t) {
        int size_s = s.length();
        int size_t = t.length();
        if(size_s!=size_t){
            return false;
        }
        map<char,int> tmp;
        for(int i=0;i<size_s;i++){
            tmp[s.at(i)]++;
            tmp[t.at(i)]--;
        }
        for(auto iter = tmp.begin();iter!=tmp.end();iter++){
            if(iter->second!=0){
                return false;
            }
        }
        return true;
    }


};

int main(){
    string s = "anagram";
    string t = "nagaram";
    Solution solution;
    bool isAnagram = solution.isAnagram(s,t);
//    bool isAnagram = solution.isAnagram_second(s,t);
    cout<<isAnagram<<endl;
}