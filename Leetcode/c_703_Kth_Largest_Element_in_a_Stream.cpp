//
// Created by Mr.Hu on 2019/1/22.
//
// leetcode 703 kth largest element in a stream
//
// 题目给定一个数组和一个k值，要求每次向该数组add一个值时，返回当前数组中第k大的值。
//
// 这个题目的思路是维护一个container容器，来保存当前k个最大的值，然后每次加入一个值时，判断当前容器中的数量，超过k则删除较小的值，
// 最后，第k大的值即为容器中的最小值。
// 我们这里使用优先队列来保存数据，默认容器为vector，队列按照从小打大的顺序排列，如{1,2,3,5,4}用priority_queue保存，以从小到大的顺序：
// [5，4，3，2，1]为队列顺序，而输出顺序为1，2，3，4，5。当调用pop()/top()方法时，即返回1。
// 优先队列中的排序情况需要了解清楚。
// 当每次加入一个值后，就会自动按照规定好的顺序排序，再判断当前是否为k个，超过则pop()，最后返回top()即为第k大的值。
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > cur;
    int kth;

    KthLargest(int k, vector<int> nums) {
        kth = k;
        for (auto i:nums) {
            cur.push(i);
        }
    }

    int add(int val) {
        cur.push(val);
        while (cur.size() > kth) {
            cur.pop();
        }
        return cur.top();
    }
};

int main() {
    vector<int> nums = {1, 3, 2, 5};
    KthLargest *obj = new KthLargest(2, nums);
    int param_1 = obj->add(4);
    cout << param_1 << endl;
    return 0;
}

