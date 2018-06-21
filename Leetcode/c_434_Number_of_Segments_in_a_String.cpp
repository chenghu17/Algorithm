//
// Created by Mr.Hu on 2018/6/21.
//
// leetcode 434 number of segments in a string
//
// 题目要求对给定的字符串，求其存在多少个部分，其中空格为划分符号
//
// 这个题目和第58题的思路有点像：对string进行遍历，给定一个bool型变量hasWord，即判断是否从word中来，还是从连续空格中过来；
// 如果当前位置为space，则判断前面是否为word，即hasWord是否为true，为则count++，将hasWord设置为false，继续进行遍历；
// 若为false，则前面没有word，为连续的space，则continue；
// 在遍历结束之后，还需要对hasWord进行判断，因为如果最后是一个word，则该hasWord没有在为space的判断中被检查过，
// 所以最后还需要再检查一个，为true，则count++并return，否则直接return count
//

#include <iostream>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        bool hasWord = false;
        int length = s.size();
        int count = 0;
        for (int i = 0; i < length; ++i) {
            if (s[i] == ' ') {
                if (hasWord) {
                    ++count;
                    hasWord = false;
                }
                continue;
            }
            hasWord = true;
        }
        return hasWord ? ++count : count;
    }
};

int main() {
    string s = " hi, how are you? ";
    Solution solution;
    int result = solution.countSegments(s);
    cout << result << endl;
    return 0;
}