//
// Created by Mr.Hu on 2018/7/10.
//
// 题目要求小明走100阶楼梯，每次可以走1阶、2阶或者3阶，求走完楼梯最多有多少种走法
//
// 刚看到这个题目没有什么想法，于是把楼梯数减小到从0开始进行观察。
// 当stair_num等于0，1，2，3时，分别有0，1，2，4种走法可走完楼梯。
// 当stair_num继续增加到4时，则从第一步开始考虑，第一步有三种走法：走1阶，剩下3阶；走2阶，剩下2阶；走3阶，剩下1阶。
// 剩下的台阶需要继续走完，可以使用之前已有的情况；
// 按照相同思想，使用数学归纳法可以得到这样一个递推公式f(n)=f(n-1)+f(n-2)+f(n-3)且n>3；
// 考虑到走完当前stair_num与其前面的结果有关，所以将之前的结果进行保存，方便下次反复使用。
//
// 由于每次都要叠加之前的结果，当台阶数不断增加时，走完楼梯的方法会迅速增加，以至于超过int和long的取值范围。
// 所以对于之前的结果使用string进行保留，当计算当前结果时，则需要对字符串进行加法，这也就是我们常用的大数加法，
// 基本思想是三个数字的从个位数开始相加，并考虑之前进位的结果，如果当前位数已经超过了字符串长度，则返回0与其他数字进行相加，
// 相加的结果考虑进位和当前位的数字，最后将结果进行字符串拼接，直到三个数所有位都加完，则返回三个数的结果。
//

#include<iostream>
#include<vector>

using namespace std;

string addStrings(string num1, string num2, string num3) {
    int carry = 0;
    int first, second, third;
    string summary = "";
    for (int i = (int) num1.length(), j = (int) num2.length(), k = (int) num3.length();
         i > 0 || j > 0 || k > 0 || carry > 0;) {
        first = i > 0 ? num1[--i] - '0' : 0;
        second = j > 0 ? num2[--j] - '0' : 0;
        third = k > 0 ? num3[--k] - '0' : 0;
        summary = to_string((first + second + third + carry) % 10) + summary;
        carry = (first + second + third + carry) / 10;
    }
    return summary;
}

string StepUp(int stairs_num) {
    vector<string> result;
    result.emplace_back("0");
    result.emplace_back("1");
    result.emplace_back("2");
    result.emplace_back("4");
    for (int i = 4; i <= stairs_num; ++i) {
        result.emplace_back(addStrings(result[i - 1], result[i - 2], result[i - 3]));
    }
    return result[stairs_num];
}


int main() {
    cout << "please enter the number of stairs: ";
    int stairs_num;
    cin >> stairs_num;
    string method_count = StepUp(stairs_num);
    cout << "the sum of methods: " << method_count;
    return 0;
}
