//
// Created by Mr.Hu on 2019/1/16.
//
// 题目给定一个机器人从原点（0,0）位置开始上下左右移动，要求判断经过一系列运动后，是否能继续回到原点。
//
// 其实这个题目在描述上写的很复杂，又是原点，又是机器人移动，然后判断最后是否回到原点。
// 其本质就是判断上下移动的次数是否相等，左右移动的次数是否相等，如果都相等，那最后回到原点，否则不能回到原点。
// 用四个变量分别保存四个方向移动的次数，最后再判断对应是否相等即可。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        // 即判断moves中U和D的个数是否相等；
        // L和R的个数是否相等
        // L=0,R=1,U=2,D=3;
        vector<int> records(4, 0);
        for (int i = 0; i < moves.length(); i++) {
            if (moves[i] == 'L') {
                records[0]++;
            } else if (moves[i] == 'R') {
                records[1]++;
            } else if (moves[i] == 'U') {
                records[2]++;
            } else {
                records[3]++;
            }
        }
        return records[0] == records[1] && records[2] == records[3];
    }
};

int main() {
    string moves = "LRRLUDDULDUR";
    Solution solution;
    bool result = solution.judgeCircle(moves);
    cout << "return to origin？" << result << endl;
    return 0;
}