#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;


int main() {
    // 读取数据
    int n;
    int count = 0;
    cin >> n;
    int tmp = 1024 - n;
    int i = 3;
    vector<int> coin = {1, 4, 16, 64};

    while (tmp) {
        count += tmp / coin[i];
        tmp %= coin[i];
        i--;
    }
    cout<<count;
    return 0;
}