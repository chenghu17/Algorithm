//
// Created by Mr.Hu on 2019/1/23.
//
// leetcode 933 number of recent calls
//
// 这个题目的题意看了一会儿才理解！
// 构建一个类，用来统计最近外部访问的次数，该类只有一个ping(t)方法，参数t为访问的时间，多次访问的时间为严格递增，
// 且属于[t-3000,t]这个范围的时间才会被统计，每次调用ping(t)，返回累计访问次数。
//
// 其实这么一说，也不是很清晰，给一个例子：如果第一次t=1，而之前还没有访问的元素，则返回1；第二次输入30002，则此时的有效范围为[2,3002]，
// 那么之前t=1就不会被统计，因此返回的也是1，那么再输入3003，有效范围为[3,3003]，此时有效的为3002和3003，累计2次。
// t其实就相当于一个时间点，而每次统计次数只考虑当前时间往前推3000微秒。
//
// 由于可以是时间点，那么满足先进先出的特点，所以我们这里使用队列(queue)来保存当前有效的时间点，当输入新的时间点时，则需要从队列头开始判断，
// 因为队头是离当前时间最远的时间节点，如果没在范围内，则弹出；在范围内，则其后的时间点肯定也在要求的范围内，此时直接输出队列元素数即可。
//

#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
public:
    queue<int> pre_queue;

    RecentCounter() {

    }

    int ping(int t) {
        pre_queue.push(t);
        while (!pre_queue.empty()) {
            if (pre_queue.front() < t - 3000) {
                pre_queue.pop();
            } else {
                break;
            }
        }
        return pre_queue.size();
    }
};

int main() {
    RecentCounter *obj = new RecentCounter();
    int param_1 = obj->ping(1);
    cout << param_1 << endl;
    int param_2 = obj->ping(100);
    cout << param_2 << endl;
    int param_3 = obj->ping(1000);
    cout << param_3 << endl;
    int param_4 = obj->ping(3002);
    cout << param_4 << endl;
    int param_5 = obj->ping(3100);
    cout << param_5 << endl;
    int param_6 = obj->ping(3200);
    cout << param_6 << endl;
    return 0;
}


