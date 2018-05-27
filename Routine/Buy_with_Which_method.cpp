//
// Created by Mr.Hu on 2018/5/26.
//
// 2018 CodeM资格赛 第一题
// 1、给定商品的价格以及是否参与打折，折扣统一为八折
// 2、给定总金额达到上限后的减小幅度
// 求最合理的购买方式
//
//
// 美团在吃喝玩乐等很多方面都给大家提供了便利。最近又增加了一项新业务：小象生鲜。
// 这是新零售超市，你既可以在线下超市门店选购生鲜食品，也可以在手机App上下单，最快30分钟就配送到家。
// 新店开张免不了大优惠。我们要在小象生鲜超市里采购n个物品，每个物品价格为ai，有一些物品可以选择八折优惠（称为特价优惠）。
// 有m种满减优惠方式，满减优惠方式只有在所有物品都不选择特价优惠时才能使用，且最多只可以选择最多一款。
// 每种满减优惠描述为(bi,ci)，即满bi减ci（当消费>=bi时优惠ci）。
// 求要买齐这n个物品（必须一单买齐），至少需要多少钱（保留两位小数）。
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
