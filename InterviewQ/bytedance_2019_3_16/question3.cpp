#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;


int cal_Gifts_Num(vector<int> v) {

    vector<int> gifts(v.size());
    for (int i = 0; i < v.size(); i++) {
        gifts[i] = 1;
    }

    // 1、确定大小顺序pair<score,idx>
    vector<pair<int, int>> orders;
    for (int i = 0; i < v.size(); i++) {
        orders.push_back(make_pair(v[i], i));
    }
    sort(orders.begin(), orders.end());


    // 2、遍历填充

    for (auto pair:orders) {
        int idx = pair.second;
        cout<<"idx-->"<<idx<<endl;
        if (idx == 0) {
            int left = v.size() - 1, right = idx + 1;
            // 大于左右
            if (v[idx] > v[right] && v[idx] > v[left]) {
                gifts[idx] = max(gifts[left], gifts[right]) + 1;
            } else if (v[left] < v[right]) {
                if (v[idx] == v[right]) {
                    gifts[idx] = gifts[left] + 1;
                }
            } else if (v[left] > v[right]) {
                if (v[idx] == v[left]) {
                    gifts[idx] = gifts[right] + 1;
                }

            }
        } else if (idx == v.size() - 1) {
            int left = idx - 1, right = 0;
            if (v[idx] > v[right] && v[idx] > v[left]) {
                gifts[idx] = max(gifts[left], gifts[right]) + 1;
            } else if (v[left] < v[right]) {
                if (v[idx] == v[right]) {
                    gifts[idx] = gifts[left] + 1;
                }
            } else if (v[left] > v[right]) {
                if (v[idx] == v[left]) {
                    gifts[idx] = gifts[right] + 1;
                }
            }
        } else {
            int left = idx - 1, right = idx + 1;
            if (v[idx] > v[right] && v[idx] > v[left]) {
                gifts[idx] = max(gifts[left], gifts[right]) + 1;
            } else if (v[left] < v[right]) {
                if (v[idx] == v[right]) {
                    gifts[idx] = gifts[left] + 1;
                }
            } else if (v[left] > v[right]) {
                if (v[idx] == v[left]) {
                    gifts[idx] = gifts[right] + 1;
                }
            }
        }
        cout<<gifts[idx]<<endl;
    }


    // 3、计算礼物个数
    int count = 0;
    for (auto g:gifts) {
        count += g;
    }
    return count;
}


int main() {
    int n;  //测试样例个数
    cin >> n;
    vector<vector<int>> cases; // 每个样本的记录
    int num;    // 每个样本的个数
    for (int i = 0; i < n; i++) {
        cin >> num;
        vector<int> case_line;  // 记录单个样本
        int score;
        for (int j = 0; j < num; j++) {
            cin >> score;
            case_line.push_back(score);
        }
        cases.push_back(case_line);
    }

    for (int i = 0; i < cases.size(); i++) {
        if (i != cases.size() - 1) {
            cout << cal_Gifts_Num(cases[i]) << endl;
        } else {
            cout << cal_Gifts_Num(cases[i]);
        }
    }


    return 0;
}



//for(auto line:cases){
//for(auto v:line){
//cout<<v<<" ";
//}
//cout<<endl;
//}