//
// Created by Mr.Hu on 2019/1/21.
//
// leetcode 784 letter case permutation
//
// 题目给定一个字符串S，其中只包含数字和字母，要求对字母进行变换，小写变成大写，大写变成小写。可变可不变。
// 经过变换后，总共有多少个不同的字符串。
//
// 这个题目和401很像，当然都是属于backtracking，401中包含了两个选与不选的问题，而这个问题中只包含的一个选与不选的问题。
// 所以同样使用递归的思想，参数为idx，S。idx表示当前可能需要变换的位置，S为当前的字符串（前面可能已经有部分字符发生了大小写变化）
// 递归的主体：首先判断idx与S的大小，如果相等，说明已经对S遍历完，此时的S即为最终变换后的结果，可以放入到res中。
// 否则判断当前字符是否为字母，如果为字母，则存在两种情况，即变换与不变换：不变换则idx+1，变换则需要判断当前字符是小写还是大写，
// 然后变换为相反情况，最后将变换后的S，以及idx+1传入到递归方法的参数中，
// 如果当前位置是数字，则不需要变换，idx+1，然后S传入即可。
// 最后递归结束后，res中即为所有可能的变换情况。
//
// 总结：像这种排列组合的题目，选与不选，更新操作，用递归的方式进行解答相当清晰
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> res;

    void dfs(int idx, string S) {
        if (idx == S.size()) {
            res.push_back(S);
        } else if (isalpha(S[idx])) {
            dfs(idx + 1, S);
            S[idx] = isupper(S[idx]) ? tolower(S[idx]) : toupper(S[idx]);
            dfs(idx + 1, S);
        } else {
            dfs(idx + 1, S);
        }
    }


    vector<string> letterCasePermutation(string S) {
        dfs(0, S);
        return res;
    }
};

int main() {
    string S = "abCd12";
    Solution solution;
    vector<string> res = solution.letterCasePermutation(S);
    for (auto s:res) {
        cout << s << ",";
    }
    return 0;
}