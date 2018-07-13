//
// Created by Mr.Hu on 2018/7/13.
//
// 题目要求判断只包含小括号、中括号、大括号的字符串是否有效，即括号成对存在。
//
// 这个题目在编译原理中经常遇到，为了判断一个多项式是否正确，需要判断其括号是否成对有效的存在。
//
// 第一次使用栈这个数据结构来进行操作，与其他vector，map很像，都是需要定义数据类型
// 这里采用栈来存储左括号，因为栈满足先进后出的特征，所以当我们遇到左括号时，将其压入栈中，
// 如果遇到右括号，则将栈顶元素取出来，并将栈顶元素弹出出，此时判断栈顶元素与右括号是否匹配，
// 此处是否匹配我采用了这样一个方法：将成对的括号存储在map<char,int>中，成对括号value和为7，
// 所以在判断时，只需要判断两个键对应值的和是否为7即可，不等于7则返回false，等于7则继续遍历字符串。
// 遍历完字符串之后，判断栈内是否还存在元素，即stack.empty()，不为空则说明括号并不是全部成对存在。
// 最后直接return stack.empty()，因为该方法的返回值与我们判断字符串有效的结果对应。
//

#include <iostream>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_char;
        map<char,int> characters = {{'(',1},{'{',2},{'[',3},{']',4},{'}',5},{')',6}};
        int length = (int)s.size();
        for(int i=0;i<length;++i){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                stack_char.push(s[i]);
            }
            else{
                if(stack_char.empty()){
                    return false;
                }
                char stack_top = stack_char.top();
                stack_char.pop();
                if(characters[s[i]]+characters[stack_top]!=7){
                    return false;
                }
            }
        }
        return stack_char.empty();
    }
};

int main(){
    string s = "[{([])}]";
    Solution solution;
    bool isvalid = solution.isValid(s);
    cout<<isvalid<<endl;
    return 0;
}