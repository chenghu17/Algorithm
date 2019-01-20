//
// Created by Mr.Hu on 2019/1/20.
//
// leetcode 973 k closet points to origin
//
// 题目给定坐标系中一些点，要求找出离原点最近的K个点，其中距离使用欧式距离
//
// 刚开始做这个题目，想到是最大/小的k个值，利用堆的思想来做，于是先维护一个k大小的结果集合，按照从小到大的顺序进行排序，
// 当新来一个坐标时，与最后一个值比较大小，即当前k个坐标中离原点最远的点。如果比其近，则可以替代该点，并且需要更新k个坐标点的位置；
// 按照上面的操作，直到遍历完所有的节点。
//
// 但是上面的方法在实际运行中，一旦数据量和k值很大时，效率很低，出现time limited的错误。
// 于是参考了discussion中别人的方法，利用优先队列实现，这也让我学习了一些优先队列的使用方法
// priority_queue<>存在三个参数，第一个参数为每个数据的类型，第二个参数为container容器的类型，第三个参数为比较方法所在的类，
// 即容器中的数据按照什么方法进行排序，注意，这里需要传入的是一个类/结构体，其成员函数为重载的比较方法。
// 通过这种方法，每次取优先队列中的top()，即距离最小的点，取k次，即可得到最终的结果。
//
// 这里也可以使用multiset的方式，毕竟set会自动排序，multiset<vector<int>,Compare>即可
//
// 最近K的问题都可以利用这两种数据结构来解答
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:


    static bool compare(vector<int> A, vector<int> B) {
        // 降序排列
        return A[0] * A[0] - B[0] * B[0] < B[1] * B[1] - A[1] * A[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
        int count = 0;
        int cur_max = INT_MAX, distance;
        vector<vector<int>> res;
        map<vector<int>, int> each_distance;
        bool fill = true;
        for (auto it:points) {
            distance = it[0] * it[0] + it[1] * it[1];
            if (count < K) {
                count++;
                res.push_back(it);
                each_distance[it] = distance;
            } else if (distance < cur_max) {
                each_distance[it] = distance;
                res[count - 1][0] = it[0];
                res[count - 1][1] = it[1];
                // update res order
                for (int i = K - 2; i >= 0; i--) {
                    if (each_distance[res[i + 1]] < each_distance[res[i]]) {
                        swap(res[i + 1][0], res[i][0]);
                        swap(res[i + 1][1], res[i][1]);
                    } else {
                        break;
                    }
                }
            } else {
                continue;
            }

            if (count == K && fill) {
                // sort
                fill = false;
                sort(res.begin(), res.end(), compare);
            }
            cur_max = each_distance[res[count - 1]];
        }
        return res;
    }

    struct Compare {
        bool operator()(vector<int> A, vector<int> B) {
            return A[0] * A[0] + A[1] * A[1] > B[0] * B[0] + B[1] * B[1];
        }
    };

    vector<vector<int>> kClosest_optimal(vector<vector<int>> &points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq(points.begin(), points.end());
        vector<vector<int>> ans;
        while (K) {
            ans.push_back(pq.top());
            pq.pop();
            K--;
        }
        return ans;
    }

};

int main() {
    vector<vector<int>> points = {{1,  3},
                                  {-2, 2},
                                  {5,  -1}};
    Solution solution;
    vector<vector<int>> ans = solution.kClosest(points, 2);
    vector<vector<int>> ans_optimal = solution.kClosest_optimal(points, 2);
    for (auto it:ans) {
        cout << "{" << it[0] << "," << it[1] << "}" << endl;
    }
    cout << endl;
    for (auto it:ans_optimal) {
        cout << "{" << it[0] << "," << it[1] << "}" << endl;
    }
    return 0;
}