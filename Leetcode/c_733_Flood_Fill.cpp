//
// Created by Mr.Hu on 2019/1/23.
//
// leetcode 733 flood fill
//
// 题目给定一个场景：对于一张图片，可以用一个二维数组表示，每个点的值表示像素值，现在给定一个起始点坐标，要求
// 从上下左右四个方向出发，类似洪水操作，对于四个方向中，与中心方向上点的值相同的点，其像素值更新为给定的newColor，
// 依次传递下去，要求输出最后flood fill之后的image。
//
// 这个题目类似于求最大岛面积，利用BFS或DFS的方法，采用递归的方式，依次判断相邻四个方向像素点的状态，满足上述条件则进行相应的变换。
// 另外值得注意的是：对于访问过的点，为了防止死循环，需要进行标示，这里我们使用set<pair<int,int>>来存储访问过的节点。
// 主要的方法还是DFS的结构，递归实现。
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int start_pixel;
    set<pair<int, int>> visited;

    void fill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != start_pixel) {
            return;
        }
        pair<int, int> cur = make_pair(sr, sc);
        if (visited.count(cur)) {
            return;
        }
        image[sr][sc] = newColor;
        visited.insert(cur);
        // left
        fill(image, sr, sc - 1, newColor);
        // right
        fill(image, sr, sc + 1, newColor);
        // top
        fill(image, sr - 1, sc, newColor);
        // bottom
        fill(image, sr + 1, sc, newColor);
    }


    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        start_pixel = image[sr][sc];
        fill(image, sr, sc, newColor);
        return image;
    }
};

int main() {
    vector<vector<int>> image = {{1, 0, 1},
                                 {0, 1, 1},
                                 {1, 1, 0}};
    Solution solution;
    vector<vector<int>> res = solution.floodFill(image, 1, 1, 2);
    for (auto row:res) {
        for (auto i:row) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}