//
// Created by Mr.Hu on 2019/1/16.
//
// leetcode 696 count binary substrings
//
// 题目给定一个字符串，要计算满足条件的非空子串的个数，非空子串需要包含相同个数的0和1，且字符串中0和1是连续存在的。
// 如果存在相同的子串，则以其出现的次数来计数。
//
// 这个题目思考了一会儿，可以从左向右进行遍历，且嵌套循环，设置0和1出现的次数，则定义是否为一次连续0和1，
// 如0011即为一次连续，而001100则为多次，不在考虑范围内；
// 因此设定了一些参数来辅助判断。
// 最终执行的结果accepted，但是只击败了百分之二点几的答案...
//
// 所以想要优化，有这样一个思考，如果我当前判断出111000，则可以直接在count上加3，下次索引的位置直接从第一个0开始，
// ...实现起来发现还是有很多细节没有注意到
//
// 于是去看了一下别人的答案：即下面的optimal method。
// 其思路是设定一个pre来表示前一种数字出现的次数，cur表示当前数字出现的次数，每次判断当前数字与前一个是否相同，
// 如果相同，则cur++，不相同，则把cur值复制给pre，即当前类别的数字变成前一种，然后把cur赋值为1；
// 上述判断之后，再判断pre与cur的大小关系，只要存在pre>=cur，则res++；
// 这一种方法确实很妙，而且很优美。在计数的过程中，同时通过pre>=cur的操作来累加满足情况的子串。
// 出发点应该是：1110则res++，11100则res++ ...
//

#include <iostream>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int zeros, ones, last, result = 0;
        bool consec;
        for (int i = 0; i < s.length() - 1; i++) {
            last = s[i];
            consec = true;
            zeros = 0;
            ones = 0;
            for (int j = i; j < s.length(); j++) {
                if (s[j] == last) {
                    if (s[j] == '0')
                        zeros++;
                    else
                        ones++;

                    if (zeros == ones) {
                        result++;
                        break;
                    }
                } else if (consec) {
                    consec = false;
                    last = s[j];

                    if (s[j] == '0')
                        zeros++;
                    else
                        ones++;

                    if (zeros == ones) {
                        result++;
                        break;
                    }
                } else {
                    break;
                }
            }
        }
        return result;
    }

    int countBinarySubstrings_optimal(string s) {
        int pre = 0, cur = 1, res = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) cur++;
            else {
                pre = cur;
                cur = 1;
            }

            if (pre >= cur) res++;
        }
        return res;
    }
};

int main() {
    string s = "01001000111";
    Solution solution;
    int count = solution.countBinarySubstrings(s);
    int count_expect = solution.countBinarySubstrings_optimal(s);
    cout << "count = " << count << endl;
    cout << "count_expect = " << count_expect << endl;
    return 0;
}