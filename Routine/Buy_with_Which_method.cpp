//
// Created by Mr.Hu on 2018/5/26.
//
// 2018 CodeM资格赛 第一题
// 1、给定商品的价格以及是否参与打折，折扣统一为八折
// 2、给定总金额达到上限后的减小幅度
// 求最合理的购买方式
//

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


double
MinPrice(int n, int m, vector<int> price_count, vector<int> is_count, vector<int> sum_reduce, vector<int> reduce_num) {
    // 采用打折的购买
    double sum1 = 0;
    // 采用总价减价的方式购买
    double sum2 = 0;
    for (int i = 0; i < n; i++) {
        if (is_count[i] == 1) {
            sum1 += 0.8 * price_count[i];
        } else {
            sum1 += price_count[i];
        }
        sum2 += price_count[i];
    }
    double tmp = sum2;
    for (int i = 0; i < m; i++) {
        if(sum2>=sum_reduce[i]){
            tmp = min(tmp,sum2-reduce_num[i]);
        }
    }
    return min(sum1,tmp);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> price_count;
    vector<int> is_count;
    vector<int> sum_reduce;
    vector<int> reduce_num;
    for (int i = 0; i < n; i++) {
        int price, isCount;
        cin >> price >> isCount;
        price_count.push_back(price);
        is_count.push_back(isCount);
    }
    for (int j = 0; j < m; j++) {
        int sum, reduce;
        cin >> sum >> reduce;
        sum_reduce.push_back(sum);
        reduce_num.push_back(reduce);
    }
    double minPrice = MinPrice(n, m, price_count, is_count, sum_reduce, reduce_num);
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<minPrice<<endl;
    return 0;
}
