//
// Created by Mr.Hu on 2018/8/5.
//
// Netease 2018
//
// 题目描述：平面内又n个矩形，第一个矩形的左下角坐标为（x1[i],y1[i]），右上角坐标为（x2[i],y2[i]）
// 如果两个或多个矩形存在公共区域，则认为它们相互重叠（不考虑边界和角落），求平面内重叠矩阵数量最多的地方，有多少个矩阵相互重叠。
//
// 输入描述：输入五行，第一行为矩阵个数（2<=n<=50）；第二行包含n个整数，x1[i]，表示左下角的横坐标；第三行包括n个整数，y1[i]，
// 表示左下角的纵坐标，第四行包括n个整数，x2[i]，表示右上角的横坐标；第五行包含n个整数，y2[i]，表示右上角的纵坐标。
//
// 输出描述：输出整数，表示重叠区域最多地方的矩形个数，如果都不重叠，则输出1
//
// 想法1：对于所有的矩形，判断是否两两相交，并将结果记录在map<int,set<int>>当中，然后再分析相交结果中最多的相交区域。
//
// 想法2：对于所有x，y进行两两组合，即可得到所有矩阵的交点和顶点，然后对每个点判断是否在给定的矩阵内部，如果在，则count++，
// 每次取最大的count值最为结果，最后输出最终的count值即可。
//
//

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

bool is_duplicated(vector<vector<int>> &position, int i, int j) {
    // true表示存在重复，false表示不存在重复
    return !(position[0][i] >= position[2][j] || position[2][i] <= position[0][j] || position[3][i] <= position[1][j] ||
             position[1][i] >= position[3][j]);
}

int duplication_area_number(int n, vector<vector<int>> &position) {
    int result = 1;
    map<int, set<int>> state;
    set<int> tmp;
    for (int i = 0; i < n - 1; ++i) {
        state[i].insert(i);
        for (int j = i + 1; j < n; ++j) {
            if (is_duplicated(position, i, j)) {
                state[i].insert(j);
                state[j].insert(i);
            }
        }
    }
    // 遍历完之后判断交集,得到最终的重叠个数
    // 遇到问题...如何去判断相交位置最多的矩形个数
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> position(4, vector<int>(n));
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> position[i][j];
        }
    }
    int result = duplication_area_number(n, position);
    cout << result << endl;
    return 0;
}