//
// Created by Mr.Hu on 2018/6/15.
//
// leetcode 415 add strings
//
// 题目要求对两个只包含0-9数字的字符串进行相加操作，即大数加法。
// 题目要求不能否使用自带的大数加法库和将string转换为int的方式来进行计算。
//
// 所以就用最原始的两个数相加，先低位再高位，同时判断进位的方式来coding，
// 这个思想比较简单，主要是要细心，我就是不细心导致提交了两三次才accetped。
// 主要思想就是从每个string的最高位，即数字的最低位开始做加法，对应位置相加，同时判断是否大于10来决定进位项tmp的取值。
// 对应位置相加完之后，则需要判断是否又string没有加完，因为上一步的对应位置加法操作只能将较小位数的那个string遍历完，
// 所以需要对是否又剩下位数进行判断，而且最多只有一个数存在这种情况，如果存在这种情况，则不能简单的使用substr的方式，因为
// 之前的加法可能存在进位。再剩下的部分遍历完之后，最后还需要判断是否存在进位，存在则需要在最终的结果前面加上1，最后输出结果。
// 但是这种方法的执行效率似乎不高，只超过百分之二十几的accepted solution
//
// 第二种方法的代码更简洁，将我上述的操作放在一个for循环中全部执行，每次两个string是否遍历完，同时是否还存在进位项，只要满足一个，
// 就进入for循环中。这种代码结构的执行时间也只超过了百分之二十八的accepted solution
//

#include <iostream>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int num1_size = num1.length();
        int num2_size = num2.length();
        int tmp = 0;
        string result = "";
        int i = num1_size - 1, j = num2_size - 1;
        for (; i >= 0 && j >= 0; --i, --j) {
            int sum = (num1[i] - 48) + (num2[j] - 48);
            if (tmp == 1) {
                sum += 1;
            }
            tmp = sum >= 10 ? 1 : 0;
            sum %= 10;
            result = to_string(sum) + result;
        }

        if (i >= 0) {
            for (; i >= 0; --i) {
                int sum = num1[i] - 48;
                if (tmp == 1) {
                    sum += 1;
                }
                tmp = sum >= 10 ? 1 : 0;
                sum %= 10;
                result = to_string(sum) + result;
            }
        } else if (j >= 0) {
            for (; j >= 0; --j) {
                int sum = num2[j] - 48;
                if (tmp == 1) {
                    sum += 1;
                }
                tmp = sum >= 10 ? 1 : 0;
                sum %= 10;
                result = to_string(sum) + result;
            }
        }
        if (tmp == 1) {
            result = to_string(1) + result;
        }
        return result;
    }

    string addStrings_concise(string num1, string num2) {
        int tmp = 0;
        int first, second;
        string result = "";
        for (int i = num1.length(), j = num2.length(); i > 0 || j > 0 || tmp > 0;) {
            first = i > 0 ? num1[--i] - '0' : 0;
            second = j > 0 ? num2[--j] - '0' : 0;
            result = to_string((first + second + tmp) % 10) + result;
            tmp = (first + second + tmp) / 10;
        }
        return result;
    }

};

int main() {
    string num1 = "123456";
    string num2 = "3548276494";
    Solution solution;
    string result = solution.addStrings(num1, num2);
    cout << result << endl;
    return 0;
}