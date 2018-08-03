//
// Created by Mr.Hu on 2018/8/3.
//
// leetcode 392 is subsequence
//
// 题目要求判断字符串s是否为字符串t的子序列，即能否在字符串t中不改变字符顺序的前提下拼接出字符串s。
//
// 这个题目是我在leetcode上随机pick one得到的，这个题目来的正是时候。
// 为什么说正是时候呢？因为最近几天正在看关于字符串相关的算法，然后有很多模糊区域，这个题目让我对这类问题更加清晰。
//
// 首先我来说说我刚开始看到这个题目思路，我想从两个字符串的末尾开始判断，如果当前字符相同，我只需要判断两个
// 字符串的子串，子串可以通过string.substr(begin,length)得到，然后继续判断。如果不相等，我们不改变s，将
// t字符串取t.substr(begin,length-1)，继续比较。这就是采用递归的方式进行解答。
// 然后我还傻傻的想，如果第一种情况下最终递归结果为false，那我是不是应该回溯一下，在第一种情况下还要考虑
// s不变，t.substr(begin,length-1)来递归一下。于是有了下面code中的isSubsequence，而该方法的注释部分就是
// 我在判断s[length-1]==t[length-1]的情况下进行递归，最终结果为匹配不到，只将t减少末尾一位，而s不变的操作。
//
//
// 好了，上面就是我滑稽而迷糊的操作。
// 当然这种操作在s和t长度较小的情况是可以得到正确结果的，但是题目指出，t的长度可以达到500000，而我每次做递归都
// 将s和t进行传递，而这种传递是拷贝字符串，而不是引用，所以就导致了最后的memory limit exceeded错误。
//
// 除了这一点以外，另外主要一点，就是我在isSubsequence方法中注释的那一部分，在s[s_length-1]==t[t_length-1]
// 的情况下，进行递归操作，最终的递归返回的结果为false时，我去进行isSubsequence(s,t.substr(0,t_length-1))操作。
// 其实这个操作是多余无用的，只会增加计算量，对最终的结果没有影响。
//
// 我为什么会有这种想法呢，我分析了一下：之所以进行这样的操作，是因为在"字符串的模式匹配"中，如果两个字符相等，继续后面的
// 判断，如果最终没有匹配到，此时模式串回到第一个字符位置，而在BF方法中，字符串则回到原来与模式串第一位相等的字符的下一位。
//
// 没错，正是因为将"字符串的模式匹配"与"字符串子序列"混淆，导致我增加了这个多余的操作。
// 对于"字符串的模式匹配"，是要求找到与模式串相同的子串，而这个子串在字符串中必须是连续的。
// 对于"字符串子序列"，要求就没有那么严格，只需要字符在顺序上一致就行。
// 所以对于s[length-1]==t[length-1]的情况，我们只需要去继续执行
// isSubsequence(s.substr(0, s_length - 1), t.substr(0, t_length - 1))，
// 因为如果这样执行最终得到false的结果，说明t剩下子串中没有包含s剩下子串的，
// 计算增加注释中的操作，一个更小的t子串更加不可能包含原本的s串。
//
// 所以不管是这个简单的判断子序列是否存在，还是常见问题Longest Common Subsequence（最长公共子序列）
// 在遇到s[s_length] == t[t_length]时，只需要判断s和t剩下部分的情况即可，无需判断t剩下部分与s的情况，因为这是无用的。
// 而在"字符串的模式匹配"中就需要继续考虑剩下t与s的关系，毕竟它要求的是连续字符串，而一个字符一个字符的BF方法
// 时间复杂度达到O(m*n)，所以就有了线性时间的KMP方法。
//
// 这个题目采用递归的方法会导致内存不够，因为每次需要将两个字符串进行值传递，
// 所以采用双层循环的方式，即code中的isSubsequence_optimal的方法，对子序列s进行遍历
// 在t中寻找与s中当前位置相同的字符，使用一个bool变量来表示是否存在，如果不存在，则直接return false，
// 如果存在，则继续s的一下位，而t则从上一个相同字符的下一位开始，我们之前可以用一个loc变量来保存之前的位置
//
// 这种子序列的问题还是相对比较简单的，相等于用两个指着，而时间复杂度为O(m+n)，
// 通过这个题目，让我对子序列和字符串匹配这两类问题的认识更加清晰。
//
// 另一个思考，题目另外问如果s是一系列字符串，不断的输入，应该如何更改代码呢？
// 值得思考🤔
//


#include <iostream>
using namespace std;


class Solution {
public:
    //  这种方法可以说是使用 贪心算法 的思想
    bool isSubsequence_optimal(string s, string t) {
        bool result = false;
        int t_length = t.size();
        int loc = 0;
        for (auto c:s) {
            result = false;
            for (int i = loc; i < t_length; ++i) {
                if (c == t[i]) {
                    result = true;
                    loc = i + 1;
                    break;
                }
            }
            if (!result) {
                return false;
            }
        }
        return true;
    }

    bool isSubsequence(string s, string t) {
        bool result;
        int s_length = s.size();
        int t_length = t.size();
        if (s_length == 0) {
            return true;
        }
        if (s_length > t_length) {
            return false;
        }
        if (s[s_length - 1] == t[t_length - 1]) {
            result = isSubsequence(s.substr(0, s_length - 1), t.substr(0, t_length - 1));
            // 此处无需再判断结果，之前认识存在误区
            // if(!result){
            //     result = isSubsequence(s,t.substr(0,t_length-1));
            // }
        } else {
            result = isSubsequence(s, t.substr(0, t_length - 1));
        }
        return result;
    }
};

int main(){
    string s = "abcdefg";
    string t = "aabbccddeeffgg";
    Solution solution;
//    bool result = solution.isSubsequence(s,t);
    bool result = solution.isSubsequence_optimal(s,t);
    cout<<result<<endl;
    return 0;
}