//
// Created by Mr.Hu on 2018/8/30.
//
// leetcode 292 nim game
//
// 题目描述了一个游戏：现有n个棋子，两个人依此从棋子中取，一次最多取3粒，最少取1粒。最后取完的那个人算赢。
// 给定棋子n的个数，判断是否能赢。
//
// 这个题目属于智力题，其实我们可以先将n取较小的几个数就可以发现规律。
// 如果当前n为4的倍数，那么无论先取几粒，另外一个人可以使得这一轮两个人取的总粒数为4，那么依此轮训下去，最后取的肯定为后取的人。
// 如果当前n不为4的倍数，那么先取的人可以取几粒，使得剩下的粒数为4的倍数，那么剩余的情况将和前面描述的类似，
// 只是接下来后取的人为整个游戏最开始取的人。
//

#include <iostream>
using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0 || n < 4;
    }
};

int main() {
    int n = 10001;
    Solution solution;
    bool win = solution.canWinNim(n);
    cout << "can win? " << win << endl;
    return 0;
}