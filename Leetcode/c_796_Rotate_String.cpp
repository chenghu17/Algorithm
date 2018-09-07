//
// Created by Mr.Hu on 2018/9/7.
//
// leetcode 796 rotate string
//
// 题目要求判断字符串B能否通过字符串A进行shift得到，所谓的shift即将当前第一位字符移动到最后一位
//
// 这个题目之前遇到过，记得一种思想就是将字符串A自身拼接，即A+A，然后从拼接串开头遍历，每次取长度为A.size()的子串，
// 循环的终止条件为i<A.size()，即只需要遍历到A的最后一位即可。每次比较子串与B是否相等，相等则返回true。
//
// 在编写上面方法时又想到另外一种方法，因为字符串A是通过shift操作转换为字符串B，所以我们可以将字符串B分为两部分，一部分为未
// shift过的字符，一部分为shift过的字符，那么可以通过字符串B的第一个字符去字符串A中匹配，得到所在的位置index，
// 此时我们可以区分B中的两个部分，也可以得到A中的两个部分，A(1)==B(2) && A(2)==B(1) 则返回true
// 同时需要考虑字符串中存在重复字符的情况。
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        if(A==B){
            return true;
        }
        if(A.size()!=B.size()){
            return false;
        }
        string C = A+A;
        for(int i=1;i<A.size();++i){
            if(C.substr(i,A.size())==B){
                return true;
            }
        }
        return false;
    }


    bool rotateString_option(string A, string B) {
        if(A==B){
            return true;
        }
        if(A.size()!=B.size()){
            return false;
        }
        char model=B[0];
        for(int i=1;i<A.size();++i){
            if(A[i]==model){
                if(A.substr(i,A.size()-i)==B.substr(0,A.size()-i)
                   && A.substr(0,i)==B.substr(A.size()-i,i))
                    return true;
            }
        }
        return false;
    }
};

int main(){
    string A = "abcde";
    string B = "cdeab";
    Solution solution;
//    bool result = solution.rotateString(A,B);
    bool result = solution.rotateString_option(A,B);
    cout<<result<<endl;
    return 0;
}