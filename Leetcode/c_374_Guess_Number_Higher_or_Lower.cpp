//
// Created by Mr.Hu on 2018/6/24.
//
// leetcode 374 Guess Number Higher or Lower
//
// 题目给出了一个我们日常生活中玩的一个游戏，猜选择的数字，如果猜的比原来的大，则返回-1，如果猜的比原来小，则返回1，相同，则返回0。
//
// 这是一个典型的二分查找的题目，思路就是定义letf和right，然后每次判断mid与真是结果的差别，对letf和right进行更新。
// 其中有一个坑，就是最大值可以选择INT_MAX，所以在定义left、right、mid时，将其定义为long型最合适，方式越界。
//

#include <iostream>
using namespace std;
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long left = 0;
        long right = n;
        long mid,guess_right;
        while(left<=right){
            mid = (left+right)/2;
            guess_right = guess(mid);
            if(guess_right == 0){
                return mid;
            }
            else if(guess_right == 1){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
    }
};

int main(){
    return 0;
}