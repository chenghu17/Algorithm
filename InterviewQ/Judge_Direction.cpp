//
// Created by Mr.Hu on 27/03/2018.
//
// Netease 2018
// 小明初始方向为N(北)，L为左转，R为右转
// 第一行输入N，表示转动次数，N不大于1000
// 第二行为字符串，LR组成，表示每次的转动方向
// 最后输出小明转动后所面对的方向

#include <iostream>

using namespace std;

int main() {
    int count = 0;
    int N;
    char direction[1001];
    cin >> N;
    cin >> direction;
    // L:+1 R:-1
    for (int i = 0; i < N; i++) {
        if (direction[i] == 'L')
            count++;
        else
            count--;
    }
    int result = count % 4;
    if (result == -3 or result == 1)
        cout << "W";
    else if (result == -2 or result == 2)
        cout << "S";
    else if (result == -1 or result == 3)
        cout << "E";
    else
        cout << "N";
    return 0;
}
