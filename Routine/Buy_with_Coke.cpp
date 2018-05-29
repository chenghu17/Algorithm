//
// Created by Mr.Hu on 2018/5/27.
//
// 2018 CodeM资格赛 第二题
//
//
// 小美和小团最近沉迷可乐。可供TA们选择的可乐共有k种，比如可口可乐、零度可乐等等，每种可乐会带给小美和小团不同的快乐程度。
// TA们一共要买n瓶可乐，每种可乐可以买无限多瓶，小美会随机挑选其中的m瓶喝，剩下的n-m瓶小团喝。
// 请问应该如何购买可乐，使得小美和小团得到的快乐程度的和的期望值最大？
// 现在请求出购买可乐的方案。

#include <iostream>
#include <vector>

using namespace std;


vector<int> MaxHappy(int n, int m, int k, vector<int> first, vector<int> second) {
    vector<int> result(k);
    int max_happy = 0;
    int index = 0;
    for (int i = 0; i < k; i++) {
        int happy = m * first[i] + (n - m) * second[i];
        if (happy > max_happy) {
            max_happy = happy;
            index = i;
        }
    }
    result[index] = n;
    return result;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> first;
    vector<int> second;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        first.push_back(a);
        second.push_back(b);
    }

    vector<int> result = MaxHappy(n, m, k, first, second);
    for (int i = 0; i < k - 1; i++) {
        cout << result[i] << " ";
    }
    cout << result[k - 1];
    return 0;
}
