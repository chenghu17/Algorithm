//
// Created by Mr.Hu on 2018/6/22.
//
// leetcode 443 string compression
//
// 题目要求在in-place下对string进行压缩，即如果字符m连续出现n次，则记为m,n，如果n==1，则只保留m，
// 压缩结果保留在原string的前面，最后返回压缩结果的位数
//
// 这个题目细节的东西比较多，基本思想就是对string进行遍历，记录当前char连续出现的次数repeated_time，以及压缩位数count。
// 如果下一个char与当前这个不想等，则判断repeated_time的返回，==1，<10，>=10，
// 根据不同的repeated_time来写入到字符串的前面，写入后将repeated_time恢复到初始状态，继续上述过程，循环结束后输出count即可。
//
// 在这个题目中我扫清了一个盲点，就是int转换为char直接转换是涉及到ASCII码，不是我所想的1转换为'1'。
// int到char，此时的int表示char所对应的ASCII码值，转换为char后即ASCII码所对应的字符。
// 如果要将1转换为'1'，可以使用to_string(1)[0]即可
//
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int length = chars.size();
        if(length<=1){
            return 1;
        }
        char module = chars[0];
        int repeated_time = 1;
        int count = 0;
        for(int i=1;i<=length;++i){
            if(i<length && chars[i] == module){
                ++repeated_time;
            }
            else if(i==length || chars[i] != module){
                chars[count]=module;
                if(repeated_time==1){

                }
                else if(repeated_time<10){
                    count += 1;
                    chars[count]=to_string(repeated_time)[0];
                }
                else{
                    string times = to_string(repeated_time);
                    int size = times.size();
                    for(int j=0;j<size;++j){
                        count += 1;
                        chars[count]=times[j];
                    }
                }
                repeated_time = 1;
                count +=1;
                module = chars[i];
            }
        }
        return count;
    }
};

int main(){
    vector<char> chars;
    chars.push_back('a');
    chars.push_back('a');
    chars.push_back('b');
    chars.push_back('b');
    chars.push_back('b');
    chars.push_back('c');
    chars.push_back('c');
    chars.push_back('c');
    chars.push_back('c');
    chars.push_back('c');
    Solution solution;
    int count = solution.compress(chars);
    cout<<count<<endl;
    return 0;
}