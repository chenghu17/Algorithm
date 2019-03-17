#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

bool check(vector<double> Li, double mid, int N, int M) {
    int count = 0;
    for (int i = 1; i <= N; i++) {
        count += (int) (Li[i] / mid);
    }
    return count >= M;
}

int main() {
    int N, M;
    vector<double> Li;
    cin >> N >> M;
    // 准备数据
    Li.push_back(-1);
    int tmp;
    for (int i = 1; i <= N; i++) {
        cin >> tmp;
        Li.push_back(tmp*100);
    }

    // 二分循环判断是否合理
    int left = 0, mid, right = 1000000000;
    while (left <= right) {
        mid = (left + right) / 2;
        if(mid==0)
            break;
        if (check(Li, mid, N, M)){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout << fixed << setprecision(2) << 1.0 * right / 100;
    return 0;
}