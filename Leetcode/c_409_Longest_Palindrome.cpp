//
// Created by Mr.Hu on 2018/6/8.
//
// leetcode 409 longest palindrome
//
// 这个题目要求从给定的字符串中提取字符，组成回文串，求该回文串最大的长度
//
// 题目已经说明了字符串区分大小写，所以我们在对字符中所有字符进行保存时，就要区分大小写
// 但是ASCII码中A的值为65，a的值为97，中间还包含其他的字符，所以我们在初始化数组时，就需要把这些数组的位置空出来
// 经过计算，通过ASCII码映射到数字需要58个数字才能保留，所以初始化int数组为58
// 然后遍历字符串中所有的字符，记录其在字符串中出现的次数；
//
// 最后，对字符数组进行遍历，我们都知道，回文串字符都是一一对应的，所以对于每个字符出现的次数，我们取其最大偶数个数
// 即如果一个字符出现5次，那么我们至少需要拿4个，这样才能保证一一对应。(length/2)*2就可以达到这种效果
// 另外还有一种情况，如果字符串长度中存在某一个字符出现的次数为奇数，那说明我们在回文串中可以把其放在中间位置，无需一一对应。
// 而这个位置只能放一个数，一旦我们判断存在这样奇数，我们就不需要继续寻找，于是就有一个bool变量来保存这个状态。
// 最后循环结束后，判断bool值，如果为true，则在回文串长度上加一，如果为false，则直接输出回文串长度。
// 最终的结果超过来百分之九十八的cpp accpeted
//

#include <iostream>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int low[58] = {};
        int tmp = 0;
        int re_length = 0;
        for (int i = 0; i < s.length(); i++) {
            tmp = s[i] - 65;
            low[tmp]++;
        }
        bool is_single = false;
        for (int i = 0; i < 58; i++) {
            if (!is_single) {
                if (low[i] % 2 != 0) {
                    is_single = true;
                }
            }
            re_length += (low[i] / 2) * 2;
        }
        return is_single ? re_length + 1 : re_length;
    }
};

int main() {
    string s = "abcdefgabcdef";
    Solution solution;
    int length = solution.longestPalindrome(s);
    cout << length << endl;
    return 0;
}


//
//Python代码实现：
//
//对于存字符的列表，在python中需要初始化，因为list的插入是append()，初始化之后
// 则可以通过索引值来查询指定的位置，不然会报 index out of range。
// 而python中char转换为int需要调用内置函数ord()方法，int转换为char则需要调用chr()，
// 这里的转换是基于ASCII码转换，如果“1”转换为1，则直接int强转就行。
//
//class Solution:
//        def longestPalindrome(self, s):
//        """
//        :type s: str
//        :rtype: int
//          """
//              voca = list(0 for i in range(58))
//              s_length = len(s)
//              is_single = False
//              res_length = 0
//              for i in s:
//                  index = ord(i) - 65
//                  voca[index] += 1
//              for i in range(58):
//                  if not is_single:
//                      if voca[i] % 2 != 0:
//                          is_single = True
//                  res_length += int(voca[i] / 2) * 2
//              return res_length + 1 if is_single else res_length