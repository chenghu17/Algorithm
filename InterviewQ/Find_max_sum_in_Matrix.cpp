//
// Created by Mr.Hu on 2019/3/1.
//
// 在一个N*N的数组中寻找所有横，竖，左上到右下，右上到左下，四种方向的直线连续D个数字的和里面最大的值
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int N, D;
    cin >> N;
    cin >> D;
    vector<vector<int>> m(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> m[i][j];
        }
    }
    // 得到所有数据
    int cur_max = INT_MIN;
    // 横
    for (int r = 0; r < N; r++) {
        for (int l = D - 1; l < N; l++) {
            int tmp = 0;
            for (int i = l - D + 1; i <= l; i++) {
                tmp += m[r][i];
            }
            cur_max = max(cur_max, tmp);
        }
    }
    // 竖
    for (int l = 0; l < N; l++) {
        for (int r = D - 1; r < N; r++) {
            int tmp = 0;
            for (int i = r - D + 1; i <= r; i++) {
                tmp += m[i][l];
            }
            cur_max = max(cur_max, tmp);
        }
    }
    // 左上到右下
    for (int r = 0; r < N; r++) {
        for (int l = 0; l < N; l++) {
            if (r + D - 1 < N && l + D - 1 < N) {
                int tmp = 0;
                for (int i = r, j = l; i <= r + D - 1 && j <= l + D - 1;) {
                    tmp += m[i][j];
                    i++;
                    j++;
                }
                cur_max = max(cur_max, tmp);
            } else {
                break;
            }
        }
    }
    // 右上到左下
    for (int r = 0; r < N; r++) {
        for (int l = N - 1; l >= 0; l--) {
            if (r + D - 1 < N && l - D + 1 >= 0) {
                int tmp = 0;
                for (int i = r, j = l; i <= r + D - 1 && j >= l - D + 1;) {
                    tmp += m[i][j];
                    i++;
                    j--;
                }
                cur_max = max(cur_max, tmp);
            } else {
                break;
            }
        }
    }
    cout << cur_max;
    return 0;

}