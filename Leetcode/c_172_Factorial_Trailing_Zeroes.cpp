//
// Created by Mr.Hu on 2018/6/4.
//
// leetcode 172 factorial trailing zeros
//
// 题目要求对于给定的整数n，求其阶乘结果后面0的个数
//
// 这个题目之前和qy交流的时候做过，当时的想法是既然要 求 末位0的个数，那么就是在阶乘中10出现的次数
// 又分析发现要找出10出现的个数，就是要找出2*5的个数，而2在数字中出现的次数一定多于5出现的次数，
// 所以我们只需要判断5在所有数字中以因子的形式出现了多少次，即阶乘结果尾数有多少个0；
// 于是有了trailingZeroes_one的解法，这个方法在n比较小的时候还是可以用，但是数字大则相当耗时，
// 我们可以发现，我们对每一个数字求其因子中含有多少个5，复杂度位O(nlogn)
//
// 而题目要求复杂度为O(logn)
// 所以我去查了一下别人的解法：首先对n = n/5，结果即为有多少个数字包含一个因子5，
// 然后对得到的结果n继续n=n/5，结果即为有多少个数字包含两个因子5，此处为包含第二个因子5
// 然后对得到的结果n继续n=n/5，结果即为有多少个数字包含三个因子5，此处为包含第三个因子5
// 重复这一操作，每次的商叠加到result商，直到商不大于5，则循环结束。这种方式的复杂度明显为O(logn)
//
// 对第一种方法和第二种方法进行了关联，第一种方法的逆过程其实就是第二种方法。
// 第二种方法值得学习和深思
//

#include <iostream>
using namespace std;

class Solution {
public:

    int trailingZeroes_one(int n) {
        int result = 0;
        if (n <= 0)
            return result;
        for (int i = 1; i <= n; i++) {
            int m = i;
            while (m % 5 == 0) {
                result++;
                m /= 5;
            }
        }
        return result;
    }

    int trailingZeroes(int n) {
        int result = 0;
        while (n > 4) {
            result += n /= 5;
        }
        return result;

    }
};

int main() {
    int n = 10000001;
    Solution solution;
    int result = solution.trailingZeroes(n);
    cout << result << endl;
    return 0;
}