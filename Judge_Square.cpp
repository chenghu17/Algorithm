//
// Created by Mr.Hu on 24/03/2018.
//
// 2018 Tencent 机试题
// 给定t组数据，每组数据包含四个坐标点（二维）
// 每组数据第一行为4个x轴坐标，第二行为y轴坐标
// 判断每组数据是否为正方形，若是则输出Yes，不是则输出No

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main() {

    int t = 0;
    cin >> t;
    vector<int> x[t];           //x坐标轴
    vector<int> y[t];           //y坐标轴
    vector<double> sides[t];    //两点距离的平方
    string result[t];
    //输入具体的数据
    for (int i = 0; i < t; i++) {

        for (int j = 0; j < 4; j++) {
            int x_num = 0;
            cin >> x_num;
            x[i].push_back(x_num);
        }
        for (int k = 0; k < 4; k++) {
            int y_num = 0;
            cin >> y_num;
            y[i].push_back(y_num);
        }
    }

    //计算任意两点之间的距离平方
    for (int i = 0; i < t; i++) {
        for (int j = 0, k = 0; j < 4, k < 4; j++, k++) {
            for (int m = j + 1, n = k + 1; m < 4, n < 4; m++, n++) {
                double side = pow(abs(x[i][j] - x[i][m]), 2) + pow(abs(y[i][k] - y[i][n]), 2);
                sides[i].push_back(side);
            }
        }
    }

    //判断是否是正方形
    for (int i = 0; i < t; i++) {
        int count_s = 0, count_l = 0;
        auto biggest = max_element(begin(sides[i]), end(sides[i]));
        auto smallest = min_element(begin(sides[i]), end(sides[i]));
        for (int j = 0; j < 6; j++) {
            if (sides[i][j] == *biggest)
                count_l++;
            else if (sides[i][j] == *smallest)
                count_s++;
        }
        if (count_l == 2 && count_s == 4)
            result[i] = "Yes";
        else
            result[i] = "No";

    }

    //输出结果
    for (int i = 0; i < t; i++) {
        cout << result[i] << endl;
    }

    return 0;
}
