//
// Created by Mr.Hu on 2018/7/24.
//
// 题目定义在excel表格环境，第一列用A表示，第二十六列用Z表示，第二十七列用AA表示...以此类推，要求给出列出，输出其字母表示
//
// 刚开始拿到这个题目以为就是简单的26进制，其实不然。
// 如果是单纯的26进值，那么数应该是从0到25，满26则进位，但是这里满26不进位，超过26才进位。
//
// 所以我们在代码中应该要重点考虑数字能够被26整除的情况，如果能够整除，则说明当前位需要用"Z"表示，
// 如果不能整除，则用n%26得到的结果使用ASCII码转换为char即可。
// 在分析每一位之后，需要对当前n进行更新，而这个更新就与之前的n能否被26整除有关：
// 如果能整除，则说明n需要更新为(n/26)-1，如果不能整除，则n被更新为n/26
// 之所以需要剪一，是因为在能整除的情况下，低位满26不需要进位，而n/26则自动将其进位，需要手动将该进位值减去。
//
// 这个题目重点考察了进制的关系，而且在能被26整除的情况下不进位对最终n的处理是这个题目的关键点也是难点。
//

#include<iostream>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string out = "";
        while(n>0){
            char newone = n % 26 == 0 ? 90 : n % 26 + 64;
            out = newone + out;
            n = n % 26 == 0 ? (n /= 26) - 1 : n /= 26;
        }
        return out;
    }
};

int main(){
    Solution solution;
    string result = solution.convertToTitle(52);
    cout<<result<<endl;
    return 0;
}