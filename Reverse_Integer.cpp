//
// Created by Mr.Hu on 24/03/2018.
//
// leetcode reverse integer
// 将整数进行颠倒，值得注意的是，输入的是int值，但是颠倒后可能会超过32bit，导致overflow
// 所以在存储结果上，要设置为long long，然后对最终的结果要进行判断，且绝对值是否大于INT_MAX。

#include <iostream>
using namespace std;
class Solution {
    public:
    int reverse(int x) {
        int count = 0;
        long long result = 0;
        bool negative = false;
        if(x<0){
            negative = true;
            x = -x;
        }
        while(x>0){
            result = result * 10 + x%10 ;
            x = x/10;
        }
        if(result>INT_MAX)
            return 0;
        if(negative)
            result = -result;
        return result;
    }
};

int main(){
    int x;
    cin>>x;
    Solution solution;
    int result = solution.reverse(x);
    cout<<result<<endl;
    return 0;

}